//P name: domino
//Fig : 
//use ?:
//date
//amiraliamini 610399102 UT-CS-99

//=================================================================================

#include <iostream>
#include <string>
#include<vector>
#include <iomanip>
#include<cstdlib>
using namespace std;


//----------------------------------------------------------------------------------

void sp(int ** st , int m)
{
    int a ,b , c ;
    a=st[m-1][0];           b=st[m-1][1];           c=st[m-1][2];
    st[m-1][0]=st[m][0];    st[m-1][1]=st[m][1];    st[m-1][2]=st[m][2];
    st[m][0]=a;             st[m][1]=b;             st[m][2]=c;
}

void print (int **st ,int n )
{
    for (int i = 0 ; i < n ; i++)
    {
        cout << st[i][0]<<" "<<st[i][1]<<endl;
    }
}

int main ()
{
    int n ; 
    cin >> n ; 
    int **st;
    st=new int *[n];
    for (int i = 0 ; i < n ; i++)
    {
        st[i]=new int [3];
        st[i][0]=i;
        cin>>st[i][1]>> st[i][2];
    }
    for (int i = 1 ; i < n  ; i++)
    {
        for (int j = i ;j > 0  && st[j][1]<st[j-1][1]   ; j--)
        {
            sp(st,j); 
        }
    }
    int * ans ; 
    ans = new int [n] ; 
    for (int i = 0 ; i < n ; i++)
    {
        ans [i] = 1;
    }
    for (int i = 0 ; i < n ; i++)
    {
        int tool = st[i][1]+st[i][2];
        for (int j = i+1 ; j<n ; j++)
        {
            if (st[j][1]<tool)
            {
                ans[st[i][0]]++;
                if (st[j][1]+st[j][2]>tool)
                    tool = st[j][1]+st[j][2];
            }
            else 
                break ;
        }

    }
    for (int i = 0 ; i < n ; i++)
        cout << ans [i] <<" "; 
    return 0 ;
}