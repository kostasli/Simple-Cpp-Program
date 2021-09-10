#ifndef APPSYSTEM_H
#define APPSYSTEM_H

#include <vector>
#include "AppDeveloper.h"
#include "UserRating.h"
#include <fstream>

using namespace std;

class OfficeApp;
class Game;

class AppSystem {

protected:
    string name;
    const char* id;//if it's a game put a g as first char of id
    float osVersion;
    AppDeveloper* developer;
    float price;
    vector<UserRating*> ratings;

    const char* getDevName();
    friend ostream &operator<< (ostream &os, vector <AppSystem*> a);
    friend ostream &operator<< (ostream &os, AppSystem &a);

public:
    const char *getId() const;
    const string &getName() const;
    float getOsVersion() const;
    float getPrice() const;
    void setName(const string &name);
    void setId(char *id);
    void setOsVersion(float osVersion);
    void setPrice(float price);

    AppSystem();
    AppSystem(const char* appId, const string& appName, float appLeastOsVersion, AppDeveloper* appDeve, float appPrice);
    virtual ~AppSystem();

    void addApp(AppSystem*);
    void addDeveloper(AppDeveloper*);
    void rateApp(UserRating *);
    void deleteMalicious(AppDeveloper* developer);

    vector<AppSystem*> displayFreeOfficeApps();
    vector<AppSystem*> displayGoodGames();
    vector<AppSystem*> apps;    // list with all apps

    bool isGame(AppSystem*) const;
    float calcAverageRatings();

    void saveToFile(string filename, AppSystem&);

private:
    vector<AppDeveloper*> devs;
};


#endif