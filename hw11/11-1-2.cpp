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
class f 
{
public:
    f(int nn , int kk)
    {
        n=nn;
        k=kk;
        input=new int [n];
    }
    void inp()
    {
        for (int i = 0 ; i < n; i++)
        {
            cin >> input[i];
        }
    }
    int findd()
    {
        return find(input , k , n);
    }
private:
    int *input , n , k;
    int find (int *arr , int k , int n )
    {
        // cout<< " arr :  ";
        // for(int i = 0 ; i < n ; i++)
        // {
        //     cout<< arr[i] << ' ';
        // }
        // cout<< endl;
        // cout<< "k ::   " << k << endl;
        if (n==1)
        {
            return arr[0];
        }
        int index=rand()%n;
        // cout<< "index :: " << index << endl;
        int s =0 , new_index ;
        int *ans=new int[n];
        for(int i = 0 ; i < n; i ++)
        {
            if (i==index) continue;
            if (arr[i] <=arr[index])
            {
                ans[s++]=arr[i];
                // cout<< arr[i]<< endl;
            }
        }
        new_index=s;
        // cout<< "newindex::: "<<new_index<<endl;
        ans[s++]=arr[index];
        for (int i = 0 ; i < n ;i++)
        {
            if (i==index) continue;
            if (arr[i] >arr[index])
            {
                ans[s++]=arr[i];
            }
        }
        // for (int i = 0 ; i < n ; i++ )
        //     cout<< ans[i]<< " , " ;
        // cout<< endl;
        if (new_index==k-1)return ans[new_index];
        else if(k-1<new_index)
        {
            int *anss = new int [new_index];
            for(int i = 0 ; i < new_index ; i++)
                anss[i]=ans[i];
            return find(anss , k , new_index);
        }
        else
        {
            int *anss = new int [n-new_index-1];
            for(int i = 0 ; i < n-new_index-1 ; i++)
                anss[i]=ans[new_index+1+i];
            return find(anss , k-new_index-1 ,n-new_index-1);
        }
    }
};


int main ()
{
    int n , k ;
    cin >> n >> k ;
    f ff(n , k);
    ff.inp();
    cout<<ff.findd();
    return 0 ;
}