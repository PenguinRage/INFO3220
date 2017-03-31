#ifndef LASER_H
#define LASER_H

#include "spaceitem.h"
#include <string>
#include <iostream>
#include <QPixmap>


class Laser : public SpaceItem
{

public:
    Laser(int posx=-1000, int posy=-1000, int speed=10);
    ~Laser();
    QPixmap getLaser();
    int getSpeed();
    int getPosX();
    int getPosY();
    void setSpeed(int speed);
    void setPosX(int x);
    void setPosY(int y);


protected:
    QPixmap laser;
    int ls;
    int lx;
    int ly;
};


#endif // LASER_H