#include<header.h>

void read_file(struct account accounts[])
{
    FILE* fp;
    int i=0;   // count how many lines are in the file
    int c;
    
    while(!feof(fp)) {
        c=fgetc(fp);
        if(c=='\n')
            ++i;
    }

    int j=0;

    rewind(fp);  // Line I added // read each line and put into accounts

    while((fscanf(fp, "%*s,%*s", accounts[j].username, accounts[j].password))>0){
	printf("%S\t %s\t\n", accounts[j].username, accounts[j].password);
        ++j;
	--i;
    }
    fclose(fp);
}

void CreateUser()
{
	char user[51];
	FILE *fptr;
	char status;
	printf("Enter Username:");
	scanf("%s",&user);
	fptr = fopen("users.txt", "a");
	gets(user);
	fprintf(fptr, "%s,%s", user, user);
	fclose(fptr);
	printf("Do you want to add more users (y/n)?");
	scanf("%c",&status);
	if(status == 'y'){
		CreateUser();
	}
}

void CreatePolls()
{
	char PollName[10];
	char PollDescription[50];
	int WardNo;
	char PollDate[10];
	FILE *fptr;
	char status;
	
	printf("Poll Name:");
	scanf("%s", PollName);
	printf("Poll Description:");
	scanf("%s", PollDescription);
	printf("Poll Date (in DD/MM/YY format):");
	scanf("%s", PollDate);
	printf("Ward No.:");
	scanf("%d", &WardNo);
	
	fptr = fopen("polls.txt", "a");
	fprintf(fptr, "%s", PollName);
	fprintf(fptr, "%s", PollDescription);
	fprintf(fptr, "%s", PollDate);
	fprintf(fptr, "%d", WardNo);
	fclose(fptr);
	
	printf("Do you want to add more users (y/n)?");
	scanf("%c", &status);
	if(status == 'y'){
		CreatePolls();
	}
}

void Quit()
{
	exit(0);
}

void Nominate(struct polls pollS[])
{
	FILE *fp;
	FILE *fptr;
    int i=0;   // count how many lines are in the file
    int c;
    fp=fopen("polls.txt", "r");
    while(!feof(fp)) {
        c=fgetc(fp);
        if(c=='\n')
            ++i;
    }
    int j=0;
    fptr = fopen("candidates.txt", "a");
    while((fscanf(fp, "%s\t,%s\t", pollS[j].pollNum))>0) {
	    fprintf(fptr, "%s\t,%s\t",pollS[j].pollNum);
	    ++j;
    }

    fclose(fp);
    fclose(fptr);
}

void Changepassword(struct account accounts[], char* username)
{
    	FILE *fp;
	FILE *fptr;
    	int i=0;   // count how many lines are in the file
    	int c;
	char pass[50];

    	fp=fopen("users.txt", "r");
    	while(!feof(fp))
	{
        	c=fgetc(fp);
        	if(c=='\n')
            	++i;
    	}

    	int j=0;
    	rewind(fp);  // Line added to read each line and put into accounts
    	while(i>0)
    	{
        	fscanf(fp, "%s,%s", accounts[j].username, accounts[j].password);
        	++j;
		--i;
    	}

	fclose(fp);
	printf("Enter new Password:");
	scanf("%s",pass);

	for(int i=0 ; i<= sizeof(*accounts); i++)
	{
		if(accounts[j].username == username)
		{
			accounts[j].password == pass;
		}
	}

	fp=fopen("users.txt", "a");
	fprintf(fptr, "%s", accounts);
	fclose(fptr);
}

/*void DisplayPollResults()
{
	char pollNumber[];
	char PollDescription[];
	int WardNo;
	char PollDate[];
	
	printf("Enter Poll Number");
	scanf("%s",pollNumber);
	
	FILE *in_file = fopen(“polls.txt" , "r" );
	FILE *in_file1 = fopen(“pollresults.txt", "r" );
	
	While(in_file){
		if(pollNumber == in_file[Poll No]){
			PollDescription = in_file[i].Poll Description;
			WardNo = in_file[i].Ward No;
			PollDate = in_file[i].Poll Date;
			print("Poll No - "+pollNumber);
			print("\n");
			print("Poll Description - "+PollDescription);
			print("\n");
			print("Ward No - "+WardNo);
			print("\n");
			print("Poll Date - "+PollDate);
			print("\n");
		}
	}
	
	While(in_file1){
		print("Candidate Name ");
		print("Number of votes ");
		print("\n");
		if(pollNumber == in_file1[j].Poll No){
			print(in_file1[Candidate Name]);
			print(in_file1[Number of votes]);
			print("\n");
		}
	}
	 fclose(in_file);
	 fclose(in_file1);	
}*/

/*void Vote()
{
	getdate(&dt);
	char pollNum[51];
	FILE *fp;
	FILE *fptr;
	FILE *fptr1
	char candidate[51];
	 
	fp=fopen("poll.txt", "r");
    	while(!feof(fp)){
        c=fgetc(fp);
        if(c=='\n')
            ++i;
        }
    	int j=0;
    	rewind(fp);
	
	while(j!=i-1){
        fscanf(fp, "%s,%s,%s", pollS[j].pollName, pollS[j].pollNum, pollS[j].PollDate);
        ++j;
    	}
	
	for(int i=0; i<=sizeof(pollS);i++){
		if(pollS[i].PollDate == dt){
			fprintf(fptr, "%s",pollS[i].pollNum);
		}
	}
	
	printf("Enter Poll Number");
	scanf("%s",pollNum);
	
	fptr=fopen("candidates.txt", "r");
    	while(!feof(fptr)) {
        c=fgetc(fptr);
        if(c=='\n')
            ++i;
    	}
    	int j=0;
    	rewind(fptr);
	
	while(j!=i-1) {
        fscanf(fptr, "%s %s", pollS[j].candidateName, pollS[j].pollNum);
        ++j;
    	}
	
	for(int i=0; i<=sizeof(pollS);i++){
		if(pollS[i].pollNum == pollNum){
			printf(fptr, "%s",pollS[i].candidateName);
		}
	}
	
	printf("Select Candidate");
	scanf("%s"candidate);
	
	fptr1=fopen("vote.txt", "a");
    	while(!feof(fptr1)) {
        c=fgetc(fptr1);
        if(c=='\n')
            ++i;
    	}
    	int j=0;
    	rewind(fptr1);
	
	while(j!=i-1) {
        fprintf(fptr, "%s,%s,%s",pollS[j].pollNum, Username, candidate);
        ++j;
    	}
	
}*/
