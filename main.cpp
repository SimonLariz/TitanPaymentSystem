//Includes
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include "Purchase.h"
#include "User.h"
#include "userCreation.h"
#include "accountFunctions.h"

//currentUser and userStatus
User currentUser;
bool logged_in = false;

//Main 
int main() {
    int userInput = 0;

    //If no user is logged in ask to login or register
    if (!logged_in) {
        std::cout << "Login or Register:\n";
        std::cout << "1) Login\n";
        std::cout << "2) Register\n";
        std::cout << "3) Quit\n";
        std::cout << "Enter Choice Number: "; 
        
        std::cin >> userInput;

        //Switch on userInput
        switch (userInput) {
         //Call Login() attempt login
        case 1:
            std::cout << "Login chosen\n";
            Login();
            logged_in = true;
            break;
         //Call getInformation and register
        case 2:
            std::cout << "Registeration Chosen\n";
            GetInformation();
            main();
            break;
         //Exit
        case 3:
            exit(0);
            break;
         //Ask for valid input
        default:
            std::cout << "Invalid choice.\n\n";
            main();
        }
    }

    //If user is successfully logged in
    while (logged_in) {
        std::cout << "Menu: \n";
        std::cout << "1) User Information\n";
        std::cout << "2) Add Purchase \n";
        std::cout << "3) Upload Purchase(s) from file \n";
        std::cout << "4) View payment info \n";
        std::cout << "5) View purchases \n";
        std::cout << "6) Log out\n";
        std::cout << "Enter Choice Number: "; 
        std::cin >> userInput;

        //Switch on userInput
        switch (userInput) {
            //User information, Call Account_Query() to query user information
            case 1:
                Account_Query();
                main();
                break;
            //Add Purchase, Call addPurchaseUser() to add a purchase to current user
            case 2:
                currentUser = addPurchaseUser(currentUser);
                break;
            //Add Purchase from file, Call addPurchaseUserFile() to add purchase from .txt file
            case 3:
                currentUser = addPurchaseUserFile(currentUser);
                break;
            //Payment Information, Call paymentInfo() to view account bal and make a payment
            case 4:
                currentUser = paymentInfo(currentUser);
                break;
            //View purchases, Call viewPurchases() to view user purchases
            case 5:
                viewPurchases(currentUser);
                break;
            //Log out, Return to main and sign out
            case 6:
                logged_in = false;
                main();
                break;
            //Ask for valid input
            default:
                std::cout << "Please select an option between 1 - 6\n";
        }
    }
    return 0;
}