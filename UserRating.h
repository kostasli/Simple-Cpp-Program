#ifndef RATE_H
#define RATE_H

#include <string>
#include <iostream>

using namespace std;

class UserRating{

private:
    unsigned int stars;
    const char* name;
    string comms;
public:
    UserRating();
    UserRating(unsigned int appNumOfStars, const char* appUserName, string appComments);
    ~UserRating();
    unsigned int getStars() const;
};

#endif