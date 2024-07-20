#ifndef DVDSTOREMANAGEMENTSYSTEM_H
#define DVDSTOREMANAGEMENTSYSTEM_H

#include "DVDStoreManagementSystem.h"

DVDStoreManagementSystem::DVDStoreManagementSystem(){
    this->dvdCount = 0;
    this->customerCount = 0;
    this->transactionCount = 0;

    this->dvdList = new DVD* [10];
    this->customerList = new Customer* [10];
    this->transactionHistory = new string* [10];
}

DVDStoreManagementSystem::~DVDStoreManagementSystem(){
    delete[] dvdList;
    delete[] customerList;
    delete[] transactionHistory;
}

void DVDStoreManagementSystem::addDVD( const string serialNo, const string title, const string director ){
    
}

void DVDStoreManagementSystem::removeDVD( const string serialNo ){
    
}

void DVDStoreManagementSystem::addCustomer( const int customerID, const string name ){
    
}

void DVDStoreManagementSystem::removeCustomer( const int customerID ){
    
}

void DVDStoreManagementSystem::rentDVD( const int customerID, const string serialNo ){
    
}

void DVDStoreManagementSystem::returnDVD( const int customerID, const string serialNo ){
    
}

void DVDStoreManagementSystem::showAllDVDs() const{
    
}

void DVDStoreManagementSystem::showAllCustomers() const{
    
}

void DVDStoreManagementSystem::showDVD( const string serialNo ) const{
    
}

void DVDStoreManagementSystem::showCustomer( const int customerID ) const{
    
}

void DVDStoreManagementSystem::showTransactionHistory() const{
    
}

#endif

