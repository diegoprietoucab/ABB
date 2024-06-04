#include <iostream>

using namespace std;

struct Node
{
    int value;
    Node *left;
    Node *right;
};

void InsertarABB(Node **p, int n)
{
    Node *nuevo = new Node();
    nuevo -> value = n;
    if (*p)
        if (n < (*p) -> value)
        {
            if (!(*p) -> left)
            {
                (*p) -> left = nuevo;
                nuevo -> left = NULL;
                nuevo -> right = NULL;
            }
            else
            {
                InsertarABB(&((*p) -> left), n);
            }
        }
        else
        {
            if (!(*p) -> right)
            {
                (*p) -> right = nuevo;
                nuevo -> left = NULL;
                nuevo -> right = NULL;
            }
            else
            {
                InsertarABB(&((*p) -> right), n);
            }
        }
    else
    {
        nuevo -> left = *p;
        *p = nuevo;
    }
}

void MostrarPostOrden(Node *p)
{
    if (p)
    {
        MostrarPostOrden(p -> left);
        MostrarPostOrden(p -> right);
        cout << p -> value << "   ";
    }
}

void MostrarPreOrden(Node *p)
{
    if (p)
    {
        cout << p -> value << "   ";
        MostrarPreOrden(p -> left);
        MostrarPreOrden(p -> right);
    }
}

void MostrarEnOrden(Node *p)
{
    if (p)
    {
        MostrarEnOrden(p -> left);
        cout << p -> value << "   ";
        MostrarEnOrden(p -> right);
    }
}

int main()
{
    Node *p = NULL;
    InsertarABB(&p, 8);
    InsertarABB(&p, 3);
    InsertarABB(&p, 11);
    InsertarABB(&p, 9);
    InsertarABB(&p, 12);
    InsertarABB(&p, 1);
    InsertarABB(&p, 5);
    InsertarABB(&p, 10);
    MostrarEnOrden(p);
    cout << "" << endl;
    cout << "" << endl;
    MostrarPreOrden(p);
    cout << "" << endl;
    cout << "" << endl;
    MostrarPostOrden(p);
    return 0;
}