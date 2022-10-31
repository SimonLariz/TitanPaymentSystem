#pragma once
#include <iostream>
#include <vector>
#include "Purchase.h"

class User {
private:
	// Variables
	std::string userFirstName;
	std::string userLastName;
	std::string userFullName;
	std::string userPhoneNumber;
	std::string userPassword;
	std::string userCountry;
	std::string userAddress;
	std::vector<Purchase> purchaseVect;

public:
	//Adds purchase to purchase vector
	void addPurchase(std::string date, std::string card, std::string amount, std::string status);

	//Setter Functions
	void setFirstName(std::string firstName);
	void setLastName(std::string lastName);
	void setUserFullName(std::string fullName);
	void setUserPhoneNumber(std::string phoneNumber);
	void setUserPassword(std::string password);
	void setUserCountry(std::string country);
	void setUserAddress(std::string address);
	//Getter Functions
	std::string getFirstName();
	std::string getLastName();
	std::string getFullName();
	std::string getPhoneNumber();
	std::string getUserPassword();
	std::string getCountry();
	std::string getAddress();
};
