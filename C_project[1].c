#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <windows.h>

#define MAX_SIZE 50
 
void user(); 
int admin(); 

//ADMIN OPTIONS.
void reg();
void add();
void del();
void DelUser();
void review();
void history();

//USER OPTIONS.
int log_in();
int bill();
void feedback();


void file_update();


void heading()
{
	time_t now=time(NULL);
	char *st=ctime(&now);
    printf("\n\t\t\t\t--------------------------------------------------\t\t\t\t");
    printf("\n\t\t\t\t|   WELCOME TO INTERNET CAFE MANAGEMENT SYSTEM   |\t\t");
    printf("\n\t\t\t\t|    - The place where world under your fingers  |\t\t");

 	printf("\n\t\t\t\t--------------------------------------------------\t\t\t\t");
    printf("\n\t\t\t\t      %s                                    \t\t",st);
}

void main_heading()
{
	time_t now=time(NULL);
	char *st=ctime(&now);
    printf("\n\t\t\t\t--------------------------------------------------\t\t\t\t");
    printf("\n\t\t\t\t|          INTERNET CAFE MANAGEMENT SYSTEM        |\t\t");
    printf("\n\t\t\t\t|          --Every click you make brings you      |\t\t");
    printf("\n\t\t\t\t|            close to our hearts     %c            |\t\t",1);

    printf("\n\t\t\t\t--------------------------------------------------\t\t\t\t");
 	printf("\n\t\t\t\t--------------------------------------------------------------\t\t\t\t");
    printf("\n\t\t\t\t      %s                                    \t\t",st);
}



struct user
{
	char name[150];
	int user_id;
	char feedback[4000];
	char userpass[MAX_SIZE];
	struct user *next;
	char reg_time[MAX_SIZE];
	int balance;
};
struct user *first=NULL;


char owner[MAX_SIZE]="OWNER";
char pass[MAX_SIZE]="PASS";


struct admin
 {
 	char user_name[MAX_SIZE];
 	char password[MAX_SIZE];	
 };
struct admin *ad;


int main() 
{	
	system("color B4");
	int ch;
	while(1)
	{	
	    
		main_heading();
		printf("\n\t\t\t\t\t\t 1.USER \n\t\t\t\t\t\t 2.ADMIN \n\t\t\t\t\t\t 3.exit");
		printf("\n\t\t\t\t\t\t\t enter the choice :\t");
		scanf("%d",&ch);

		system("cls");
		switch(ch)
		{
			case 1:
					{
						user();
						break;
					}
			case 2:
				{
					admin();
					break;
				}
			case 3:
				{
					file_update();
					exit(0);
					break;
				}
			default:
				printf("\n\t\t\t\t\t\tPLEASE CHECK YOUR INPUT AND ENTER A VALID INPUT");
		}
	
	}
	
	return 0;
}
void user() 
{
	system("cls");
	heading();
		int ch;
		while(1)
		{	printf("\n\t\t\t\t\t\t YOUR AVAILABLE OPTIONS ARE:");
			printf("\n\t\t\t\t\t\t1. Login");
			printf("\n\t\t\t\t\t\t2. FEEDBACK");
			printf("\n\t\t\t\t\t\t3. EXIT");
			printf("\n");
			printf("\n\t\t\t\t\t\t enter the choice :\t");
			scanf("%d",&ch);
			system("cls");

			switch(ch)
			{
				case 1:
					heading();
					log_in();
					break;
				
				case 2:
						heading();
						feedback();
					break;
				case 3:
					main();
				default:
					printf("\n PLEASE ENTER A VALID INPUT");
			}
		}	
		system("cls");
}
  
  
int admin() 
{ 	int namecmp,passcmp;
	struct admin *ad=(struct admin*)malloc(sizeof(struct admin));
	heading();
	printf("\n\t\t\t\t\t\t LOGIN TO CONTINUE\n\t");
	while(1)
	{
	
		printf("\n\t\t\t\t\t\t PLEASE ENTER THE USER NAME \t");
		fflush(stdin);
		scanf("%s",(ad->user_name));
		printf("\n\t\t\t\t\t\t PLEASE ENTER THE PASSWORD\t");
		fflush(stdin);
		scanf("%s",ad->password);
		namecmp=strcmp(ad->user_name,owner);
		passcmp=strcmp(ad->password ,pass);
		if(namecmp !=0 || passcmp!=0)
		{
		
			printf("\n\t\t\t\t\t\t PLEASE ENTER THE CORRECT CREDENTIALS");
			continue;
		}
		else
		{
			system("cls");
			printf("\n\t\t\t\t\t\t YOU HAVE SUCCESSFULLY LOGGED IN ");
			int ch;
			heading();
			while(1)
			{
				printf("\n\t\t\t\t\t\t DEAR ADMIN CHOOSE YOUR OPTION TO PERFORM");
				printf("\n\t\t\t\t\t\t 1.NEW REGISTRATION FOR USER");
				printf("\n\t\t\t\t\t\t 2.DELETE THE USER");
				printf("\n\t\t\t\t\t\t 3.REVIEW BOX");
				printf("\n\t\t\t\t\t\t 4.HISTORY(use when not executing for 1st time )");
				printf("\n\t\t\t\t\t\t 5.EXIT");
				printf("\n\t\t\t\t ENTER YOUR CHOICE:");
				scanf("%d",&ch);
				system("cls");
				switch(ch)
					{
						
						case 1:
							heading();
							reg();
							break;
		
						case 2:
							{
								heading();
								del();
								break;
							}

						case 3:
							heading();
							review();
							break;
						
						
						case 4:
							{
								history();
								break;
							}
						case 5:
							{
								main();
							}
							
						default:
							printf("\n\t\t\t\t\t\t PLEASE CHOOSE A VALID INPUT");	
					}
			}	
		}
	}
			system("cls");

	
}

void reg()
{

printf("\n\t\t\t\t\t PLEASE CONTACT ADMIN AND PROVIDE THE REQ DETAILS\t");


	
	printf("\n\t\t\t\t\t\t------------\n");
	printf("\n\t\t\t\t\t\t|%s|\n",__DATE__);
	printf("\n\t\t\t\t\t\t|%s|",__TIME__);
	printf("\n\t\t\t\t\t\t------------\n");
	add();
	
}

void add() 
{	system("cls");
	struct user *temp,*newuser=(struct user*)malloc(sizeof(struct user));
	char name[MAX_SIZE],pass[MAX_SIZE];
	static	int a=1000;
	register int x,flag;
	main_heading();
	printf("\n\t\t\t\t THE RECORDS OF PREVIOUS USERS ARE:\n");
	printf("\n\t\t\t\t\tUsername:\t\t UserId");

		for(temp=first;temp!=NULL;temp=temp->next)
		{
		printf("\n\t\t\t\t-------------------------------------------------------------\n");
		printf("\n\t\t\t\t\t%s\t\t%d",temp->name,temp->user_id);
		}
		printf("\n\t\t\t\t-------------------------------------------------------------\n");

	printf("\n\t\t\t\t\t\t Dear, provide the user details");
	printf("\n\t\t\t\t\t\t ENTER THE FULL NAME (WITHOUT SPACES):\t");
	scanf("%s",newuser->name);
	fflush(stdin);
	printf("\n\t\t\t\t\t\t ENTER THE PASSWORD :\t");
	scanf("%s",newuser->userpass);
	newuser->next=NULL;
	for(temp=first;temp!=NULL;temp=temp->next)
	{
		x=strcmp(temp->name,newuser->name);
		if(x==0)
			flag=0;
		else
			flag=1;
	}
	if(flag!=0)
	{
	
		if(first == NULL)
		   first = newuser;
		else
		{	temp=first;
			while(temp->next!=NULL)
			{
				temp=temp->next;
			}
			temp->next=newuser;
		
		}
		time_t login=time(NULL);
		char *reg_time=ctime(&login);
		newuser->user_id= ++a;
		strcpy(newuser->reg_time,reg_time);
		printf("\n\t\t\t\t\t\tYOUR client has been added successfully\t");
		printf("\n\n\t\t\t\t\t\tDear User!! your id is : \t%d",newuser->user_id);
		newuser->balance=1000;
		printf("\n\n\t\t\t\t\t\tDear user ! you have an initial balance of 1000 amount \n\t\t you will be redirected in 5 seconds!!");
		Sleep(5000);
		system("cls");
	}
	else
	{
		printf("\n\t\t\t\t\t Username already existing");
		Sleep(2000);
		system("cls");
		add();
	}
	
}
void f1(){
		printf("\n\t\tProcessing payment through Spot Cash\a\a\a");
		Sleep(3000);
		user();
}

int bill(int login,int uid) 
{
	int ch,id,f=1;
	struct user *temp;
	time_t logout=time(NULL);

	double diff=difftime(logout,login);
	printf("\n\t\t\t\t%.2f is the time used\t\t\t\t\n",diff);
	int bill=(int)(diff *10); 
	printf("\n\t\t\t\t\t Your bill is  %d\n",bill);
	printf("\n\t\t\t\t Please choose the method to pay the bill");
	printf("\n\t\t\t\t\t 1.IC card\n\t\t\t\t\t 2.Spot Cash :\t");
	scanf("%d",&ch);
	if(ch==1){
		printf("\n\t\t\t\tplease enter the user_id to continue :\t");
		scanf("%d",&id);
		if(id==uid)
		for(temp=first;temp!=NULL;temp=temp->next)
		{
			if(temp->user_id==id)
			{
				printf("\n\t\t\t\t\t %d amount have been deducted from your account \t",bill);
				temp->balance-=bill;
				printf("\n\t you will be redirected in 3 seconds!!");
				Sleep(3000);
				system("cls");
				user();
			}	
		}
		printf("\n\t\t\t\t\t sorry you don't have an account in our cafe");
		f1();
		
		
	}
	else if(ch==2)
		f1();
}

void  del() 
{	char ch[3];
	int x,loc=0,id;
			struct user *temp=first;

	printf("\n\t\t\t\t THE RECORDS OF OUR USERS ARE:\n");
	printf("\n\t\t\t\t\tUsername:\t\t UserId");
		for(temp=first;temp!=NULL;temp=temp->next)
		{
		printf("\n\t\t\t\t-------------------------------------------------------------\n");
		printf("\n\t\t\t\t\t%s\t\t%d",temp->name,temp->user_id);
		}
	printf("\n\t\t\t\t-------------------------------------------------------------\n");
	printf("\n\t\t\t\t\tPlease enter the user id :\t");
	scanf("%d",&id);
	temp=first;
		while(temp!=NULL)
		{	loc++;
			if(temp->user_id==id)
			{
				printf("\n\t\t\t\t\t\t %d is your number \t",loc);
				DelUser(loc);
			}
			temp=temp->next;
		}
		if(temp==NULL)
		 	printf("\n\t\t\t\t\t User doesnt exist in our record\n\t you will be redirected in 2 seconds");
	Sleep(2000);
	system("cls");
}

 
 void history() 
 {
 	char ch;
 	printf("\n\t THE HISTORY OF PAST SESSIONS IS");
 	FILE *fptr=fopen("Internet.txt","r");
 	while(fscanf(fptr,"%c",&ch)!=EOF)
 	{
 		if(ch=='\n')
		 printf("\n");
		else
		{
			printf("%c",ch);
		}	
	}
	fclose(fptr);
 }

void feedback() 
 {	int id;
 	struct user *temp =first;
 	printf("\n\t\t\t\t\t\t ENTER THE USER ID TO CONTINUE :\t");
 	scanf("%d",&id);
 	while(temp!=NULL)
 	{
 		if(temp->user_id==id)
		 
		 {
		 	fflush(stdin);
		 	printf("\n\t\t\t\t\t\t YOUR RESPONSE WILL HELP US A LOT ");
 			printf("\n\t\t\t\t\t\t PLEASE ENTER YOUR FEEDBACK :\t");
 			gets(temp->feedback);
 			fflush(stdin);
		 }
		 temp=temp->next;	
	}
	printf("\n\t\t\t\t\tPress any key to continue.. :\t");
	getch();
	system("cls");
	free(temp);
 }
 
 void review() 
{
 	printf(" \n\t\t\t\t\t\tDear Admin,Here are the feedbacks by your beloved users\t");
   struct user *temp;
   printf("\n\t Name\t\tFeedback\t\tUser Id\tBalance\tRegistration time\t");
   for(temp=first;temp!=NULL;temp=temp->next)
   {
printf("\n--------------------------------------------------------------------------------------------------------\n");

   	printf(" \t%s\t\t%s\t\t\t%d\t%d\t\t%s",temp->name,temp->feedback,temp->user_id,temp->balance,temp->reg_time);
   	
   }
		printf("\n--------------------------------------------------------------------------------------------------------\n");
 		printf("Enter key to continue :\t");
 		getch();
		system("cls");
		free(temp);

}


void DelUser(int loc) 
{
	static int a=1000;
	struct user *temp,*temp1;
	
	if(first== NULL)
		printf("n\t\t\t\t\t\t\t\t\t\t\t NO USERS ");
	if(loc==1)
	{
		temp=first;
		temp=temp->next;
		first=temp;
		
	}
	else	
	{
		temp=first;
		if(temp->next==NULL)
			first =NULL;
		else
		{
		
			while(--loc)
		{
			temp1=temp;
			temp=temp->next;	
		}
		temp1->next=temp->next;
	for(temp=first;temp!=NULL;temp=temp->next)
		temp->user_id=++a;
	printf("\n\t\t\t\t\t\t  YOUR ACCOUNT HAS BEEN DELETED");		
		}
	}
	printf("\n\t\t\t\t\t Press any key to continue.. :\t");
	getch();
	system("cls");
	admin();

}

int log_in()
{
	int user_id,ch,cmp,flag=0;
	char password[MAX_SIZE];
		if(first==NULL)
	{
			printf("\n\t\t\t\t\t\t Our Record is empty please be our valuable customer");
			printf("\n\t\t\t\t\t\t Enter 1 to create an account\n\t\t\t\t\t\tEnter 2 to exit \n\t\t\t\t\t\t");
			scanf("%d",&ch);
			if(ch==1)
			{
				printf("\n\t\t Kindly goto admin and register Yourself");
				Sleep(2000);
				system("cls");
			}
			else{
				printf("\t\t\t\t\t\t\t\t\t\t Thanks for visiting the Cafe\n\t you will be redirected in 2 seconds");
				Sleep(2000);
				system("cls");
			}
				
	}
	else
	{
	printf("\n\t\t\t\t\t\t Enter the user id:\t");
	scanf("%d",&user_id);
	struct user *temp,*temp2;
	for(temp=first;temp!=NULL;temp=temp->next)
	{
		if( user_id==temp->user_id)
		{
			flag=1;
			temp2=temp;
			break;
		}
		else
		{
			flag=0;
		}
	}
		if(flag==1)
	 {
		    fflush(stdin);
		    a:
		    printf("\n\t\t\t\t\t\t Enter the password :\t");
			scanf("%s",password);
			cmp=strcmp(password,temp2->userpass);
			if(cmp==0)
			{
				printf("\n\t\t\t\t\t\t Successful Login\n");
				time_t login=time(NULL);
				printf("\n\t\t\t\t\t\t Enter 1 to go to bill :\t");
				while(1)
				{
					scanf("%d",&ch);
					if(ch==1)
					{
						bill(login,temp->user_id);
						break;
					}
					
				}
			}
			else
			{
				printf("\n\t\t\t\t\t\t Please check your credentials and retry again");
				goto a;	
			}	
   	 }
		else if(flag==0)
		{
			printf("\n\t\t\t\t\t\t Sorry Dear ! you do not have an account here\n");
			printf("\n\n\t\t\t\t\t\t Enter 1 to create an account\n\t\t\t\t\t\t Enter 2 to exit \n\t\t\t\t");
			scanf("%d",&ch);
			if(ch==1){
				printf("\n\t\t Kindly goto admin and register Yourself");
				Sleep(2000);
				system("cls");
			}
				
			else{
				printf("\t\t\t\t\t\t\t\t\t\t Thanks for visiting the Cafe\n\t you will be redirected in 2 seconds");
				Sleep(2000);
				system("cls");
			}
			
		}
	 }
		    return 0;
		    
			system("cls");
}

void file_update()
{
	int i=1;
	struct user *temp;
	time_t now=time(NULL);
	char *st=ctime(&now);
	FILE *fptr=fopen("Internet.txt","a+");
	fprintf(fptr,"\n\tDate: %s",st);
	fprintf(fptr,"\nS.No   Name \tID\tFeedback\t\tBalance\t\tRegistration Time");
	for(temp=first;temp!=NULL;temp=temp->next)
	{
		fprintf(fptr,"\n  %d   %s \t %d\t%s\t%d \t%s",i++,temp->name,temp->user_id,temp->feedback,temp->balance,temp->reg_time);
	}
	fprintf(fptr,"\n--------------------------------------------------------------------------------------");
	fclose(fptr);	
}

 
