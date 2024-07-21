#ifndef DVDSTOREMANAGEMENTSYSTEM_H
#define DVDSTOREMANAGEMENTSYSTEM_H

#include <cmath>
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
    int index = DVDSearch(serialNo)
    string currentMid = (*dvdList[index]).getSerialNumber();
    int serialInt = (int) serialNo;

      // Duplicate found
    if(currentMid == serialNo){
        return;
    }

    // Find insert index (It has to be next to the last found middle element)
    int insertIndex = mid - 1;
    if (currentMid < serialInt) {
      insertIndex = mid + 1;
    }

    // Shift array if needed
    if (insertIndex < dvdCount) {
      for (i = dvdCount - 1; i >= insertIndex; i--) {
        dvdList[i+1] = dvdList[i];
      }
    }

    // Create DVD and insert it to the correct place
    DVD newDVD(serialNo, title, director);
    dvdList[insertIndex] = &newDVD;

    // Array is expanded whenever expand count reaches an integer
    double expandCount = log2(dvdCount / 10) + 1;
    if (ceil(expandCount) == floor(expandCount)) {
        newDVDList = new DVD** [2 * dvdCount];

        for (int i = 0; i < dvdCount; i++) {
            newDVDList[i] = dvdList[i];
        }

        delete[] dvdList;
        this->dvdList = newDVDList;
    }
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

int DVDStoreManagementSystem::DVDSearch(const string serialNo){
    int first = 0;
    int last = dvdCount - 1;
    int mid;

    int currentMid;
    int serialInt = (int) serialNo;
    bool found = false;

    // Search for a duplicate serialNo via binary search
    while (last >= first) {
        mid = (first +  last) / 2;
        currentMid = (int) (*dvdList[mid]).getSerialNumber(); 
        if (currentMid == serialInt) {
            return mid;
        }
        else if (currentMid > serialInt) {

            last = mid - 1;
        }
        else {
            first = mid + 1;
        }
    }
    return mid;
}

#endif

