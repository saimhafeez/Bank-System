#pragma once

void MENU_signup();
void Additional_info(int index);
void MENU_login();

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
		MENU_login();
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
	char select;
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
			printf("%c--> Gender: ", 219);
			gets_s(UA[i].gender);
			printf("%c--> CNIC no: ", 219);
			gets_s(UA[i].cnic);
			printf("%c%c%c%c Date of Birth\n%c--> [day-month-year]: ", 219, 219, 219, 219, 219);
			scanf("%d-%d-%d", &UA[i].DB.day, &UA[i].DB.month, &UA[i].DB.year);
			UA[i].account_no = account_no;
			account_no += 10;
			FILE* User_basic;
			User_basic = fopen("user_accounts.bin", "ab");
			fprintf(User_basic, "\n%s %s %s %s %s %s %d %d %d %d",
				UA[i].email, UA[i].password, UA[i].name_first, UA[i].gender,
				UA[i].name_last, UA[i].cnic, UA[i].DB.day, UA[i].DB.month, UA[i].DB.year,
				UA[i].account_no);
			fclose(User_basic);
			printf("%c--> Would you like to complete your profile now or\n", 219);
			printf("%c--> You can update it later from profile.\n", 219);
			printf("%c--> Complete now ? [Y/N]: ", 219);
			getchar();
			scanf("%c", &select);
			if (select == 'y' || select == 'Y')
			{
				Additional_info(i);
			}
			break;
		}
	}
}

void Additional_info(int index)
{
	printf("%c--> Phone no. : ", 219);
	getchar();
	gets_s(UA[index].AI.phone_no);
	printf("%c--> ZipCode: ", 219);
	gets_s(UA[index].AI.zipcode);
	printf("%c--> Address: ", 219);
	gets_s(UA[index].AI.address);
	FILE* User_additional_print = fopen("user_additional_info.bin", "ab");
	fprintf(User_additional_print, "\n%d %s %s %s",
		UA[index].account_no, UA[index].AI.phone_no, UA[index].AI.zipcode, UA[index].AI.address);
	fclose(User_additional_print);
}

void MENU_login()
{
	int i, flag;
	char email[STRING_LENGTH], password[STRING_LENGTH];
	printf("%c--> Enter Email: ", 219);
	getchar();
	gets_s(email);
	printf("%c--> Enter Password: ", 219);

	gets_s(password);
	for (i = 0; i < RECORD_DATA; i++)
	{
		if (strcmp(email, UA[i].email) == 0 && strcmp(password, UA[i].password) == 0)
		{
			printf("login successful!");
			flag = 0;
		}
		else if (strcmp(email, UA[i].email) != 0)
		{
			flag = 1;
		}
		else if (strcmp(password, UA[i].password) != 0)
		{
			flag = 2;
		}
	}
	if (flag == 1)
	{
		printf("%c--> User not Found, Register new from signup\n", 219);
	}
	else if (flag == 2)
	{
		printf("%c--> incorrect Password!\n", 219);
	}
}