#ifndef ACCOUNTCONTROLLER_H
#define ACCOUNTCONTROLLER_H

#include <iostream>
#include <iomanip> // This header is needed for std::get_time
#include "../Business/AccountManager.h"
#include "../Data/Savings.h"
#include "../Data/Current.h"
#include "../Data/AccountImplFactory.h"
#include "../Log/logger.h"

using namespace std;


// Boundary Class - This class is being consumed by the end user
// Account Controller class is the one which interacts with the user. Is given to collect infomation and submit to the manager and other classes to further process the account
// This is a boundary class which user interacts with
class AccountController
{
private:
    // Account controler Has A Account Manager. Has-A relationship
    // scope of this object is class level
    AccountManager *manager;
    AccountManager *accountImpl; // Declare accountImpl as a member variable
    Logger *logger;

public:
    AccountController();
    AccountController(Logger* );
    ~AccountController();
    void open();
    Account* getAccountInformation(const string&);
    string acceptUserChoice();
    void displayAccountStatus(bool );
    Account* getCommonAccountInformation(Account*);
    Account* getAccountTypeInformation(Account* , const string&);
    void withdraw();
    void deposit();
    void transfer();
    void close();

};

#endif