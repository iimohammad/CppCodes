//merge sort
#include <iostream>
#include <fstream>
#include <conio.h>
using namespace std;
///////////////////////////
void merge(int [], int , int , int );
void mergeSort(int [], int , int );

////////////////////////
int main()
{
    int a[] = {38, 27, 43, 3, 9, 82 ,10};
    int n = sizeof(a)/sizeof(a[0]);  //n=7

    cout<<"Given array is \n";
    for (int i=0; i < n; i++)
        cout<<a[i]<<'\t';
    cout<<endl;

    mergeSort(a, 0, n-1);

    cout<<"\nSorted array is \n";
    for (int i=0; i < n; i++)
        cout<<a[i]<<'\t';
    cout<<endl;
    
    getch();
}

/////////////////////////////////////////////////////
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
        
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    
    i = 0; 
    j = 0; 
    k = l; 
    
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there  are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
//////////////////////////////////////////////////////////////////
void mergeSort(int x[], int l, int r)   // l=0 , r=6  , m=0+3=3
{
	int m;  
    if (l < r)
    {
        m = l+(r-l)/2;
        mergeSort(x, l, m);
        mergeSort(x, m+1, r);
        merge(x, l, m, r);
    }
}


