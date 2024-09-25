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
template<typename nodeType> class tree ; 
template <typename nodeType > 
class nodeTree
{friend class tree<nodeType>;
public:
    nodeTree(string s ="", char chr ='-' , bool chk=false , nodeTree<nodeType>* f =0)
    {
        for (int i =0 ; i < 26 ; i++)
            children[i]=0;
        str=s ;
        c = chr ; 
        if (chk)
            counter++;
        father=f;
    }
 

private:
    nodeTree<nodeType > * children[26] , *father ; 
    string str="";
    char c ;
    int counter=0;
};

template<typename nodeType> 
class tree
{
public:
    tree()
    {
        rootPtr =getNewNode();
    }
    void input()
    {
        string str ;
        getline(cin,str);
        int size=str.size();
        nodeTree<nodeType>*newPtr = rootPtr;
        for(int i = 0 ; i< size ;i++)
        {
            int child=int (str[i])-97;
            if(newPtr->children[child]==0)
            {
                // cout<<child<<endl;
                newPtr->children[child]=getNewNode(newPtr->str+str[i] , str[i] , false , newPtr);
            }
            newPtr=newPtr->children[child];
            if(i==size-1)
            {
                // cout<<"chkkkk\n";
                newPtr->counter++;
                if (newPtr->counter==1)
                {
                    cout<<"OK\n";
                }
                else
                {
                    cout<<newPtr->str << newPtr->counter -1<<endl;
                }
            }
        }
    }

     void input(string s)
    {
        string str =s;
        int size=str.size();
        nodeTree<nodeType>*newPtr = rootPtr;
        for(int i = 0 ; i< size ;i++)
        {
            int child=int (str[i])-97;
            if(newPtr->children[child]==0)
            {
                // cout<<child<<endl;
                newPtr->children[child]=getNewNode(newPtr->str+str[i] , str[i] , false , newPtr);
            }
            newPtr=newPtr->children[child];
            if(i==size-1)
            {
                // cout<<"chkkkk\n";
                newPtr->counter++;
                if (newPtr->counter==1)
                {
                    cout<<"OK\n";
                }
                else
                {
                    cout<<newPtr->str << newPtr->counter -1<<endl;
                }
            }
        }
    }
private:
    nodeTree<nodeType> *rootPtr;
    nodeTree<nodeType> *getNewNode(string s ="", char chr ='-' , bool chk=false , nodeTree<nodeType>* f =0)
    {
        return new nodeTree<nodeType> (s,chr,chk,f);
    }
};

int main()
{
    int n; 
    cin >> n ;
    cin.ignore();
    tree<int> drakht ;
    string str[n];
    for(int i = 0 ; i < n ; i++)
    {
        getline(cin,str[i]);
    }
    for(int i = 0 ; i < n ; i++)
    {
        drakht.input(str[i]);
    }

    return 0 ;
}