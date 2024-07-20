#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Customer.h"

Customer::Customer(int customerID, string name){
    this->customerID = customerID;
    this->name = name;
}

int Customer::getCustomerID(){
    return customerID;
}

string Customer::getName(){
    return name;
}

#endif
