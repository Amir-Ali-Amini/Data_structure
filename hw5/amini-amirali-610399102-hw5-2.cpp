//P name : custom liked list for 5.2 DS
//Fig : 1
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
    void insertAtFront(nodetype d)
    {
        nodeList<nodetype> *newPtr = getNewNode(d);
        newPtr->nextPtr=firstPtr;
        firstPtr=newPtr;
        toSeen=toAdd=toAddMemmory=firstPtr;
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
        //cout<<toAdd->data<< " + "<<d <<" = ";
        toAdd->data+=d;
        //cout<<toAdd->data<<endl;
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
    int getFull()
    {
        nodeList<nodetype> *newPtr=firstPtr;
        int a=0, b =0;
        while(newPtr!=lastPtr)
        {
            //cout<<newPtr->data<<endl;
            b++;
            if (newPtr->data!=0&&newPtr->data!='0')
               { a=b;
               //cout<<newPtr->data<<endl;
               }
            newPtr=newPtr->nextPtr;

        }
        return a ;
    }
    void fix()
    {
        nodeList<nodetype> * newPtr = firstPtr;
        while(newPtr!=lastPtr)
        {
            newPtr->nextPtr->data+=newPtr->data/10;
            newPtr->data%=10;
            newPtr=newPtr->nextPtr;
        }
    }
    bool chek_m()
    {
        nodeList<nodetype> * newPtr = firstPtr;
        bool c=true;
        while(newPtr!=lastPtr)
        {
            if (newPtr->data<0)
            {
                c=false;
            }
            if (newPtr->data>0)
                c=true;
            newPtr=newPtr->nextPtr;
        }
        return c;
    }
    void fix_m(int i=0)
    {
        //cout<<"mines\n";
        nodeList<nodetype> * newPtr = firstPtr;
        if (i==0)
        {
            while(newPtr!=lastPtr)
            {
                if (newPtr->data<0)
                {
                    //cout<<"mines\n";
                    newPtr->data+=10;
                    newPtr=newPtr->nextPtr;
                    newPtr->data-=1;
                }
                else 
                    newPtr=newPtr->nextPtr;
            }
        }
        else
        {
            while(newPtr!=lastPtr)
            {
                newPtr->data*=-1;
                newPtr=newPtr->nextPtr;
            }
        }
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
//------------------------------------------------------------




int main () 
{
    list<int> *answ;
    int  nSize , mSize ; 
    cin>>nSize;
    char input;
    cin>>input;
    list<int> n ((int)input -48);
    for(int i = 1 ; i < nSize; i++)
    {
        cin>>input;
        n.insertAtFront((int)input -48);
    }
    char t;
    cin>>t;
    cin>>mSize;
    cin>>input;
    list<int> m ((int)input -48);
    for(int i = 1 ; i < mSize; i++)
    {
        cin>>input;
        m.insertAtFront((int)input -48);
    }
    //cout<<endl;
    if (t=='+')
    {
        if (nSize>mSize)
        {
            
            n.insertAtBack(0);n.insertAtBack(0);
            for (int i = 0 ; i < mSize;i++)
            {
                //cout<<1<<endl;
                n.addTo(m.getToSeen());
            }
            //n.printList();
            n.fix();
            answ=&n;
            
        }
        else
        {
            m.insertAtBack(0);m.insertAtBack(0);
            for (int i = 0 ; i < nSize;i++)
            {
                m.addTo(n.getToSeen());
            }
            //m.printList();
            m.fix();
            answ=&m;
        }
        int size= answ->getFull();
        for(int i = 0 ; i < size;i++)
        {
            cout<<answ->getToSeen();
        }
    }
   
    if (t=='*')
        {
           list <int> ans(0);
           for (int i = 0 ; i < mSize+nSize+3 ; i ++)
           {
               ans.insertAtBack(0);
           }
           n.insertAtBack(0);
           m.insertAtBack(0);
           for(int i =0 ; i < nSize ; i++)
           {
               int nn = n.getToSeen();
               ans.updateMemory();
               for(int j=0 ; j < mSize ; j++)
               {
                   ans.addTo(nn*m.getToSeen());
               }
               m.resetToSeen();
               ans.resetToAdd();
           }
           ans.fix();ans.fix();
           
           for(int i = 0 ; i <ans.getFull() ; i++)
           {
               cout<<ans.getToSeen();
           }
           
        }
    /*
    if (t=='/')
        ans=n/m; 
    */
    if (t=='-')
        { 
            if (nSize<=mSize)
            {
                while (nSize<=mSize)
                    { 
                       n.insertAtBack(0);
                        nSize++;
                    }
            }
            for (int i = 0 ; i < mSize;i++)
            {
                //cout<<1<<endl;
                int min=m.getToSeen();
                n.addTo(-min);
            }
            answ=&n;
            bool chk=answ->chek_m();
            if (chk==false)
            {
                n.fix_m(1);
                n.fix_m(0);
            }
            else
                n.fix_m(0);
            int size= answ->getFull();
            for(int i = 0 ; i < size;i++)
            {
                cout<<answ->getToSeen();
            }
            if (chk==false)cout<<'-';
        }
    return 0 ;
    
}