//P name : custom liked list
//Fig : 2
//use ?:
//date: 2 nov 2021
//amiraliamini 610399102 UT-CS-99

//=================================================================================

#include <iostream>
#include <string>
#include<vector>
#include <iomanip>
#include<cstdlib>
using namespace std;


//----------------------------------------------------------------------------------
template <typename nodetype> class list ; 
template <typename nodetype> 
class nodeList 
{
    friend class list<nodetype>;
public:
    nodeList(nodetype d =0)
    {
        data = d ;
        nextPtr=0;
    }
    
    void print ()
    {
        cout << data<<" ";
    }
private:
    nodetype data ; 
    nodeList<nodetype> * nextPtr ; 
};

template<typename nodetype>
class list 
{
public:
    list(nodetype d)
    {
        firstPtr=lastPtr=toSeen=toAdd=toAddMemmory=getNewNode(d);
    }
    nodeList<nodetype> * getNewNode(nodetype d)
    {
        return new nodeList<nodetype> (d);
    }
    
    void insertAtBack(nodetype d)
    {
        nodeList<nodetype> * newPtr = getNewNode(d);
        lastPtr->nextPtr=newPtr;
        lastPtr=newPtr;
    }

    nodetype getToSeen()
    {
        nodetype ans = toSeen->data;
        if (toSeen==lastPtr)
            toSeen=firstPtr;
        else
            toSeen=toSeen->nextPtr;
        return ans;
    }
    void resetToSeen()
    {
        toSeen=firstPtr;
    }
    void printList () 
    {
        nodeList<nodetype>*newPtr =firstPtr;
        while (newPtr!=lastPtr)
        {
            //cout <<"printing ...\n";
            //newPtr->print();
            //cout<<newPtr->data<<endl;
            newPtr->print();
            newPtr=newPtr->nextPtr;
        }
        lastPtr->print();
    }
    void addTo(nodetype d)
    {
        toAdd->data+=d;
        //cout<<toAdd->data;
        toAdd=toAdd->nextPtr;
    }
    void resetToAdd()
    {
        toAdd=toAddMemmory;
    }
    void updateMemory()
    {
        if (toAdd->nextPtr!=0)
            toAddMemmory=toAdd->nextPtr;
    }
    void printTest()
    {
        lastPtr->print();
        firstPtr->print();
    }
    ~list()
    {
        while(firstPtr!=0)
        {
            bool chk = true ;
            if (firstPtr->nextPtr=0)
                chk=false;
            if (chk)
            {
                nodeList<nodetype> * newPtr = firstPtr->nextPtr;
                delete firstPtr;
                firstPtr=newPtr;
            }
            else 
            {
                delete firstPtr;
                firstPtr=lastPtr=0;
            }
        }
    }
private:
    nodeList<nodetype> *firstPtr ; 
    nodeList<nodetype> *lastPtr ; 
    nodeList<nodetype> *toSeen ;
    nodeList<nodetype> *toAdd ;
    nodeList<nodetype> *toAddMemmory;
};

int main()
{
    int  n  , m ; 
    cin >> n ;
    cin>> m ; 
    n++;m++;
    int input;
    cin>> input;
    list<int> first(input);
    for (int i = 0 ; i < n-1 ; i++)
    {
        cin>>input;
        first.insertAtBack(input);
    }
    cin>> input;
    list<int> seccend(input);
    for (int i = 0 ; i < m-1 ; i++)
    {
        cin>>input;
        seccend.insertAtBack(input);
    }

    list<int>ans(0);
    for(int i = 0 ; i < m+n-2;i++)
    {
        ans.insertAtBack(0);
    }

    //cout<<first.getToSeen();cout<<first.getToSeen();cout<<first.getToSeen();
    
    for (int i = 0 ; i < n ; i++)
    {
        int firstP=first.getToSeen();
        seccend.resetToSeen();
        ans.updateMemory();
        for(int j = 0 ; j<m;j++ )
        {
            ans.addTo(firstP*seccend.getToSeen());
        }
        ans.resetToAdd();
    }
    ans.printList();
    return 0 ; 
}