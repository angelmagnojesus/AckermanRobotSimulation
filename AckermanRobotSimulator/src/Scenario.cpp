#include "../include/Scenario.h"
#include <iostream>
using namespace std;

Scenario::Scenario(int  heigth, int width, int maxRobots)
{
	this->heigth = heigth;
	this->width = width;
	this->maxRobots = maxRobots;
	this->tab = (char*)malloc(sizeof(char)*heigth*width);
	this->arobots = (AckermanRobot**) malloc(sizeof(AckermanRobot*)*maxRobots);
	this->robotCont = 0;
}

Scenario::~Scenario()
{
    delete [] tab;
    delete [] arobots;
}

void Scenario::updateTab(){
	char* p = tab;
	int posLineY = heigth / 2;
	int posLineX = width / 2;
	cout <<"\n"<< posLineX << "\n";
	cout <<"\n"<< posLineY << "\n";

	for(int i=0; i < heigth; i++){
	   for(int j=0; j < width; j++){

	   	    *p = VOID;

		    if(j == posLineX){
		       *p = LINE;
		    }
		    if(i == posLineY){
		       *p = LINE;
		    }
		    //check robots on tab
		    AckermanRobot** auxbots = arobots;
		    //convert to center coordinates
		    int ci = i - heigth / 2;
		    int cj = j - width / 2;
		    for(int c = 0; c < robotCont; c++){
			   if((*auxbots)->getXPos() == cj && (*auxbots)->getYPos() == ci){
				   *p = (*auxbots)->label;
			   }
			   auxbots++;
		    }// for c

		    p++;

	   }//for j
	}
}

void Scenario::drawTab(){
	char* p = tab;
	for(int i=0; i < heigth; i++){
		for(int j=0; j < width; j++){
			cout << *p << " " ;
			p++;
		}
		cout << "! \n";
	}
}

void Scenario::addRobot(AckermanRobot* robot){
	if(robotCont < maxRobots){
		AckermanRobot** iteraux = arobots;
		iteraux += robotCont;
		*iteraux = robot;
		robotCont++;
	}else{
		cout << "Robot limit reached \n";
	}
}
