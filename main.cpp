#include <iostream>
#include "Purchase.h"
#include "User.h"

using namespace std;

int main()
{
    cout << "Hello, Welcome to the Titan Payment System\n";
    //Testing Purchase Class
    cout << "Testing Purchase Class\n";
    Purchase tempPurchase;
    tempPurchase.setPurchaseDate(221009);
    tempPurchase.setPurchaseCard("TEST");
    tempPurchase.setAmountPaid(111.02);
    cout << tempPurchase.getPurchaseDate() << '\n';
    cout << tempPurchase.getPurchaseCard() << '\n';
    cout << tempPurchase.getAmountPaid() << "\n\n\n";

    //Testing User Class
    cout << "Testing User Class\n";
    User tempUser;
    tempUser.setFirstName("Bob");
    tempUser.setLastName("Mill");
    tempUser.setUserCountry("United States");
    cout << tempUser.getFirstName() << '\n';
    cout << tempUser.getLastName() << '\n';
    cout << tempUser.getCountry() << "\n\n\n";

    return 0;
}
