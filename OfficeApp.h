#ifndef OFFICEAPP_H
#define OFFICEAPP_H

#include "AppSystem.h"
#include <vector>
#include <iostream>

using namespace std;

class OfficeApp : public AppSystem
{
private:
    vector<const char*> typeFileCat;

public:
    OfficeApp();
    OfficeApp(const char* appId, string appName, float appLeastOsVersion, AppDeveloper* appDeve,
            vector<const char *> appTypeFileCat, float appPrice);
    ~OfficeApp();
};


#endif