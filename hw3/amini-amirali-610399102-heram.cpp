//P name
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
    int sum =0;
    for (int i = 0 ; i < n ; i++)
    {
        st[i]=new int [3];
        cin>>st[i][0]>>st[i][1]>> st[i][2];
        sum +=st[i][2];
    }
    for (int i = 1 ; i < n  ; i++)
    {
        for (int j = i ;j > 0  && st[j][1]<st[j-1][1]   ; j--)
        {
            sp(st,j); 
        }
    }
    int * ans ; 
    sum+=5;
    ans = new int [sum] ; 
    for (int i = 0 ; i < sum ; i++)
    {
        ans [i] = -1;
    }
    for (int i = n-1 ; i>=0 ; i--)
    {
        //cout << i<<" " <<endl;
        for (int j= sum-1; j >0 ; j-- )
        {
            //cout << j <<" ";
            if (ans[j]!=-1)
            {
                if (st[ans[j]][0]<st[i][1])
                {
                    ans[j+st[i][2]]=i;
                }
            }
        }
        ans[st[i][2]]=i;
    }
   
    for (int j= sum-1; j >0 ; j-- )
    {
        if (ans[j]!=-1)
        {
            cout<<j ;
            return 0 ;
        }
    }
    
    return 0 ;
}