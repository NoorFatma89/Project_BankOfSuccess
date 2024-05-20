#include "SavingsImpl.h"
#include <iostream>
using namespace std;

bool SavingsImpl::open(Account *account)
{
    Savings savingsAccount = dynamic_cast<Savings &>(*account);

    bool isOpen = false;

    int age=savingsAccount.getCurrentYear()-savingsAccount.getYearFromDateOfBirth(savingsAccount.getDateOfBirth());

    try
    {
        // Logic to open savings account   
        if ( age>= 18)
        {
            // current date and time on the current system
            // time_t now = time(0);

            // convert now to string form
            // char* date_time = ctime(&now);

            time_t currentTime = chrono::system_clock::to_time_t(chrono::system_clock::now());

            tm currentDate = *localtime(&currentTime);
            
            // savingsAccount.setActivatedDate(date_time);
            account->setActivatedDate(currentDate);

            account->setIsActive(true);

            isOpen = true;
        }
        else
        {
            throw CustomException("You are not eligible");
        }
    }
    catch (const CustomException &e)
    {
        std::cout << "Caught exception: " << e.what() << '\n';
    }

    return isOpen;
}
