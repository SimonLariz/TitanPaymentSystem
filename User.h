#pragma once
#include <iostream>
#include <vector>
#include "Purchase.h"

class User {
private:
	// Variables
	std::string userName;
	std::string userFirstName;
	std::string userLastName;
	std::string userPhoneNumber;
	std::string userPassword;
	std::string userCountry;
	std::string userAddress;

	std::vector<Purchase> purchaseVect;
	//NEW
	double totalAmountPaid;
	double amountDue;

public:
	//Adds purchase to purchase vector
	void addPurchase(std::string date, std::string card, std::string amount);

	//Setter Functions
	void setFirstName(std::string firstName);
	void setLastName(std::string lastName);
	void setUserName(std::string fullName);
	void setUserPhoneNumber(std::string phoneNumber);
	void setUserPassword(std::string password);
	void setUserCountry(std::string country);
	void setUserAddress(std::string address);
	void setAmountDue(double amount);
	void setTotalAmountPaid(double amount);
	//Getter Functions
	std::string getFirstName();
	std::string getLastName();
	std::string getUserName();
	std::string getPhoneNumber();
	std::string getUserPassword();
	std::string getCountry();
	std::string getAddress();
	double getAmountDue();
	double getTotalAmountPaid();
};
