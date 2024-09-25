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

template <typename Type>
class radix
{
public:


    radix(int nn )
    {
        n=nn;
        max=0;
        strs=new string [n];
        inputt="";
        t =1;
        for (int i =1;i <= n ; i ++)
            {
                t*=i;
                inputt+=char(47+i);
            }
        jaygashtha=new string [t];
    }



    void input() 
    {
        // getchar();
        for (int i=0 ; i < n ; i++)
        {
            getline(cin , strs[i]);
            if (strs[i].size()>max)
                max+=strs[i].size();
        }
        // for (int i=0 ; i < n ; i++)
        // {
        //     cout << strs[i] <<" * ";
        // }
    }


    void fix()
    {
        for(int i = 0 ; i< n ; i++)
        {
            while(strs[i].size()<max)
                strs[i]+='{';
        }
    }

    void make ()
    {
        permute(inputt , ans , jaygasht);
        for(int i=0 ; i <t ; i++)
        {
            string q="";
            for(int j =0 ; j<n ; j++)
            {
                q+=strs[int(jaygasht[i][j])-48];
            }
            jaygashtha[i]=q;
            // cout<<jaygashtha[i]<<endl;
        }
        strs=jaygashtha;
        // for (int i = 0; i < t; i++){
        //     // if (strs[i] == jaygashtha[i]) cout <<"*"<<endl;
        //     // cout << strs[i] << " "<<jaygashtha[i]<<endl;
        // }
    }


    void radixsort()
    {
        sort(max);
    }
    void sort(int k )
    {
        if (k < 0){
            return;
        }
        // k--;
        int n = t;
        string* all_perm = new string[n];
        int i, count[26] = { 0 };
        int l = strs[0].length();

        for (i = 0; i < n; i++) {
            count[strs[i][k] - 97]++;
        }

        for (i = 1; i < 26; i++)
            count[i] += count[i - 1];

        for (i = n - 1; i >= 0; i--) {
            all_perm[count[strs[i][k] - 97] - 1] = strs[i];
            count[strs[i][k] - 97]--;
        }

        for (i = 0; i < n; i++)
            strs[i] = all_perm[i];   
        k--;
        // if (k)
        // {
        //     k--;
        //     int counter [englishcount];
        //     for(int i =0 ; i < englishcount ; i ++)
        //         counter[i]=0;
        //     for(int i=0 ;i< t;i++)
        //     {
        //         counter [int(strs[i][k])-97]++;
        //     }
        //     int temp1,temp2=0;
        //     temp1=0;
        //     for(int i=1 ;i<englishcount;i++)
        //     {
        //         counter[i] += counter[i - 1];
        //         // temp2=temp1;
        //         // temp1+=counter [i];
        //         // counter [i]=temp2;
        //     }
        //     string *newstrs = new string [t];
        //     for(int i =0 ; i < t ; i++)
        //     {
        //         newstrs[counter [int(strs[i][k])-97] - 1]=strs[i];
        //         counter [int(strs[i][k])-97]--;
        //     }
        //     // delete[] strs;
        //     strs=newstrs;
        //     sort(k);
        // }
        // cout<<strs[0];
    }

    void creat()
    {
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j< max ; j++)
            {
                if (strs[i][j]!='{')
                    cout<<strs[i][j];
            }
        }
    }
    void print()
    {
        for(int i =0 ; i < t ; i++)
            cout<<strs[i]<<endl;
            // cout<<jaygashtha[i]<<endl;
    }

public:
    string * strs;
    int t;

private:


    int n ,max  ,englishcount = 26;
    string *jaygashtha;
    vector<string> jaygasht;
    string ans="",inputt;
    void permute(string s , string answer, vector<string> &res)
        {
            if (s.length() == 0) {
                res.push_back(answer);
                return;
            }
            for (int i=0 ; i<s.length() ; i++) {
                char ch = s[i];
                string left_substr = s.substr(0,i);
                string right_substr = s.substr(i+1);
                string rest = left_substr + right_substr;
                permute(rest , answer + ch, res);
            }
        }
};
void countSort(string* arr, int n, int curr) {

 string* all_perm = new string[n];
 int i, count[26] = { 0 };
 int l = arr[0].length();

 for (i = 0; i < n; i++) {
  count[arr[i][l - curr] - 97]++;
 }

 for (i = 1; i < 26; i++)
  count[i] += count[i - 1];

 for (i = n - 1; i >= 0; i--) {
  all_perm[count[arr[i][l - curr] - 97] - 1] = arr[i];
  count[arr[i][l - curr] - 97]--;
 }

 for (i = 0; i < n; i++)
  arr[i] = all_perm[i];
}
//////////////////////////////////////////////////////////////
string* radixsort(string* arr, int n) {

 int m = arr[0].length();

 for (int curr = 1; curr <= m; curr++)
  countSort(arr, n, curr);

 return arr;
}
int main()
{
    int n;
    cin >> n ;
    getchar();
    radix<char> a(n);
    a.input();
    a.make();
    string* res = radixsort(a.strs, a.t);
    cout << res[0];
    // a.radixsort();
    // cout<<endl;
    // a.print();
    return 0 ;
}