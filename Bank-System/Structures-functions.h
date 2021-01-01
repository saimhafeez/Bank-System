#pragma once

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