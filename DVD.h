#include <iostream>
using std::string;

class DVD {
    private:
        string serialNumber;
        string title;
        string director;
        bool rentable;
        int clientID;

    public:
        DVD(string serialNum, string title, string director);
        string getSerialNumber() const;
        string getTitle() const;
        string getDirector() const;
        bool isRentable() const;
        int getClientID() const;
        void rent(int clientID);
        void returnDVD();
};


