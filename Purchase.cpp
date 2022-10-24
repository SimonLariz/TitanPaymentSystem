#include <iostream>
#include "Purchase.h"

void Purchase::setPurchaseDate(int pDate) {
	purchaseDate = pDate;
}
//Sets purchase card (AMEX / VISA / DISCOVER)
void Purchase::setPurchaseCard(std::string pCard) {
	purchaseCard = pCard;
}
//Sets purchase amount 
void Purchase::setPurchaseAmount(double pAmount) {
	purchaseAmount = pAmount;
}
//Sets amount paid 
void Purchase::setAmountPaid(double aPaid) {
	amountPaid = aPaid;
}
//Sets card amount 
void Purchase::setCardAmount(double cAmount) {
	cardAmount = cAmount;
}
//Sets convience amount
void Purchase::setConvenienceAmount(double convAmount) {
	convenienceAmount = convAmount;
}
//Sets billing cycle (YYMMDD)
void Purchase::setBillingCycle(int bCycle) {
	billingCycle = bCycle;
}
//Sets transaction status
void Purchase::setTransactionStatus(bool tStatus) {
	transactionStatus = tStatus;
}
//Getter Functions
//Returns purchaseDate (YYMMDD)
int Purchase::getPurchaseDate() {
	return purchaseDate;
}
//Returns purchaseCard 
std::string Purchase::getPurchaseCard() {
	return purchaseCard;
}
//Returns purchaseAmount
double Purchase::getPurchaseAmount() {
	return purchaseAmount;
}
//Returns amountPaid
double Purchase::getAmountPaid() {
	return amountPaid;
}
//Returns cardAmount
double Purchase::getCardAmount() {
	return cardAmount;
}
//Returns convenienceAmount
double Purchase::getConvenienceAmount() {
	return convenienceAmount;
}
//Returns billingCycle (YYMMDD)
int Purchase::getBillingCycle() {
	return billingCycle;
}
//Returns transactionStatus
bool Purchase::gettTansactionStatus() {
	return transactionStatus;
}

/*
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
	//Sets purchase date (YYMMDD)
	void setPurchaseDate(int pDate) {
		purchaseDate = pDate;
	}
	//Sets purchase card (AMEX / VISA / DISCOVER)
	void setPurchaseCard(std::string pCard) {
		purchaseCard = pCard;
	}
	//Sets purchase amount 
	void setPurchaseAmount(double pAmount) {
		purchaseAmount = pAmount;
	}
	//Sets amount paid 
	void setAmountPaid(double aPaid) {
		amountPaid = aPaid;
	}
	//Sets card amount 
	void setCardAmount(double cAmount) {
		cardAmount = cAmount;
	}
	//Sets convience amount
	void setConvenienceAmount(double convAmount) {
		convenienceAmount = convAmount;
	}
	//Sets billing cycle (YYMMDD)
	void setBillingCycle(int bCycle) {
		billingCycle = bCycle;
	}
	//Sets transaction status
	void setTransactionStatus(bool tStatus) {
		transactionStatus = tStatus;
	}
	//Getter Functions
	//Returns purchaseDate (YYMMDD)
	int getPurchaseDate() {
		return purchaseAmount;
	}
	//Returns purchaseCard 
	std::string getPurchaseCard() {
		return purchaseCard;
	}
	//Returns purchaseAmount
	double getPurchaseAmount() {
		return purchaseAmount;
	}
	//Returns amountPaid
	double getAmountPaid() {
		return amountPaid;
	}
	//Returns cardAmount
	double getCardAmount() {
		return cardAmount;
	}
	//Returns convenienceAmount
	double getConvenienceAmount() {
		return convenienceAmount;
	}
	//Returns billingCycle (YYMMDD)
	int getBillingCycle() {
		return billingCycle;
	}
	//Returns transactionStatus
	bool gettTansactionStatus() {
		return transactionStatus;
	}
};
*/