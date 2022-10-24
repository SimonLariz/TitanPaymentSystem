#include <iostream>
#include "Purchase.h"

using namespace std;

int main()
{
    cout << "Hello, Welcome to the Titan Payment System\n";
    Purchase temp;
    temp.setPurchaseDate(221009);
    temp.setPurchaseCard("TEST");
    temp.setAmountPaid(111.02);
    cout << temp.getPurchaseDate() << '\n';
    cout << temp.getPurchaseCard() << '\n';
    cout << temp.getAmountPaid() << '\n';


    return 0;
}