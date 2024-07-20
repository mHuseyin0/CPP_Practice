#include <iostream>
using namespace std;

class Customer {
private:
    int customerID;
    string name;

public:
    Customer(int customerID, string name);
    int getCustomerID();
    string getName();
};
