#ifndef GAME_H
#define GAME_H

#include <iostream>
#include "AppSystem.h"

using namespace std;

class Game : public AppSystem
{
    private:
        bool online;
        const char *gameCategory;
    public:
        Game();
        Game(const char *appId, string appName, float appLeastOsVersion, AppDeveloper *appDev,
        bool appOnline, const char *appGameCategory, float appPrice);
        ~Game();

    bool isOnline() const;
    const char *getCategory() const;    
};

#endif