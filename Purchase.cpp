#include <iostream>
#include <iomanip>
#include "Purchase.h"

//Sets purchase date (YYMMDD)
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
//Operator required for class sorting
bool Purchase::operator< (const Purchase& other)const {
	return purchaseAmount < other.purchaseAmount;
}
//Displays purchase information
void Purchase::printPurchase() {
	std::cout << "Date: " << purchaseDate << " Amount: " << std::fixed << std::setprecision(2) << purchaseAmount << " Card Fee: "
		<< std::fixed << std::setprecision(2) << cardAmount << " Convenience Fee: " << std::fixed << std::setprecision(2) << convenienceAmount << "\n\n";
}

