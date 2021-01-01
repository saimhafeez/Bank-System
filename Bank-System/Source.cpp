#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <conio.h>
#include <time.h>
#include <iostream>
enum Colors { blue = 1, green, cyan, red, purple, yellow, grey, dgrey, hblue, hgreen, hred, hpurple, hyellow, hwhite };
HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
#define STRING_LENGTH 100
#define RECORD_DATA 5
#define RESET_COLOR "\033[0m"
#include "Structures-functions.h"
#include "Startup.h"
#include "Menus.h"

int main()
{
	printf("%c Fetching Data\n", 219);
	loading(13, 2);
	Startup();
	printf("%c Successful\n", 219);
	MENU_main();
	return 0;
}