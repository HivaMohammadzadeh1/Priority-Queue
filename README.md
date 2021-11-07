# Priority-Queue


Write a program  a menu driven program to handle the flow of widgets out of a warehouse using priority queue  implemented as a  tree. Orders  are received throughout a day and processed at night. The orders are filled in the order they were received, with consideration of the orders with rush status. 

The warehouse will have numerous orders for widgets throughout a day
Orders are filled in the first come first serve bases with the exception of rush  orders; use enum for the rush status
extreme rush orders -  filled before  any other order; 50% markup
expedite rush orders- filled after extreme rush orders but before standard; 20% markup
standard orders -  filled in the order  received, 10% markup
Program menu
option to display the details of the inventory and outstanding orders on hand
option to receive a new order
assign a unique order number for each new order
number of widgets ordered and rush status are entered by a user
option to close a day and process orders received on that day
The warehouse has a fixed number of widgets at a fixed price 
show the total number of orders processed along with their total cost to the warehouse, total profit, and total cost to the customers
show inventory on hand (if any) after day's orders been processed.
show a list of processed orders in the order they will be shipped.
With each filled order include the following information (see the sample below):  order number, rush status ( extreme, rush, standard; do not use numeric values), total quantity shipped, total quantity ordered, % of markup, the total cost to the warehouse, amount of markup,  and warehouse profit
display  the processed orders in a table format
There will be no backorders; there is enough inventory to ship all orders
Do not standard library classes such as stack, queue, list and etc.
Make sure each function definition is preceded by  a description, post-and pre-conditions
