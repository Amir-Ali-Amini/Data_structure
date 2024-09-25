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
template<typename type>
class hashing
{
    friend class input;
public :
    hashing(int nn=201)
    {
        n =nn;
        arr=new type *[n];
        for (int i = 0 ; i < n ; i++) arr[i]=new type [n];
        for (int i = 0 ; i < n ; i++)
        {
            for(int j = 0; j < n ; j++)
                arr[i][j]=0;
        }
    }
    bool add(int i , int j , bool p =true)
    {
        if (p)return ++arr[i][j];
        else if (arr[i][j]!=0) return --arr[i][j];
        else return false;
    }
    type find (int i =0, int j=0 )
    {
        return arr[i][j];
    }

private:
    int n;
    type **arr;
};

int f (int a , int b)
{
    if (a>b)
    {
        if (b==0)return a;
        return f(b , a%b);
    }
    else
    {
        if (a==0)return b ;
        return f(a,b%a);
    }
}
class input
{
public:
    input(int nn )
    {
        n = nn;
        a=new int [n];
        b=new int [n];
    }
    void inputing ()
    {
        for(int i = 0 ; i < n;  i++)
            cin>>a[i];
        for (int i = 0 ; i < n ; i++)
            cin >> b [i];
    }

    void made()
    {
        int i = 0 ;
        while( i < n )
        {
            if(a[i]==0 && b[i]==0) hsh.add(0,0);
            else 
            {
                int q =f(ff(a[i] ), ff(b[i]));
                a[i]/=q;
                b[i]/=q;
                if (a[i]>0 && b[i]<0)
                {
                    b[i]*=-1;a[i]*=-1;
                }
                hsh.add(a[i]+100 , b[i]+100);
            }
            i++;
        }
        
    }
    void find ()
    {
        int max = 0 ; 
        int i = 0 ; 
        while (i<n){
            if(a[i] != 0){
            if(max < hsh.find(a[i] +100 ,b[i] +100 )  ) max = hsh.find(a[i] +100 ,b[i] +100 )  ;
            }
            i++;
        }
        
        max += hsh.find(0,0);
            
        cout<<max ;
    }
    int ff(int a)
    {
        return (a<=0)?-a:a;
    }
private:
    int n ;
    int *a , *b;
    hashing <int> hsh ;
};
int main ()
{
    int n ;cin>>n ;
    input a(n);
    a.inputing();
    a.made();
    a.find();
}