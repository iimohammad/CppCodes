/*
 Snake

             W
        A         D
             S
*/

#include <iostream>
#include <conio.h>
#include <cstdlib>
using namespace std;
/////////////////////////////////////////
void move(int dx, int dy);
void produce();            //generate food
char getvalue(int value);
////////////////////////////
int    food = 1;
int    hx;  //headx
int    hy;  //heady
int    d;   //direction

const int w  = 15;        //weight
const int h  = 20;        //height
const int size = w * h;
int   a[size];            // map

bool   r;  
   
/////////////////////////////////
main()
{
    // Places the initual head location in middle of a
    hx = w / 2;
    hy = h / 2;
    a[hx + hy * w] = 1;

    // Places top and bottom walls 
    for (int x = 0; x < w; ++x) 
	{
        a[x] = -1;
        a[x + (h - 1) * w] = -1;
    }

    // Places left and right walls
    for (int y = 0; y < h; y++) 
	{
        a[0 + y * w] = -1;
        a[(w - 1) + y * w] = -1;
    }
    // Generates first food
    
	produce();
    
    r = true;
    while (r) 
	{
      if (kbhit())          // If a key is pressed
      {
       switch (getch()) 
    	{
		    case 'w':   if (d != 2) d = 0;  break;
		    case 'd':   if (d != 3) d = 1;  break;
		    case 's':   if (d != 4) d = 2;  break;
		    case 'a':   if (d != 5) d = 3;  break;
    	}
   	  }
	 switch (d)
     {
	    case 0: move(-1, 0);  break;
	    case 1: move(0 , 1);  break;
	    case 2: move(1 , 0 ); break;
	    case 3: move(0 ,-1);  break;
     }

      // Reduce snake values on a by 1
      for (int i = 0; i < size; i++) 
         if (a[i] > 0) 
		    a[i]--;
		 
		system("cls"); 
		
		for (int x = 0; x < w; ++x) 
	    {
        	for (int y = 0; y < h; ++y) 
            	cout << getvalue(a[x + y * w]);
            	
            cout << endl;
        }      
        
        _sleep(500);        // wait 0.5 seconds
    }

    cout << "\t\tGame over!" << endl << "\t\tscore= " << food;
    cin.ignore();    
}

////////////////////////////////
void produce() 
{
    int x = 0;
    int y = 0;
    do {
        x = rand() % (w - 2) + 1;
        y = rand() % (h - 2) + 1;
        // If location is not free try again
    } while (a[x + y * w] != 0);

    // Place new food
    a[x + y * w] = -2;
}

//////////////////////////////////////////
char getvalue(int v)
{
    if (v > 0) 
	    return 'o';
	    
    switch (v) 
	{
      case -1: return '#';        // Return wall
      case -2: return 'O';        // Return food
    }
}

//////////////////////////////
void move(int dx, int dy) 
{
    int x = hx + dx;
    int y = hy + dy;

    // Check if there is food at location
    if (a[x + y * w] == -2)
	{
        food++;                
        produce();        
    }

    // Check location is free
    else if (a[x + y * w] != 0) 
	{
        r = false;
    }
    // Move head to new location
    hx = x;
    hy = y;
    a[hx + hy * w] = food + 1;
}


