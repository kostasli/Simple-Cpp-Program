#include "OfficeApp.h"

OfficeApp::OfficeApp() {}

OfficeApp::OfficeApp(const char* appId, string appName, float appLeastOsVersion, AppDeveloper* appDeve,
            vector<const char *> appTypeFileCat, float appPrice):
            AppSystem(appId, appName, appLeastOsVersion, appDeve, appPrice)
		{
    typeFileCat = appTypeFileCat;
}

OfficeApp::~OfficeApp(){}