#include<header.h>

void main()
{
	struct account *accounts[100];
	char *u_str[50];
	char *p_str[50];
	struct account item[100]; //retrieving file data
	int choice;
	char *username[50];
	printf("\n--------------------------Login Screen--------------------------\n\n");
	printf("Username:");
	scanf("%s", &u_str);
	printf("USername read successfully %s\n", u_str);
	printf("password:");
	scanf("%s", &p_str);
	printf("Password read successfully %s \n", p_str);
	read_file(*accounts);
	printf("File read successfully\n");
	
	for(int i = 0; i <= sizeof(item); i++){
		if(*u_str == "admin" && *p_str == "admin"){
			printf("--------------------------Admin Screen---------------------------");
			printf("1. Create Users");
			printf("2. Create Polls");
			printf("3. Calculate Poll Results");
			printf("0. Quit");
			
			switch (choice)
			{
				case 1:
				CreateUser();
				break;

				case 2:
				CreatePolls();
				break;
				
				case 3:
				//CalculatePollresults();
				break;
				
				case 0:
				Quit();
				break;
    
				default:
				printf("Wrong Input");
			}
		}
		else if(accounts[i]->username == *u_str && accounts[i]->password == *p_str){
			printf("--------------------------User Screen---------------------------");
			printf("1. Nominate");
			printf("2. Vote");
			printf("3. Display poll results");
			printf("4. Change password");
			printf("0. Quit");

			*username = *u_str;
			switch (choice)
			{
				case 1:
				Nominate();
				break;

				case 2:
				//Vote();
				break;
				
				case 3:
				//DisplayPollResults();
				break;
				
				case 4:
				Changepassword(*accounts, *username);
				break;
				
				case 0:
				Quit();
				break;
    
				default:
				printf("Wrong Input");
			}
		}
		else {
			printf("Invalid User or password");
			break;
		}
	}
	
}
