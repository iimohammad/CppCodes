/*
 Binary Search Tree
                        5
                    /      \
			       2        8
			     /  \         \
                1    3         9
 
*/

#include<iostream>
#include<conio.h>
using namespace std;

struct tree
 {
  int   data;
  tree  *left;
  tree  *right;
 }*p,*q,*node;
 
  int x;
  
  void  search();
  void  rightcheck();
  void  leftcheck();

//////////////////////////////////////////
  
main()
   {
    node = new tree;
    cout<<" Enter root: ";
    cin>> node->data;
    p=node;
    q=p;
    node->left = NULL;
    node->right= NULL;
    cout<<"   GIVE : ";
    cin>>x;
    search();
    
    while(x!=0)
	{
	 if(x > p->data)
	    rightcheck();
	 else
	    leftcheck();
	    
	 cout<<"   GIVE : ";
	 cin>>x;
	 search();
	 p=node;
    }
    getch();
}
      
//////////////////////////////////////////

void rightcheck()
 {
	 if(p->right==NULL)
	   {
	    cout<<"    "<< x <<" IS THE  RIGHT  of "<< q->data <<endl;
	    p->right = new tree;
	    p = p->right;
	    
		p->data  = x;
	    p->left  = NULL;
	    p->right = NULL;
	    
		q = node;
	   }
	 else
	    {
	     if(x > p->data)
	      {
	       p = p->right;
	       q = p;
	       if(x > p->data)
				rightcheck();
			else
				leftcheck();
	      }
	     else
	      {
			p=p->left;
			q=p;
			leftcheck();
	      }
	    }
	}

//////////////////////////////////////////
void leftcheck()
{
		 if(p->left == NULL)
		  {
		   cout<<"   "<<x<<" IS THE LEFT of "<<q->data<<endl;
		   p->left = new tree;
		   p = p->left;
		   p->data  = x;
		   p->right = NULL;
		   p->left  = NULL;
		   q = node;
		  }
	 else
	 {
	   if(x<p->data)
	    {
			p = p->left;
			q = p;
			if(x > p->data)
				rightcheck();
			else
				leftcheck();
	    }
	    else
	      {
			p = p->right;
			q = p;
			rightcheck();
		  }
	}
}
//////////////////////////////////////////

void search()
{
	p=node;
	while(p != NULL)
	{
	  if(x == p->data)
	    {
	    	cout << "not insertable.";
	    	cout << "\nInsert: ";
	    	cin >> x;
	    	search();
	    	break;
	    }
	  else
	  {
	    	if(x > p->data)
				p = p->right;
	    	else
				p = p->left;
	  }
    }
	 p = node;

}

