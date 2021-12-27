/**
        This Header file contains useful functions for GameMaker Dll export.
        <!-- Feel free to use this in your projects-->
        - GameMaker Booleans              : gmtrue and gmfalse
        - GameMaker Boolean Return value  : gmbool
        - GameMaker Integer Return value  : gmint
        - GameMaker Strings:
            -> When passing a string to a dll function from GameMaker, use stringToDLL as param value
            -> When passing a string from the dll (as a return value) back to GameMaker, use stringFromDLL
        And the most important:
        To expose functions from the DLL to GameMaker, use the keyword "gmx"
        Example:
        - Non exposed function (Only accessible from within the C++ Code):
            -> void doSometing();
        - GameMaker exposed DLL function (Callable from GM):
            -> gmx gmbool doSomething(gmint myNumber)
            {
                return myNumber*2
            }
            (All functions in GM must return something...)
            (In this case, it just returns double the value it got.)
*/

/* Header Guards*/
#ifndef GMS_H_INCLUDED
#define GMS_H_INCLUDED

/* Define extern export for GameMaker */
#define gmx extern "C" __declspec(dllexport)

/* Define GameMaker Booleans */
#define gmtrue 1.0;
#define gmfalse 0.0;

/* Define GameMaker datatypes*/
typedef double gmint;               // Integer for GM
typedef const char* stringToDLL;    // String passed GM --> DLL
typedef char* stringFromDLL;        // String passed DLL -- > GM
typedef double gmbool;              // Datatype for GM Boolean

/* Regular includes */
#include <string>
#include <string.h>
#include <iostream>
using namespace std; // Fight me

/**
* @brief This is the static helper class.
*        Access is namespace-like: gmu::function
*/
class gmu {

public:

    /**
    * @param s String to convert to char*
    * @brief Convert string to char*
    */
    static char* string_to_charptr(string s)
    {
        return _strdup(s.c_str());
    }


    /**
    * @param s String to convert to const char*
    * @brief Convert string to const char*
    */
    static const char* string_to_constcharptr(string s)
    {
        return s.c_str();
    }

    /**
    * @param p const char* to convert
    * @brief Convert const char* to string
    */
    static string constcharptr_to_string(const char* p)
    {
        return string(p);
    }

    /**
    * @param s String to print
    * @brief Prints a string to GMS debug console
    */
    static void debugmessage(string s)
    {
        std::cout << s << std::endl;
    }

private:
    /**
    *   @brief Do not instantiate.
    */
    gmu() {}
};
#endif // AMOGUS_H_INCLUDED