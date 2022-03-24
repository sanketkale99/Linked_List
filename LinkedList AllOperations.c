#include <stdio.h>
#include <stdlib.h>
struct node
{
	
	// these are the two main component of the node 
	// node contsin the data and the address 
	// also in a single node we can store whatever that we want more data 
	int data;
	struct node *address_next; // this place is to store the address of the next node in previous 
}*start,*newnode,*current,*previous,*temp,*temp2,*temp3; // we have taken the different pointer variable to store the address of the nodes 
void create(int);
void display();
void insertbeg(int); // which data we have to passs
void insertmiddle(int ,int);
void insertend(int);
void deletefirst();
void deletemiddle(int);
void deleteend();
void search(int);

int main()
{
	int n,ch,loc,elm;
	do
	{
		printf("1]-create\n2]-display\n3]-insert at beg\n4]-insert at middle\n5]- insert at end\n6]-delete first node\n7]-delete middle noden8]-delete last node\n9]-search element\n10]sort element");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\nEnter element for the linked list :-");
				scanf("%d",&n);
				create(n);
				display();
				break;
			case 2:
				display();	
				break;
			case 3:
				printf("\nEnter the element to insert at the beg :-");
				scanf("%d",&n);
				insertbeg(n);
				break;
			case 4:
				printf("\nEnter the element to insert  :- ");
				scanf("%d",&n);
				printf("\n Enter Postion of element  :-");
				scanf("%d",&loc);
				insertmiddle(n,loc);
				break;	
			case 5:
				printf("\nEnter the element to insert at the end of the linked list :-");
				scanf("%d",&n);
				insertend(n);
				break;
			case 6:
				deletefirst();
				break;	
			case 7:
				printf("\nEnter the location of the node to delete it :-");
				scanf("%d",&loc);
				deletemiddle(loc);
				break;
			case 8:
				deleteend();
			case 9:
				printf("\nEnter the element to search in the linked list :-");
				scanf("%d",&elm);
				search(elm);
				break;		
		}
		printf("\nDo you want to continue press 1:");
		scanf("%d",&ch);
	}while(ch==1);
	return 0;
}
void create(int n)
{
	newnode =malloc(sizeof(struct node)); // this will allocate the memory for the newnode
	newnode->data=n;
	newnode->address_next=NULL;// initially it is null its a first.
	if(start==NULL)
	{
		start=newnode; // start become a newnode;	
	}
	else
	{
		current=start;
		while(current->address_next!=NULL) //NULL!=NULL false next time 1000!=NULL
		{
			current = current->address_next; // now current is become who having a address of current previously.
		}
		current->address_next=newnode;
	}
}
void display()
{
	if(start==NULL)
	{
		printf("\nlinked list is empty.");
	}
	else
	{
		current = start; // start alwasys start from the initial.
		while(current!=NULL)
		{
			printf("<-| %d | %u | ",current->data,current->address_next);
			current = current->address_next; // who having a address of the current become the current.
		}
	}
}
void insertbeg(int n)
{
	newnode = malloc(sizeof(struct node));
	newnode->data = n;
	newnode->address_next=start;
	start=newnode; // start become a newnode;
}
void insertmiddle(int n,int loc)//55  4
{
	// suppose location is 4
	int cnt=1;
	current=start;			//where is our pointer now 
	previous=NULL;
	while(cnt<loc)
	{
		previous=current; // previous become current
		current=current->address_next; // current move to next;
		cnt++;
	}
	newnode = malloc(sizeof(struct node));
	newnode->data = n;
	newnode->address_next=current;
	previous->address_next= newnode; // this is pointer variable which store the address.
	
}
void insertend(int n)
{
	newnode = malloc(sizeof(struct node));
	newnode->data = n;
	newnode->address_next = NULL;
	if(start==NULL)
	{
		start=newnode;
	}
	else
	{
		current=start;
		while(current->address_next!=NULL) // to find the NULL in current.
		{
			current= current->address_next; // current moving to the next node which having the present addrss.
		}
		current->address_next=newnode; // address  of the newnode is place in the previous node.
	}
}
void deletefirst()
{
	temp=start; // temp will store the address of the start and start will ( now start is empty so will make new start)
	start = start->address_next; // this is point to next node which is become a start.
	printf("\n First node is delete sucessfully..!!");
}
void deletemiddle(int loc)
{
	int cnt=1; // here i have strted the index from the 1 so it will be current node that we have to delete 
	current=start;
	previous=NULL;
	while(cnt<loc)
	{
		previous=current; // current become previous
		current=current->address_next; // next become a current
		cnt++;
	}
	// here deleting means storing in the temp and later on making the free
	temp2=current; // found current is stored in temp2;
	current=current->address_next; // next node become a current which is next to the current
	previous->address_next=current; // address of the new current is stored in the address of the previous
	//temp2->data=NULL;
	free(temp2); // make a memory free
	printf("\n node at %d location deleted sucessfully ...!!",loc);
}
void deleteend()	//end node will be delete....
{
	previous=NULL;
	current=start;					//curr is point to first node of list 
	while(current->address_next!=NULL)
	{
		previous=current;
		current=current->address_next;
	}
	printf("\n last Node is :- | %d | %u |->",current->data,current->address_next);
	printf("\n second last node is :- | %d | %u | -> ",previous->data,previous->address_next);
	temp3=current;			//		last node is in temp now
	previous->address_next=NULL;		//break the link of nodes and second last node to null
	free(temp3);			//delete the last node
	printf("\n Last node Is deleted ...!!");
}
// for searching enter the element
void search(int elm)
{
	int flag=0;
	current=start;	//current become a start.
	int count=0;
	while(current!=NULL)
	{
		count++;
		if(current->data=elm)
		{
			flag=1;
			break;
		}
		current=current->address_next;
	}
	if(flag)
	{
		printf("\n %d Element found in the linked list at %d location ",elm,count);
	}
	else
	{
		printf("\nElement not found in the linked list...");
	}
}
