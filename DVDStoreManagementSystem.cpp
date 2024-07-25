#ifndef DVDSTOREMANAGEMENTSYSTEM_H
#define DVDSTOREMANAGEMENTSYSTEM_H

#include "DVDStoreManagementSystem.h"
#include <cmath>

using namespace std;

DVDStoreManagementSystem::DVDStoreManagementSystem(){
    this->dvdCount = 0;
    this->customerCount = 0;
    this->transactionCount = 0;

    this->dvdList = new DVD* [10];
    this->customerList = new Customer* [10];
    this->transactionList = new string* [10];
}

DVDStoreManagementSystem::~DVDStoreManagementSystem(){
    for (int i = 0; i < dvdCount; i++) {
        delete dvdList[i];
    }

    for (int i = 0; i < customerCount; i++) {
        delete customerList[i];
    }

    for (int i = 0; i < transactionCount; i++) {
        delete transactionList[i];
    }

    delete[] dvdList;
    delete[] customerList;
    delete[] transactionList;
}

void DVDStoreManagementSystem::addDVD( const string serialNo, const string title, const string director ){
    int index = DVDSearch(serialNo);
    int insertIndex = 0;

    if(index != -1){
        int currentMid = stoi(dvdList[index]->getSerialNumber());
        int serialInt = stoi(serialNo);

        if(currentMid == serialInt){ // Duplicate found
            cout << "Cannot add DVD. DVD with serial number " << serialNo << " already exists." << endl;
            return;
        }

        // Find insert index (It has to be next to the last found middle element)
        insertIndex = index;
        if (currentMid < serialInt) {
            insertIndex = index + 1;
        }

        // Shift array if needed
        if (insertIndex < dvdCount) {
            for (int i = dvdCount - 1; i >= insertIndex; i--) {
                dvdList[i+1] = dvdList[i];
            }
        }
    }
    // Create DVD and insert it to the correct place
    dvdList[insertIndex] = new DVD(serialNo, title, director);
    // Array is expanded whenever expand count reaches an integer

    double expandCount = log2(++dvdCount / 10.0) + 1;
    if (ceil(expandCount) == floor(expandCount) && expandCount > 0) {
        DVD** newDVDList = new DVD* [2 * dvdCount];
        cout << "Expanding DVD array." << endl;
        for (int i = 0; i < dvdCount; i++) {
            newDVDList[i] = dvdList[i];
        }

        delete[] dvdList;
        this->dvdList = newDVDList;
    }
    cout << "DVD with serial number " << serialNo << " successfully added." << endl;
}

void DVDStoreManagementSystem::removeDVD( const string serialNo ){
    int index = DVDSearch(serialNo);

    if (index == -1) {
        return;
    }

    int currentMid= stoi((*dvdList[index]).getSerialNumber());
    int serialInt = stoi(serialNo);

    // No such DVD
    if(currentMid != serialInt){
        cout << "Cannot remove DVD. DVD with serial number " << serialNo << " not found." << endl;
        return;
    }
    if (!dvdList[index]->isRentable()) {
        cout << "Cannot remove DVD. DVD with serial number " << serialNo << " is currently rented by a customer." << endl;
        return;
    }

    delete dvdList[index];

    for (int i = index; i < dvdCount; i++) {
        dvdList[i] = dvdList[i + 1];
    }

    dvdCount--;

    cout << "DVD with serial number " << serialNo << " successfully removed." << endl;
}

void DVDStoreManagementSystem::addCustomer( const int customerID, const string name ){
    int index = customerSearch(customerID);
    int insertIndex = 0;

    if(index != -1){
        int currentMid = (*customerList[index]).getCustomerID();

        if(currentMid == customerID){ // Duplicate found
            cout << "Cannot add customer. Customer with ID " << customerID << " already exists." << endl;
            return;
        }

        // Find insert index (It has to be next to the last found middle element)
        insertIndex = index;
        if (currentMid < customerID) {
            insertIndex = index + 1;
        }

        // Shift array if needed
        if (insertIndex < customerCount) {
            for (int i = customerCount - 1; i >= insertIndex; i--) {
                customerList[i+1] = customerList[i];
            }
        }
    }
    // Create Customer and insert it to the correct place
    customerList[insertIndex] = new Customer(customerID, name);

    cout << "Customer with ID " << customerID << " successfully added." << endl;

    // Array is expanded whenever expand count reaches an integer
    double expandCount = log2(++customerCount / 10.0) + 1;
    if (ceil(expandCount) == floor(expandCount) && expandCount > 0) {
        Customer** newCustomerList = new Customer* [2 * customerCount];

        cout << "Expanding Customer array." << endl;
        for (int i = 0; i < customerCount; i++) {
            newCustomerList[i] = customerList[i];
        }

        delete[] customerList;
        this->customerList = newCustomerList;
    }
}

void DVDStoreManagementSystem::removeCustomer( const int customerID ){
    int index = customerSearch(customerID);

    if (index == -1) {
        return;
    }

    int currentMid = (*customerList[index]).getCustomerID();

    if(currentMid != customerID){
        cout << "Cannot remove customer. Customer with ID " << customerID << " not found." << endl;
        return;
    }
    if (customerList[index]->getRentedDVDCount() != 0) {
        cout << "Cannot remove customer. Customer with ID " << customerID << " has rented DVDs." << endl;
        return;
    }

    delete customerList[index];

    for (int i = index; i < customerCount; i++) {
        customerList[i] = customerList[i + 1];
    }

    customerCount--;

    cout << "Customer with ID " << customerID << " successfully removed." << endl;
}

void DVDStoreManagementSystem::rentDVD( const int customerID, const string serialNo ){
    int customerIndex = customerSearch(customerID);
    int DVDIndex = DVDSearch(serialNo);

    bool dvdNotFound = dvdList[DVDIndex]->getSerialNumber() != serialNo;
    bool customerNotFound = customerList[customerIndex]->getCustomerID() != customerID;

    if (dvdNotFound && customerNotFound) {
        cout << "Cannot rent DVD. Customer with ID " << customerID << " and DVD with serial number " << serialNo << " not found." << endl;
        return;
    }
    if (customerNotFound){
        cout << "Cannot rent DVD. Customer with ID " << customerID << " not found." << endl;
        return;
    }
    if (dvdNotFound){
        cout << "Cannot rent DVD. DVD with serial number " << serialNo <<" not found." << endl;
        return;
    }
    if (!dvdList[DVDIndex]->isRentable()) {
        cout << "Cannot rent DVD. DVD with serial number " << serialNo << " is not available." << endl;
        return;
    }

    DVD* dvd = dvdList[DVDIndex];
    Customer* customer = customerList[customerIndex];

    dvd->rent(customerID);
    customer->incrementRentedDVDCount();


    transactionList[transactionCount++] = new string("Transaction: Rental, Customer: " + to_string(customerID) + ", DVD: " + serialNo);

    cout << "DVD with serial number " << serialNo << " successfully rented by customer with ID " << customerID << "." << endl;
    double expandCount = log2(transactionCount / 10.0) + 1;
    if (ceil(expandCount) == floor(expandCount) && expandCount > 0) {
        string** newTransactionList = new string* [2 * transactionCount];

        for (int i = 0; i < transactionCount; i++) {
            newTransactionList[i] = transactionList[i];
        }

        delete[] transactionList;
        this->transactionList = newTransactionList;
    }
}

void DVDStoreManagementSystem::returnDVD( const int customerID, const string serialNo ){
    int customerIndex = customerSearch(customerID);
    int DVDIndex = DVDSearch(serialNo);

    bool dvdNotFound = dvdList[DVDIndex]->getSerialNumber() != serialNo;
    bool customerNotFound = customerList[customerIndex]->getCustomerID() != customerID;

    if (dvdNotFound && customerNotFound) {
        cout << "Cannot return DVD. Customer with ID " << customerID << " and DVD with serial number " << serialNo << " not found." << endl;
        return;
    }
    if (customerNotFound){
        cout << "Cannot return DVD. Customer with ID " << customerID << " not found." << endl;
        return;
    }
    if (dvdNotFound){
        cout << "Cannot return DVD. DVD with serial number " << serialNo <<" not found." << endl;
        return;
    }
    if (dvdList[DVDIndex]->getClientID() != customerID) {
        cout << "Cannot return DVD. DVD with serial number " << serialNo << " not rented by customer with ID " << customerID<< "." << endl;
        return;
    }
    DVD* dvd = dvdList[DVDIndex];
    Customer* customer = customerList[customerIndex];

    dvd->returnDVD();
    customer->decrementRentedDVDCount();

    transactionList[transactionCount++] = new string("Transaction: Return, Customer: " + to_string(customerID) + ", DVD: " + serialNo);

    cout << "DVD with serial number " << serialNo << " successfully returned by customer with ID " << customerID << "." << endl;
    double expandCount = log2(transactionCount / 10.0) + 1;
    if (ceil(expandCount) == floor(expandCount) && expandCount > 0) {
        string** newTransactionList = new string* [2 * transactionCount];
        cout << "Expanding transaction list." << endl;
        for (int i = 0; i < transactionCount; i++) {
            newTransactionList[i] = transactionList[i];
        }

        delete[] transactionList;
        this->transactionList = newTransactionList;
    }
}

void DVDStoreManagementSystem::showAllDVDs() const{
    cout << "DVDs in the system:" << endl;
    if(dvdCount == 0){
        cout << "None" << endl;
        return;
    }

    for (int i = 0; i < dvdCount; i++) {
        showDVD(dvdList[i]->getSerialNumber());
    }

}

void DVDStoreManagementSystem::showAllCustomers() const{
    cout << "Customers in the system:" << endl;
    if(customerCount == 0){
        cout << "None" << endl;
        return;
    }

    for (int i = 0; i < customerCount; i++) {
        showCustomer(customerList[i]->getCustomerID());
    }
}

void DVDStoreManagementSystem::showDVD( const string serialNo ) const{
    int index = DVDSearch(serialNo);

    if (index == -1 || dvdList[index]->getSerialNumber() != serialNo){
        cout << "DVD with serial number " << serialNo << " not found." << endl;
        return;
    }

    DVD* current = dvdList[index];
    string isAvailable;
    current->isRentable() ? isAvailable = "Available" : isAvailable = "Rented";
    cout << "DVD: " << current->getSerialNumber() << ", ";
    cout << "Title: " << current->getTitle() << ", ";
    cout << "Director: " << current->getDirector() << ", " << isAvailable << endl;

}

void DVDStoreManagementSystem::showCustomer( const int customerID ) const{
    int index = customerSearch(customerID);

    if (index == -1 || customerList[index]->getCustomerID() != customerID){
        cout << "Customer with ID " << customerID << " not found." << endl;
        return;
    }

    Customer* customer = customerList[index];

    cout << "Customer: " << customer->getCustomerID() << ", ";
    cout << "Name: " << customer->getName() << ", ";
    cout << "DVDs Rented: " << customer->getRentedDVDCount() << endl;
}

void DVDStoreManagementSystem::showTransactionHistory() const{
    cout << "Transactions in the system:" << endl;
    if(transactionCount == 0){
        cout << "None" << endl;
        return;
    }

    for (int i = 0; i < transactionCount; i++) {
        cout << *transactionList[i] << endl;
    }
}

int DVDStoreManagementSystem::DVDSearch(const string serialNo) const {
    int first = 0;
    int last = dvdCount - 1;
    int mid = -1;

    int currentMid;
    int serialInt = stoi(serialNo);

    // Search for a duplicate serialNo via binary search
    while (last >= first) {
        mid = (first +  last) / 2;
        currentMid = stoi((*dvdList[mid]).getSerialNumber()); 
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

int DVDStoreManagementSystem::customerSearch(const int customerID) const{
    int first = 0;
    int last = customerCount - 1;
    int mid = -1;

    int currentMid;

    // Search for a duplicate customerID via binary search
    while (last >= first) {
        mid = (first +  last) / 2;
        currentMid = (*customerList[mid]).getCustomerID(); 
        if (currentMid == customerID) {
            return mid;
        }
        else if (currentMid > customerID) {

            last = mid - 1;
        }
        else {
            first = mid + 1;
        }
    }
    return mid;
}


#endif

