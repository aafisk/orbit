/*************************************************************
 * 1. Name:
 *      Aaron Fisk and [Your name here] - Final Submission
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
#include "position.h"   // for POINT
#include <math.h>
#include "simulator.h"  // To run the simulation
using namespace std;


double Position::metersFromPixels = 40.0;
   
ogstream gout;
Earth earth;

/******************************
* The main callback loop that drives the simulator
******************************/
void callBack(const Interface* pUI, void* p)
{
   Simulator* sim = (Simulator*)p;

   sim->input(*pUI);
   sim->update();
   sim->checkCollisions();
}


/*********************************
 * Initialize the simulation and set it in motion
 *********************************/
#ifdef _WIN32_X
#include <windows.h>
int WINAPI wWinMain(
   _In_ HINSTANCE hInstance,
   _In_opt_ HINSTANCE hPrevInstance,
   _In_ PWSTR pCmdLine,
   _In_ int nCmdShow)
#else // !_WIN32
int main(int argc, char** argv)
#endif // !_WIN32
{
   // Initialize OpenGL
   Position ptUpperRight;
   ptUpperRight.setZoom(128000.0 /* 128km equals 1 pixel */);
   ptUpperRight.setPixelsX(1000.0);
   ptUpperRight.setPixelsY(1000.0);
   Interface ui(0, NULL,
      "Orbit Simulator",   /* name on the window */
      ptUpperRight);

   // Initialize the simulator
   Simulator sim;

   // Populate the simulator with everything
   sim.populateSim();

   // set everything into action
   ui.run(callBack, &sim);


   return 0;
}

//#include "test.h"
//
//int main()
//{
//   testRunner();
//   cout << "Tests pass!" << endl;
//}
