#include <iostream>
using namespace std;

class DVD {
    private:
        string serialNumber;
        string title;
        string director;
        bool rentable;

    public:
        DVD(string serialNum, string title, string director);
        string getSerialNumber();
        string getTitle();
        string getDirector();
        bool isRentable();
        void revertRentable();

};


