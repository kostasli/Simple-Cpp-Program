#include "UserRating.h"
#include <iostream>

UserRating::UserRating(unsigned int appNumOfStars, const char* appUserName, string appComments)
{
    if (appNumOfStars <= 5)
    {
        stars = appNumOfStars;
        name = appUserName;
        comms = std::move(appComments);
    }
    else
	{
        cout<<"You must enter stars from 1 through 5."<<endl;
        exit(1);
    }
}

unsigned int UserRating::getStars() const{
    return stars;
}

UserRating::~UserRating() {}