//  Eric Chu
//  board.h
//  Battleship
//  Final Project: BattleShip
#ifndef BOARD_H
#define BOARD_H
#include "PointCollection.h"
#include "Ship.h"
#include <iostream>

class Board
{
    private:
    int x3;
    int y3;
    Ship *ships[4];
    
    PointCollection shotsFired;
    PointCollection misses;
    Ship* generateShipWithLength(int l);
    
    public:
           Board();
           ~Board();
           void display();
           bool fireShot(int x, int y);
           int unsunkShipCount();
};

#endif
