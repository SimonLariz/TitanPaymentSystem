#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include<sstream>
#include "Purchase.h"
#include "User.h"


using namespace std;

//Unordered Map to hold users
// phoneNumber , User
unordered_map <string, User> usersMap;

//Currently signed in user
User currentUser;



//Creates a new user
void createUser() {
    //Get user input
    string inputFirstName, inputLastName, inputPhoneNumber, inputPassword, inputCountry, inputAddress;
    cout << "\n To create an account please fill out the fields\n";
    cout << "\t Please enter your First Name: ";
    cin >> inputFirstName;
    cout << "\t Please enter your Last Name: ";
    cin >> inputLastName;
    cout << "\t Please enter your Phone Number: ";
    cin >> inputPhoneNumber;
    cout << "\t Please enter your Password: ";
    cin >> inputPassword;
    cout << "\t Please enter your Country: ";
    cin >> inputCountry;
    cout << "\t Please enter your Address: ";
    cin >> inputAddress;
    
    //Make newUser
    User newUser;
    newUser.setFirstName(inputFirstName);
    newUser.setLastName(inputLastName);
    newUser.setUserFullName(inputFirstName + " " + inputLastName);
    newUser.setUserPhoneNumber(inputPhoneNumber);
    newUser.setUserCountry(inputCountry);
    newUser.setUserAddress(inputAddress);
    
    //Add user to usersMap
    usersMap[inputPhoneNumber] = newUser;
}

//User sign in
void userLogin() {
    //Input
    string inputPhoneNumber, inputPassword;
    cout << "To sign please enter your credentials\n";
    cout << "\t Enter your phone number: ";
    cin >> inputPhoneNumber;
    cout << "\t Enter your password: ";
    cin >> inputPassword;

    //If user exist
    if (usersMap.find(inputPhoneNumber) != usersMap.end()) {
        User temp = usersMap[inputPhoneNumber];
        if (temp.getUserPassword() == inputPassword) {
            cout << "\t Successfully signed in as " << temp.getFullName() << "\n";
            currentUser = temp;
        }
        else {
            cout << "\t Incorrect password\n";
        }
    }
    //User doesnt exist
    else {
        cout << "\t No account associated with the phone number: " << inputPhoneNumber << "\n";
    }
}

//Main menu
void mainDisplay() {
    int userSelection;
    cout << "Hello, Welcome to the Titan Payment System\n\n";
    cout << "Please select an option \n";
    cout << "1. Create an account \n";
    cout << "2. Sign into an Account \n";
    cout << "3. Exit \n\n";
    cout << "\t Make a selection: ";
    cin >> userSelection;

    switch (userSelection) {
        //Create an account
    case 1:
        createUser();
        break;
        //Login to user
    case 2:
        userLogin();
        break;
    default:
        exit(0);
    }
}

//User options
void userOptions() {
    while (true) {
        int userInput;
        cout << "\n Currently signed in as: " << currentUser.getFullName() << "\n";
        cout << "Please select an option \n";
        cout << "1. Add purchase \n";
        cout << "2. Upload purchases from file \n";
        cout << "3. View minimum transaction \n";
        cout << "4. View maximum transaction \n";
        cout << "5. Display account information \n";
        cout << "6. Display all transactions \n";
        cout << "7. Sign out \n\n";
        cout << "\t Make a selection: ";
        cin >> userInput;

        switch (userInput) {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:

            break;
        case 7:
            return;
            break;
        default:
            cout << "\t Please make a selection between 1 - 7 \n";
        }

    }

}

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
