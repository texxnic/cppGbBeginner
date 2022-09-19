#include "FileLoggerSingleton.h"

FileLoggerSingleton::FileLoggerSingleton()
{};

FileLoggerSingleton& FileLoggerSingleton::GetInstance()
{
    static FileLoggerSingleton instance;
    return instance;
}

void FileLoggerSingleton::OpenLogFile(const std::string& FN)
{
    logOut_.open(FN, std::ios_base::app);
}

void FileLoggerSingleton::CloseLogFile()
{
    if (logOut_.is_open())
    {
        logOut_.close();
    }
}

void FileLoggerSingleton::WriteToLog(const std::string& str)
{
    if (logOut_.is_open())
    {
        logOut_ << GetCurDateTime() << " - " << str << std::endl;
    }
}

void FileLoggerSingleton::WriteToLog(const std::string& str, int n)
{
    if (logOut_.is_open())
    {
        logOut_ << GetCurDateTime() << " - " << str << n << std::endl;
    }
}

void FileLoggerSingleton::WriteToLog(const std::string& str, double d)
{
    if (logOut_.is_open())
    {
        logOut_ << GetCurDateTime() << " - " << str << d << std::endl;
    }
}

std::string FileLoggerSingleton::GetCurDateTime()
{
    auto cur = std::chrono::system_clock::now();
    time_t time = std::chrono::system_clock::to_time_t(cur);

    char buf[64] = { 0 };
    ctime_s(buf, 64, &time);
    buf[strlen(buf) - 1] = '\0';

    return std::string(buf);
}
