#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <fstream>
#include <ctime>
#include <chrono>
using namespace std;

// Logger class to manage logging to a file
class Logger {
private:
    ofstream logFile;

public:
    Logger() ;
    ~Logger();
    void logMessage(const string& );
};

// Global Logger object
// Logger logger;

#endif