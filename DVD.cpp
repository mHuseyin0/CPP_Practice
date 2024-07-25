#ifndef DVD_H
#define DVD_H

#include "DVD.h"

DVD::DVD(string serialNum, string title, string director){
    this->serialNumber = serialNum;
    this->title = title;
    this->director = director;
    this->rentable = true;
}

string DVD::getSerialNumber() const {
    return serialNumber;
}

string DVD::getDirector() const {
    return director;
}

string DVD::getTitle() const {
    return title;
}

bool DVD::isRentable() const {
    return rentable;
}

void DVD::rent(int id){
    rentable = false;
    clientID = id;
}

void DVD::returnDVD(){
    rentable = true;
    clientID = 0;
}

int DVD::getClientID() const{
    return clientID;
}

#endif
