// Tic Tac Toe
#include <iostream>
#include <string.h>
#include <conio.h>
using namespace std;

char a[10] = {'o','1','2','3','4','5','6','7','8','9'};

void draw();
int  check();
////////////////////////////////////////////////////////////
int main()
{
	int  p = 1;    // player
	int  i,choice;
	char mark;
	cout << "\t\t\tTic Tac Toe \n\n";
	cout << "\t\t\t p1 (X)\n" ;
	cout << "\t\t\t p2 (O)" ;

	do
	{
		draw();
		p=(p %2 ) ? 1:2;
		
		mark=(p == 1) ? 'X' : 'O';
		
		cout << "\np " << p << ":  ";
		cin >> choice;
				
		if (choice == 1 && a[1] == '1')
			a[1] = mark;
		else if (choice == 2 && a[2] == '2')
			a[2] = mark;
		else if (choice == 3 && a[3] == '3')
			a[3] = mark;
		else if (choice == 4 && a[4] == '4')
			a[4] = mark;
		else if (choice == 5 && a[5] == '5')
			a[5] = mark;
		else if (choice == 6 && a[6] == '6')
			a[6] = mark;
		else if (choice == 7 && a[7] == '7')
			a[7] = mark;
		else if (choice == 8 && a[8] == '8')
			a[8] = mark;
		else if (choice == 9 && a[9] == '9')
			a[9] = mark;
		else {cout<<"Invalid move "; p--;getch();}
		i=check();
		p++;
	}while(i==-1);
	
	draw();
	
	if(i==1)
		cout<<"==>\a p"<<--p<<" win ";
	else
		cout<<"==>\a Game draw";
		
	getch();
	return 0;
}
//////////////////////////////////////

int check()
{
	if (a[1] == a[2] && a[2] == a[3])     	return 1;  //GAME IS OVER WITH RESULT
	else if (a[4] == a[5] && a[5] == a[6])	return 1;
	else if (a[7] == a[8] && a[8] == a[9])	return 1;
	
	else if (a[1] == a[4] && a[4] == a[7])	return 1;
	else if (a[2] == a[5] && a[5] == a[8])	return 1;
	else if (a[3] == a[6] && a[6] == a[9])	return 1;
	
	else if (a[1] == a[5] && a[5] == a[9])	return 1;
	else if (a[3] == a[5] && a[5] == a[7])	return 1;
	
	if ( a[1] != '1' && a[2] != '2' && a[3] != '3' && a[4] != '4' && 
	     a[5] != '5' && a[6] != '6' && a[7] != '7' && a[8] != '8' && a[9] != '9')
	                  return 0;              //GAME IS OVER AND NO RESULT
	else
	    return -1;   //GAME IS IN PROGRESS
}

/////////////////////////////////////////////////////////

void draw()
{
	cout << endl;
	cout << "  " << a[1] << "  |  " << a[2] << "  |  " << a[3] << endl;
	cout << "_____|_____|_____" << endl;
	cout << "  " << a[4] << "  |  " << a[5] << "  |  " << a[6] << endl;
	cout << "_____|_____|_____" << endl;
	cout << "  " << a[7] << "  |  " << a[8] << "  |  " << a[9] << endl;
}

