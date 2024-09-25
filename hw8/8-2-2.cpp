//P name
//Fig : 
//use ?:
//date
//amiraliamini 610399102 UT-CS-99

//=================================================================================

#include <iostream>
#include<math.h>
using namespace std;


//----------------------------------------------------------------------------------
int main () 
{
    int nn ; 
    cin >> nn; 
    int n = pow(2,nn);
    int *arr ;
    arr=new int [n];
    for(int i = 1 ; i < n ; i ++)
    {
        cin >> arr [ i ];
    }
    int a , b ;
    cin >> a >>  b ;
    int aa ,bb  ; 
    for ( int i = 1 ; i < n ; i++ )
    {
        if (arr[i] == a)
            aa=i ;
        if (arr[i] == b)
            bb=i;
    }
    if (aa>bb)
    {
        int t =aa ;
        aa=bb;
        bb=t;
    }
    int lgA = log2(aa);
    while(bb>=pow(2,lgA)*2)
        bb/=2;
    while(aa!=bb)
    {   
        aa/=2;
        bb/=2;
    }
    if (aa==0)
        aa=1;
    cout<<arr[aa];
    return 0 ;
}