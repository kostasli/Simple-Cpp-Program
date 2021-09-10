#include "AppSystem.h"

using namespace std;

AppSystem::AppSystem() {}

AppSystem::AppSystem(const char* appId, const string& appName, float appLeastOsVersion, AppDeveloper* appDeve, float appPrice)
	{
    id = appId;
    name = appName;
    osVersion = appLeastOsVersion;
    developer = appDeve;
    price = appPrice;
}

AppSystem::~AppSystem() {}

const char *AppSystem::getId() const
{
    return id;
}

const string &AppSystem::getName() const
{
    return name;
}

float AppSystem::getOsVersion() const
{
    return osVersion;
}

float AppSystem::getPrice() const
{
    return price;
}

const char* AppSystem::getDevName()
{
    return developer->getName();
}

void AppSystem::setName(const string &name)
{
    AppSystem::name = name;
}

void AppSystem::setId(char *id)
{
    AppSystem::id = id;
}

void AppSystem::setOsVersion(float osVersion)
{
    osVersion = osVersion;
}

void AppSystem::setPrice(float price)
{
    AppSystem::price = price;
}

void AppSystem::addApp(AppSystem *app)
{
    apps.push_back(app);
    cout<<"A new app has been added."<<endl<<endl;
}

void AppSystem::addDeveloper(AppDeveloper *dev)
{
    devs.push_back(dev);
    cout<<"A new developer has been added."<<endl;
}

void AppSystem::rateApp(UserRating *rate)
{
    ratings.push_back(rate);
}

void AppSystem::deleteMalicious(AppDeveloper *dev)
{
    const char* name = dev->getName();
    bool deleted = false;

    for(int i=0; i<apps.size(); i++)
        if (apps.at(i)->getDevName() == name)
        {
            apps.erase(apps.begin() + i);
            deleted = true;
        }

    if (deleted)
        cout<<"Apps of developer "<<name<<" have been deleted."<<endl<<endl;
    else
        cout<<"No apps found for developer "<<name<<"."<<endl;
}

bool AppSystem::isGame(AppSystem* application) const{
    const char* applicationIdHolder = application->getId();
    //const char* firstChar = 'g';
    if(applicationIdHolder[0] == 'g')
    {
        return true;
    }
    else
    {
        return false;
    }
}

vector<AppSystem*> AppSystem::displayFreeOfficeApps()
{
    //check if it's an offfice app...
    vector<AppSystem*> freeOfficeApps;
    for(auto app:apps)
        if(app->getPrice()==0 && !app->isGame(app))
        freeOfficeApps.push_back(app);
    return freeOfficeApps;
}

vector<AppSystem*> AppSystem::displayGoodGames()
{
    //check if it's a game
    vector<float> sum;
    vector<AppSystem*> goodGames;

    for(auto app:apps){
        if(app->calcAverageRatings()>4 && app->isGame(app))
        {
            goodGames.push_back(app);
        }
    }

    return goodGames;
}

float AppSystem::calcAverageRatings()
{
    float sum = 0.0;
    int i=0;

    for(auto rating:ratings){
        sum+=float(rating->getStars());
        i++;
    }

    return sum/i;
}

ostream& operator<<(ostream& os, vector<AppSystem *> a)
{
    for(auto app : a)
        os<<app->getName()<<endl;

    return os;
}

ostream& operator<<(ostream& os, AppSystem& a)
{
    for(auto app : a.apps)
        os<<"Name: "<<app->getName()<<"  "<<" Id: "<<app->getId()
        <<"  "<<" osVersion: "<<app->getOsVersion()<<"  "<<" Developer: "
        <<app->developer->getName()<<"  "<<" Price: "<<app->getPrice()<<"  "
        <<" User ratings: "<<app->ratings.size()<<"  "<<endl;

    return os;
}

void AppSystem::saveToFile(string filename, AppSystem& a){
    try{
    ofstream newFile(filename);
    newFile<<a;
    newFile.close();
    cout<<endl<<"Apps successfully saved to file."<<endl;
    }
    catch(exception const& error){
        cout<<error.what();
    }
}