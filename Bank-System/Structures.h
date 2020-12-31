#pragma once


struct date_birth {
	int day, month, year;
};

struct User_account {
	char email[STRING_LENGTH];
	char password[STRING_LENGTH];
	char name_first[STRING_LENGTH];
	char name_last[STRING_LENGTH];
	char cnic[STRING_LENGTH];
	struct date_birth DB;
	int deposit;
	int account_no;
}UA[RECORD_DATA], Del_record;