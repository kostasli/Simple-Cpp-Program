#ifndef APPDEVELOPER_H
#define APPDEVELOPER_H

#include <iostream>

using namespace std;

class AppDeveloper
{
private:
    const char* id;
    const char* name;
    const char* email;

public:
    AppDeveloper();
    AppDeveloper(const char* appDevId, const char* appDevName, const char* appDevEmail);
    ~AppDeveloper();
    const char *getName() const;
};


#endif