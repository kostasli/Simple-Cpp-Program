#include "Game.h"
#include<fstream>

Game::Game() {}

Game::Game (const char *appId, string appName, float appLeastOsVersion, AppDeveloper *appDev, 
            bool appOnline,const char *appGameCategory, float appPrice):
            AppSystem(appId, appName, appLeastOsVersion, appDev, appPrice)
            {
                online=appOnline;
                gameCategory= appGameCategory;
            }

Game::~Game() {}

bool Game::isOnline() const
{
    return online;
}

const char *Game::getCategory() const
{
    return gameCategory;
}

