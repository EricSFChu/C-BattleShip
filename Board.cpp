//  Eric Chu
//  Board.cpp
//  Battleship
//  Final Project: BattleShip
#include <cstdlib> //srand, rand
#include <ctime> // so that random numbers are tied to system time
#include "Board.h"
using namespace std;
//*******************************************************************************************
//  The Board constructor creates ships
//*******************************************************************************************

Board::Board()
{
  cout << "constructing Board.";
  x3 = 10;
  y3 = 10;
  for (int shipLength = 5, index = 0; index < 4; shipLength--, index++)
	{
      bool isColliding; 
		do
		{
          isColliding = false; // check to make sure ship does not collide with others if it does recreate the ship
          ships[index] = generateShipWithLength(shipLength);
		  for (int collision = 0; collision < index; collision++)
		  {
             if (ships[index]->collidesWith(*ships[collision]))
             {
                 isColliding = true;
             }
          }
          if (isColliding) // delete the ship before creating a new one so as not to cause a memory leak
             delete ships[index]; 
        }while(isColliding);
    }
}
//*******************************************************************************************
//  Destructor deletes dynamically allocated ships
//*******************************************************************************************

Board::~Board()
{
  for (int index = 0; index < 4; index++) 
		delete ships[index];
}

//*******************************************************************************************
//  Helper function for generating ships
//*******************************************************************************************

Ship* Board::generateShipWithLength(int l)
{
      //get a random enumerated type
      direction shipOrientation = static_cast<direction>(rand() % RANDFUNC);
      
      int xCoordinate = rand() % 10;
      //Prevent the ship from leaving the board
      while ((shipOrientation == HORIZONTAL) && (xCoordinate + l) > 9)
      {
            xCoordinate = rand() % 10;
      }
      int yCoordinate = rand() % 10;
      //Prevent the ship from leaving the board
      while ((shipOrientation == VERTICAL) && (yCoordinate + l) > 9)
      {
            yCoordinate = rand() % 10;
      }      
      point origin = point(xCoordinate, yCoordinate);
      
      return new Ship(origin, shipOrientation, l);
}
/*
 *Checks all ships to see if the fired shot is located on the ship  
 * the ship's function will add a hit to ship if it is hit
 * misses will be added to the board's point collection
 * returns boolean for hit or miss
 */ 
bool Board::fireShot(int x, int y)
{
		bool hitOrMiss = false;
		point check = point(x,y);
		for(int index = 0; index < 4; index++)
		{
			if(ships[index]->containsPoint(check))
				{
					ships[index]->shotFiredAtPoint(check);
					hitOrMiss = true;
				}
			else
				{
					misses.add(check);
				}
		}
		return hitOrMiss;
}

//*******************************************************************************************
//  Represents the board with a nested for loop
//*******************************************************************************************
void Board::display()
{
     point temp;
     cout << endl;
     for(int row = y3-1; row >= 0; row--)
     {
       cout << row << " ";
       for (int collumn = 0; collumn < x3; collumn++)
       {
           temp = point(collumn, row);
           if (ships[0]->isHitAtPoint(temp) || ships[1]->isHitAtPoint(temp) || ships[2]->isHitAtPoint(temp) || ships[3]->isHitAtPoint(temp))
              cout << "X ";
           else if (misses.contains(temp))
              cout << "o ";
           else 
              cout << "~ ";
       }
       cout << "\n\n";
     }
     cout << "  ";
     for (int row = 0; row < x3; row++)
         cout << row << " ";
     cout << endl;
}
//*******************************************************************************************
//  checks to see how many ships are not sunk
//*******************************************************************************************
int Board::unsunkShipCount()
{
    int counter = 0;
    for (int index = 0; index < 4; index++)
    {
        if (ships[index]->isSunk())
           counter++;
    }
    return counter;
}
