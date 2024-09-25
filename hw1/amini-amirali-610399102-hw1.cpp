#include <iostream>
#include <string>
#include<vector>
using namespace std;

//amiraliamini
class mat 
{
    public:
    mat(int aa, int bb )
    {
        a=aa; b=bb;
        m = new int *[a];
        for (int i = 0 ; i < a ; i++)
        {
            m[i]=new int [b];
        }
    }
    

    void input () 
    {
        for (int i = 0 ; i< a ; i++)
        {
            for (int j = 0 ; j < b ; j++)
            {
                cin  >> m [i][j] ;     
            }
        }
    }
    void print () 
    {
        for (int i = 0 ; i< a ; i++)
        {
            for (int j = 0 ; j < b ; j++)
            {
                cout << m[i][j]<< " ";     
            }
            cout<<endl;
        }
    }
    int gt(int aa , int bb )
    {
        return m[aa][bb];
    }
    private:
    int ** m;
    int a , b ;
};
int main(){
    int q[2] , w[2] ; 
    cin >> q[0]>>q[1]>>w[0]>>w[1];
    mat a (q[0],q[1]) , b(w[0] , w[1]);
    getchar();
    a.input();
    b.input();
    if (q[1]==w[0])
    {
        int ** ans ;
        ans =new int *[q[0]] ; 
        for (int i = 0 ; i < q[0] ; i++)
        {
            ans [ i ] = new int [w[1]];
            for (int j =0 ;j  < w[1] ; j ++)
            {
                ans[i][j]=0;
            }
        }
        for (int i =0 ; i< q[0] ; i++)
        {
            for (int j = 0 ; j < w[1]; j++)
            {
                for (int k = 0 ; k< q[1] ; k++)
                {
                    ans [i][j] += a.gt(i,k)*b.gt(k,j);
                }
            }
        }
        for (int i = 0 ; i < q[0] ; i++)
        {
            for (int j =0 ;j  < w[1] ; j ++)
            {
                cout << ans[i][j]<<" ";
            }
            cout << endl;
        }
    }
    else 
        cout<<"the number of columns of the first matrix not equal to the number of rows of the second one. ";
    return 0;
}
