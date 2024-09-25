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

template<typename nodeType>
class heap
{
public:
    heap(int nn )
    {
        n=nn ;
        arr=new nodeType [n*2+1];
        arrT=new int [n];
        for(int i = 0 ; i < 2*n+1 ; i ++)
        {
            arr[i]=-100;
        }
        mid = (nn+1)/2;
    }

    void input()
    {
        for (int i =  1 ; i <= n ; i++)
        {
            cin >> arr[i];
            arrT[i-1]=arr[i];
        }
    }

    void soaping(int i ,int j )
    {
        int t =arr[i];
        arr[i]=arr[j];
        arr[j]=t;
    }
    void heapify()
    {
        for(int i=n; i>=1 ; i --)
        {
            int j = i ; 
            while(arr[j]<arr[2*j] || arr[j]<arr[2*j+1])
            {
                if(arr[2*j]<arr[2*j+1] && 2*j+1<=n)
                {   
                    soaping(j , 2*j+1);
                    if (j==mid)
                    {
                        mid=2*j+1;
                    }
                    if (2*j+1==mid)
                        mid=j;
                    j=2*j+1;
                }
                else 
                {
                    if(2*j<=n)   
                    {
                        soaping(j , 2*j);
                        if (j==mid)
                        {
                            mid=2*j;
                        }
                        if (2*j==mid)
                            mid=j;
                        j=2*j;
                    }
                    else 
                        break;
                }
                //cout<< "\n" << i<<"  ---------------------------------------------------------\n";print();
            }
        }
    }
    nodeType removeFtomFront()
    {
        nodeType ans = arr[1] ;
        arr[1]=arr[n];
        arr[n--]=-100;
        int j = 1 ; 
        while(arr[j]<arr[2*j] || arr[j]<arr[2*j+1])
        {
            if(arr[2*j]<arr[2*j+1] && 2*j+1<=n)
            {   
                soaping(j , 2*j+1);
                if (j==mid)
                {
                    mid=2*j+1;
                }
                if (2*j+1==mid)
                    mid=j;
                j=2*j+1;
            }
            else 
            {
                if(2*j<=n)   
                {
                    soaping(j , 2*j);
                    if (j==mid)
                    {
                        mid=2*j;
                    }
                    if (2*j==mid)
                        mid=j;
                    j=2*j;
                }
                else 
                    break;
            }
            //cout<< "\n" << i<<"  ---------------------------------------------------------\n";print();
        }
        return ans;
    }
    nodeType * creatSortedList()
    {
        nodeType*ans;
        ans = new nodeType[n];
        int nn = n ;
        for(int i = nn-1; i>=0 ; i--)
        {
            ans[i]=removeFtomFront();
        }
        return ans ; 
    }
    void print()
    {
        int j =1;
        for (int i = 1; i <= n ; i ++)
        {
            cout<<arr[i]<<" ";
        
            if (j==i)
            {
                cout<< endl;
                j=2*j+1;
            }
        }
    }
private:
    int n ;
    nodeType *arr,* arrT;
    int endPtr;
    int mid;
};

int main () 
{
    int n , k ; 
    cin >> n >> k ;
    heap <int> h(n);
    h.input();
    h.heapify();
    int *ls = h.creatSortedList();
    // for(int i   = 0  ; i < n ; i ++)
    //     cout<<ls[i]<<" " ;
    // cout<<endl;
    int nn = (n+1)/2-1;
    int l =nn-1;
    int r =nn+1;
    for (int i = 0 ; i < k ; i ++)
    {
        if (ls[nn]-ls[l]<=ls[r]-ls[nn] )
            cout<<ls[l--];
            // cout<< ls[l]-ls[nn]<< "   " << ls[r]-ls[nn];
        else
            cout<<ls[r++];
        if (i<k-1)
            cout<<endl;
    }
    return 0 ;
}