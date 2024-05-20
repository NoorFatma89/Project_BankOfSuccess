#ifndef CUSTOMEXCEPTION_H
#define CUSTOMEXCEPTION_H

#include <exception>
#include <string>
using namespace std;

// Custom exception class to handle exceptions
class CustomException : public exception
{
private:
    string m_message;

public:
    CustomException(const string &message) ;

    virtual const char *what() const noexcept override;
    
};

#endif