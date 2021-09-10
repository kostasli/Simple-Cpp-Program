#include <iostream>
#include <fstream>
#include <vector>
#include "AppSystem.h"
#include "AppDeveloper.h"
#include "Game.h"
#include "OfficeApp.h"
#include "UserRating.h"


using namespace std;

int main()
{
    AppSystem apps;

    AppDeveloper developer1("dev1", "Kostas", "kostas@gmail.com");
    AppDeveloper *developer = &developer1;
    apps.addDeveloper(developer);// Method to insert new Developer
    cout<<endl;

    AppDeveloper developer2("dev2", "Giannis", "giannis@gmail.com");
    AppDeveloper *newDeveloper = &developer2;
    apps.addDeveloper(newDeveloper);// Method to insert new Developer
    cout<<endl;

    vector<const char*> fileType;
    fileType.push_back("docx");
    OfficeApp officeApp1("officeapp1", "Microsoft Office", 6.9, &developer1, fileType, 112.0);
    AppSystem *officeApp = &officeApp1;
    apps.addApp(officeApp);//Method to insert new App

    vector<const char*> fileType2;
    fileType2.push_back("pptx");
    OfficeApp officeApp2("officeapp2", "Microsoft Powerpoint", 5.3, &developer2, fileType2, 0.0);
    AppSystem *newOfficeApp = &officeApp2;
    apps.addApp(newOfficeApp);

    Game game1("game1", "Call of Duty: Warzone", 5.4, &developer1, true, "First-Person-Shooter", 0.0);
    AppSystem *game = &game1;
    apps.addApp(game);

    Game game2("game2", "Fortnite", 6.0, &developer2, true, "Battle-Royal", 0.0);
    AppSystem *newGame = &game2;
    apps.addApp(newGame);

    UserRating *rating1 = new UserRating(5, "Kostas", "Great game.");
    game1.rateApp(rating1);//Method to insert user rating 
    cout<<"Your rating for "<<game1.getName()<<" has been submitted."<<endl<<endl;

    UserRating *rating2 = new UserRating(5, "Giannis", "Great game.");
    game2.rateApp(rating2);//Method to insert user rating 
    cout<<"Your rating for "<<game2.getName()<<" has been submitted."<<endl<<endl;

    cout<<"The items of the list of all the apps are:"<<endl<<apps;//List with all apps of MAD Robot
    string appFile = "apps.txt";
    apps.saveToFile(appFile, apps);
    
    cout<<endl;

    cout<<"The items of the list of the free office apps are:"<<endl<<apps.displayFreeOfficeApps();
    cout<<endl;

    apps.deleteMalicious(&developer1);//Method to delete malicious apps of developer

    cout<<"List with all app names:"<<endl<<apps<<endl;

    cout<<"The items of the list of all the games with average ratings above 4 are:"<<endl<<apps.displayGoodGames();//List with all apps of MAD Robot

    return 0;
}