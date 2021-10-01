/* link list

    17,1000  ->   20,500  ->  18 ,NULL
    
*/

#include <iostream>
#include <fstream>
#include <conio.h>
using namespace std;

struct node
{
	int    data;
	node  *next;
}*start=NULL;


////
void  create(int );
void  insert ();
void  del();
void  traverse();
int   count(node *);
////

main()
{
	int ch, n;
	while(1)
	{
		cout << endl;
		cout << "1. Create a list "<<endl;
		cout << "2. Insert " <<endl;
		cout << "3. Delete " <<endl;
		cout << "4. Traverse " <<endl;
		cout << "5. Count " <<endl;
		cout << "6. Exit "  <<endl;
		cout << "\n\nEnter your choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				if(start == NULL)
				{
					cout<<"Number of nodes : ";
					cin>>n;
					create(n);
				}
				else
					cout<<"List is already created..";
				break;
				
			case 2:
				insert();
				break;
				
			case 3:
				del();
				break;
				
			case 4:
				traverse();
				break;
				
			case 5:
				cout<<count(start);
				break;
				
			case 6 :
				exit(0);
		}
	}
}
///////
void create(int K)
{
	int   i;
	node  *n;
	node  *temp;
	
	for(i = 0; i < K; i++)
	{
	    n=new node;
		cout <<"\nEnter data: ";
		
		cin >> n -> data;
		n -> next = NULL;
		
		if(start == NULL)
			start = n;
		else
		{
			temp = start;
			while(temp -> next != NULL)
				temp = temp -> next;
			temp -> next = n;
		}
	}
}
///////
void insert ()
{
	node *n;
	n = new node;
	
	cout <<"\nEnter data: ";
	
	cin >> n -> data;
	n -> next = NULL;
	
	if(start == NULL)
		start = n;
	else
	{
		n -> next = start;
		start = n;
	}
}

void del()
{
	node *temp;
	
	if(start == NULL)
	{
		cout<<"No nodes are exist.."<<endl;
		return ;
	}
	else
	{
		temp = start;
		start = start -> next;
		delete temp;
		cout<<"Node deleted "<<endl;
	}
}


void traverse()
{
	node *temp;
	
	temp = start;
	cout<<"The contents of List "<<endl;
	if(start == NULL)
	{
		cout<<"Empty List"<<endl;
		return;
	}
	else
	{
		while(temp != NULL)
		{
			cout << temp -> data <<'\t';
			temp = temp -> next;
		}
	}
	cout<<endl<<endl;
}
///////
int count(node *p)
{
	int c=0;
	while(p != NULL)
	{
		c++;
		p = p -> next;
	}
	return (c);
}

