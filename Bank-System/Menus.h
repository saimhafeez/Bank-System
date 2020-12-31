#pragma once
int account_no = 204060;
void MENU_signup();

void MENU_main()
{
	int i, select = 0;
	for (i = 0; i < 34; i++)
	{
		printf("%c", 219);
	}
	printf("\n%c %-30s %c\n", 219, "     Welcome To Grand Bank", 219);
	printf("%c %-30s %c\n", 219, "         Online Portal", 219);
	printf("%c %-30s %c\n", 219, "01. --> Login", 219);
	printf("%c %-30s %c\n", 219, "02. --> Signup", 219);
	for (i = 0; i < 34; i++)
	{
		printf("%c", 219);
	}
	printf("\n%c %s--> ", 219, "SELECT");
	scanf("%d", &select);
	if (select == 1)
	{

	}
	else if (select == 2)
	{
		MENU_signup();
	}
	else
	{
		printf("%c %-30s %c\n", 219, "SELECT: ", 219);
	}
}

void MENU_signup()
{
	int i;
	for (i = 0; i < RECORD_DATA; i++)
	{
		if (UA[i].account_no == 0)
		{
			printf("%c--> Enter Email: ", 219);
			getchar();
			gets_s(UA[i].email);
			printf("%c--> Enter Password: ", 219);
			gets_s(UA[i].password);
			printf("%c--> First Name: ", 219);
			gets_s(UA[i].name_first);
			printf("%c--> Last Name: ", 219);
			gets_s(UA[i].name_last);
			printf("%c--> CNIC no: ", 219);
			gets_s(UA[i].cnic);
			printf("%c--> Date of Birth\n%c--> day-month-year: ", 219, 219);
			scanf("%d-%d-%d", UA[i].DB.day, UA[i].DB.month, UA[i].DB.year);
			UA[i].deposit = 0;
			UA[i].account_no = account_no;
			account_no += 10;
			FILE* FILE_STORE;
			FILE_STORE = fopen("user_account.txt", "ab+");
			if (FILE_STORE == NULL)
			{
				printf("%c Error opening file\n", 219);
			}
			else
			{
				fscanf(FILE_STORE, "\n%s %s %s %s %s %d-%d-%d",
					UA[i].email, UA[i].password, UA[i].name_first,
					UA[i].name_last, UA[i].cnic, UA[i].DB.day, UA[i].DB.month, UA[i].DB.year,
					UA[i].cnic);
			}
			break;
		}
	}
}
