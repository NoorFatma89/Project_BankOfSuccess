Project: Bank Account Management System

Description:
Developed a comprehensive Bank Account Management System using C++ to manage various types of bank accounts including Savings and Current accounts. The system encompasses core functionalities such as opening accounts, depositing and withdrawing funds, transferring amounts between accounts, and closing accounts. Implemented robust error handling and logging mechanisms to ensure smooth operation and maintain a detailed record of all transactions and exceptions.

Key Features:
Account Types: Implemented both Savings and Current accounts, each with specific attributes and behaviors.
Logging: Developed a Logger class to maintain detailed logs of all activities and exceptions, ensuring traceability and ease of debugging.
Custom Exception Handling: Created a CustomException class to handle specific error scenarios gracefully and provide meaningful error messages.
Factory Pattern: Utilized Factory Pattern to create account implementations, promoting scalability and maintainability.
Dynamic Casting: Employed dynamic casting to ensure type safety and correct account type handling.
Transaction Management: Managed deposits, withdrawals, and transfers with appropriate checks and balances, including PIN verification and balance validation.
Transfer Logging: Maintained a log of transfer transactions to track and limit the total transferred amount, enhancing security.

Technologies and Concepts:
Programming Language: C++
Standard Library: Utilized various standard library features including iostream, fstream, ctime, chrono, and exception.
Object-Oriented Programming (OOP): Implemented OOP principles such as inheritance, polymorphism, and encapsulation.
Design Patterns: Applied Factory Pattern for creating account types and Interface for account operations.
Error Handling: Developed custom exception handling to manage and log errors effectively.
Chrono Library: Utilized chrono library for handling date and time operations.

Responsibilities:
Designed and implemented classes for different account types and their specific attributes.
Developed a Logger class for detailed logging of all system activities and exceptions.
Created a CustomException class for handling and logging specific errors.
Implemented methods for account operations including opening, closing, depositing, withdrawing, and transferring funds.
Ensured robust error handling and logging throughout the system to facilitate debugging and maintain traceability.
Utilized design patterns to enhance the system's scalability and maintainability.

Outcome:
Successfully created a robust and scalable Bank Account Management System with detailed logging and error handling, facilitating efficient management of different types of bank accounts and their associated transactions. The system's architecture ensures easy maintenance and future enhancements, making it a reliable solution for banking operations.
