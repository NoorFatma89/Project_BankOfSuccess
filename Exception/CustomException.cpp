#include "CustomException.h"


    CustomException::CustomException(const string &message) : m_message(message) {}

    const char *CustomException::what() const noexcept 
    {
        return m_message.c_str();
    }
