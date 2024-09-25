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
#include<stack>
#include<queue>
#include<math.h>
using namespace std;


//----------------------------------------------------------------------------------
template <typename nodeType> class tree;
template <typename nodeType>
class nodeTree
{
    friend class tree<nodeType> ;
public:
    nodeTree(nodeType d , nodeTree<nodeType> * papa = 0)
    {
        data=d;
        leftPtr=rightPtr=0;
        babaPtr=papa;
    }

    bool seen()
    {
        s=!(s==true);
        return s; 
    }

private:
    nodeType data ; 
    nodeTree<nodeType> * leftPtr ; 
    nodeTree<nodeType> * rightPtr , * babaPtr ; 
    bool s =true;
};

template <typename nodeType>
class tree
{
public:
    tree(nodeType d , int floor)
    {
        rootPtr=getNewNode(d);
        inputFloor=floor;
    }
    void input()
    {
        int i = pow(2,inputFloor-1);
        //cout<< i << endl ;
        inputQueue.push(rootPtr);
        //cin>>rootPtr->data;
        while(i>1)
        {
            i--;
            nodeTree<nodeType> * newPtr ; 
            newPtr= inputQueue.front();
            inputQueue.pop();
            nodeType newData ;
            cin>>newData;
            newPtr->leftPtr=getNewNode(newData,newPtr);
            inputQueue.push(newPtr->leftPtr);
            cin>>newData;
            newPtr->rightPtr=getNewNode(newData,newPtr);
            inputQueue.push(newPtr->rightPtr);
        }
    }
    void print ()
    {
        seenStack.push(rootPtr);
        while (seenStack.empty()==false)
        {
            if (seenStack.top()==0)
            {
                seenStack.pop();
            }
            else{
                nodeTree<nodeType> * newPtr =  seenStack.top();
                bool seen=newPtr->seen();
                if (seen)
                {
                    if ( newPtr->data!=-1) cout<<newPtr->data<< " " ; 
                    seenStack.pop();
                    seenStack.push(newPtr->rightPtr);
                    
                }
                else
                {
                    seenStack.push(newPtr->leftPtr);
                }
            }
        }
        
    }
private:
    nodeTree<nodeType> *rootPtr ;
    int inputFloor ; 
    stack <nodeTree<nodeType> * > seenStack ; 
    queue<nodeTree<nodeType> *> inputQueue;
    nodeTree<nodeType> * getNewNode(nodeType d  ,nodeTree<nodeType> * papa = 0)
    {
        return new nodeTree<nodeType> (d,papa);
    }
};

int main ()
{
    int floor , root; 
    cin >> floor >> root  ; 
    
    tree<int> drakht(root , floor) ;
    drakht.input();
    drakht.print();
}