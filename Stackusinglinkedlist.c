//Aim:To implement Stack operations using Linked List in C, including push, pop and display functions, by dynamically creating and managing nodes as per the given algorithm.
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node*next;
};
struct node*CreateNode(int data)
{
	struct node*newnode=(struct node*)malloc(sizeof(struct node));
	if(!newnode)
	{
	printf("memory allocation failed!\n");
	return NULL;
	}
	newnode->data=data;
	newnode->next=NULL;
	return newnode;
}
void push(struct node**top,int,data)
{
	struct node*newnode = CreateNode(data);
	newNode -> next=*top;
	*top = newnode;
	printf("pushed %d successfully",data );
}
void pop(struct node**top)
{
	if(*top==NULL)
	{
	printf("stack underflow!pop not position ")
	return ;
	}
	struct node*temp=*top
	printf("popped %d\n",temp->data);
	*top z(*top)->next
	free(temp);
}
void peek(struct node*top)
{
	if(top==NULL)
	{
	printf("stack is empty\n");
	}
	else
	{
	printf("top element =%d\n",top->data)
	}
}
void display(struct node*top)
{
	if(top==NULL)
	{
	printf("stack is empty\n");
	return ;
	}
	struct node*temp=top;
	printf("\n stack (top to bottom);\n");
	while(temp!=NULL)
	{
	printf("null\n");
	}
	int main()
	{
		struct node*top=NULL;
		int choice data 
		while(1)
		{
			printf("\n----stack using singly linked list---\n");
			printf("1.push\n")
			printf("2.pop\n")
			printf("3.peek\n")
			printf("4.display")
			printf("5.exit\n")
			printf("enter your choice\n");
			scanf("%d",&choice)
			switch(choice)
			{
				case 1:
					printf("enter value to push:")
					scanf("%d",&data)
					push(&top,data)
					break;
				case 2:
					pop(top);
					break;
				case 3:
					peek(top)
					break;
				case 4:
					display(top);
					break;
				case 5:
					printf("exiting -----\n");
					exit(0)
				default:
					printf("invalid choice!try again\n");
			}
		}
	}
	return 0;
}
