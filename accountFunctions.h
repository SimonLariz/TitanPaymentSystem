#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <sstream>
#include "Purchase.h"
#include "User.h"
#include "userCreation.h"

//Var placeholders for account information
std::string current_user_name = "";
std::string current_file_name = "";
bool userFound = false;
bool passwordFound = false;

//Collect user information
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

//Attempt user login if login fails exit()
User Login() {
    //Var placeholders
    User currentUser;
    std::string name;
    std::string userName = "";
    std::string userPassword = "";
    int userLine = 0;
    int passwordLine = 5;

    //Ask for username and password
    std::cout << "Enter Username: "; std::cin >> userName;
    std::cout << "Enter Password: "; std::cin >> userPassword;
    //Open user csv file
    current_file_name = userName + ".csv";
    std::fstream fin;
    fin.open(current_file_name.c_str(), std::ios::in);
    std::string userAccountName;
    std::getline(fin, userAccountName);
    //Username validation
    if (userName == userAccountName) {
        userFound = true;
    }
    //Password validation
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
    //User and password validation
    if (passwordFound && userFound) {
        std::cout << "Account Logged In\n\n";
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
        //Create new user class object
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


//Adds purchase, takes User as an arguement
User addPurchaseUser(User& currentUser) {
    //Var placeholders
    std::string strDate;
    std::string purchaseCard;
    std::string purchaseAmount;
    //Ask for purchase information
    std::cout << "\nTo add a purchase please fill out the following\n";
    std::cout << "Enter purchase date (YYMMDD): ";
    std::cin >> strDate;
    std::cout << "Enter purchase card (AMEX / VISA / DISCOVER): ";
    std::cin >> purchaseCard;
    std::cout << "Enter purchase amount: $";
    std::cin >> purchaseAmount;
    //Call addPurchase() with purchase information as arguement
    currentUser.addPurchase(strDate, purchaseCard, purchaseAmount);
    //Update amount due
    currentUser.setAmountDue(currentUser.getAmountDue() + stod(purchaseAmount));
    std::cout << "Purchase added!\n\n";
    //Return updated User object
    return currentUser;
}

//Adds purchase(s), from .txt file
User addPurchaseUserFile(User& currentUser) {
    int count = 0;
    //Ask for file name
    std::string fileName;
    std::cout << "\nEnter the name of the file: ";
    std::cin >> fileName;
    std::fstream myFile;
    //Open file
    myFile.open(fileName, std::ios::in);
    if (myFile.is_open()) {
        //Get currentLine
        std::string currentLine;
        //Loop through text file
        while (getline(myFile, currentLine)) {
            std::vector<std::string> parsedInput;
            std::stringstream s_stream(currentLine);
            //Parse line
            while (s_stream.good()) {
                std::string subString;
                getline(s_stream, subString, ',');
                parsedInput.push_back(subString);
            }
            //Call addPurchase() with parsedInput as arguement
            currentUser.addPurchase(parsedInput[0], parsedInput[1], parsedInput[2]);
            count++;
            //Update amount due
            currentUser.setAmountDue(currentUser.getAmountDue() + stod(parsedInput[2]));
        }
    }
    std::cout << "Added: " << count << " purchases from: " << fileName << "\n\n";
    //Return updated User object
    return currentUser;
}


//Allows user to query information
void Account_Query() {
    //Var placeholders
    std::vector<std::string> userInformation;
    std::string file_line = "";
    std::fstream fin;
    int userInput = 0;
    //Open file and dump info into vector
    fin.open(current_file_name.c_str(), std::ios::in);
    userInformation.clear();
    int i = 0;
    while (i < 7) {
        std::getline(fin, file_line);
        userInformation.push_back(file_line);
        i++;
    }
    fin.close();
    //Ask for user input
    std::cout << "\nWhat user information do you want to see?\n";
    std::cout << "1) User's Username\n";
    std::cout << "2) User's Full Name\n";
    std::cout << "3) User's Password\n";
    std::cout << "4) User's Address\n";
    std::cout << "5) User's Country\n";
    std::cout << "6) User's Phone Number\n";
    std::cout << "7) Return to Main Menu\n";
    std::cout << "Enter Choice Number: "; 
    std::cin >> userInput;
    //Switch on userInput
    switch (userInput) {
    case  1:
        std::cout << "\nUser's Username: " << userInformation[0] << "\n\n";
        Account_Query();
        break;
    case  2:
        std::cout << "\nUser's Full Name: " << userInformation[1] << " " << userInformation[2] << "\n\n";
        Account_Query();
        break;
    case  3:
        std::cout << "\nUser's Password: " << userInformation[5] << "\n\n";
        Account_Query();
        break;
    case  4:
        std::cout << "\nUser's Address: " << userInformation[3] << "\n\n";
        Account_Query();
        break;
    case  5:
        std::cout << "\nUser's Country: " << userInformation[4] << "\n\n";
        Account_Query();
        break;
    case  6:
        std::cout << "\nUser's Phone Number: " << userInformation[6] << "\n\n";
        Account_Query();
        break;
    case  7:
        std::cout << "\n\n";
        break;

    }
}

//View user purchases
void viewPurchases(User& currentUser) {
    int userInput;
    int startingDate, endingDate;
    std::vector<Purchase> userPurchaseVector = currentUser.getPurchaseVect();
    //If no purchases return to menu
    if (userPurchaseVector.empty()) {
        std::cout << "\nNo purchases found\n\n";
        return;
    }
    //Ask for input
    std::cout << "\n1) View all purchases\n";
    std::cout << "2) View min purchase\n";
    std::cout << "3) View max purchase\n";
    std::cout << "4) View filtered purchases\n";
    std::cout << "Enter Choice Number: ";
    std::cin >> userInput;
    //Switch on userInput
    switch (userInput) {
    //Display all purchases
    case 1:
        std::cout << "\n";
        for (int i = 0; i < userPurchaseVector.size(); i++) {
            userPurchaseVector[i].printPurchase();
        }
        std::cout << '\n';
        break;
     //Display userPurchaseVector[0] (min)
    case 2:
        std::cout << "Min Purchase: \n";
        userPurchaseVector[0].printPurchase();
        std::cout << '\n\n';
        break;
     //Display userPurchaseVector[size() - 1] (max)
    case 3:
        std::cout << "Max Purchase: \n";
        userPurchaseVector[userPurchaseVector.size()-1].printPurchase();
        std::cout << '\n\n';
        break;
    //Display filtered results
    case 4:
        std::cout << "Please enter starting date (YYMMDD): ";
        std::cin >> startingDate;
        std::cout << "Please enter ending date (YYMMDD): ";
        std::cin >> endingDate;
        std::cout << "Purchases betwen " << startingDate << " and " << endingDate << "\n";
        for (int i = 0; i < userPurchaseVector.size(); i++) {
            if (userPurchaseVector[i].getPurchaseDate() >= startingDate && userPurchaseVector[i].getPurchaseDate() <= endingDate) {
                userPurchaseVector[i].printPurchase();
                std::cout << "\n";
            }
        }
        std::cout << '\n\n';
        break;
    //Ask for valid input
    default:
        std::cout << "Please make a selection between 1 - 3\n";
        viewPurchases(currentUser);
    }
}

//Displays payment information
User paymentInfo(User currentUser) {
    //Ask for input
    int userInput;
    std::string strPayment;
    std::cout << "\nCurrent account balance: $" << std::fixed << std::setprecision(2) << currentUser.getAmountDue() << '\n';
    std::cout << "1) Make payment\n";
    std::cout << "2) View total amount paid\n";
    std::cout << "3) Return to main menu \n";
    std::cout << "Enter Choice Number: ";
    std::cin >> userInput;
    //Switch on input
    switch (userInput) {
     //Allow user to make a payment and update balance
    case 1:
        std::cout << "Please enter payment amount: $";
        std::cin >> strPayment;
        currentUser.setAmountDue(currentUser.getAmountDue() - stod(strPayment));
        std::cout << "\nPayment complete new account balance: $" << std::fixed << std::setprecision(2) << currentUser.getAmountDue() << "\n\n";
        currentUser.setTotalAmountPaid(currentUser.getTotalAmountPaid() + stod(strPayment));
        return currentUser; 
        break;
     //Display total amount paid by user
    case 2:
        std::cout << "Total amount paid: $" << std::fixed << std::setprecision(2) << currentUser.getTotalAmountPaid() << "\n\n";
        return currentUser;
        break; 
    //Return to menu
    case 3:
        std::cout << "\n";
        return currentUser;
        break;
    //Ask for valid input
    default:
        std::cout << "Please make a selection between 1 -2\n";
        paymentInfo(currentUser);
    }
}