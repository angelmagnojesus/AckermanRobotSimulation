#define _USE_MATH_DEFINES
#include "../include/AckermanRobot.h"
#include <cmath>

AckermanRobot::AckermanRobot(char label, double d)
{
    this->label = label;
    this->d = d;
    this->xpos = 0;
    this->ypos = 0;
    this->thetaAngle = 0;
    this->deltaAngle = 0;
}

AckermanRobot::~AckermanRobot()
{
    //dtor
}

void AckermanRobot::addRight(double degree){
      if(deltaAngle - degree >= -1 * maxAngle){
	deltaAngle -= degree;
      }
}

void AckermanRobot::addLeft(double degree){
       if(deltaAngle + degree <= maxAngle){
         deltaAngle += degree;
       }
}

int AckermanRobot::getXPos(){
	return this->xpos;
}

int AckermanRobot::getYPos(){
	return this->ypos;
}

void AckermanRobot::move(double vd){
	xpos += vd*cos((thetaAngle * deltaAngle)*M_PI/180);
	ypos += vd*sin((thetaAngle * deltaAngle)*M_PI/180);
	thetaAngle += sin(deltaAngle)*vd/d;
}
