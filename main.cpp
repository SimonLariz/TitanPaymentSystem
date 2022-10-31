#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include<sstream>
#include "Purchase.h"
#include "User.h"
#include "user_creation.h"
#include "account_functions.h"


using namespace std;

User currentUser;
bool logged_in = false;

int main() {
    int choice = 0;

    if (!logged_in) {
        std::cout << "Login or Register:\n";
        std::cout << "1) Login\n";
        std::cout << "2) Register\n";
        std::cout << "Enter Choice Number: "; std::cin >> choice;

        if (choice == 1) {
            std::cout << "Login chosen\n";
            Login();
            logged_in = true;
        }
        else if (choice == 2) {
            std::cout << "Registeration Chosen\n";
            GetInformation();
            main();
        }
        else {
            std::cout << "Invalid choice.\n\n";
            main();
        }
    }

    while (logged_in) {
        std::cout << "Currently signed in as";
        std::cout << "Menu: \n";
        //Done
        std::cout << "1) User Information\n";

        std::cout << "2) Add Purchase \n";
        std::cout << "3) Upload Purchase(s) from file \n";
        std::cout << "4) View payment history \n";
        std::cout << "5) View purchases \n";
        std::cout << "6) Log out";


        std::cout << "Enter Choice Number: "; std::cin >> choice;

        switch (choice) {
            //User information
            case 1:
                Account_Query();
                main();
                break;
            //Add Purchase
            case 2:
                addPurchaseUser(currentUser);
                break;
            //Add Purchase from file
            case 3:
                break;
            //Payment history
            case 4:
                break;
            //View purchases
            case 5:
                break;
            //Log out
            case 6:
                break;

            default:
                cout << "Please select an option between 1 - 5";
        }
    }

    return 0;
}

/*

int main()
{
    mainDisplay();

    vector<std::string> parsedInput;

    //Testing reading from file
    fstream myFile;
    //Open file
    myFile.open("pruchases.txt", ios::in);
    if (myFile.is_open()) {
        //Get currentLine
        std::string currentLine;
        //Vector for parsed input
        //CHANGEvector<std::string> parsedInput;
        //Loop through text file
        while (getline(myFile, currentLine)) {
            stringstream s_stream(currentLine);
            while (s_stream.good()) {
                string subString;
                getline(s_stream, subString, ',');
                parsedInput.push_back(subString);
            }
        }
    }

    //Testing 
    for (string str : parsedInput) {
        std::cout << str << '\n';
    }


    return 0;
}
*/
