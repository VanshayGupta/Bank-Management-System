#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>

struct Node{
	struct Node *next;
	int balance;
	int number;
	char name[20];
	char account[20];
}*start;

void create()
{
	struct Node *temp,*newnode,*post;
	char acc_name[20], acc_type[20];
	int acc_balance,acc_number;
	printf("Enter the name of the account holder\n");
	scanf("%s",&acc_name);
	printf("Enter the type of account\n");
	scanf("%s",&acc_type);
	printf("Enter the account balance\n");
	scanf("%d",&acc_balance);
	printf("Enter the account number\n");
	scanf("%d",&acc_number);
	newnode=(struct Node *)malloc(sizeof(struct Node));
	strcpy(newnode->name,acc_name);
	strcpy(newnode->account,acc_type);
	newnode->balance=acc_balance;
	newnode->number=acc_number;
	if(start==NULL)
	{
		start=newnode;
	}
	else 
	{
		temp=start;
		while(temp->number<newnode->number)
		{
			temp=temp->next;
		}
		if(temp==start)
		{
			newnode->next=start;
			start=newnode;
		}
		else
		{
			post=temp->next;
			temp->next=newnode;
			newnode->next=post;
		}
	}
}

void delete()
{
	struct Node *temp,*prev;
	int val;
	printf("Enter the account number you want to delete\n");
	scanf("%d",&val);
	temp=start;
	while(temp!=NULL&&temp->number!=val)
	{
		prev=temp;
		temp=temp->next;
	}
	if(temp==start)
	{
		start=start->next;
		free(temp);
		printf("The deleted value is %d\n",val);
	}
	else if(temp->number==val)
	{
		prev->next=temp->next;
		free(temp);
		printf("The deleted value is %d\n",val);
	}
	else
	{
		printf("Account not found\n");
	}
}

void transaction()
{
	struct Node *temp;
	int val,transact,choice;
	printf("Enter the account number\n");
	scanf("%d",&val);
	temp=start;
	while(temp!=NULL&&temp->number!=val)
	{
		temp=temp->next;
	}
	if(temp->number==val)
	{
		printf("Enter 1 for credit and 2 for debit\n");
		scanf("%d",&choice);
		printf("Enter the amount\n");
		scanf("%d",&transact);
		switch(choice)
		{
			case 1:
			{
				temp->balance+=transact;
				break;
			}
			case 2:
			{
				temp->balance-=transact;
				break;
			}
		}
	}
	else
	{
		printf("Account not found\n");
	}
	
}

void check()
{
	struct Node *temp;
	int val;
	temp=start;
	printf("Enter the account number whose details you want to check\n");
	scanf("%d",&val);
	while(temp!=NULL&&temp->number!=val)
	{
		temp=temp->next;
	}
	if(temp->number==val)
	{
		printf("%d\n%s\n%s\n%d\n",temp->number,temp->name,temp->account,temp->balance);
	}
	else
	{
		printf("Account not found\n");
	}
}

void update()
{
	struct Node *temp;
	char edit_name[20],edit_type[20];
	int val,choice,edit_balance;
	temp=start;
	printf("Enter the account number whose details you want to update\n");
	scanf("%d",&val);
	while(temp!=NULL&&temp->number!=val)
	{
		temp=temp->next;
	}
	if(temp->number==val)
	{
		printf("Enter 1 to update the name, 2 to update the balance and 3 to update the type of account");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				{
					printf("Enter the new name");
					scanf("%s",&edit_name);
					strcpy(temp->name,edit_name);
					break;
				}
			case 2:
				{
					printf("Enter the new balance");
					scanf("%d",&edit_balance);
					temp->balance=edit_balance;
					break;
				}
			case 3:
				{
					printf("Enter the new account type");
					scanf("%s",&edit_type);
					strcpy(temp->account,edit_type);
					break;
				}
		}
		printf("%d\n%s\n%s\n%d\n",temp->number,temp->name,temp->account,temp->balance);
	}
	else
	{
		printf("Account not found\n");
	}
}

void display()
{
	struct Node *temp;
	temp=start;
	printf("List Of Customers\n");
	while(temp!=NULL)
	{
		printf("%d\t%s\n%s\t%d\n",temp->number,temp->name,temp->account,temp->balance);
		temp=temp->next;
	}
}

void main()
{
	int choice;
	printf("\t\t WELCOME TO THE BANK MANAGEMENT SYSTEM PORTAL\n");
	do
	{
		printf("Operation Menu\n 1.Create an account 2.Delete an account 3.Make a transaction 4.View the details of an account 5.Update the details of an account 6.View the customer list 7.Exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				{
					create();
					display();
					break;
				}
			case 2:
				{
					delete();
					break;
				}
			case 3:
				{
					transaction();
					break;
				}
			case 4:
				{
					check();
					break;
				}
			case 5:
				{
					update();
					break;
				}
			case 6:
				{
					display();
					break;
				}
		}
	}while(choice!=7);
	printf("Thank you for visiting the portal!\nGoodbye!");
}