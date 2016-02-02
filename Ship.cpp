//  Eric Chu
//  Ship.cpp
//  Battleship
//  Final Project: BattleShip

#include "Ship.h"
//#include "Point.h"
using namespace std;
//*******************************************************************************************
//Constructor
//*******************************************************************************************

Ship::Ship(point originPoint, direction o, int l) 
{
 origin = originPoint;
 orientation = o;
 length = l;
 if (orientation == HORIZONTAL) //compared with their integer values
 {
    points.add(origin);
    //the loop moves us along the x axis
    point temp;
    for( int x = origin.getX() + 1; x < (origin.getX() + length); x++)
    {
         //Y remains constant for a horizontal ship
         temp =point(x, origin.getY());
         points.add(temp);
    }
 }
  else //else it is verticle
  {
    points.add(origin);
    point temp; 
    //the loop moves us along the y axis
    for( int y = origin.getY() + 1; y < (origin.getY() + length); y++)
    {
         //X remains constant for a vertical ship
         temp = point(origin.getX(), y);
         points.add(temp);
    }
 }      
}

//*******************************************************************************************
// Copy Constructor
//*******************************************************************************************

Ship::Ship(const Ship& s) 
{
 origin = s.origin;
 orientation = s.orientation;
 length = s.length;
 points = s.points;
 hits = s.hits;
}

//*******************************************************************************************
//Contains Point 
//Returns true if point is contained in ship
//*******************************************************************************************

bool Ship::containsPoint(const point& p) const
{   
	return points.contains(p)?true:false;
}

//*******************************************************************************************
// Collides With checks if ship shares a point with another ship
//*******************************************************************************************

bool Ship::collidesWith(const Ship& s) const
{
     bool isColliding = false;
	for(int x = 0; x < s.length;x++)
    {
      if (points.contains(s.points[x])== true)
      {
       isColliding = true;
       cout << "Collision\n";
       }
    }
    return isColliding;
}

//*******************************************************************************************
// Shot Fired At Point
//*******************************************************************************************

void Ship::shotFiredAtPoint(const point& p)
{
     if (points.contains(p))  //if the fired at coordinate is contained in ship
        hits.add(p); // add coordinate to hit point collection
}

//*******************************************************************************************
// Is Hit At Point
//*******************************************************************************************

bool Ship::isHitAtPoint(const point& p)
{
    return hits.contains(p)?true:false;  //check the hit list to see if it contains this point
}

//*******************************************************************************************
// Hit Count
//*******************************************************************************************

int Ship::hitCount() const
{
    return hits.getSize(); // the size is incremented in the PointCollection class every time add is called
}

//*******************************************************************************************
// Operator =
//*******************************************************************************************

const Ship& Ship::operator=(const Ship& s)
{
 origin = s.origin;
 orientation = s.orientation;
 length = s.length;
 points = s.points;
 hits = s.hits;
    return *this;
}


//*******************************************************************************************
//  Is Sunk if points is the same size as hits
//*******************************************************************************************

bool Ship::isSunk() 
{
	return points.getSize()==hits.getSize()?true:false;	
}











