#include <iostream>
#include <string>

#include "User.h"

void addPurchase(std::string date, std::string card, std::string purchaseAmount, std::string amountPaid) {
	Purchase newPurchase;
	int purchaseDate = stoi(date);
	double amountDouble = stod(purchaseAmount);
	double paidDouble = stod(amountPaid);
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
	newPurchase.setAmountPaid(paidDouble);
	newPurchase.setCardAmount(amountDouble * (1 + convenienceFee));
	newPurchase.setConvenienceAmount(convenienceFee);

	//Billing cycle
	//Status



}

//Setter Functions
void User::setFirstName(std::string firstName) {
	userFirstName = firstName;
}
void User::setLastName(std::string lastName) {
	userLastName = lastName;
}
void User::setUserFullName(std::string fullName) {
	userFullName = fullName;
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

//Getter Functions
std::string User::getFirstName() {
	return userFirstName;
}
std::string User::getLastName() {
	return userLastName;
}
std::string User::getFullName() {
	return userFullName;
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
