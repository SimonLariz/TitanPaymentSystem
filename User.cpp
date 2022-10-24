#include <iostream>

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

	//Setter Functions
	void setFirstName(std::string firstName) {
		userFirstName = firstName;
	}
	void setLastName(std::string lastName) {
		userLastName = lastName;
	}
	void setUserFullName(std::string fullName) {
		userFullName = fullName;
	}
	void setUserPhoneNumber(std::string phoneNumber) {
		userPhoneNumber = phoneNumber;
	}
	void setUserPassword(std::string password) {
		userPassword = password;
	}
	void setUserCountry(std::string country) {
		userCountry = country;
	}
	void setUserCountry(std::string address) {
		userAddress = address;
	}


public:
	//Getter Functions
	std::string getFirstName() {
		return userFirstName;
	}
	std::string getLastName() {
		return userLastName;
	}
	std::string getFullName() {
		return userFullName;
	}
	std::string getPhoneNumber() {
		return userPhoneNumber;
	}
	std::string getUserPassword() {
		return userPassword;
	}
	std::string getCountry() {
		return userCountry;
	}
	std::string getAddress() {
		return userAddress;
	}
};