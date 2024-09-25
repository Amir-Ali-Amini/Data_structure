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
template<typename nodeType>class tree ;
template <typename nodeType >
class nodeTree
{
    friend class tree<nodeType>;
public:
    nodeTree(string d  , bool m=false  , char w = 'a', nodeTree<nodeType> * f = 0 )
    {
        data =d ;
        mean = 0 ; 
        if (m==true)
            mean++;
        father = f ;
        who = w ; 
        children=new nodeTree<nodeType> * [26];
        for(int i = 0 ; i < 26 ; i++)
        {
            children[i]=0;
        }
    }
private:
    nodeTree<nodeType> *father ;
    nodeTree<nodeType> **children ; 
    int mean ;
    string data ;
    char who ; 
};

template<typename nodeType > 
class tree 
{
public:
    tree()
    {
        rootPtr=getNewNode("");
    }

    void add(string str)
    {
        nodeTree<nodeType> *newPtr = rootPtr;
        int sizeOfStr=str.size() ; 
        for (int i = 0 ; i< sizeOfStr ; i++)
        {
            if (newPtr->children[((int)str[i])-97]==0)
            {
                newPtr->children[((int)str[i])-97]=getNewNode(newPtr->data+str[i] , (i==sizeOfStr-1) , ((int)str[i])-97 , newPtr);
                newPtr =newPtr->children[((int)str[i])-97];
                //cout<< newPtr->mean<<endl;
            }
            else 
            {
                newPtr=newPtr->children[((int)str[i])-97];
                //newPtr= newPtr->children[((int)str[i])-97];
                if (i==sizeOfStr-1)
                    newPtr->mean++;
            }
        }
    }

    bool remove(string str)
    {
        nodeTree<nodeType> *newPtr = rootPtr;
        int size =  str.size();
        for (int i = 0 ; i <size ; i++)
        {
            newPtr=newPtr->children[((int)str[i])-97];
            if (newPtr==0)
                return false;
            
        }
        newPtr->mean--;
        if (newPtr->mean<0)newPtr->mean=0;
        return true ;
    }
    int get(string str )
    {
        nodeTree<nodeType> *newPtr = rootPtr;
        int size =  str.size();
        int counter = 0 ;
        for (int i = 0 ; i <size ; i++)
        {
            newPtr=newPtr->children[((int)str[i])-97];
            if (newPtr==0)
                return counter ;
            if (newPtr->mean)
                 counter+=newPtr->mean;
            
        }
        return counter ; 
    }

private:
    nodeTree<nodeType> *rootPtr ;
    nodeTree<nodeType> * getNewNode(string d , bool m =false , char w = '!', nodeTree<nodeType> * f = 0 )
    {
        return new nodeTree<nodeType> ( d ,  m  ,  w ,   f  );
    }
    bool rootChek ;
};

int main () 
{
    int n ; 
    cin >> n ;
    tree<char> drakht;
    string a, b ;
    cin.ignore();
    for(int i = 0 ; i < n ; i++)
    {
        getline(cin, b );
        a=b.substr(0,3);
        b=b.substr(4);
        //cout<<b+'\n';
        if (a=="add")
        {
            drakht.add(b);
        }
        if (a=="del")
        {
            drakht.remove(b);
        }
        if (a=="get")
        {
            cout<<drakht.get(b)<<endl;
        }
    }
    return 0 ;
}