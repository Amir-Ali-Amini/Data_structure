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
template<typename noddeType> class tree;
template< typename nodeType > 
class nodeTree
{
    friend class tree<nodeType>;
public :
    nodeTree(nodeType d , nodeTree<nodeType> * p = 0 , bool IR =false)
    {   
        data=d;
        leftPtr=rihgtPtr=0;
        papaPtr=p;
        if (IR)
            isRight=true;
    }
private:
    nodeType data;
    nodeTree<nodeType> * leftPtr , *rihgtPtr , *papaPtr;
    bool isRight = false ;
};

template<typename nodeType> 
class tree 
{
public:
    tree(int n )
    {
        number = n-1 ;
        arr=new nodeTree<nodeType> *[n];
        papa=new int [n-1] ; 
    }
    /*void createArrs()
    {
        arr=new nodeTree<nodeType> *[number+1];
        papa=new int [number] ; 
    }*/
    void input()
    {
        for(int i = 0 ; i < number ; i ++)
        {
            cin >> papa[i];
        }
        int w;
        cin >>w;
        arr[0]=rootPtr=getNewNode(w);
        for (int i = 0 ; i < number ; i++)
        {
            cin >>w;
            
            addChild(arr[papa[i]],w,i);
        }
    }
    void addChild(nodeTree<nodeType> * root , nodeType d  , int i )
    {
        if (root->leftPtr)
        {
            arr[i+1]=root->rihgtPtr=getNewNode(d , root , true);
        }
        else 
        {
            arr[i+1]=root->leftPtr=getNewNode(d,root);
        }
        
    }

    int findMax1 (nodeTree<nodeType> *root , int &count)
    {
        if (root == 0 )
        {
            return 0 ;
        }
        int l = findMax1(root->leftPtr , count);
        int r = findMax1(root->rihgtPtr, count);
        int maxSingle = max(max(l, r) + root->data, root->data);
        int maxTop = max(maxSingle, l + r + root->data);
        count = max(count, maxTop);
        return maxSingle;
    }
    int findMax2(nodeTree<nodeType> *root)
    {
        int count = INT8_MIN;
        findMax1(root, count);
        return count;
    }
    int find()
    {
        return findMax2(rootPtr);
    }
    
    private :
    nodeTree<nodeType> * rootPtr , *lastPtr ,**arr;
    nodeTree<nodeType> * getNewNode(nodeType d , nodeTree<nodeType> * p = 0 , bool IR =false)
    {
        return new nodeTree<nodeType> (d,p,IR);
    }
    int number;
    int *papa ;

};

int main ()
{
    int n ; 
    cin >> n ;
    tree<int > drakht (n);
    //drakht.createArrs();
    drakht.input();
    cout<<drakht.find();
    return 0 ;
}