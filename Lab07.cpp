/*************************************************************
 * 1. Name:
 *      Demo
 * 2. Assignment Name:
 *      Lab 07: Orbit Simulator
 * 3. Assignment Description:
 *      Simulate satellites orbiting the earth
 * 4. What was the hardest part? Be as specific as possible.
 *      ??
 * 5. How long did it take for you to complete the assignment?
 *      ??
 *****************************************************************/

#define _USE_MATH_DEFINES
#include <cassert>      // for ASSERT
#include "uiInteract.h" // for INTERFACE
#include "uiDraw.h"     // for RANDOM and DRAW*
#include "position.h"      // for POINT
#include <math.h>
using namespace std;

const double EARTH_SECS_PER_DAY   = 86400.0;
const double FRAMERATE            = 30.0;
const double EARTH_HOURS_PER_DAY  = 24.0;
const double EARTH_MIN_PER_HOUR   = 60.0;
const double EARTH_RADIUS         = 6378000.0; // 6,378,000 meters
const double EARTH_GRAVITY_AT_SEA = 9.80665;
const double EARTH_X_CENTER       = 0.0;
const double EARTH_Y_CENTER       = 0.0;
const double GEO_ORBIT            = 42164000.0;

double getTimeDilation(double hoursday, double minutesHours)
{
   return hoursday * minutesHours;
}

double getTimePerFrame(double td, double frameRate)
{
   return td / frameRate;
}

double getRotationSpeed(double frameRate, double td, double secondsDay)
{
   double part1 = -((2 * M_PI) / frameRate);
   double part2 = td / secondsDay;
   return part1 * part2;
}

double getGravity(double seaLevelGravity, double radius, double heightAboveSurface)
{
   double inner = radius / (radius + heightAboveSurface);
   return seaLevelGravity * (inner * inner);
}

double getHeightAboveSurface(double x, double y, double radius)
{
   double inner = (x * x) + (y * y);
   return sqrt(inner) - radius;
}

double getGravityDirection(double xEarth, double yEarth, double xSatellite, double ySatellite)
{
   double lhs = xEarth - xSatellite;
   double rhs = yEarth - ySatellite;
   return atan2(lhs, rhs);
}

double getHorizontalComponent(double input, double aRadians)
{
   return input * sin(aRadians);
}

double getVerticalComponent(double input, double aRadians)
{
   return input * cos(aRadians);
}

double getDistance(double iP, double v, double a, double time)
{
   double part1 = v * time;
   double part2 = a * (time * time) * 0.5;
   return iP + part1 + part2;
}

double getVelocity(double iV, double a, double time)
{
   return iV + (a * time);
}

/*************************************************************************
 * Demo
 * Test structure to capture the LM that will move around the screen
 *************************************************************************/
class Demo
{
public:
   Demo(Position ptUpperRight) :
      ptUpperRight(ptUpperRight)
   {
      ptHubble.setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
      ptHubble.setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));

      ptSputnik.setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
      ptSputnik.setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));

      ptStarlink.setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
      ptStarlink.setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));

      ptCrewDragon.setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
      ptCrewDragon.setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));

      ptShip.setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
      ptShip.setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));

      ptGPS.setMetersX(0);
      ptGPS.setMetersY(GEO_ORBIT);

      ptStar.setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
      ptStar.setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));

      angleShip = 0.0;
      angleEarth = 0.0;
      phaseStar = 0;
      GPSVelocityX = -3100.0;
      GPSVelocityY = 0.0;
   }

   Position ptHubble;
   Position ptSputnik;
   Position ptStarlink;
   Position ptCrewDragon;
   Position ptShip;
   Position ptGPS;
   Position ptStar;
   Position ptUpperRight;

   double GPSVelocityX;
   double GPSVelocityY;

   unsigned char phaseStar;

   double angleShip;
   double angleEarth;
   double td = getTimeDilation(EARTH_HOURS_PER_DAY, EARTH_MIN_PER_HOUR);
   double tpf = getTimePerFrame(td, FRAMERATE);
};

/*************************************
 * All the interesting work happens here, when
 * I get called back from OpenGL to draw a frame.
 * When I am finished drawing, then the graphics
 * engine will wait until the proper amount of
 * time has passed and put the drawing on the screen.
 **************************************/
void callBack(const Interface* pUI, void* p)
{
   // the first step is to cast the void pointer into a game object. This
   // is the first step of every single callback function in OpenGL. 
   Demo* pDemo = (Demo*)p;

   //
   // accept input
   //

   // move by a little
   if (pUI->isUp())
      pDemo->ptShip.addPixelsY(1.0);
   if (pUI->isDown())
      pDemo->ptShip.addPixelsY(-1.0);
   if (pUI->isLeft())
      pDemo->ptShip.addPixelsX(-1.0);
   if (pUI->isRight())
      pDemo->ptShip.addPixelsX(1.0);


   //
   // perform all the game logic
   //

   
   double rotationSpeed = getRotationSpeed(FRAMERATE, pDemo->td, EARTH_SECS_PER_DAY);
   double height = getHeightAboveSurface(pDemo->ptGPS.getMetersX(), pDemo->ptGPS.getMetersY(), EARTH_RADIUS);
   double gravity = getGravity(EARTH_GRAVITY_AT_SEA, EARTH_RADIUS, height);
   double angle = getGravityDirection(EARTH_X_CENTER, EARTH_Y_CENTER, pDemo->ptGPS.getMetersX(), pDemo->ptGPS.getMetersY());
   double ddx = getHorizontalComponent(gravity, angle);
   double ddy = getVerticalComponent(gravity, angle);
   pDemo->GPSVelocityX = getVelocity(pDemo->GPSVelocityX, ddx, pDemo->tpf);
   pDemo->GPSVelocityY = getVelocity(pDemo->GPSVelocityY, ddy, pDemo->tpf);
   pDemo->ptGPS.setMetersX(getDistance(pDemo->ptGPS.getMetersX(), pDemo->GPSVelocityX, ddx, pDemo->tpf));
   pDemo->ptGPS.setMetersY(getDistance(pDemo->ptGPS.getMetersY(), pDemo->GPSVelocityY, ddy, pDemo->tpf));

   // rotate the earth
   pDemo->angleEarth += rotationSpeed;
   pDemo->angleShip += 0.02;
   pDemo->phaseStar++;

   //
   // draw everything
   //

   Position pt;
   ogstream gout(pt);

   // draw satellites
   gout.drawCrewDragon(pDemo->ptCrewDragon, pDemo->angleShip);
   gout.drawHubble    (pDemo->ptHubble,     pDemo->angleShip);
   gout.drawSputnik   (pDemo->ptSputnik,    pDemo->angleShip);
   gout.drawStarlink  (pDemo->ptStarlink,   pDemo->angleShip);
   gout.drawShip      (pDemo->ptShip,       pDemo->angleShip, pUI->isSpace());
   gout.drawGPS       (pDemo->ptGPS,        pDemo->angleShip);

   // draw parts
   pt.setPixelsX(pDemo->ptCrewDragon.getPixelsX() + 20);
   pt.setPixelsY(pDemo->ptCrewDragon.getPixelsY() + 20);
   gout.drawCrewDragonRight(pt, pDemo->angleShip); // notice only two parameters are set
   pt.setPixelsX(pDemo->ptHubble.getPixelsX() + 20);
   pt.setPixelsY(pDemo->ptHubble.getPixelsY() + 20);
   gout.drawHubbleLeft(pt, pDemo->angleShip);      // notice only two parameters are set
   pt.setPixelsX(pDemo->ptGPS.getPixelsX() + 20);
   pt.setPixelsY(pDemo->ptGPS.getPixelsY() + 20);
   gout.drawGPSCenter(pt, pDemo->angleShip);       // notice only two parameters are set
   pt.setPixelsX(pDemo->ptStarlink.getPixelsX() + 20);
   pt.setPixelsY(pDemo->ptStarlink.getPixelsY() + 20);
   gout.drawStarlinkArray(pt, pDemo->angleShip);   // notice only two parameters are set

   // draw fragments
   pt.setPixelsX(pDemo->ptSputnik.getPixelsX() + 20);
   pt.setPixelsY(pDemo->ptSputnik.getPixelsY() + 20);
   gout.drawFragment(pt, pDemo->angleShip);
   pt.setPixelsX(pDemo->ptShip.getPixelsX() + 20);
   pt.setPixelsY(pDemo->ptShip.getPixelsY() + 20);
   gout.drawFragment(pt, pDemo->angleShip);

   // draw a single star
   gout.drawStar(pDemo->ptStar, pDemo->phaseStar);

   // draw the earth
   pt.setMeters(0.0, 0.0);
   gout.drawEarth(pt, pDemo->angleEarth);
}

double Position::metersFromPixels = 40.0;

///*********************************
// * Initialize the simulation and set it in motion
// *********************************/
//#ifdef _WIN32_X
//#include <windows.h>
//int WINAPI wWinMain(
//   _In_ HINSTANCE hInstance,
//   _In_opt_ HINSTANCE hPrevInstance,
//   _In_ PWSTR pCmdLine,
//   _In_ int nCmdShow)
//#else // !_WIN32
//int main(int argc, char** argv)
//#endif // !_WIN32
//{
//   // Initialize OpenGL
//   Position ptUpperRight;
//   ptUpperRight.setZoom(128000.0 /* 128km equals 1 pixel */);
//   ptUpperRight.setPixelsX(1000.0);
//   ptUpperRight.setPixelsY(1000.0);
//   Interface ui(0, NULL,
//      "Demo",   /* name on the window */
//      ptUpperRight);
//
//   // Initialize the demo
//   Demo demo(ptUpperRight);
//
//   // set everything into action
//   ui.run(callBack, &demo);
//
//
//   return 0;
//}

#include "testPhysicsManager.h"

int main()
{
   TestPhysicsManager physicsTest;
   physicsTest.runTests();
   cout << "Tests pass!" << endl;
}
