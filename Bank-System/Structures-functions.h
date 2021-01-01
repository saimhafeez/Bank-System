#pragma once
char verfication_code[STRING_LENGTH];
struct date_birth {
	int day, month, year;
};

struct Additional_info {
	char phone_no[STRING_LENGTH];
	char zipcode[STRING_LENGTH];
	char address[STRING_LENGTH];
};

struct User_account {
	char email[STRING_LENGTH];
	char password[STRING_LENGTH];
	char name_first[STRING_LENGTH];
	char name_last[STRING_LENGTH];
	char gender[STRING_LENGTH];
	char cnic[STRING_LENGTH];
	int account_no;
	struct date_birth DB;
	struct Additional_info AI;
}UA[RECORD_DATA], Del_record;

int Search_account(int account_no)
{
	int i;
	for (i = 0; i < RECORD_DATA; i++)
	{
		if (UA[i].account_no == account_no)
		{
			return i;
			break;
		}
	}
	return -1;
}

int View( int index)
{
	int i;
	for (i = 0; i < RECORD_DATA; i++)
	{
		if (UA[index].account_no != 0)
		{
			printf("%c %-25s %-10s %-10s %-10s %-10s %-20s %-11s %-10s\n", 219, "Email", "Pass", "1st_name", "2nd_name", "Gender", "CNIC", "DOB", "Acc_no.");
			printf("%c %-25s %-10s %-10s %-10s %-10s %-20s %02d-%02d-%-5d %-10d\n", 219,
				UA[index].email, UA[index].password, UA[index].name_first,
				UA[index].name_last, UA[index].gender, UA[index].cnic, UA[index].DB.day, UA[index].DB.month, UA[index].DB.year,
				UA[index].account_no);
			printf("%c ----Additional info----\n", 219);
			printf("%c %-15s %-8s %-10s\n", 219, "Phone no.", "ZipCode", "Address");
			printf("%c %-15s %-8s %-10s\n", 219,
				UA[index].AI.phone_no, UA[index].AI.zipcode, UA[index].AI.address);
			return 1;
			break;
		}
	}
	return -1;
}

void delay(int milli_seconds)
{
	clock_t start_time = clock();

	while (clock() < start_time + milli_seconds)
		;
}

void loading(int mili_sec, int color)
{
	int i;
	printf("%c", 219);
	SetConsoleTextAttribute(handle, color);
	for (i = 0; i < 33; i++)
	{
		printf("%c", 219);
		delay(mili_sec);
	}
	printf(RESET_COLOR);
	printf("\n");
}

const char* rand_string(int length)
{
	int x, i, upper = 61, lower = 0;
	char str[70];
	char str_2[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
	char ch = NULL;
	int length_str = length + 1;
	srand(time(0));
	for (i = 0; i < length_str; i++)
	{
		x = (rand() % (upper - lower + 1)) + lower;
		//printf("x  = %d\n", x);
		ch = str_2[x];
		if (i == length_str - 1)
		{
			str[i] = '\0';
		}
		else
		{
			str[i] = ch;
		}
	}
	//printf("\n%s\n", str);
	return str;
}