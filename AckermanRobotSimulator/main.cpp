#include <iostream>
#include "include/AckermanRobot.h"
#include "include/Scenario.h"

using namespace std;

//for test proposes
int main()
{
    AckermanRobot* bot = new AckermanRobot('*', 1);
    bot->addLeft(29);
    cout << bot->getXPos() << " ";
    cout << bot->getYPos() << " ";

    Scenario* scene = new Scenario(40, 50, 1);
    scene->addRobot(bot);
    scene->updateTab();
    for(int c =0; c < 5; c++){
    	    bot->move(2);
    	    scene->updateTab();
    	    scene->drawTab();
    }
    for(int c =0; c < 5; c++){
    	    bot->addRight(5);
    	    bot->move(2);
    	    scene->updateTab();
    	    scene->drawTab();
    }
    scene->drawTab();

    return 0;
}
