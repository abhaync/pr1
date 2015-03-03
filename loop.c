#include<stdio.h>
#include<stdlib.h>

typedef struct abb
{
	int data;
	struct abb *link;
}node;

node *head;

node *getnode()
{
	return malloc(sizeof(node));
}

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
	}
	else
	{
		temp->link=head;
		head->link=NULL;
		head=temp;
	}
	free(temp);
	temp=NULL;
}


void makeloop()
{
	node *temp,*loop;
	temp=getnode();
	loop=getnode();
	temp=head;
	loop=temp->link;
	loop=loop->link;
	while(temp!=NULL)
	{
		temp=temp->link;
	}
	temp->link=loop;
	free(temp);
	free(loop);
	temp=NULL;
	loop=NULL;
}



int hasLoop( node *startNode )
{
    node *slowNode, *fastNode;
    slowNode = fastNode = startNode;
    while( slowNode && fastNode && fastNode->link )
    {
        if( slowNode == fastNode->link || slowNode == fastNode->link->link )
        {
            return 1;
        }
        slowNode = slowNode->link;
        fastNode = fastNode->link->link;
    }
    return 0;
}

void menu()
{
	int ch;
	int b;
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
		case 3: b=hasLoop(head);
			if(b==1){
			printf("Loop Found\n");
			exit(0);
			}
			else{
			printf("No loop\n");
			exit(0);
			}
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
