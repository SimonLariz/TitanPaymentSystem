#include <iostream>
#include "User.h"

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