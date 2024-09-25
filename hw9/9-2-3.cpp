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
class list ; 
template<typename nodeType> 
class nodeList 
{
    friend class list<nodeType>;
public:
    nodeList(nodeType d)
    {
        data=d ;
        nextPtr=0;
    }
private:
    nodeType data;
    nodeList<nodeType> *nextPtr;
};

template <typename nodeType>
class list
{
public:
    list()
    {
        lastPtr=firstPtr=0;
        size=0;
    }
    void insertAtFront(nodeType d)
    {
        if (isEmpty())
        {
            firstPtr=lastPtr=getNewNode(d);
        }
        else 
        {
            nodeList<nodeType> *newPtr = getNewNode(d);
            newPtr->nextPtr=firstPtr;
            firstPtr=newPtr;
        }
        size++;
    }
    void insertAtBack(nodeType d)
    {
        if (isEmpty())
        {
            firstPtr=lastPtr=getNewNode(d);
        }
        else 
        {
            nodeList<nodeType> *newPtr = getNewNode(d);
            lastPtr->nextPtr=newPtr;
            lastPtr=newPtr;
        }
        size++;
    }
    nodeType removeFromFront()
    {
        nodeList<nodeType> *newPtr=firstPtr;
        firstPtr=firstPtr->nextPtr;
        nodeType ans = newPtr->data;
        delete newPtr;
        size--;
        if(size==0)
            lastPtr=firstPtr=0;
        return ans;
    }
    int getSize()
    {
        return size;
    }
    void insertAt(nodeType d , nodeList<nodeType>*Ptr)
    {
        nodeList<nodeType>* newPtr = getNewNode(d);
        newPtr->nextPtr=Ptr->nextPtr;
        Ptr->nextPtr=newPtr;
        size++;
    } 
    void findAndAdd(nodeType d) 
    {
        
        if (isEmpty())
        {
            firstPtr=lastPtr=getNewNode(d);
            size++;
        }
        else
        {
            if (d->getWeight()<=firstPtr->data->getWeight())
            {
                insertAtFront(d);
            }
            else 
            {
                if (d->getWeight() >=lastPtr->data->getWeight())
                {
                    insertAtBack(d);
                }
                else
                {
                    nodeList<nodeType>* newPtr=firstPtr;
                    
                    while(d->getWeight() > newPtr->nextPtr->data->getWeight())
                    {
                        newPtr=newPtr->nextPtr;
                        
                    }
                    insertAt(d , newPtr);
                }
            }
            
        }
    }
    bool isEmpty()
    {
        return (size==0);
    }
    nodeType getAtFront()
    {
        nodeType ans = removeFromFront();
        insertAtBack(ans);
        return ans;
    }
private:
    nodeList<nodeType> *firstPtr , *lastPtr;
    int size ;
    nodeList<nodeType> *getNewNode(nodeType d)
    {
        return new nodeList<nodeType> (d);
    }
};
//----------------------------------------------------------------------------
class hashing
{
public:
    hashing(int n )
    {
        size = n ; 
        hashList=new list<int> [n];
    }


    void add(string str , int index)
    {
        
        int h = 0 ;
        for (int i = 0 ; i < str.size() ; i++)
        {
            h*=6;
            h+=int(str[i]-96);
            h%=size;
        }
        // cout<< h << " " << givePal(str)[1]<< endl;

        hashList[h].insertAtBack(index);
    }

    int *givePal(string str)
    {
        int h = 0 ;
        int * ans ;
        for (int i = str.size()-1 ; i >=0 ; i--)
        {
            h*=6;
            h+=int(str[i]-96);
            h%=size;
        }
        int s = hashList[h].getSize();
        ans =new int [s];
        ans[0]=s;
        for(int i = 1 ; i < s+1 ; i ++)
        {
            ans[i]=hashList[h].getAtFront();
        }
        return ans;
    }

private:
    int size;
    list<int> * hashList ;
};

bool chk(string str)
{
    int n =str.size() ;
    for(int i = 0 ; i <n;i++)
    {
        if (str[i]!=str[n-1-i])return false;
        if(i>=n-i-1)return true;
    }
    return true ;
}
//-----------------------------------------------------------------------------
int main () 
{
    hashing hash (7649);
    int n ; cin>> n ;
    // getchar();
    string input [n];
    for (int i = 0 ; i < n ; i ++)
    {
        // getline(cin , input[i]);
        cin>>input[i];
        hash.add(input[i] , i);
    }
    bool c =true;
    for(int i = 0 ; i <  n ; i++)
    {
        for (int j =0 ; j < n ; j++)
        {
            if (j!=i)
            {
                if(chk(input[i]+input[j]))
                {cout<< i << " " << j <<endl;
                c=false;}
            }
        }
    }
    if (c)cout<<0<<endl;
    return 0 ; 
}