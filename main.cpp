#include <iostream>
#include <string>
#include <ctime>
#include <typeinfo>
#include <exception>
#include <map>
#include <chrono>

#include "./UI/AccountController.h"

using namespace std;


int main()
{
    // Instantiate a Logger object
    Logger logger;

    // Instantiate an AccountController object with the Logger object
    AccountController controller(&logger); 

    int choice;

    cout<< "Welcome to the Bank: \n";
    cout<< "Please Select what operation you want to perform: \n";
    cout<< "To Open an Account, Press 1: \n";
    cout<< "To Deposite money, Press 2: \n";
    cout<< "To Withdraw money, Press 3: \n";
    cout<< "To Transfer money, Press 4: \n";
    cout<< "To Close Account, Press 5: \n";
    cout<< "Enter Your Choice: \n";

    cin >> choice;

    switch (choice)
    {
    case 1:
        controller.open();
        break;
    case 2:
        controller.deposit();
        ;
        break;
    case 3:
        controller.withdraw();
        break;
    case 4:
        controller.transfer();
        break;
    case 5:
        controller.close();
        break;
    default:
        cout << "Incorrect Choice! ";
    }

    return 0;
}
