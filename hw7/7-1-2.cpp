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
#include<iomanip>
using namespace std;


//----------------------------------------------------------------------------------
int poro(char a )
{
    if (a=='-' || a == '+')
        return 0;

    if (a=='(')
        return -1;
    if (a=='*'||a=='/')
        return 1;
//    return -1 ;
}
/*
bool chkP(string str)
{
    for (int i = 0 ; i < str.size () ; i++)
    {
        if (str[i]=='(')
            return true ;
    }
    return false ;
}
string psFix(string str)
{
    
}
*/
int main() 
{
    int n ; 
    cin >> n ; 
    string input[n];
    string ans[n];
    float anss[n];
    int start = -1 ;
    char stk[250];
    cin.ignore();
    for (int i =0 ; i < n ; i ++)
    {
        ans[i]="";
        getline(cin , input[i]);
        for (int j = 0; j < input[i].size() ; j++)
        {
            
            if(input[i][j] <='9' &&input[i][j] >='0')
            {
                ans[i]+=input[i][j];
//                cout<< ans[i]<< "\n";
            }
            else
            {
                if (start==-1 )
                    stk[++start]=input[i][j];
                else 
                {
                  if(input[i][j] =='(') stk[++start] = input[i][j];
                  else if(input[i][j] ==')'){
                    while(stk[start]!='('){
                      ans[i]+=stk[start];
                      start--;
            }
            start--;
          }
                    else if (poro(input[i][j])>poro(stk[start]))
                        stk[++start]=input[i][j];
                    else 
                    {
                        while(poro(input[i][j])<=poro(stk[start]) && start>=0)
                        {
                            if (poro(stk[start] )!=-1)ans[i]+=stk[start];
                            start--;
                        }
                        stk[++start]=input[i][j];
                    }
                }
            }
//            for (int i = 0; i <=start; i++)cout<<stk[i]<<" ";
//            cout<<endl;
        }
        while(start>=0)
        {
            if (poro(stk[start] )!=-1)ans[i]+=stk[start];
            start--;
        }
    }
    for(int i = 0 ; i < n ; i ++)
    {
        start=-1;
        float intstk[250];
        cout<<ans[i]<<endl;
        for(int j = 0 ; j < ans[i].size(); j++)
        {
            if (ans[i][j] <='9' &&ans[i][j] >='0')
            {
                intstk[++start]=(int) ans[i][j] - 48 ;
            }
            else 
            {
                if (ans[i][j]=='+')
                    intstk[--start]+=intstk[start+1];
                if (ans[i][j]=='-')
                    intstk[--start]-=intstk[start+1];
                if (ans[i][j]=='*')
                    intstk[--start]*=intstk[start+1];
                if (ans[i][j]=='/')
                    intstk[--start]/=intstk[start+1];
            }
        }
        cout<<fixed<<setprecision(3) << intstk[start--]<<endl;
    }
    return 0 ;
}