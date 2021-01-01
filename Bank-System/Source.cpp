#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <conio.h>
#define STRING_LENGTH 100
#define RECORD_DATA 5
#include "Structures-functions.h"
#include "Startup.h"
#include "Menus.h"


void View();
int main()
{
	Startup();
	View();
	MENU_main();
	return 0;
}

void View()
{
	int i = 0;
	for (i = 0; i < RECORD_DATA; i++)
	{
		if (UA[i].account_no != 0)
		{
			printf("\n%s %s %s %s %s %s %02d-%02d-%d %d",
				UA[i].email, UA[i].password, UA[i].name_first,
				UA[i].name_last, UA[i].gender, UA[i].cnic, UA[i].DB.day, UA[i].DB.month, UA[i].DB.year,
				UA[i].account_no);
			printf("Additional info\n");
			printf("%s %s %s",
				UA[i].AI.phone_no, UA[i].AI.zipcode, UA[i].AI.address);
		}
	}
}