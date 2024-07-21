#include <iostream>

using namespace std;
#include "DVDStoreManagementSystem.h"

int main() {

    if (__cplusplus == 202101L) std::cout << "C++23";
    else if (__cplusplus == 202002L) std::cout << "C++20";
    else if (__cplusplus == 201703L) std::cout << "C++17";
    else if (__cplusplus == 201402L) std::cout << "C++14";
    else if (__cplusplus == 201103L) std::cout << "C++11";
    else if (__cplusplus == 199711L) std::cout << "C++98";
    else std::cout << "pre-standard C++." << __cplusplus;
    std::cout << "\n";

    DVDStoreManagementSystem dvdsms;
    cout << "Initial state:" << endl << endl;
    dvdsms.showAllDVDs();
    cout << endl;
    dvdsms.showAllCustomers();
    cout << endl;
    dvdsms.showTransactionHistory();
    cout << endl;
    
    // Add some DVDs
    dvdsms.addDVD("001", "Inception", "Christopher Nolan");
    dvdsms.addDVD("002", "The Shawshank Redemption", "Frank Darabont");
    dvdsms.addDVD("005", "The Dark Knight", "Christopher Nolan");
    cout << endl << "After adding DVDs:" << endl << endl;
    dvdsms.showAllDVDs();
    cout << endl;
    
    // Add an existing DVD
    dvdsms.addDVD("003", "Pulp Fiction", "Quentin Tarantino");
    cout << endl;
    
    // Remove a few DVDs
    dvdsms.removeDVD("004");
    dvdsms.removeDVD("005");
    cout << endl << "After removing DVDs:" << endl << endl;
    dvdsms.showAllDVDs();
    cout << endl;
    
    // Remove a non-existing DVD
    dvdsms.removeDVD("006");
    cout << endl;
    
    // Add some customers
    dvdsms.addCustomer(1001, "Alice");
    dvdsms.addCustomer(1002, "Bob");
    dvdsms.addCustomer(1003, "Charlie");
    dvdsms.addCustomer(1004, "Diana");
    dvdsms.addCustomer(1005, "Edward");
    cout << endl << "After adding customers:" << endl << endl;
    dvdsms.showAllCustomers();
    cout << endl;
    
    // Add an existing customer
    dvdsms.addCustomer(1001, "Alice");
    cout << endl;
    
    // Remove a few customers
    dvdsms.removeCustomer(1004);
    dvdsms.removeCustomer(1005);
    cout << endl << "After removing customers:" << endl << endl;
    dvdsms.showAllCustomers();
    cout << endl;
    
    // Remove a non-existing customer
    dvdsms.removeCustomer(1006);
    cout << endl;
    // Rent some DVDs (successful)
    dvdsms.rentDVD(1001, "001");
    dvdsms.rentDVD(1002, "002");
    dvdsms.rentDVD(1003, "003");
    cout << endl << "After renting DVDs:" << endl << endl;
    dvdsms.showTransactionHistory();
    cout << endl;
    
    // Rent a non-existing DVD with an existing customer
    dvdsms.rentDVD(1001, "006");
    
    // Rent an existing DVD with a non-existing customer
    dvdsms.rentDVD(1006, "001");
    
    // Rent a non-existing DVD with a non-existing customer
    dvdsms.rentDVD(1006, "006");
    
    // Rent a non-available DVD with an existing customer
    dvdsms.rentDVD(1002, "001");
    cout << endl;
    
    // Return a few DVDs (successful)
    dvdsms.returnDVD(1001, "001");
    dvdsms.returnDVD(1002, "002");
    cout << endl << "After returning DVDs:" << endl << endl;
    dvdsms.showTransactionHistory();
    cout << endl;
    
    // Return a non-existing DVD with an existing customer
    dvdsms.returnDVD(1001, "999");
    
    // Return an existing DVD with a non-existing customer
    dvdsms.returnDVD(999, "001");
    
    // Return a non-existing DVD with a non-existing customer
    dvdsms.returnDVD(999, "999");
    
    // Return a rented DVD with an existing customer but not rented by this customer
    dvdsms.returnDVD(1001, "003");
    
    // Remove a rented DVD
    dvdsms.removeDVD("003");
    
    // Remove a customer who rented a DVD
    dvdsms.removeCustomer(1003);
    cout << endl;
    
    // Show an existing DVD
    dvdsms.showDVD("002");
    
    // Show a non-existing DVD
    dvdsms.showDVD("999");
    
    // Show an existing customer
    dvdsms.showCustomer(1003);
    
    // Show a non-existing customer
    dvdsms.showCustomer(999);
    cout << endl << "Final state:" << endl << endl;
    dvdsms.showAllDVDs();
    cout << endl;
    dvdsms.showAllCustomers();
    cout << endl;
    dvdsms.showTransactionHistory();
    
    return 0;
}
