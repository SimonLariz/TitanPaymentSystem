#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "Purchase.h"
#include "User.h"
#include "user_creation.h"

std::string current_user_name = "";
std::string current_file_name = "";
bool userFound = false;
bool passwordFound = false;

void GetInformation() {
    std::string userName, firstName, lastName, userAddress, userCountry, userPassword, userPhoneNum;

    std::cout << "Creating New Account\n";
    std::cout << "Enter Username: "; std::cin >> userName;
    std::cout << "Enter First Name: "; std::cin >> firstName;
    std::cout << "Enter Last Name: "; std::cin >> lastName;
    std::cin.ignore(1000, '\n');
    std::cout << "Enter Address: ";
    std::getline(std::cin, userAddress);
    std::cout << "Enter Country: ";
    std::getline(std::cin, userCountry);
    std::cout << "Enter Password: "; std::cin >> userPassword;
    std::cout << "Enter Phone Number: "; std::cin >> userPhoneNum;

    user_creation newUser;
    newUser.SetUserName(userName);
    newUser.SetFirstName(firstName);
    newUser.SetLastName(lastName);
    newUser.SetUserAddress(userAddress);
    newUser.SetUserCountry(userCountry);
    newUser.SetUserPassword(userPassword);
    newUser.SetUserPhoneNumber(userPhoneNum);

    newUser.CreateAccount();
};

User Login() {
    User currentUser;
    std::string name;
    std::string userName = "";
    std::string userPassword = "";
    int userLine = 0;
    int passwordLine = 5;

    std::cout << "Enter Username: "; std::cin >> userName;
    std::cout << "Enter Password: "; std::cin >> userPassword;

    current_file_name = userName + ".csv";

    std::fstream fin;
    fin.open(current_file_name.c_str(), std::ios::in);

    std::string userAccountName;
    std::getline(fin, userAccountName);
    if (userName == userAccountName) {
        userFound = true;
    }

    int i = 0;
    while (i < 5) {
        std::string password;
        std::getline(fin, password);

        if (i == 0) {
            name = password;
        }

        if (password == userPassword) {
            passwordFound = true;
        }
        i++;
    }

    if (passwordFound && userFound) {
        std::cout << "Account Logged In\n";
        current_user_name = userName;
        std::cout << "Welcome, " << name << "!\n";
        //Read file
        std::vector<std::string> userInformation;
        std::string file_line = "";
        std::fstream fin;
        int choice = 0;

        fin.open(current_file_name.c_str(), std::ios::in);

        userInformation.clear();

        int i = 0;
        while (i < 7) {
            std::getline(fin, file_line);
            userInformation.push_back(file_line);
            i++;
        }

        fin.close();
        currentUser.setUserName(userInformation[0]);
        currentUser.setFirstName(userInformation[1]);
        currentUser.setLastName(userInformation[2]);
        currentUser.setUserAddress(userInformation[3]);
        currentUser.setUserCountry(userInformation[4]);
        currentUser.setUserPassword(userInformation[5]);
        currentUser.setUserPassword(userInformation[6]);

        fin.close();
        return currentUser;
    }
    else if (!passwordFound || !userFound) {
        std::cout << "Invalid credentials or user not found!\n";
        exit(0);
        fin.close();
    }
    exit(0);
    fin.close();
};


void addPurchaseUser(User currentUser) {
    std::string strDate;
    std::string purchaseCard;
    std::string purchaseAmount;

    std::cout << "To add a purchase please fill out the following\n";
    std::cout << "Enter purchase date (YYMMDD): ";
    std::cin >> strDate;
    std::cout << "Enter purchase card (AMEX / VISA / DISCOVER): ";
    std::cin >> purchaseCard;
    std::cout << "Enter purchase amount: $";
    std::cin >> purchaseAmount;
    currentUser.addPurchase(strDate, purchaseCard, purchaseAmount);
    currentUser.setAmountDue(currentUser.getAmountDue() + stod(purchaseAmount));
    std::cout << "Purchase added!\n";
}

void Account_Query() {
    std::vector<std::string> userInformation;
    std::string file_line = "";
    std::fstream fin;
    int choice = 0;

    fin.open(current_file_name.c_str(), std::ios::in);

    userInformation.clear();

    int i = 0;
    while (i < 7) {
        std::getline(fin, file_line);
        userInformation.push_back(file_line);
        i++;
    }

    fin.close();


    std::cout << "What user information do you want to see?\n";
    std::cout << "1) User's Username\n";
    std::cout << "2) User's Full Name\n";
    std::cout << "3) User's Password\n";
    std::cout << "4) User's Address\n";
    std::cout << "5) User's Country\n";
    std::cout << "6) User's Phone Number\n";
    std::cout << "7) Return to Main Menu\n";
    std::cout << "Enter Choice Number: "; std::cin >> choice;

    if (choice == 1) {
        std::cout << "User's Username: " << userInformation[0] << "\n\n";
        Account_Query();
    }
    else if (choice == 2) {
        std::cout << "User's Full Name: " << userInformation[1] << " " << userInformation[2] << "\n\n";
        Account_Query();
    }
    else if (choice == 3) {
        std::cout << "User's Password: " << userInformation[5] << "\n\n";
        Account_Query();
    }
    else if (choice == 4) {
        std::cout << "User's Address: " << userInformation[3] << "\n\n";
        Account_Query();
    }
    else if (choice == 5) {
        std::cout << "User's Country: " << userInformation[4] << "\n\n";
        Account_Query();
    }
    else if (choice == 6) {
        std::cout << "User's Phone Number: " << userInformation[6] << "\n\n";
        Account_Query();
    }
    else if (choice == 7) {
        std::cout << "\n\n";
        return;
    }
}
