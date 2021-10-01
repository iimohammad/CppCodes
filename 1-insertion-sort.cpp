 /*
 Insertion Sort
 41    67    34    0    69          
 
 i=2 , key=34
   j=1 : 41    67    67    0    69
   j=0 : 41    41    67    0    69
         34    41    67    0    69
 
 i=3: key=0
   j=2:   34    41   67   67   69
   j=1:   34    41   41   67   69
   j=0:   34    34   41   67   69
          0     34   41   67   69
 
 i=4 , key=69
 
 */
 
#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <iomanip>
using namespace std;

main()
{
    int n;
    cout <<"Enter n:" ;
    cin >> n;
    int a[n];
    
    for(int i=0;i<n;i++)
         a[i]=rand() % 100;
        
    for(int i=0;i<n;i++)        
        cout<<setw(5)<< a[i];
   
	//sort        
    for(int i=1;i<n;i++)        
    {
        int j;
        int key=a[i];
        
        for(j=i-1;j>=0;j--)
        {
            if(a[j] > key)
                a[j+1]=a[j];
            else
                break;
        }
        a[j+1]=key;
    }
    
    cout<<endl<<"sort:";

    for(int i=0;i<n;i++)        
        cout<<setw(5)<<a[i];
        
    getch();
    
}
