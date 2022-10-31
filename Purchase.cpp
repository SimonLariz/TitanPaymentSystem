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
bool Purchase::operator< (const Purchase& other)const {
	return purchaseAmount < other.purchaseAmount;
}

void Purchase::printPurchase() {
	std::cout << "Date: " << purchaseDate << " Amount: " << purchaseAmount << " Card Fee: " << cardAmount << " Convenience Fee: " << convenienceAmount << '\n\n';
}

