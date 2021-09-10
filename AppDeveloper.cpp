#include "AppDeveloper.h"

AppDeveloper::AppDeveloper() {}

AppDeveloper::AppDeveloper(const char* appDevId, const char* appDevName, const char* appDevEmail)
{
    id = appDevId;
    name = appDevName;
    email = appDevEmail;
}

AppDeveloper::~AppDeveloper(){}

const char *AppDeveloper::getName() const
{
    return name;
}

