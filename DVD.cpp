#ifndef DVD_H
#define DVD_H

#include "DVD.h"

DVD::DVD(string serialNum, string title, string director){
    this->serialNumber = serialNum;
    this->title = title;
    this->director = director;
    this->rentable = true;
}

string DVD::getSerialNumber(){
    return serialNumber;
}

string DVD::getDirector(){
    return director;
}

string DVD::getTitle(){
    return title;
}

bool DVD::isRentable(){
    return rentable;
}

void DVD::revertRentable(){
    rentable = !rentable;
}
#endif
