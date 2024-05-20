#include "AccountController.h"

//Constructor
AccountController::AccountController()
{
    // Has-A objects should be instantiated in the constructor
    manager = new AccountManager();
    accountImpl = nullptr; // Initialize accountImpl properly
}

AccountController::AccountController(Logger* logger) : accountImpl(new AccountManager(logger)), logger(logger) {}

// Destructor
AccountController::~AccountController()
{
    delete manager;
}

// Method to open the account
void AccountController::open()
{
    // Construction of a solution...
    // 1. Check the type of account user wants to create
    string accountType = acceptUserChoice();

    // This is to get the object filled based on the type of account needed
    Account *account = getAccountInformation(accountType);

    IAccountImpl *accountImpl = AccountImplFactory::createAccount(accountType);

    bool status=accountImpl->open(account);

    // 5. Display message to the user
    displayAccountStatus(status);
    try 
    {
        if(status)
        {
            // std::cout << "Your Account Number is: " << account->getAccountNumber() << std::endl;
            cout << "Wao" << endl;
        }
        else 
        {
            throw CustomException("Failed to open account!");
        }
    }
    catch (const exception &e) 
    {
        logger->logMessage("Exception occurred: " + string(e.what()));
    }
}

// Method to get account object filled with user information based on the type needed
Account* AccountController::getAccountInformation(const string &accountType)
{
    Account *account = new Account();

    // Create the object based on the type of account to be created;
    // IAccountImpl *accountImpl = AccountImplFactory::createAccount(accountType);

    // Account *tempAccount1;
    // Account *tempAccount2;

    // Get Common Account information
    account=getCommonAccountInformation(account);

    // cout << endl << "account1: " << account << endl<< endl;

    // Get specific information related to savings or current
    account=getAccountTypeInformation(account,accountType);
    
    // cout << "account4: " << account << endl;

    return account;
}

// Method to accept the user choice to open the type of account needed
string AccountController::acceptUserChoice()
{
    // cout << "Select the account type you want to open: " << endl;
    // cout << "1. SAVINGS, 2. CURRENT " << endl;
    // int choice;
    // cin >> choice;
    // string accountType;
    // if (choice == 1)
    // {
    //     accountType = "SAVINGS";
    // }
    // else
    // {
    //     accountType = "CURRENT";
    // }
    // return accountType;
    try
    {
        std::cout << "Select the account type you want to open: " << std::endl;
        std::cout << "1. SAVINGS, 2. CURRENT " << std::endl;
        int choice;
        std::cin >> choice;
        if (choice == 1)
        {
            return "SAVINGS";
        }
        else if (choice == 2)
        {
            return "CURRENT";
        }
        else
        {
            throw CustomException("INVALID ACCOUNT TYPE CHOICE!");
        }
    }
    catch (const exception &e) {
        logger->logMessage("Exception occurred: " + string(e.what()));
    }
}

// Method to display the account opening status
void AccountController::displayAccountStatus(bool status)
{
    if (status)
    {
        cout << "\nCongratulations! Your account is opened successfully." << endl;
    }
    else
    {
        cout << "\nSorry. Try again next time" << endl;
    }
    // try 
    // {
    //     if(status)
    //     {
    //         cout << "\nCongratulations! Your account is opened successfully." << endl;
    //         // std::cout << "Your Account Number is: " << account->getAccountNumber() << std::endl;
    //     }
    //     else if(!status)
    //     {
    //         cout << "Not Status" << endl;
    //         throw CustomException("Failed to open account!");
    //     }
    // }
    // catch (const exception &e) 
    // {
    //     logger->logMessage("Exception occurred: " + string(e.what()));
    // }
}

// Method to get common account information from the user
Account* AccountController::getCommonAccountInformation(Account *account)
{
    // Get Common Account information
    cout << "Enter Name: " << endl;
    string name;
    cin >> name;
    account->setName(name);

    cout << "Enter Balance: " << endl;
    double balance;
    cin >> balance;
    account->setBalance(balance);

    std::cout << "Enter Privilege Type (0 for PREMIUM, 1 for GOLD, 2 for SILVER): " << endl;
    int priv;
    std::cin >> priv;

    Account::Privilege privilege;

    // Convert the integer input to Privilege enum
    switch (priv)
    {
    case 0:
        privilege = Account::Privilege::PREMIUM;
        break;
    case 1:
        privilege = Account::Privilege::GOLD;
        break;
    case 2:
        privilege = Account::Privilege::SILVER;
        break;
    default:
        std::cerr << "Invalid input!" << std::endl;
    }
    account->setPrivilege(privilege);

    cout << "Enter Pin Number: " << endl;
    int pinNumber;
    cin >> pinNumber;
    bool isPin=account->setPinNumber(pinNumber);

    if (!isPin)
    {
        throw CustomException("Enter Currect Pin ");
    }

    // account.setPinNumber(pinNumber);
    account->setAccountNumber();

    // Account account = dynamic_cast<Account &>(*accountImpl);

    return account;
}

// Method to get specific account type information from the user
Account* AccountController::getAccountTypeInformation(Account *account, const string& accountType)
{
    // Based on the type of account - Ask the user to give information
    if (accountType=="SAVINGS")
    {
        // creating Savings account object
        Savings *savingsAcc=new Savings();

        cout << "Enter Gender: " << endl;
        string gender;
        cin >> gender;
        savingsAcc->setGender(gender);

        cout << "Enter Date of Birth (YYYY/MM/DD): " << endl;
        // // time_t dateOfBirth;
        // // cin >> dateOfBirth;

        struct tm tm_dateOfBirth = {0}; // Initialize all fields to zero

        cin >> std::get_time(&tm_dateOfBirth, "%Y/%m/%d"); // Parse the input date

        // Convert the tm structure to a time_t value
        time_t dateOfBirth = std::mktime(&tm_dateOfBirth);

        // Check if mktime failed
        if (dateOfBirth == -1) {
            cout << "Error: Invalid date." << endl;
            return nullptr; // Exit with error
        }

        // Set the date of birth in savingsAcc
        savingsAcc->setDateOfBirth(dateOfBirth);

        cout << "Enter Phone Number: " << endl;
        string phoneNo;
        cin >> phoneNo;
        savingsAcc->setPhoneNumber(phoneNo);

        // cout << "account2: " << account << endl;

        account=dynamic_cast<Savings*>(savingsAcc);

        // cout << "account3: " << account << endl;
    }
    else if (accountType=="CURRENT")
    {
        // creating Current account object
        Current *currentAcc=new Current();

        cout << "Enter Registration Number: " << endl;
        string registrationNo;
        cin >> registrationNo;

        cout << "Enter Company Name: " << endl;
        string companyName;
        cin >> companyName;

        cout << "Enter website URL: " << endl;
        string websiteUrl;
        cin >> websiteUrl;

        // Store common account information in the object
        currentAcc->setRegistrationNumber(registrationNo);
        currentAcc->setCompanyName(companyName);
        currentAcc->setWebsiteURL(websiteUrl);

        account=dynamic_cast<Current*>(currentAcc);
    }

    return account;
}

// withdraw method
void AccountController::withdraw()
{
    cout << "Enter Account Number: ";
    long accNo;
    cin >> accNo;

    // Create the account object for the given account number
    Account account;

    Savings savingAccount;
    account = savingAccount;

    cout << "Please Enter amount to Withdraw: ";
    double amount;
    cin >> amount;

    cout << "Please Enter Pin Number: ";
    int pinNo;
    cin >> pinNo;

    bool isWithdrawn = manager->withdraw(account, amount, pinNo);

    if (isWithdrawn)
    {
        cout << "\nAmount has been withdrawn successfully!";
    }
    else
    {
        cout << "Error! Please try again!";
    }
}

// method to deposit amount
void AccountController::deposit()
{
    cout << "Enter Account Number: ";
    long accNo;
    cin >> accNo;

    // Create the account object for the given account number
    Account account;

    Savings savingAccount;
    account = savingAccount;

    cout << "Please Enter amount to Deposit: ";
    double amount;
    cin >> amount;

    cout << "Please Enter Pin Number: ";
    int pinNo;
    cin >> pinNo;

    bool isDeposit = manager->deposit(account, amount, pinNo);

    if (isDeposit)
    {
        cout << "\nAmount has been deposited successfully!";
    }
    else
    {
        cout << "Error! Please try again!";
    }
}

// method to transfer amount
void AccountController::transfer()
{
    cout << "Enter Sender's Account Number: ";
    long senderAccNo;
    Account *sender = new Savings();
    cin >> senderAccNo;

    cout << "Enter Receiver's Account Number: ";
    long receiverAccNo;
    Account *receiver = new Savings();
    cin >> receiverAccNo;

    cout << "Enter the amount to be transfer: ";
    int amount;
    cin >> amount;

    cout << "Please Enter Pin Number: ";
    int pinNo;
    cin >> pinNo;

    bool isTransfer = manager->transfer(*sender, *receiver, amount, pinNo);

    if (isTransfer)
    {
        cout << "\nAmount has been transfered successfully!";
    }
    else
    {
        cout << "Error! Please try again!";
    }
}

// Method to close the account
void AccountController::close()
{
    // Creating the instance of manager. A new instance is created
    // In this case - AccountController USES AccountManager
    cout << "Enter Account number that you want to close :" << endl;
    long accNum;
    cin >> accNum;
    cout << "\nEnter Pin Number: ";
    int pinNum;
    cin >> pinNum;

    Account *account = new Savings();

    bool isClosed = manager->close(*account, accNum, pinNum);
    if (isClosed)
    {
        cout << "\nAccount has been closed successfully!";
    }
    else
    {
        cout << "Error! Please try again!";
    }

    delete account;
}
