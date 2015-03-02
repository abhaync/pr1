#include<stdio.h>
#include<stdlib.h>

typedef struct abb
{
	int data;
	struct abb *link;
}node;

node *head=NULL;

node *getnode()
{
	return malloc(sizeof(node));
}

node *prev;

void insert()
{
	node *temp;
	temp=getnode();
	temp->data=rand()%10;
	temp->link=NULL;
	if(head==NULL)
	{
		head=temp;
		head->link=NULL;
		prev=head;
	}
	else
	{
		prev->link=temp;
		prev=prev->link;
		prev->link=NULL;
	}
	free(temp);
	temp=NULL;
}


void makeloop()
{
	node *temp,*loop;
	while(temp!=NULL)
	{
		temp=temp->link;
	}
	temp->link=head;
}

void detloop()
{
	node *tmp1,*tmp2;
	tmp1=head;
	tmp2=head;
	while(1)
	{
		tmp1=tmp1->link;
		tmp2=(tmp2->link)->link;
		if(tmp1==tmp2)
		{
			printf("Loop Found\n:");
			exit(0);
		}
		if(tmp1==NULL||tmp2==NULL)
		{
			printf("No Loop\n");
			exit(0);
		}
	}
}

void menu()
{
	int ch;
	printf("1.Insert\n");
	printf("2.Makeloop\n");
	printf("3.Detect Loop\n");
	printf("Enter your choice:\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1: insert();
			break;
		case 2: makeloop();
			break;
		case 3: detloop();
			break;
		default : printf("Invalid Choice\n");
			  break;
	}
}

void main()
{
	while(1)
	menu();
}
