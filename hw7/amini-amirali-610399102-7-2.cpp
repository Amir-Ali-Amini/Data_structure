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
    tree(int nn )
    {
        rootPtr=0;
        n=nn;
        seen = new bool [n];
        for (int i = 0 ; i <n ; i++)
        {
            seen[i]=false;
        }
    }
    void maininput(int * a , int * b )
    {
        input(rootPtr , a , b , 0 , n);
    }

    void input(nodeTree<nodeType> * &subRoot , int *a , int*b , int start , int end )
    {
        int r=-1;
        for (int i = 0 ; i< n && r<0 ; i++)
        {
            if (!seen[i])
            {
                
                for (int j = start ; j <end && r<0 ; j++)
                {
                    //cout<<"cheked\n";
                    if (a[i]==b[j])
                    {
                        //cout<< j << endl;
                        r=j;
                        seen[i]=true;
                    }
                }
            }
        }
        if (r>=0)
        {
            subRoot=getNewNode(b[r]);
            input(subRoot->leftPtr , a , b , start , r);
            input(subRoot->rightPtr , a , b , r+1 , end);
        }
    }

    void printInOrder ()
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
    void printPostOrder ()
    {
        postPrint(rootPtr);
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
    bool *seen ;
    int n ;

    void postPrint (nodeTree<nodeType> * root)
    {
        if (root)
        {
            postPrint(root->leftPtr);
            postPrint(root->rightPtr);
            cout<< root->data<<" ";
        }
    }
};


int main () 
{ 
    int n ; 
    cin >> n ;
    tree<int> drakht ( n );
    int *a , *b ; 
    a= new int [n];
    b=new int [n]; 
    for (int i = 0 ; i < n ; i++)
        cin >> a [i] ; 
    for (int i = 0 ; i < n ; i++)
        cin >> b [i] ; 
    drakht.maininput(a,b);
    drakht.printPostOrder();
    
}