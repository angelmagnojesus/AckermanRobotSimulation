#ifndef SCENARIO_H
#define SCENARIO_H

#include "AckermanRobot.h"

class Scenario
{
    public:
        static const char LINE = '.';
        static const char VOID = '_';
    	Scenario(int heigth, int width, int maxRobots);
        virtual ~Scenario();
        int width;
        int heigth;
        int maxRobots;
        int robotCont;
        AckermanRobot** arobots;
        void drawTab();
        void updateTab();
        void addRobot(AckermanRobot* robot);
    protected:
    private:
    	char* tab;
};

#endif // SCENARIO_H
