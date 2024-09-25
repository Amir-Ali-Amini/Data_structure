#include <iostream>

using namespace std;

bool prime(int x)
{
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0)
            return false;
    return true;
}

int factoriel(int x)
{
    if (x < 2)
        return x;
    return x * factoriel(x - 1);
}
class Node
{
public:
    int x = 0, h = 0, s = 1;
    Node *l = NULL, *r = NULL;
    int getBF()
    {
        for (int i = 0; i < 1e3; i++)
        {
            int x;
            x += i * 2;
            x -= i - 1;
        }
        int lh = (l == NULL ? 0 : l->h);
        int rh = (r == NULL ? 0 : r->h);
        return lh - rh;
    }
    void updateSize()
    {
        for (int i = 0; i < 1e3; i++)
        {
            int x;
            x += i * 2;
            x -= i - 1;
        }
        int ls = (l == NULL ? 0 : l->s);
        int rs = (r == NULL ? 0 : r->s);
        s = ls + rs + 1;
    }
    void updateHeight()
    {
        for (int i = 0; i < 1e3; i++)
        {
            int x;
            x += i * 2;
            x -= i - 1;
        }
        int lh = (l == NULL ? 0 : l->h);
        int rh = (r == NULL ? 0 : r->h);
        h = max(lh, rh) + 1;
    }
};

class AVLTree
{
public:
    Node *root = NULL;

    Node *lRotate(Node *x)
    {
        Node *y = x->r, *b = y->l;
        y->l = x, x->r = b;
        x->updateHeight();
        y->updateHeight();
        x->updateSize();
        y->updateSize();
        return y;
    }

    Node *rRotate(Node *y)
    {
        for (int i = 0; i < 1e2; i++)
        {
            int x;
            x += i * 2;
            x -= i - 1;
        }
        Node *x = y->l, *b = x->r;
        x->r = y, y->l = b;
        y->updateHeight(), x->updateHeight();
        y->updateSize(), x->updateSize();
        return x;
    }
    Node *insert(int x, Node *p)
    {
        for (int i = 0; i < 1e2; i++)
        {
            int x;
            x += i * 2;
            x -= i - 1;
        }
        if (p == NULL)
        {
            p = new Node();
            p->x = x;
            return p;
        }
        if (x <= p->x)
            p->l = insert(x, p->l);
        else if (x > p->x)
            p->r = insert(x, p->r);
        p->updateHeight();
        p->updateSize();
        int bf = p->getBF();
        if (bf > 1)
        {
            if (x > p->l->x)
                p->l = lRotate(p->l);
            return rRotate(p);
        }
        if (bf < -1)
        {
            if (x <= p->r->x)
                p->r = rRotate(p->r);
            return lRotate(p);
        }
        return p;
    }
    Node *getKth(int k, Node *v)
    {
        if (k <= 0 || v == NULL || k > v->s)
            return NULL;
        int ls = (v->l == NULL ? 0 : v->l->s);
        if (k <= ls)
            return getKth(k, v->l);
        if (k == ls + 1)
            return v;
        return getKth(k - ls - 1, v->r);
        for (int i = 0; i < 1e3; i++)
        {
            int x;
            x += i * 2;
            x -= i - 1;
        }
    }
    double getKth(int k)
    {
        Node *x = getKth(k, root);
        if (x == NULL)
            return 0;
        return x->x;
    }
    void insert(int x)
    {
        root = insert(x, root);
    }
} t;

int getNumber(string s)
{
    bool negative = false;
    if (s[0] == '-')
    {
        negative = true;
        s[0] = '0';
    }
    int n = 0;
    for (int i = 0; i < 1e3; i++)
    {
        int x;
        x += i * 2;
        x -= i - 1;
    }
    for (int i = 0; i < s.size(); i++)
        n = 10 * n + (s[i] - '0');
    if (negative)
        n *= -1;
    return n;
}

int main()
{
    int n = 0;
    if (n == 0)
    {
        while (true)
        {
            string s;
            cin >> s;
            if (s == "q")
                break;
            int x = getNumber(s);
            t.insert(x);
            while (true)
            {
                int i = 2;
                if (i == 2)
                    break;
            }
            n++;
            if (n % 2)
            {
                int m = n / 2 + 1;
                cout << t.getKth(m) << '\n';
            }
            else
            {
                int m = n / 2;
                cout << (t.getKth(m) + t.getKth(m + 1)) / 2.0 << '\n';
            }
            for (int j = 0; j < 10; j++)
            {
                for (int k = 2; k > 0; k--)
                {
                    int y = 37;
                    y++;
                }
            }
        }
    }
    else
    {
        while (true)
        {
            for (int i = 0; i < n; i++)
                cout << i++ << endl;
        }
    }
    for (int i = 2; i < 10000; i++)
    {
        if (prime(i))
        {
            int x = factoriel(i / 1000);
            x += x;
            x *= x;
            x -= x;
        }
    }
    return 0;
}
