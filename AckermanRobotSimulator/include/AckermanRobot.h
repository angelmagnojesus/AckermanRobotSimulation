#ifndef ACKERMANROBOT_H
#define ACKERMANROBOT_H


class AckermanRobot
{
    public:
        AckermanRobot(char label, double d);
        virtual ~AckermanRobot();
        char label;
        double d;
        double vd;
        int getXPos();
        int getYPos();
        void addRight(double degree);
        void addLeft(double degree);
        void move(double vd);
    protected:
    private:
    	double thetaAngle;
        double deltaAngle;
        const double maxAngle = 45;
        int xpos;
        int ypos;
};

#endif // ACKERMANROBOT_H
