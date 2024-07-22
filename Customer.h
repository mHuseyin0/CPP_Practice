#include <iostream>
using std::string;

class Customer {
private:
    int customerID;
    string name;
    int rentedDVDCount;

public:
    Customer(int customerID, string name);
    int getCustomerID() const;
    string getName() const;
    void incrementRentedDVDCount();
    void decrementRentedDVDCount();
    int getRentedDVDCount() const;
};
