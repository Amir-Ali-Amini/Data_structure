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

template<typename nodeType> class list ; 
template<typename nodeType>
class listNode 
{
    friend class list<nodeType>  ;
public:
    listNode(nodeType d )
    {
        data = d ;
        nextPtr=0;
    }

private:
    nodeType data ; 
    listNode<nodeType> * nextPtr ; 
};

template<typename nodeType>
class list
{
public:
    list()
    {
        firtsPtr=lastPtr=0;
        size=0;
    }
    bool isEmpty()
    {
        return (size==0);
    }
    void insertAtBack(nodeType d)
    {
        if (isEmpty())
        {
            firtsPtr=lastPtr=then=getNewNode(d);
        }
        else
        {
            lastPtr=lastPtr->nextPtr=getNewNode(d);
        }
        size++;
    }
    void insertAtFront(nodeType d)
    {
        if (isEmpty())
        {
            firtsPtr=lastPtr= getNewNode(d);
        }
        else
        {
            listNode<nodeType> *newPtr = getNewNode(d);
            newPtr->nextPtr = firtsPtr;
            firtsPtr=newPtr;
        }
        size++;
    }
    nodeType removeAtFront()
    {
        nodeType ans;
        if (!isEmpty())
        {
            listNode<nodeType> *newPtr = firtsPtr->nextPtr;
            ans = firtsPtr->data;
            delete firtsPtr ; 
            firtsPtr=newPtr;
            size--;
        }
        if (isEmpty())
            firtsPtr=lastPtr=0;
        return ans;
    }

    nodeType get(int x )
    {
        listNode<nodeType> *newPtr = firtsPtr;
        for(x ; x>1 ; x--)
        {
            newPtr=newPtr->nextPtr;
        }
        return newPtr->data;
    }
    void print()
    {
        listNode<nodeType> *newPtr = firtsPtr;
        while(newPtr!=lastPtr)
        {
            cout<<newPtr->data<<endl;
        }
        cout<<newPtr->data<<endl;
    }
    nodeType getToAdd()
    {
        listNode<nodeType> *newPtr=then;
        then=then->nextPtr;
        return newPtr->data;
    }
    int sizee()
    {
        return size;
    }

private:
    listNode <nodeType> *firtsPtr , *lastPtr ,*then;
    int size  ; 
    listNode <nodeType> * getNewNode(nodeType d)
    {
        return new listNode <nodeType> (d);
    }
};

// end of list --------------------------------------------------------------------------------------

template<typename nodeType> 
class tree
{
public:
    tree(int n ,int r)
    {
        number=n;
        root = r ; 
        listOfNodes = new list<nodeType>[n];
        seen = new bool [number];
        for (int i = 0 ; i < n ; i ++)
        {
            seen[i]=false;
        }
    }
    void input()
    {
        for (int i = 0 ; i < number-1 ; i++)
        {
            //cout<< "inputing .. " << i <<endl;
            int a , b ;
            cin >> a >> b ; 
            listOfNodes[a].insertAtBack(b);
            listOfNodes[b].insertAtBack(a);
        }
    }

    void print () 
    {
        list<int>q;
        q.insertAtBack(root);
        int counter= 0;
        while(!q.isEmpty() && counter<number)
        {
            int x= q.removeAtFront();
            if (seen[x]==false)
            {
                cout<< x <<endl;
                seen[x]=true;
            
                for(int i = 0 ; i < listOfNodes[x].sizee() ; i++)
                {
                    //cout<< "**" <<endl;
                    q.insertAtBack(listOfNodes[x].getToAdd());
                }
            }
        }
    }
private:
    list<nodeType> * listOfNodes ;
    int root ; 
    int number ; 
    bool * seen ; 
};

int main () 
{
    int a , b ;
    cin>> a >> b ; 
    tree<int>drakht(a,b);
    drakht.input();
    drakht.print();

    return 0 ;
}