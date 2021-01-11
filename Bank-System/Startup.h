#pragma once
int account_no = 204060;
void Startup()
{
	int i = 0, hold_account_no = 0, index, j;
	char hold_phone_no[STRING_LENGTH], hold_zipcode[STRING_LENGTH], hold_address[STRING_LENGTH];

	for (j = 0; j < RECORD_DATA; j++)
	{
		strcpy(UA[j].AI.address, "N/A");
		strcpy(UA[j].AI.phone_no, "N/A");
		strcpy(UA[j].AI.zipcode, "N/A");
	}
	FILE* User_basic_scan = fopen("user_accounts.bin", "rb");
	if (User_basic_scan == NULL)
	{
		printf("File not Found\n");
	}
	else
	{
		while(!feof(User_basic_scan))
		{
			fscanf(User_basic_scan, "\n%s %s %s %s %s %s %d %d %d %d",
				UA[i].email, UA[i].password, UA[i].name_first,
				UA[i].name_last, UA[i].gender, UA[i].cnic, &UA[i].DB.day, &UA[i].DB.month, &UA[i].DB.year,
				&UA[i].account_no);
			i++;
		}
		account_no = UA[i - 1].account_no + 10;
		fclose(User_basic_scan);
	}
	FILE* User_additional_scan = fopen("user_additional_info.bin", "rb");
	while (!feof(User_additional_scan))
	{
		fscanf(User_additional_scan, "\n%d %s %s %s",
			&hold_account_no, hold_phone_no, hold_zipcode, hold_address);
		index = Search_account(hold_account_no);
		if (index != -1)
		{
			strcpy(UA[index].AI.phone_no, hold_phone_no);
			strcpy(UA[index].AI.zipcode, hold_zipcode);
			strcpy(UA[index].AI.address, hold_address);
		}
	} 
	fclose(User_additional_scan);

	char hold_sender_name[STRING_LENGTH], hold_sender_acc_no[STRING_LENGTH];
	double hold_balance;
	int index2;
	FILE* Deposit_scan = fopen("Deposit_data.bin", "rb");
	while (!feof(Deposit_scan))
	{
		fscanf(Deposit_scan, "\n%d %lf %s %s",
			&hold_account_no, &hold_balance,
			hold_sender_name, hold_sender_acc_no);
		index2 = Search_account(hold_account_no);
		printf("\nindex = %d\n", index2);
		if (index2 != -1)
		{
			UA[index2].UAS.Balance = hold_balance;
			strcpy(UA[index2].UAS.Sender_name, hold_sender_name);
			strcpy(UA[index2].UAS.Sender_acc_no, hold_sender_acc_no);
		}
	}
	fclose(Deposit_scan);
}