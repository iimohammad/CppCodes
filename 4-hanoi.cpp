//Tower of hanoi

#include<iostream>		
#include<cstdio>	
#include<cstdlib>
#include <conio.h>		
using namespace std;

int moves(0);

void Hanoi(int , char , char , char );

/////////////////////////////////////////////////////


int main()
{
  int x;
  cout << "Enter the number of discs: " ;
  cin >> x;
  
  Hanoi(x, 'A', 'B', 'C');
  
  cout << "number moves= " << moves <<endl;

  system("pause");
}
///////////////////////////////////////////////////

void  Hanoi(int n, char a, char b, char c)
{
  moves++;
  if(n == 1)
      cout <<  a << " -> " << c << endl;
  else
   {  
    Hanoi(n-1, a, c, b);
    cout << a << " -> " << c << endl;
    Hanoi(n-1, b ,a ,c);
   }
}

