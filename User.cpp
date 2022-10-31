#include <iostream>
#include <string>
#include <algorithm>

#include "User.h"

void User::addPurchase(std::string date, std::string card, std::string purchaseAmount) {
	Purchase newPurchase;
	int purchaseDate = stoi(date);
	double amountDouble = stod(purchaseAmount);
	double convenienceFee;

	if (card == "AMEX") {
		convenienceFee = 0.008;
	}
	else if (card == "VISA") {
		convenienceFee = 0.01;
	}
	else {
		convenienceFee = 0.005;
	}


	bool purchaseStatus = false;

	//Set Purchase Information
	newPurchase.setPurchaseDate(purchaseDate);
	newPurchase.setPurchaseCard(card);
	newPurchase.setPurchaseAmount(amountDouble);
	newPurchase.setConvenienceAmount(convenienceFee * amountDouble);
	newPurchase.setCardAmount(amountDouble + (amountDouble * convenienceFee));

	purchaseVect.push_back(newPurchase);
	std::sort(purchaseVect.begin(), purchaseVect.end());
}

//Setter Functions
void User::setFirstName(std::string firstName) {
	userFirstName = firstName;
}
void User::setLastName(std::string lastName) {
	userLastName = lastName;
}
void User::setUserName(std::string fullName) {
	userName = fullName;
}
void User::setUserPhoneNumber(std::string phoneNumber) {
	userPhoneNumber = phoneNumber;
}
void User::setUserPassword(std::string password) {
	userPassword = password;
}
void User::setUserCountry(std::string country) {
	userCountry = country;
}
void User::setUserAddress(std::string address) {
	userAddress = address;
}
void User::setAmountDue(double amount) {
	amountDue = amount;
}
void User::setTotalAmountPaid(double amount) {
	totalAmountPaid = amount;
}

//Getter Functions
std::string User::getFirstName() {
	return userFirstName;
}
std::string User::getLastName() {
	return userLastName;
}
std::string User::getUserName() {
	return userName;
}
std::string User::getPhoneNumber() {
	return userPhoneNumber;
}
std::string User::getUserPassword() {
	return userPassword;
}
std::string User::getCountry() {
	return userCountry;
}
std::string User::getAddress() {
	return userAddress;
}
double User::getAmountDue() {
	return amountDue;
}
double User::getTotalAmountPaid() {
	return totalAmountPaid;
}
