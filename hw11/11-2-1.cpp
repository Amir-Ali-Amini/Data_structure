//P name
//Fig : 
//use ?:
//date
//amiraliamini 610399102 UT-CS-99

//=================================================================================

#include <iostream>
using namespace std;


//----------------------------------------------------------------------------------
class cls
{
public:
    cls(int nn )
    {
        n=nn;
        arr=new int [10001];
        for (int i=0 ; i < 10001 ; i++)
        {
            arr[i]=0;
        }
        arrr=new int[n];
    }
    void input()
    {int t;
        for (int i = 0 ; i < n; i ++)
        {
            cin>>t;
            arr[t]++; 
        }
    }

    void sort()
    {
        int j =0;
        for (int i = 0 ; i < n ; i++)
        {
            while(arr[j]==0)
                j++;
            arr[j]--;
            arrr[i]=j;
        }
    }
    int find()
    {
        int ans = 0 ;
        for(int i = 0 ; i < n ; i+=2)
        {
            ans+=arrr[i+1]-arrr[i];
        }
        return ans;
    }
private:    
    int n ;
    int *arr , *arrr ;
};  

int main () 
{
    int n ; 
    cin >> n ; 
    cls c(n);
    c.input();
    c.sort();
    cout<<c.find();
    return 0 ;
}