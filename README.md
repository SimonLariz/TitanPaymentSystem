# TitanPaymentSystem
TitanPaymentSystem CPSC 335


Payment Platform: The Payment platform helps in creating a hassle-free environment to pay the bills, sort their purchases, and store the purchase information 

Functions of a User in Payment Platform:
->User can create an Account
 1)Name,Fullname,Phone,Password,country,address 
->User can query all the above fields
->User should be able to upload his purchases
->User should be able to query his minimum transaction and maximum transaction
->User should be able to query his Amount due, total amount paid
->User should be able to retrieve the payment history(Table data to show the amount paid on different occasions)
->User should be able to display all the purchases made (use a filter to sort the purchases made between those days””)

Cards class:
Different cards have different transaction fees, so you need to sum up the transaction fee for 
the purchases paid when you pay your bills
Supported purchase cards
Amex-0.8%
Visa – 1%
Discover – 0.5%
Convenience fee -0.2% 

Purchase class:
For a purchase, the necessary fields are
1) Date 
2) Purchase card
3) Amount paid 
4) Retrieve the amount based on the card used 
5) Convenience amount on the purchase 
6) Billing cycle in which the transaction fits (“Every month is a different billing cycle example “01-01-2023,01-31-2023””)
7) Status to check whether the transaction is paid or due
