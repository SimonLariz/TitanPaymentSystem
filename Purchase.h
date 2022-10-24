#pragma once
#include <iostream>

class Purchase {
private:
	// Variables
	int purchaseDate;
	std::string purchaseCard;
	double purchaseAmount;
	double amountPaid;
	double cardAmount;
	double convenienceAmount;
	int billingCycle;
	bool transactionStatus;

public:
	//Setter Functions
	void setPurchaseDate(int pDate);
	void setPurchaseCard(std::string pCard);
	void setPurchaseAmount(double pAmount);
	void setAmountPaid(double aPaid);
	void setCardAmount(double cAmount);
	void setConvenienceAmount(double convAmount);
	void setBillingCycle(int bCycle);
	void setTransactionStatus(bool tStatus);
	//Getter Functions
	int getPurchaseDate();
	std::string getPurchaseCard();
	double getPurchaseAmount();
	double getAmountPaid();
	double getCardAmount();
	double getConvenienceAmount();
	int getBillingCycle();
	bool gettTansactionStatus();
};