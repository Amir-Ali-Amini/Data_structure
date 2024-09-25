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
private:
    nodeList<nodeType> *firstPtr , *lastPtr;
    int size ;
    nodeList<nodeType> *getNewNode(nodeType d)
    {
        return new nodeList<nodeType> (d);
    }
};

//-----------------------------------------------------------------------
template<typename nodeType> class tree;
template<typename nodeType> 
class nodeTree
{
    friend class tree<nodeType>;
public:
    nodeTree(nodeType d , int w )
    {
        data = d ;
        weight=w ;
        str="";
        leftPtr=rightPtr=0;
    }
    int getWeight()
    {
        return weight;
    }

private:
nodeType data;
int weight ;
nodeTree<nodeType> *leftPtr , *rightPtr ; 
string str  ; 
};


template<typename nodeType>
class tree
{
public:
    tree()
    {
        rootPtr=0;
    }
    void inputCoding(string str)
    {
        int s = str.size();
        int charCounter[26];
        for(int i = 0 ; i < 26 ; i++)
        {
            charCounter[i]=0;
        }
        for(int i = 0 ; i < s ; i++)
        {
            charCounter[int(str[i])-96]++;
        }
        
        for(int i = 0  ; i < 26 ; i++)
        {
            if (charCounter[i]!=0)
            {
                ls.findAndAdd(getNewNode(char(i+96) , charCounter[i]));
            }
        }
    }
    void creatTree()
    {
        while(ls.getSize()>1)
        {
            //cout<<"creating ... \n";
            nodeTree<nodeType> *l = ls.removeFromFront() , *r= ls.removeFromFront() , * newPtr = getNewNode('-' , l->weight+r->weight);
            newPtr->leftPtr=l;
            newPtr->rightPtr=r;
            ls.findAndAdd(newPtr);
        }
        rootPtr=ls.removeFromFront();
        //cout<<"done creating ...\n";
    }

    void findCode()
    {
        findc(rootPtr );
    }
     void decode(string str)
    {
        if (str.size())
        {
            for(int i = 0 ;i <code1.size();i++)
            {
                if(code1[i]==str.substr(0,code1[i].size()))
                {
                    cout<<code2[i];
                    decode(str.substr(code1[i].size()));
                    break;
                }
            }
        }
    }

private:
    void findc(nodeTree<nodeType>* ptr , string s="")
    {
        if (ptr)
        {
            if(ptr!=rootPtr)
            {
                ptr->str=s;
                if (ptr->data!='-')
                {
                    code2.push_back(ptr->data);
                    code1.push_back(s);
                }
            }
            findc(ptr->leftPtr , ptr->str+'0');
            findc(ptr->rightPtr, ptr->str+'1');
        }
    }

   
    nodeTree<nodeType> *rootPtr;
    nodeTree<nodeType> *getNewNode(nodeType d , int w)
    {
        return new nodeTree<nodeType>(d,w);
    }
    list<nodeTree<nodeType>*> ls;
    vector<string> code1;
    vector<char>code2 ;
};
int main () 
{
    tree<char> drakht;
    string str;
    getline(cin,str);
    drakht.inputCoding(str);
    drakht.creatTree();
    drakht.findCode();
    //getchar();
    string s;
    getline(cin,s);
    drakht.decode(s);
    //cout<<"done!";
}