#pragma once
#include <iostream>

class Purchase {
private:
	// Variables
	int purchaseDate;
	std::string purchaseCard;
	double purchaseAmount;
	//cardAmount = purchaseAmount + convenienceAmount
	double cardAmount;
	double convenienceAmount;
	int billingCycle;
	bool transactionStatus;

public:
	bool operator< (const Purchase& other)const;
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
