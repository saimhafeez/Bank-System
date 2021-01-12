#pragma once
void MENU_signup();
void Additional_info(int index);
void MENU_login();
void DEV_mode();
void LOGIN_PAGE(int index);
void DepositMoney(int index);
void MENU_main()
{
	int i;
	char select = NULL;
	char random_no[70];
	char verify[10];
	char pass_user[10];
	char pass[10];
	FILE* Fetch_P = fopen("DATA_FILES\\dev_p.bin", "rb");
	while (!feof(Fetch_P))
	{
		fscanf(Fetch_P, "%s", pass);
	}
	fclose(Fetch_P);
	//printf("\n%s\n", pass);
	//printf("\n%d\n", strlen(pass));
	do{
		for (i = 0; i < 34; i++) { printf("%c", 219); }
		printf("\n%c %-30s %c\n", 219, "     Welcome To Grand Bank", 219);
		printf("%c %-30s %c\n", 219, "         Online Portal", 219);
		printf("%c %-30s %c\n", 219, "Press 1 To Login", 219);
		printf("%c %-30s %c\n", 219, "Press 2 To Signup", 219);
		printf("%c %-30s %c\n", 219, "Press ESC To Exit", 219);
		printf("%c %-30s %c\n", 219, "Press / To Enter Dev Mode", 219);
		for (i = 0; i < 34; i++) { printf("%c", 219); }printf("\n");

		select = getch();
		switch (select)
		{
		case '1':
		{
			MENU_login();
			break;
		}
		case '2':
		{
			MENU_signup();
			break;
		}
		case 27:
		{
			loading(7, 7);
			break;
		}
		case '/':
		{
			do
			{
				strcpy(random_no, rand_string(5));
				printf("%c--> Type Following %s: ", 219, random_no);
				scanf("%s", verify);
				if (strcmp(verify, random_no) != 0)
				{
					printf("%c Validation Failed, Try again\n", 219);
				}
			} while (strcmp(verify, random_no) != 0);

			if (strcmp(verify, random_no) == 0)
			{
				printf("%c--> Password: ", 219);
				getchar();
				gets_s(pass_user);
				if (strcmp(pass_user, pass) == 0)
				{
					DEV_mode();
				}
			}
			break;
		}
		default:
		{
			printf("%c Invalid Command\n", 219);
			break;
		}
		}
	} while (select != 27);
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
			User_basic = fopen("DATA_FILES\\user_accounts.bin", "ab");
			fprintf(User_basic, "\n%s %s %s %s %s %s %d %d %d %d",
				UA[i].email, UA[i].password, UA[i].name_first, UA[i].name_last,
				UA[i].gender, UA[i].cnic, UA[i].DB.day, UA[i].DB.month, UA[i].DB.year,
				UA[i].account_no);
			fclose(User_basic);
			printf("%c%c%c%c Would you like to complete your profile now or\n", 219, 219, 219, 219);
			printf("%c%c%c%c You can update it later from profile.\n", 219, 219, 219, 219);
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
	FILE* User_additional_print = fopen("DATA_FILES\\user_additional_info.bin", "ab");
	fprintf(User_additional_print, "\n%d %s %s %s",
		UA[index].account_no, UA[index].AI.phone_no, UA[index].AI.zipcode, UA[index].AI.address);
	fclose(User_additional_print);
}

void MENU_login()
{
	int i, flag = 0;
	char email[STRING_LENGTH], password[STRING_LENGTH];
	printf("%c--> Enter Email: ", 219);
	gets_s(email);
	//printf("%s\n", email);
	printf("%c--> Enter Password: ", 219);
	gets_s(password);
	//printf("%s\n", password);
	loading(13, 6);
	for (i = 0; i < RECORD_DATA; i++)
	{
		if (strcmp(email, UA[i].email) == 0 && strcmp(password, UA[i].password) == 0)
		{
			printf("%c--> login successful!\n", 219);
			LOGIN_PAGE(i);
			flag = 0;
			break;
		}
		else if (strcmp(email, UA[i].email) != 0 || strcmp(password, UA[i].password) != 0)
		{
			flag = 1;
		}
	}
	if (flag == 1)
	{
		loading(70, 3);
		printf("%c%c%c%c Login Failed\n%c%c%c%c Incorrect credentionals\n%c%c%c%c If you are new, Register new account\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
	}
}

void DEV_mode()
{
	int i;
	char select = NULL;
	loading(13, 4);
	do
	{
		printf("%c DEVELOPER MODE ON\n", 219);
		printf("%c--> Press 1 Display ALL ACOUNTS INFO\n", 219);
		printf("%c--> Press 2 Display ALL ACOUNTS INFO\n", 219);
		printf("%c--> Press ESC To Return To Main Menu\n", 219);
		select = getch();
		switch (select)
		{
		case '1':
		{
			for (i = 0; i < RECORD_DATA; i++)
			{
				if (View(i) == 1)
				{
					loading(13, 3);
				}
			}
			break;
		}
		case '2':
		{
			break;
		}
		}
	} while (select != 27);
	
}

void LOGIN_PAGE(int index)
{
	char select = NULL;
	char select_2 = NULL;
	printf("%c Welcome %s %s\n", 219, UA[index].name_first, UA[index].name_last);
	do
	{
		printf("%c--> Press 1 To View Profile\n", 219);
		printf("%c--> Press 2 For Transaction Options\n", 219);
		printf("%c--> Press ESC To Logout\n", 219);
		select = getch();
		switch (select)
		{
		case '1':
		{
			printf("%c %-20s: %lf\n", 219, "Balance", UA[index].UAS.Balance);
			printf("%c %-20s: %02d-%02d-%d\n", 219, "Date-of-Birth", UA[index].DB.day, UA[index].DB.month, UA[index].DB.year);
			printf("%c %-20s: %s\n", 219, "CNIC", UA[index].cnic);
			printf("%c %-20s: %d\n", 219, "Account no", UA[index].account_no);
			printf("%c %-20s: %s\n", 219, "Phone no", UA[index].AI.phone_no);
			printf("%c %-20s: %s\n", 219, "Zipcode", UA[index].AI.zipcode);
			printf("%c %-20s: %s\n", 219, "Address", UA[index].AI.address);
			break;
		}
		case '2':
		{
			printf("%c--> Press 1: Deposit Money\n", 219);
			printf("%c--> Press 2: Transaction History\n", 219);
			printf("%c--> Press ESC To Logout\n", 219);
			select_2 = getch();
			switch (select_2)
			{
			case '1':
			{
				DepositMoney(index);
				break;
			}
			}
			break;
		}
		}
	} while (select != 27);
}

void DepositMoney(int index)
{
	char select = NULL, TimeStamp_call[STRING_LENGTH];
	double hold_balance = 0;
	printf("%c%c%c Deposit Money\n", 219, 219, 219);
	printf("%c Select Method\n", 219);
	printf("%c Press 1: By-Hand\n", 219);
	printf("%c Press 2: Transfer from Other Account\n", 219);
	select = getch();
	switch (select)
	{
	case '1':
	{
		printf("%c --> Deposit Money (Rs): ", 219);
		scanf("%lf", &hold_balance);
		UA[index].UAS.Balance = UA[index].UAS.Balance + hold_balance;
		strcpy(UA[index].UAS.Sender_name, "N/A");
		strcpy(UA[index].UAS.Sender_acc_no, "N/A");
		break;
	}
	case '2':
	{
		printf("%c --> Sender Name: ", 219);
		gets_s(UA[index].UAS.Sender_name);
		printf("%c --> Sender Account No: ", 219);
		gets_s(UA[index].UAS.Sender_acc_no);
		printf("%c --> Deposit Money (Rs): ", 219);
		scanf("%lf", &hold_balance);
		UA[index].UAS.Balance = UA[index].UAS.Balance + hold_balance;
		break;
	}
	default:
	{
		printf("%c Invalid Command\n", 219);
	}
	}
	//OPEN FILE TO STORE CURRENT BALANCE
	FILE* Deposit_print = fopen("DATA_FILES\\Deposit_data.bin","ab");
	fprintf(Deposit_print, "\n%d %lf %s %s",
		UA[index].account_no, UA[index].UAS.Balance,
		UA[index].UAS.Sender_name, UA[index].UAS.Sender_acc_no);
	fclose(Deposit_print);
	strcpy(TimeStamp_call, TimeStamp());
	printf("%c Payment successful at %s\n", 219, TimeStamp_call);
	system("pause\n");
}

void Transaction_history(int index, int action)
{
	char USER_FILE_NAME[] = "transaction_history";
}