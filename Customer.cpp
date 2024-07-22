#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Customer.h"

Customer::Customer(int customerID, string name){
    this->customerID = customerID;
    this->name = name;
    this->rentedDVDCount = 0;
}

int Customer::getCustomerID() const{
    return customerID;
}

string Customer::getName() const{
    return name;
}

int Customer::getRentedDVDCount() const{
    return rentedDVDCount;
}

void Customer::incrementRentedDVDCount(){
    rentedDVDCount++;
}

void Customer::decrementRentedDVDCount(){
    rentedDVDCount--;
}

#endif
