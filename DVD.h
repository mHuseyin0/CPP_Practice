#include <iostream>
using std::string;

class DVD {
    private:
        string serialNumber;
        string title;
        string director;
        bool rentable;

    public:
        DVD(string serialNum, string title, string director);
        string getSerialNumber() const;
        string getTitle() const;
        string getDirector() const;
        bool isRentable() const;
        void revertRentable();

};


