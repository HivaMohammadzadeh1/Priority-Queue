//Hiva Mohammadzadeh - Thursday Night
//Lab 8 (Priority Queues)

#include <iostream>
#include <iomanip>

using namespace std;

struct OrderType {
    int quantity;
    int rushStatus;
    int orderNumber;
};

template <class OrderType>
struct HeapType {
    void ReheapDown(int root, int bottom);
    void ReheapUp(int root, int bottom);
    OrderType orders[100];
    int numElements;
};

class PriorityQueue {
    
private:
    
    int ordersProcessed;
    HeapType<OrderType> Orders;
    int length;
    
public:
    PriorityQueue();
    ~PriorityQueue();
    bool isEmpty();
    void MakeEmpty();
    void Dequeue(OrderType & order);
    void Enqueue();

};

PriorityQueue::PriorityQueue() {
    
    length = 0;
    ordersProcessed = 0;
}

PriorityQueue::~PriorityQueue() {

    length = 0;
    ordersProcessed = 0;
}

bool PriorityQueue::isEmpty() {
    return length == 0;
}

void PriorityQueue::MakeEmpty() {
    length = 0;
}


void PriorityQueue::Dequeue(OrderType & order) {
    
    order = Orders.orders[0];
    Orders.orders[0] = Orders.orders[length - 1];
    length--;
    Orders.ReheapDown(0, length - 1);
}

void PriorityQueue::Enqueue() {
    
    ordersProcessed++;
    int orderNum, rushStatus, quantity;
    orderNum = ordersProcessed + 1000;
    cout << "\nORDER #" << orderNum;
    

    cout << "\nPlease enter the amount of orders: ";
    cin >> quantity;
    
    while (quantity < 1 || cin.fail()) {
        
        cout << "\nERROR: Orders must be and greater than zero and be a positive whole number. Please try again.\n" << endl;
        cout << "Please enter the amount of orders: ";
        cin >> quantity;
        cin.clear();
        cin.ignore(200, '\n');
    }

    cout << "\nRUSH STATUS OPTIONS:\n"
         << "Enter 0 for STANDARD rush (10% markup)."
         << "\nEnter 1 for EXPEDITE rush (20% markup)."
         << "\nEnter 2 for EXTREME rush (50% markup).\n";
    cout << "\nPlease select a rush status: ";
    
    cin >> rushStatus;

    while (rushStatus != 0 && rushStatus != 1 && rushStatus != 2) {
        
        cout << "\nERROR: Rush status must have a value of 0, 1, or 2. Please try again.\n" << endl;
        cout << "Please select a rush status: ";
        cin >> rushStatus;
        cin.clear();
        cin.ignore(200, '\n');
    }
    
    cout << endl;
    OrderType *newItem = new (nothrow) OrderType;
    
    if (newItem == nullptr) {
        
        cout << "ERROR: Item was not created. There is not enough memory." << endl;
        MakeEmpty();
        system("pause");
        exit(1);
    }
    
    newItem->quantity = quantity;
    newItem->rushStatus = rushStatus;
    newItem->orderNumber = orderNum;

    length++;
    Orders.orders[length - 1] = *newItem;
    Orders.ReheapUp(0, length - 1);
}


template <class OrderType>
void HeapType<OrderType>::ReheapDown(int root, int bottom) {
    
    int maxChild, rightChild, leftChild;
    leftChild = root * 2 + 1;
    rightChild = root * 2 + 2;
    
    if (leftChild <= bottom) {
        
        if (leftChild == bottom)
            maxChild = leftChild;
        
        else {
            
            if (orders[leftChild].rushStatus <= orders[rightChild].rushStatus)
                maxChild = rightChild;
            
            else
                maxChild = leftChild;
        }
        
        if (orders[root].rushStatus < orders[maxChild].rushStatus) {
            
            OrderType temp = orders[root];
            orders[root] = orders[maxChild];
            orders[maxChild] = temp;
            ReheapDown(maxChild, bottom);
        }
    }
}

template <class OrderType>
void HeapType<OrderType>::ReheapUp(int root, int bottom) {
    
    int parent;
    
    if (bottom > root) {
        
        parent = (bottom - 1) / 2;
        
        if (orders[parent].rushStatus < orders[bottom].rushStatus) {
            
            OrderType temp = orders[parent];
            orders[parent] = orders[bottom];
            orders[bottom] = temp;
            ReheapUp(root, parent);
        }
    }
}

struct WidgetType {
    int quantity;
    double price;
    WidgetType *next;
    int deliveryNumber;
};

class WidgetStack {
    
private:
    
    WidgetType *top;
    int widgetsProcessed;
    
public:
    
    WidgetStack();
    ~WidgetStack();
    void Pop();
    void Push();
    WidgetType *Peek();
    bool isEmpty();
    void PrintInventory();
    void MakeEmpty();

};

WidgetStack::WidgetStack() {
    top = nullptr;
    widgetsProcessed = 0;
}

WidgetStack::~WidgetStack() {
    top = nullptr;
    widgetsProcessed = 0;
}

void WidgetStack::Pop() {
    
    WidgetType * temp = new WidgetType;
    temp = nullptr;
    
    if (top != nullptr) {
        
        temp = top;
        top = top->next;
        delete temp;
    }
    
    temp = nullptr;
}

void WidgetStack::Push() {
    
    widgetsProcessed++;
    double price;
    int quantity;
    int deliveryNum = widgetsProcessed + 1000;
    
    cout << "\nDELIVERY #" << deliveryNum << "\n\nPlease enter the amount of orders: ";
    cin >> quantity;
    
    while (quantity < 1 || cin.fail()) {
        
        cout << "\nERROR: Quantity must be greater than zero and be a positive whole number."       << " Please try again.\n" << endl;
        cout << "Please enter the amount of orders: ";
        cin >> quantity;
        cin.clear();
        cin.ignore(200, '\n');
    }

    cout << "Please enter the price: $";
    cin >> price;
    
    while (price < 0.01 || cin.fail()) {
        
        cout << "\nERROR: Price must be greater than zero and be a positive number."
             << " Please try again.\n" << endl;
        
        cout << "Please enter the price: $";
        cin >> price;
        cin.clear();
        cin.ignore(200, '\n');
    }
    cout << endl;

    WidgetType *newItem = new (nothrow) WidgetType;

    if (newItem == nullptr) {
        
        cout << "ERROR: Item was not created. There is not enough memory." << endl;
        MakeEmpty();
        system("pause");
        exit(1);
    }
    
    newItem->price = price;
    newItem->quantity = quantity;
    newItem->next = top;
    newItem->deliveryNumber = deliveryNum;
    top = newItem;
}

WidgetType *WidgetStack::Peek() {
    return top;
}

bool WidgetStack::isEmpty() {
    return top == nullptr;
}

void WidgetStack::PrintInventory() {
 
    cout << "\nINVENTORY ON HAND:\n" << endl;

    WidgetType *temp = top;

    cout << setprecision(2) << fixed << showpoint;

    if (temp != nullptr)
        cout << "Delivery #" << setw(18) << "Widget Price" << setw(14) << "In Stock" << endl;
    else
        cout << "Inventory is Empty\n"<< endl;
    
    while (temp != nullptr) {
        
        if (temp->price != 0) {
            
            cout << right << temp->deliveryNumber << setw(14) << "$" << temp->price << setw(14) << temp->quantity << endl;
        }
        temp = temp->next;
    }

}
       

void WidgetStack::MakeEmpty() {
    
    while (top != nullptr)
        Pop();
}


enum MenuOptions { NewDelivery = 1, NewOrder, ViewInventory, CloseDay, Quit };
enum RushOptions { Standard = 0, Expedite, Extreme };

void ShipOrders(PriorityQueue & Orders, WidgetStack & Widgets);
void Swap(OrderType& one, OrderType & two);



int main() {
    
    int userInput = 0;
    WidgetStack Widgets;
    PriorityQueue Orders;
    
    cout << "WELCOME!" << endl;

    do {
        
        cout << "\n=========================================\n";
        cout << "\nEnter 1 to process a new DELIVERY."
            << "\nEnter 2 to accept a new ORDER."
            << "\nEnter 3 to print the current INVENTORY."
            << "\nEnter 4 to close the day and PROCESS ORDERS."
            << "\nEnter 5 to quit." << endl;
        
        cin >> userInput;
         
        
        switch (userInput) {
                
        case NewDelivery:
            Widgets.Push();
            break;
                
        case NewOrder:
                Orders.Enqueue();
                break;
                
        case ViewInventory:
            Widgets.PrintInventory();
            break;
                
        case CloseDay:
            ShipOrders(Orders, Widgets);
                Widgets.PrintInventory();
            break;
                
        case Quit:
            cout << "Program is now terminating. . .\n" << endl;
            break;
                
        default:
                cout << "\nERROR: Input must be between 1 and 4. Please try again." << endl;
                cin.clear();
                cin.ignore(200, '\n');
                break;
        
        }

    } while (userInput != Quit);

    system("pause");
    return 0;
}

void Swap(OrderType& one, OrderType & two) {
    
    OrderType temp = one;
    one = two;
    two = temp;
}

void ShipOrders(PriorityQueue & Orders, WidgetStack & Widgets) {
    
    OrderType order;
    int quantityShipped = 0;
    double costToWarehouse = 0, costToCustomer = 0, totalProfit = 0;
    int i = 0, k = 0;
    int totalQt = 0;
    int quantity = 0;
    
    cout << setprecision(2) << fixed << showpoint;
    
    cout << "\nSHIPMENT SUMMARY:" << endl;
    
    if (Orders.isEmpty()) {
        
        cout << "There were no orders. \nMaybe it's time to sell this company."
             << "\nProgram is now terminating.\n" << endl;
        system("pause");
        exit(0);
    }
    
    if (!Orders.isEmpty() && Widgets.isEmpty()) {
        
        cout << "\nFATAL ERROR: There are more orders than widgets;"
             << "\nWidgets cannot be backlogged.\n"
             <<"\nProgram is now terminating.\n" << endl;
        system("pause");
        exit(0);
    }
    
    while (!Orders.isEmpty() || k == 0) {
    
            if (i == 0) {
                Orders.Dequeue(order);
                quantityShipped = 0;
                totalQt = 0;
                costToWarehouse = 0;
                costToCustomer = 0;
                totalProfit = 0;
            }
        
            if (Widgets.Peek()->quantity >= order.quantity) {
                
                if (i == 0) {
                    
                    cout << "\nSHIPMENT DETAILS:\n" << endl;
                    cout << right << setw(15) << "QTY. SHIPPED:" << setw(15) << "UNIT PRICE:"
                         << setw(20) << "COST TO WAREHOUSE:" << setw(20) << "COST TO CUSTOMER:"
                         << endl;
                }
                
                quantityShipped = order.quantity;
                totalQt += quantityShipped;
                
                if (order.rushStatus == 2)
                    totalProfit = costToCustomer + 1.5 * Widgets.Peek()->price * quantityShipped - (costToWarehouse + quantityShipped * Widgets.Peek()->price);
                else if (order.rushStatus == 1)
                    totalProfit = costToCustomer + 1.2 * Widgets.Peek()->price * quantityShipped - (costToWarehouse + quantityShipped * Widgets.Peek()->price);
                              
                else if (order.rushStatus == 0)
                    totalProfit = costToCustomer + 1.1 * Widgets.Peek()->price * quantityShipped - (costToWarehouse + quantityShipped * Widgets.Peek()->price);
                
                
                cout << right << setw(15) << quantityShipped << setw(15) << Widgets.Peek()->price << setw(20) << quantityShipped * Widgets.Peek()->price << setw(20) << quantityShipped * Widgets.Peek()->price * 1.5 << endl;
                
                cout << "\nORDER NUMBER:" << right << setw(15) << order.orderNumber;
                cout << "\nQTY. ORDERED:" << setw(15) << totalQt << endl;
                
                if (order.rushStatus == 2)
                    cout << "RUSH STATUS:" << setw(16) << "Extreme" << endl;
                
                else if (order.rushStatus == 1)
                    cout << "RUSH STATUS:" << setw(16) << "Expedite" << endl;
                
                else if (order.rushStatus == 0)
                    cout << "RUSH STATUS" << setw(16) << "Standard" << endl;
                
                
                cout << "COST TO WAREHOUSE:" << setw(10) << costToWarehouse + quantityShipped * Widgets.Peek()->price << endl;
                
                
                if (order.rushStatus == 2)
                    cout << "COST TO CUSTOMER:" << setw(11) << costToCustomer + 1.5 * Widgets.Peek()->price * quantityShipped << endl;
                
                else if (order.rushStatus == 1)
                   cout << "COST TO CUSTOMER:" << setw(11) << costToCustomer + 1.2 * Widgets.Peek()->price * quantityShipped << endl;
                
                else if (order.rushStatus == 0)
                    cout << "COST TO CUSTOMER:" << setw(11) << costToCustomer + 1.1 * Widgets.Peek()->price * quantityShipped << endl;
                
                cout << "TOTAL PROFIT:" << setw(15) << totalProfit << endl;

                Widgets.Peek()->quantity = Widgets.Peek()->quantity - quantityShipped;
                
                if (Widgets.Peek()->quantity == 0)
                    Widgets.Pop();
                
                i = 0;
                quantity = 0;
                
                if (Orders.isEmpty())
                    k = 1;
            }
        
            else {
                
                if (i == 0) {
                    
                    cout << "\nSHIPMENT DETAILS:\n" << endl;
                    cout << right << setw(15) << "QTY. SHIPPED:" << setw(15) << "UNIT PRICE:"
                         << setw(20) << "COST TO WAREHOUSE:" << setw(20) << "COST TO CUSTOMER:"
                         << endl;
                    i++;
                }
                
                if (order.rushStatus == 2) {
                    
                    quantityShipped += Widgets.Peek()->quantity;
                    costToWarehouse += Widgets.Peek()->price * Widgets.Peek()->quantity;
                    costToCustomer += Widgets.Peek()->quantity * Widgets.Peek()->price * 1.5;
                }
                
                else if (order.rushStatus == 1) {
                    
                    quantityShipped += Widgets.Peek()->quantity;
                    costToWarehouse += Widgets.Peek()->price * Widgets.Peek()->quantity;
                    costToCustomer += Widgets.Peek()->quantity * Widgets.Peek()->price * 1.2;
                }
                
                else {
                    
                    quantityShipped += Widgets.Peek()->quantity;
                    costToWarehouse += Widgets.Peek()->price * Widgets.Peek()->quantity;
                    costToCustomer += Widgets.Peek()->quantity * Widgets.Peek()->price * 1.1;
                }
                

                cout << right << setw(15) << quantityShipped << setw(15)
                     << Widgets.Peek()->price << setw(20) << costToWarehouse << setw(20)
                     << costToCustomer << endl;
                
                order.quantity = order.quantity - quantityShipped;
                totalQt += quantityShipped;
                Widgets.Pop();
            }
    }
}

/*
 WELCOME!

 =========================================

 Enter 1 to process a new DELIVERY.
 Enter 2 to accept a new ORDER.
 Enter 3 to print the current INVENTORY.
 Enter 4 to close the day and PROCESS ORDERS.
 Enter 5 to quit.
 1

 DELIVERY #1001

 Please enter the amount of orders: 6
 Please enter the price: $5


 =========================================

 Enter 1 to process a new DELIVERY.
 Enter 2 to accept a new ORDER.
 Enter 3 to print the current INVENTORY.
 Enter 4 to close the day and PROCESS ORDERS.
 Enter 5 to quit.
 1

 DELIVERY #1002

 Please enter the amount of orders: 7
 Please enter the price: $55


 =========================================

 Enter 1 to process a new DELIVERY.
 Enter 2 to accept a new ORDER.
 Enter 3 to print the current INVENTORY.
 Enter 4 to close the day and PROCESS ORDERS.
 Enter 5 to quit.
 1

 DELIVERY #1003

 Please enter the amount of orders: 10
 Please enter the price: $40


 =========================================

 Enter 1 to process a new DELIVERY.
 Enter 2 to accept a new ORDER.
 Enter 3 to print the current INVENTORY.
 Enter 4 to close the day and PROCESS ORDERS.
 Enter 5 to quit.
 1

 DELIVERY #1004

 Please enter the amount of orders: 7
 Please enter the price: $35


 =========================================

 Enter 1 to process a new DELIVERY.
 Enter 2 to accept a new ORDER.
 Enter 3 to print the current INVENTORY.
 Enter 4 to close the day and PROCESS ORDERS.
 Enter 5 to quit.
 1

 DELIVERY #1005

 Please enter the amount of orders: 2
 Please enter the price: $25


 =========================================

 Enter 1 to process a new DELIVERY.
 Enter 2 to accept a new ORDER.
 Enter 3 to print the current INVENTORY.
 Enter 4 to close the day and PROCESS ORDERS.
 Enter 5 to quit.
 1

 DELIVERY #1006

 Please enter the amount of orders: 1
 Please enter the price: $15


 =========================================

 Enter 1 to process a new DELIVERY.
 Enter 2 to accept a new ORDER.
 Enter 3 to print the current INVENTORY.
 Enter 4 to close the day and PROCESS ORDERS.
 Enter 5 to quit.
 1

 DELIVERY #1007

 Please enter the amount of orders: 4
 Please enter the price: $50


 =========================================

 Enter 1 to process a new DELIVERY.
 Enter 2 to accept a new ORDER.
 Enter 3 to print the current INVENTORY.
 Enter 4 to close the day and PROCESS ORDERS.
 Enter 5 to quit.
 1

 DELIVERY #1008

 Please enter the amount of orders: 2
 Please enter the price: $30


 =========================================

 Enter 1 to process a new DELIVERY.
 Enter 2 to accept a new ORDER.
 Enter 3 to print the current INVENTORY.
 Enter 4 to close the day and PROCESS ORDERS.
 Enter 5 to quit.
 1

 DELIVERY #1009

 Please enter the amount of orders: 4
 Please enter the price: $20


 =========================================

 Enter 1 to process a new DELIVERY.
 Enter 2 to accept a new ORDER.
 Enter 3 to print the current INVENTORY.
 Enter 4 to close the day and PROCESS ORDERS.
 Enter 5 to quit.
 1

 DELIVERY #1010

 Please enter the amount of orders: 3
 Please enter the price: $10


 =========================================

 Enter 1 to process a new DELIVERY.
 Enter 2 to accept a new ORDER.
 Enter 3 to print the current INVENTORY.
 Enter 4 to close the day and PROCESS ORDERS.
 Enter 5 to quit.
 3

 INVENTORY ON HAND:

 Delivery #      Widget Price      In Stock
 1010             $10.00             3
 1009             $20.00             4
 1008             $30.00             2
 1007             $50.00             4
 1006             $15.00             1
 1005             $25.00             2
 1004             $35.00             7
 1003             $40.00            10
 1002             $55.00             7
 1001             $5.00             6

 =========================================

 Enter 1 to process a new DELIVERY.
 Enter 2 to accept a new ORDER.
 Enter 3 to print the current INVENTORY.
 Enter 4 to close the day and PROCESS ORDERS.
 Enter 5 to quit.
 2

 ORDER #1001
 Please enter the amount of orders: 3

 RUSH STATUS OPTIONS:
 Enter 0 for STANDARD rush (10% markup).
 Enter 1 for EXPEDITE rush (20% markup).
 Enter 2 for EXTREME rush (50% markup).

 Please select a rush status: 0


 =========================================

 Enter 1 to process a new DELIVERY.
 Enter 2 to accept a new ORDER.
 Enter 3 to print the current INVENTORY.
 Enter 4 to close the day and PROCESS ORDERS.
 Enter 5 to quit.
 2

 ORDER #1002
 Please enter the amount of orders: 5

 RUSH STATUS OPTIONS:
 Enter 0 for STANDARD rush (10% markup).
 Enter 1 for EXPEDITE rush (20% markup).
 Enter 2 for EXTREME rush (50% markup).

 Please select a rush status: 2


 =========================================

 Enter 1 to process a new DELIVERY.
 Enter 2 to accept a new ORDER.
 Enter 3 to print the current INVENTORY.
 Enter 4 to close the day and PROCESS ORDERS.
 Enter 5 to quit.
 2

 ORDER #1003
 Please enter the amount of orders: 2

 RUSH STATUS OPTIONS:
 Enter 0 for STANDARD rush (10% markup).
 Enter 1 for EXPEDITE rush (20% markup).
 Enter 2 for EXTREME rush (50% markup).

 Please select a rush status: 2


 =========================================

 Enter 1 to process a new DELIVERY.
 Enter 2 to accept a new ORDER.
 Enter 3 to print the current INVENTORY.
 Enter 4 to close the day and PROCESS ORDERS.
 Enter 5 to quit.
 2

 ORDER #1004
 Please enter the amount of orders: 2

 RUSH STATUS OPTIONS:
 Enter 0 for STANDARD rush (10% markup).
 Enter 1 for EXPEDITE rush (20% markup).
 Enter 2 for EXTREME rush (50% markup).

 Please select a rush status: 0


 =========================================

 Enter 1 to process a new DELIVERY.
 Enter 2 to accept a new ORDER.
 Enter 3 to print the current INVENTORY.
 Enter 4 to close the day and PROCESS ORDERS.
 Enter 5 to quit.
 2

 ORDER #1005
 Please enter the amount of orders: 4

 RUSH STATUS OPTIONS:
 Enter 0 for STANDARD rush (10% markup).
 Enter 1 for EXPEDITE rush (20% markup).
 Enter 2 for EXTREME rush (50% markup).

 Please select a rush status: 1


 =========================================

 Enter 1 to process a new DELIVERY.
 Enter 2 to accept a new ORDER.
 Enter 3 to print the current INVENTORY.
 Enter 4 to close the day and PROCESS ORDERS.
 Enter 5 to quit.
 2

 ORDER #1006
 Please enter the amount of orders: 6

 RUSH STATUS OPTIONS:
 Enter 0 for STANDARD rush (10% markup).
 Enter 1 for EXPEDITE rush (20% markup).
 Enter 2 for EXTREME rush (50% markup).

 Please select a rush status: 2


 =========================================

 Enter 1 to process a new DELIVERY.
 Enter 2 to accept a new ORDER.
 Enter 3 to print the current INVENTORY.
 Enter 4 to close the day and PROCESS ORDERS.
 Enter 5 to quit.
 2

 ORDER #1007
 Please enter the amount of orders: 3

 RUSH STATUS OPTIONS:
 Enter 0 for STANDARD rush (10% markup).
 Enter 1 for EXPEDITE rush (20% markup).
 Enter 2 for EXTREME rush (50% markup).

 Please select a rush status: 1


 =========================================

 Enter 1 to process a new DELIVERY.
 Enter 2 to accept a new ORDER.
 Enter 3 to print the current INVENTORY.
 Enter 4 to close the day and PROCESS ORDERS.
 Enter 5 to quit.
 2

 ORDER #1008
 Please enter the amount of orders: 1

 RUSH STATUS OPTIONS:
 Enter 0 for STANDARD rush (10% markup).
 Enter 1 for EXPEDITE rush (20% markup).
 Enter 2 for EXTREME rush (50% markup).

 Please select a rush status: 0


 =========================================

 Enter 1 to process a new DELIVERY.
 Enter 2 to accept a new ORDER.
 Enter 3 to print the current INVENTORY.
 Enter 4 to close the day and PROCESS ORDERS.
 Enter 5 to quit.
 2

 ORDER #1009
 Please enter the amount of orders: 7

 RUSH STATUS OPTIONS:
 Enter 0 for STANDARD rush (10% markup).
 Enter 1 for EXPEDITE rush (20% markup).
 Enter 2 for EXTREME rush (50% markup).

 Please select a rush status: 1


 =========================================

 Enter 1 to process a new DELIVERY.
 Enter 2 to accept a new ORDER.
 Enter 3 to print the current INVENTORY.
 Enter 4 to close the day and PROCESS ORDERS.
 Enter 5 to quit.
 2

 ORDER #1010
 Please enter the amount of orders: 5

 RUSH STATUS OPTIONS:
 Enter 0 for STANDARD rush (10% markup).
 Enter 1 for EXPEDITE rush (20% markup).
 Enter 2 for EXTREME rush (50% markup).

 Please select a rush status: 0


 =========================================

 Enter 1 to process a new DELIVERY.
 Enter 2 to accept a new ORDER.
 Enter 3 to print the current INVENTORY.
 Enter 4 to close the day and PROCESS ORDERS.
 Enter 5 to quit.
 2

 ORDER #1011
 Please enter the amount of orders: 6

 RUSH STATUS OPTIONS:
 Enter 0 for STANDARD rush (10% markup).
 Enter 1 for EXPEDITE rush (20% markup).
 Enter 2 for EXTREME rush (50% markup).

 Please select a rush status: 0


 =========================================

 Enter 1 to process a new DELIVERY.
 Enter 2 to accept a new ORDER.
 Enter 3 to print the current INVENTORY.
 Enter 4 to close the day and PROCESS ORDERS.
 Enter 5 to quit.
 3

 INVENTORY ON HAND:

 Delivery #      Widget Price      In Stock
 1010             $10.00             3
 1009             $20.00             4
 1008             $30.00             2
 1007             $50.00             4
 1006             $15.00             1
 1005             $25.00             2
 1004             $35.00             7
 1003             $40.00            10
 1002             $55.00             7
 1001             $5.00             6

 =========================================

 Enter 1 to process a new DELIVERY.
 Enter 2 to accept a new ORDER.
 Enter 3 to print the current INVENTORY.
 Enter 4 to close the day and PROCESS ORDERS.
 Enter 5 to quit.
 2

 ORDER #1012
 Please enter the amount of orders: 2

 RUSH STATUS OPTIONS:
 Enter 0 for STANDARD rush (10% markup).
 Enter 1 for EXPEDITE rush (20% markup).
 Enter 2 for EXTREME rush (50% markup).

 Please select a rush status: 2


 =========================================

 Enter 1 to process a new DELIVERY.
 Enter 2 to accept a new ORDER.
 Enter 3 to print the current INVENTORY.
 Enter 4 to close the day and PROCESS ORDERS.
 Enter 5 to quit.
 4

 SHIPMENT SUMMARY:

 SHIPMENT DETAILS:

   QTY. SHIPPED:    UNIT PRICE:  COST TO WAREHOUSE:   COST TO CUSTOMER:
               3          10.00               30.00               45.00
               2          20.00               40.00               60.00

 ORDER NUMBER:           1002
 QTY. ORDERED:              5
 RUSH STATUS:         Extreme
 COST TO WAREHOUSE:     70.00
 COST TO CUSTOMER:     105.00
 TOTAL PROFIT:          35.00

 SHIPMENT DETAILS:

   QTY. SHIPPED:    UNIT PRICE:  COST TO WAREHOUSE:   COST TO CUSTOMER:
               2          20.00               40.00               60.00

 ORDER NUMBER:           1012
 QTY. ORDERED:              2
 RUSH STATUS:         Extreme
 COST TO WAREHOUSE:     40.00
 COST TO CUSTOMER:      60.00
 TOTAL PROFIT:          20.00

 SHIPMENT DETAILS:

   QTY. SHIPPED:    UNIT PRICE:  COST TO WAREHOUSE:   COST TO CUSTOMER:
               2          30.00               60.00               90.00

 ORDER NUMBER:           1003
 QTY. ORDERED:              2
 RUSH STATUS:         Extreme
 COST TO WAREHOUSE:     60.00
 COST TO CUSTOMER:      90.00
 TOTAL PROFIT:          30.00

 SHIPMENT DETAILS:

   QTY. SHIPPED:    UNIT PRICE:  COST TO WAREHOUSE:   COST TO CUSTOMER:
               4          50.00              200.00              300.00
               5          15.00              215.00              322.50
              -3          25.00              -75.00             -112.50

 ORDER NUMBER:           1006
 QTY. ORDERED:              6
 RUSH STATUS:         Extreme
 COST TO WAREHOUSE:    140.00
 COST TO CUSTOMER:     210.00
 TOTAL PROFIT:          70.00

 SHIPMENT DETAILS:

   QTY. SHIPPED:    UNIT PRICE:  COST TO WAREHOUSE:   COST TO CUSTOMER:
               3          25.00               75.00              112.50

 ORDER NUMBER:           1007
 QTY. ORDERED:              3
 RUSH STATUS:        Expedite
 COST TO WAREHOUSE:     75.00
 COST TO CUSTOMER:      90.00
 TOTAL PROFIT:          15.00

 SHIPMENT DETAILS:

   QTY. SHIPPED:    UNIT PRICE:  COST TO WAREHOUSE:   COST TO CUSTOMER:
               2          25.00               50.00               60.00
               2          35.00               70.00              105.00

 ORDER NUMBER:           1005
 QTY. ORDERED:              4
 RUSH STATUS:        Expedite
 COST TO WAREHOUSE:    120.00
 COST TO CUSTOMER:     144.00
 TOTAL PROFIT:          24.00

 SHIPMENT DETAILS:

   QTY. SHIPPED:    UNIT PRICE:  COST TO WAREHOUSE:   COST TO CUSTOMER:
               5          35.00              175.00              210.00
               2          40.00               80.00              120.00

 ORDER NUMBER:           1009
 QTY. ORDERED:              7
 RUSH STATUS:        Expedite
 COST TO WAREHOUSE:    255.00
 COST TO CUSTOMER:     306.00
 TOTAL PROFIT:          51.00

 SHIPMENT DETAILS:

   QTY. SHIPPED:    UNIT PRICE:  COST TO WAREHOUSE:   COST TO CUSTOMER:
               6          40.00              240.00              360.00

 ORDER NUMBER:           1011
 QTY. ORDERED:              6
 RUSH STATUS        Standard
 COST TO WAREHOUSE:    240.00
 COST TO CUSTOMER:     264.00
 TOTAL PROFIT:          24.00

 SHIPMENT DETAILS:

   QTY. SHIPPED:    UNIT PRICE:  COST TO WAREHOUSE:   COST TO CUSTOMER:
               2          40.00               80.00               88.00
               1          55.00               55.00               82.50

 ORDER NUMBER:           1001
 QTY. ORDERED:              3
 RUSH STATUS        Standard
 COST TO WAREHOUSE:    135.00
 COST TO CUSTOMER:     148.50
 TOTAL PROFIT:          13.50

 SHIPMENT DETAILS:

   QTY. SHIPPED:    UNIT PRICE:  COST TO WAREHOUSE:   COST TO CUSTOMER:
               1          55.00               55.00               82.50

 ORDER NUMBER:           1008
 QTY. ORDERED:              1
 RUSH STATUS        Standard
 COST TO WAREHOUSE:     55.00
 COST TO CUSTOMER:      60.50
 TOTAL PROFIT:           5.50

 SHIPMENT DETAILS:

   QTY. SHIPPED:    UNIT PRICE:  COST TO WAREHOUSE:   COST TO CUSTOMER:
               2          55.00              110.00              165.00

 ORDER NUMBER:           1004
 QTY. ORDERED:              2
 RUSH STATUS        Standard
 COST TO WAREHOUSE:    110.00
 COST TO CUSTOMER:     121.00
 TOTAL PROFIT:          11.00

 SHIPMENT DETAILS:

   QTY. SHIPPED:    UNIT PRICE:  COST TO WAREHOUSE:   COST TO CUSTOMER:
               3          55.00              165.00              181.50
               2           5.00               10.00               15.00

 ORDER NUMBER:           1010
 QTY. ORDERED:              5
 RUSH STATUS        Standard
 COST TO WAREHOUSE:    175.00
 COST TO CUSTOMER:     192.50
 TOTAL PROFIT:          17.50

 INVENTORY ON HAND:

 Delivery #      Widget Price      In Stock
 1001             $5.00             4

 =========================================

 Enter 1 to process a new DELIVERY.
 Enter 2 to accept a new ORDER.
 Enter 3 to print the current INVENTORY.
 Enter 4 to close the day and PROCESS ORDERS.
 Enter 5 to quit.
 5
 Program is now terminating. . .

 sh: pause: command not found
 Program ended with exit code: 0
*/


