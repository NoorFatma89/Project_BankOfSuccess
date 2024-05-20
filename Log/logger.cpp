#include "Logger.h"

Logger::Logger() 
{
    // Open the log file in append mode
    logFile.open("bank_log.txt", ios::app);
}

Logger::~Logger() 
{
    // Close the log file when the Logger object is destroyed
    if (logFile.is_open()) 
    {
        logFile.close();
    }
}

// Method to log a message to the file
void Logger::logMessage(const string& message) 
{
    // Get the current time
    auto now = chrono::system_clock::to_time_t(chrono::system_clock::now());

    // Write the message and current time to the log file
    logFile << "[" << ctime(&now) << "] " << message << endl;
}
