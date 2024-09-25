#include<iostream>
#include <string.h>
#include <string>

using namespace std ;


class strin{
public:

    string str ;
    char ch[14]={'0','1','2','3','4','5','6','7','8','9','(',')','+','-'};
    int n ;
    bool t = false ;
    strin()
    {
        getline(cin , str);
        n=str.size();
    }
    bool chk()
    {
        int a = 0 ;
        for (int i = 0 ; i < n ; i++)
        {
            for (int j = 0  ; j< 14 ; j++)
            {
                if (str[i]==ch[j])
                {
                    break;
                }
                if (j==13)
                    return false;
            }
            if (str[i]=='(')
            {
                a++;
                t=true;
            }

            if (str[i]==')')
                a--;
            if(a<0)
                return false;
        }
        if (a!=0)
            return false;
        return true ;
    }



};

string convert(int a )
{
    int chk=0;
    if(a<0)
    {
        a=-a;
        chk=1;
    }
    int r =a ;
    string s ="";
    while (a!=0)
    {
        s=(char)(a%10+48)+s;
        a/=10;
    }
//    cout << r << " Converted to " << s << endl;
    if (chk==0)return s;
    else return ('-'+s);
}
int doo(string a)
{
//    cout << "a = " << a << endl;
    int s =-1,e=0;
    while(e<a.size())
    {
        if (a[e]=='(')
                s=e;
        if (a[e]==')')
            break;
        e++;
    }
    if (s!=-1)
    {
//        cout<< "First" <<endl;
        int temp = doo(a.substr(s+1,e-s-1));
        string x = a.substr(0,s) + convert(temp) + a.substr(e+1,a.size());

//        cout << x << endl;
        return doo(x);
    }
    else
    {
//        cout<< "second" <<endl;
        int m =a.size()-1;
        while ((a[m]!='-'&&a[m]!='+')&&m>=0)
        {
            m--;
        }
        int ans=0;
        for (int i=m+1; i<a.size();i++)
        {
            ans*=10;
            ans+=(int)(a[i])-48;
        }
        if (m==-1)
        {
            return ans;
        }
        else{
            if (a[m]=='+')
                return (doo(a.substr(0,m))+ans);
            else
                return (doo(a.substr(0,m))-ans);
        }
    }

}
int main ()
{
//    cout<<convert(49);
    strin s;
    if (s.chk()==0)
    {
        cout << "ERROR";
        return 0;
    }
    cout<<doo(s.str);
    return 0 ;
}
