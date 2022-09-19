#include "FileLogger.h"
#include <chrono>

FileLogger::FileLogger(const std::string& FN)
{
    logOut_.open(FN, std::ios_base::out);
}

FileLogger::~FileLogger()
{
    if (logOut_.is_open())
    {
        logOut_.close();
    }
}

std::string FileLogger::GetCurDateTime()
{
    auto cur = std::chrono::system_clock::now();
    time_t time = std::chrono::system_clock::to_time_t(cur);
    char buf[64] = { 0 };
    ctime_s(buf, 64, &time);
    buf[strlen(buf) - 1] = '\0';
    return std::string(buf);
}

void __fastcall FileLogger::WriteToLog(const std::string& str)
{
    if (logOut_.is_open())
    {
        logOut_ << GetCurDateTime() << " - " << str << std::endl;
    }
}

void __fastcall FileLogger::WriteToLog(const std::string& str, int n)
{
    if (logOut_.is_open())
    {
        logOut_ << GetCurDateTime() << " - " << str << n << std::endl;
    }
}

void __fastcall FileLogger::WriteToLog(const std::string& str, double d)
{
    if (logOut_.is_open())
    {
        logOut_ << GetCurDateTime() << " - " << str << d << std::endl;
    }
}
