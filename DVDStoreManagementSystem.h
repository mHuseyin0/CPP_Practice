#include <iostream>
using namespace std;

class DVDStoreManagementSystem {

    public:
        DVDStoreManagementSystem();
        ~DVDStoreManagementSystem();

        void addDVD( const string serialNo, const string title, const string director );
        void removeDVD( const string serialNo );
        void addCustomer( const int customerID, const string name );
        void removeCustomer( const int customerID );
        void rentDVD( const int customerID, const string serialNo );
        void returnDVD( const int customerID, const string serialNo );
        void showAllDVDs() const;
        void showAllCustomers() const;
        void showDVD( const string serialNo ) const;
        void showCustomer( const int customerID ) const;
        void showTransactionHistory() const;
};

