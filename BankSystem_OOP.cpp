#pragma warning(disable : 4996) // ctime()

#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>  // to is upper, lower, digit, punct
#include <fstream> // Files
#include "clsLoginScreen.h"
using namespace std;

int main()
{
	while (true)
	{
		clsLoginScreen::ShowLoginScreen();
	}


    return 0;
}