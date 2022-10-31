#pragma once
#include <iostream>
#include <string>
#include <fstream>

class user_creation {
private:
    std::string userName;
    std::string firstName;
    std::string lastName;
    std::string userPassword;
    std::string userAddress;
    std::string userCountry;
    std::string userPhoneNum;

public:
    void SetUserName(std::string userName) { this->userName = userName; };
    void SetFirstName(std::string firstName) { this->firstName = firstName; };
    void SetLastName(std::string lastName) { this->lastName = lastName; };
    void SetUserPassword(std::string userPassword) { this->userPassword = userPassword; };
    void SetUserAddress(std::string userAddress) { this->userAddress = userAddress; };
    void SetUserCountry(std::string userCountry) { this->userCountry = userCountry; };
    void SetUserPhoneNumber(std::string userPhoneNum) { this->userPhoneNum = userPhoneNum; };
    void CreateAccount();
};

void user_creation::CreateAccount() {
    std::cout << "Creating Account File" << std::endl;

    std::string fileName = userName + ".csv";

    std::ofstream fout;
    fout.open(fileName.c_str(), std::ios::out | std::ios::app);
    fout << userName << std::endl;
    fout << firstName << std::endl;
    fout << lastName << std::endl;
    fout << userAddress << std::endl;
    fout << userCountry << std::endl;
    fout << userPassword << std::endl;
    fout << userPhoneNum << std::endl;
    fout.close();
};
