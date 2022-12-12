#include <stdio.h>
#include <iostream>
#include <winsock2.h>
#include <chrono>

#include <socket_wrapper/socket_headers.h>
#include <socket_wrapper/socket_wrapper.h>
#include <socket_wrapper/socket_class.h>

#define HOST_NAME "www.sources.ru"// Любое доменное имя
#define NO_FLAGS 0// Флаги не указываем
// В RFC 792 определены значения сообщений ICMP
#define ICMP_ECHO 8// An ICMP echo message
#define ICMP_ECHOREPLY 0// An ICMP echo reply message
#define ICMP_HEADERSIZE 8

WORD InternetChksum(LPWORD lpwIcmpData, WORD wDataLength)
{
    long lSum;// Store the summation
    WORD wOddByte;// Left over byte from the summation
    WORD wAnswer;// The 1's complement checksum

    lSum = 0L;

    while (wDataLength > 1)
    {
        lSum += *lpwIcmpData++;
        wDataLength -= 2;
    }

    // Handle the odd byte if necessary and make sure the top half is zero
    if (wDataLength == 1)
    {
        wOddByte = 0;
        *((LPBYTE) &wOddByte) = *(LPBYTE)lpwIcmpData;// One byte only
        lSum += wOddByte;
    }

    // Add back the carry outs from the 16 bits to the low 16 bits
    lSum = (lSum >> 16) + (lSum & 0xffff);// Add high-16 to low-16
    lSum += (lSum >> 16);// Add carry
    wAnswer = (WORD)~lSum;// 1's complement, then truncate 
    // to 16 bits
    return(wAnswer);
}

struct ip // Структура заголовка IP
{
    BYTE ip_verlen;// Version and header length
    BYTE ip_tos;// Type of service
    WORD ip_len;// Total packet length 
    UINT ip_id;// Datagram identification 
    WORD ip_fragoff;// Fragment offset 
    BYTE ip_ttl;// Time to live 
    BYTE ip_proto;// Protocol
    UINT ip_chksum;// Checksum 
    IN_ADDR ip_src_addr;// Source address 
    IN_ADDR ip_dst_addr;// Destination address 
    BYTE ip_data[1];// Variable length data area
};

struct icmp// Структура заголовка ICMP
{
    BYTE icmp_type;// Type of message
    BYTE icmp_code;// Type "sub code" (zero for echos)
    WORD icmp_cksum;// 1's complement checksum
    HINSTANCE icmp_id;// Unique ID (the instance handle)
    WORD icmp_seq;// Tracks multiple pings
    BYTE icmp_data[1];// The start of optional data
};

char szPingBuffer[100];
BYTE IcmpSendPacket[1024];// Буфер для посылаемых данных
BYTE IcmpRecvPacket[4096];// Буфер для принимаемых данных 


bool ping(std::string &host_name)
{
    socket_wrapper::SocketWrapper sock_wrap;

	socket_wrapper::Socket sock = {AF_INET, SOCK_RAW, IPPROTO_ICMP};
	
	if (!sock)
    {
        std::cerr << sock_wrap.get_last_error_string() << std::endl;
        return EXIT_FAILURE;
    }

    HINSTANCE hInstance;
    struct icmp *pIcmpHeader;// Указатель на структуру ICMP
    struct ip *pIpHeader;// Указатель на структуру-заголовок IP

    PDWORD pdwTimeStamp;// Счетчик "тиков" при передаче
    DWORD dwReturnTime;// Счетчик "тиков" при приеме
    DWORD dwRoundTrip;// Счетчик "тиков" среднего времени пробега

    int iPacketSize;// размер ICMP-пакета 
    int iHostAddrLength;// Длина адреса сетевого компьютера
    int iIPHeadLength;// Длина заголовка IP-датаграммы
    int iReceivedBytes;// Количество принятых байтов
    int iSentBytes;// Количество посланных байтов
    int nProtocol;// Номер протокола ICMP
    int iSocketError;// Значение кода ошибки

    pIcmpHeader = (struct icmp *) IcmpSendPacket;// Point at the data area
    pIcmpHeader->icmp_type = ICMP_ECHO;// then fill in the data.
    pIcmpHeader->icmp_code = 0;// Use the Sockman instance 
    pIcmpHeader->icmp_id = hInstance;// handle as a unique ID.
    pIcmpHeader->icmp_seq = 0;// It's important to reset
    pIcmpHeader->icmp_cksum = 0;// the checksum to zero.

    //Значение счетчика "тиков" располагается в необязательной области данных
    pdwTimeStamp = (PDWORD)&IcmpSendPacket[ICMP_HEADERSIZE];
    *pdwTimeStamp = GetTickCount();
    iPacketSize = ICMP_HEADERSIZE + sizeof(DWORD);
    pIcmpHeader->icmp_cksum = InternetChksum((LPWORD)pIcmpHeader, iPacketSize);
    
    sockaddr_in addr =
    {
        .sin_family = AF_INET,
    };

    addr.sin_addr.s_addr = INADDR_ANY;

    if (pIcmpHeader->icmp_cksum !=0 )
    { 
        iSentBytes = sendto(sock, (LPSTR) IcmpSendPacket, iPacketSize, 
        NO_FLAGS, (LPSOCKADDR) &addr, sizeof(addr));
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        std::cout << "Usage: " << argv[0] << " <host name>" << std::endl;
        return EXIT_FAILURE;
    }

    std::string host_name = argv[1];

    ping(host_name);


	return EXIT_SUCCESS;
}