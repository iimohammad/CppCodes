 /* Selection Sort
             41    67    34    0    69          
 i=0:
    j=1  :   41    67    34    0    69
    j=2  :   34    67    41    0    69
    j=3  :   0     67    41    34   69
    j=4  :   0     67    41    34   69
 
 i=1: 
    j=2  :   0     41     67     34    69
    j=3  :   0     34     67     41    69
    j=4  :   0     34     67     41    69

 i=2:
    j=3  :   0     34     41     67    69
    j=4  :   0     34     41     67    69
  
 i=3:
    j=4  :   0     34     41     67    69
 */
#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <iomanip>
using namespace std;

int main()
{
    int n;
    cout<<"Enter n:" ;
    cin>>n;
    int a[n];
    
    for(int i=0;i<n;i++)
        a[i]=rand()%100;
        
    for(int i=0;i<n;i++)
       cout<<setw(5)<<a[i];
   
    cout<<endl;
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a[i] > a[j])
            {
                int temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
    
    cout<<endl<<"sort:" <<endl;

    for(int i=0;i<n;i++)
        cout<<setw(5)<<a[i];    
    
    getch();
    return 0;
}
