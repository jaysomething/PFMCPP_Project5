/*
 Project 5: Part 4 / 4
 video: Chapter 3 Part 7

 Create a branch named Part4
 
 Don't #include what you don't use
 
 1) Your task is to refactor your Chapter 3 Part 4 task into separate source and header files.
         Add files via the pane on the left.
 
 2) Put all of your declarations for each class in .h files
         One header file per class ( i.e. Raider.h for a class named "Raider" )
 
 3) Put all of your implementations in .cpp files.
         one cpp file per class ( i.e. Raider.cpp for a class named "Raider" )
 
 4) Put all of your Wrapper classes in a single Wrappers.h file
         if you implemented your wrapper class functions in-class, you'll need to move them to Wrappers.cpp
 
 5) NO IN-CLASS IMPLEMENTATION ALLOWED.
         the only exception is the existing Atomic.h and LeakedObjectDetector.h
 
 6) for every .cpp file you have to make, insert it into the .replit file after 'main.cpp'.  Don't forget the spaces between file names.
 If you need help with this step, send me a DM.
 
 7) click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
Make a pull request after you make your first commit and pin the pull request link to our DM thread.

send me a DM to check your pull request

 Wait for my code review.
 
 Remember, your Chapter 3 Part 4 task worked when it was all in one file. so you shouldn't need to edit any of it.  
         just split it up into source files and provide the appropriate #include directives.
 */

#include <iostream>

#include "Wrappers.h"
#include "Speaker.h"
#include "Bass.h"
#include "Mixer.h"
#include "SignalChain.h"
#include "Studio.h"

int main()
{
    std::cout << std::endl;

    SignalChainWrapper signalChainWrapper{new SignalChain};
    SignalChain& chain1 = *signalChainWrapper.ptrSignalChain;

    std::cout << "The " + chain1.speaker.name + " speaker has been turned ";
    std::cout << (chain1.speaker.toggleOnOff() ? "ON\n" : "OFF\n");

    chain1.speaker.selfToggleOnOFF();
    std::cout << std::endl;

    StudioWrapper studioWrapper(new Studio);
    Studio& studio1 = *studioWrapper.ptrStudio;

    std::cout << "The " + studio1.bass.name + " is ";
    std::cout << (studio1.bass.activeStatus() ? "an active bass\n" : "a passive bass\n");

    studio1.bass.reportActive();
    std::cout << std::endl;

    std::cout << "good to go!" << std::endl;
}
