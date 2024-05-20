#include "AccountManager.h"

//Default contrustor
AccountManager::AccountManager() {}

//Perameterized Constructor
AccountManager::AccountManager(Logger* logger) : logger(logger) {}

// method to deposit amount
bool AccountManager::deposit(Account account, double amountToDeposit, int pinNumber)
{
    bool isDeposited = false;

    try
    {
        if (account.getIsActive())
        {
            if (account.getPinNumber() == pinNumber)
            {
                account.setBalance(account.getBalance() + amountToDeposit);
                // update the status
                isDeposited = true;
            }
            else
            {
                throw CustomException("You entered incorrect pin!");
            }
        }
        else
        {
            throw CustomException("Account is Not Active!");
        }
    }
    catch (const exception &e)
    {
        // cout << "Caught exception: " << e.what() << endl;
        logger->logMessage("Exception occurred: " + string(e.what()));
    }
    // Return the status
    return isDeposited;
}

// Method to withdraw funds from accounnt
bool AccountManager::withdraw(Account account, double amountToWithdraw, int pinNumber)
{
    // Declaration
    bool isWithdrawn = false;

    try
    {
        if (account.getIsActive())
        {
            if (account.getPinNumber() == pinNumber)
            {
                if (account.getBalance() >= amountToWithdraw)
                {
                    account.setBalance(account.getBalance() - amountToWithdraw);
                    isWithdrawn = true;
                }
                else
                {
                    throw CustomException("Insufficiant amount!");
                }
            }
            else
            {
                throw CustomException("You entered incorrect pin!");
            }
        }
        else
        {
            throw CustomException("Account is Not Active!");
        }
    }
    catch (const exception &e)
    {
        // cout << "Caught exception: " << e.what() << endl;
        logger->logMessage("Exception occurred: " + string(e.what()));
    }
    // Return the status
    return isWithdrawn;
}

// Method to transfer from one account to another
bool AccountManager::transfer(Account sender, Account receiver, double amountToTransfer, int pinNumber)
{
    TransferLog transferLog;

    // Declaration
    bool isTransferred = false;
    
    try
    {
        // 1. Is from account active
        if (sender.getIsActive())
        {
            // 2. Is to account active
            if (receiver.getIsActive())
            {
                // 3. Check if pin number is valid
                if (pinNumber == sender.getPinNumber())
                {
                    // 4. Check if sufficient funds are available in from account
                    if (sender.getBalance() >= amountToTransfer)
                    {
                        // 5. Check if the transfer limit is exceeded
                        if (!transferLog.isMaxLimitExeeded())
                        {
                            // 6. Deduct amount from sender
                            sender.setBalance(sender.getBalance() - amountToTransfer);

                            // 7. Add amount to receiver
                            receiver.setBalance(receiver.getBalance() + amountToTransfer);
                        }
                        else
                        {
                            throw CustomException("Transferred Limit is Exeeded!");
                        }
                    }
                    else
                    {
                        throw CustomException("Insufficiant Amount!");
                    }
                }
                else
                {
                    throw CustomException("Sender's Account is not Active!");
                }
            }
            else
            {
                throw CustomException("Receiver's Account is not Active!");
            }
        }
        else
        {
            throw CustomException("Sender's Account is not Active!");
        }
    }
    catch (const exception &e)
    {
        logger->logMessage("Exception occurred: " + string(e.what()));
    }

    // 8. Add into Log the transfer made
    transferLog.addToLog(sender.getAccountNumber(), amountToTransfer);

    // 9. Update the status of transfer
    isTransferred = true;

    // 10. Return the status
    return isTransferred;
}

// method to close the account
bool AccountManager::close(Account account, long accountNumber, int pinNumber)
{
    bool isClosed = false;

    try
    {        
        if (account.getIsActive())
        {
            if (account.getAccountNumber() == accountNumber)
            {
                if (account.getPinNumber() == pinNumber)
                {
                    isClosed = true;
                    std::time_t currentTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
                    std::tm currentDate = *std::localtime(&currentTime);
                    account.setClosedDate(currentDate);
                }
                else
                {
                    throw CustomException("Pin Number is incorrect! ");
                }
            }
            else
            {
                throw CustomException("Account Number is incorrect! ");
            }
        }
        else
        {
            throw CustomException("Account is not Active! ");
        }
    }
    catch (const exception &e)
    {
        logger->logMessage("Exception occurred: " + string(e.what()));
    }

    return isClosed;
}