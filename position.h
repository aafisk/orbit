/***********************************************************************
 * Header File:
 *    Point : The representation of a position 
 * Author:
 *    Br. Helfrich
 * Summary:
 *    Everything we need to know about a location on the screen
 *    or the location on the field.
 ************************************************************************/


#pragma once

#include <iostream> 
#include <cmath>
#include <cassert>

class TestPosition;
class Acceleration;
class Velocity;

/*********************************************
 * Position
 * A single position on the field in Meters  
 *********************************************/
class Position
{
public:
   friend TestPosition;
   
   // constructors
   Position()            : x(0.0), y(0.0)  {}
   Position(double x, double y);
   Position(const Position & pt) : x(pt.x), y(pt.y) {}
   Position& operator = (const Position& pt);

   // getters
   double getMetersX()       const { return x;                    }
   double getMetersY()       const { return y;                    }
   double getPixelsX()       const { return x / metersFromPixels; }
   double getPixelsY()       const { return y / metersFromPixels; }

   // setters
   void setMeters(double xMeters, double yMeters) {x = xMeters; y = yMeters; }
   void setMetersX(double xMeters)       { x = xMeters;           }
   void setMetersY(double yMeters)       { y = yMeters;           }
   void setPixelsX(double xPixels)       { x = xPixels * metersFromPixels;          }
   void setPixelsY(double yPixels)       { y = yPixels * metersFromPixels;          }
   void addMetersX(double dxMeters)      { setMetersX(getMetersX() + dxMeters);     }
   void addMetersY(double dyMeters)      { setMetersY(getMetersY() + dyMeters);     }
   void addPixelsX(double dxPixels)      { setPixelsX(getPixelsX() + dxPixels);     }
   void addPixelsY(double dyPixels)      { setPixelsY(getPixelsY() + dyPixels);     }

   // deal with the ratio of meters to pixels
   void setZoom(double metersFromPixels)
   {
      this->metersFromPixels = metersFromPixels;
   }
   double getZoom() const { return metersFromPixels; }

protected:
   double x;                 // horizontal position
   double y;                 // vertical position
   static double metersFromPixels;
};

/*********************************************
 * COMPUTE DISTANCE
 * Find the distance between two positions
 *********************************************/
inline double computeDistance(const Position& pos1, const Position& pos2)
{
   return sqrt((pos1.getMetersX() - pos2.getMetersX()) * (pos1.getMetersX() - pos2.getMetersX()) +
               (pos1.getMetersY() - pos2.getMetersY()) * (pos1.getMetersY() - pos2.getMetersY()));
}

// stream I/O useful for debugging
std::ostream & operator << (std::ostream & out, const Position& pt);
std::istream & operator >> (std::istream & in,        Position& pt);


/*********************************************
 * PT
 * Trivial point
 *********************************************/
struct PT
{
   double x;
   double y;
};


class DummyPosition : public Position
{
public:
   DummyPosition() : Position() { }
   DummyPosition(double x, double y) : Position() { assert(false); }
   DummyPosition(const Position& pt) : Position() { assert(false); }
   Position& operator = (const Position& pt) { assert(false); };

   // getters
   virtual double getMetersX() const { assert(false); return x; }
   virtual double getMetersY() const { assert(false); return y; }
   virtual double getPixelsX() const { assert(false); assert(false); return x / metersFromPixels; }
   virtual double getPixelsY() const { assert(false); return y / metersFromPixels; }

   // setters
   void setMeters(double xMeters, double yMeters) { assert(false); }
   void setMetersX(double xMeters) { assert(false); }
   void setMetersY(double yMeters) { assert(false); }
   void setPixelsX(double xPixels) { assert(false); }
   void setPixelsY(double yPixels) { assert(false); }
   void addMetersX(double dxMeters) { assert(false); }
   void addMetersY(double dyMeters) { assert(false); }
   void addPixelsX(double dxPixels) { assert(false); }
   void addPixelsY(double dyPixels) { assert(false); }

   // deal with the ratio of meters to pixels
   void setZoom(double metersFromPixels) { assert(false); }
   double getZoom() const { assert(false); return metersFromPixels; }
};

class StubPositionOnsurface : public DummyPosition
{
public:
   double getMetersX() const override { return 6378000.0; }
   double getMetersY() const override { return 0.0; }
};

class StubPositionAbovesurface : public DummyPosition
{
public:
   double getMetersX() const override { return 6383000.0; }
   double getMetersY() const override { return 5000.0; }
};

class StubPositionAbove : public DummyPosition
{
public:
   double getMetersX() const override { return 0.0; }
   double getMetersY() const override { return 5000.0; }
};

class StubPositionBelow : public DummyPosition
{
public:
   double getMetersX() const override { return 0.0; }
   double getMetersY() const override { return -5000.0; }
};

class StubPositionLeft : public DummyPosition
{
public:
   double getMetersX() const override { return -5000.0; }
   double getMetersY() const override { return 0.0; }
};

class StubPositionRight : public DummyPosition
{
public:
   double getMetersX() const override { return 5000.0; }
   double getMetersY() const override { return 0.0; }
};