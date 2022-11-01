#pragma once
#include <iostream>

class Purchase {
private:
	// Variables
	int purchaseDate;
	std::string purchaseCard;
	double purchaseAmount;
	double cardAmount;
	double convenienceAmount;

public:
	//Operator for sort
	bool operator< (const Purchase& other)const;
	//Print info
	void printPurchase();
	//Setter Functions
	void setPurchaseDate(int pDate);
	void setPurchaseCard(std::string pCard);
	void setPurchaseAmount(double pAmount);
	void setCardAmount(double cAmount);
	void setConvenienceAmount(double convAmount);
	void setBillingCycle(int bCycle);
	void setTransactionStatus(bool tStatus);
	//Getter Functions
	int getPurchaseDate();
	std::string getPurchaseCard();
	double getPurchaseAmount();
	double getCardAmount();
	double getConvenienceAmount();
	int getBillingCycle();
	bool gettTansactionStatus();
};