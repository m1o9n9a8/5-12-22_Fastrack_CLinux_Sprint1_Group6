#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct account {
    char username[50]; 
    char password[50];
};

struct polls {
    char pollName[50]; 
    char pollNum[50];
};

//struct date dt;

void read_file(struct account *);
void CreateUser();
void CreatePolls();
void Quit();
void Nominate();
void Changepassword(struct account *, char *);
void DisplayPollResults();
void Vote();
