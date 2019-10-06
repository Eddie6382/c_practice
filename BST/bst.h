#ifndef _BST_H_
#define _BST_H_
#include <iostream>
using namespace std;

class Node
{
public:
    Node(int _key)
    {
        key = _key;
        left = right = NULL;
    }
    int key;
    //string element
    Node *left;
    Node *right;
};

class BST
{
public:
    BST()
    {
        root = NULL;
    }
    void insert(int _key)
    {
        if (root == NULL)
            root = new Node(_key);
        else
            insert(root, _key);
    }
    bool search(int _key) const
    {
        if (root == NULL)
            return false;
        else
            return search(root, _key);
    }
    void printInOrder() const
    {
        if (root == NULL)
            cout << endl;
        else
            printInOrder();
    }

protected:
    // p can never be NULL
    void
    insert(Node *p, int _key)
    {
        if (p->key > _key)
        {
            if (p->left == NULL)
                p->left = new Node(_key);
            else
                insert(p->left, _key);
        }
        else //right
        {
            if (p->right == NULL)
                p->right = new Node(_key);
            else
                insert(p->right, _key);
        }
    }
    bool search(Node *p, int _key) const
    {
        if (p->key > _key)
        {
            if (p->left == NULL)
                return false;
            else
                return search(p->left, _key);
        }
        else if (p->key < _key)
        {
            if (p->right == NULL)
                return false;
            else
                return search(p->right, _key);
        }
        else //==
            return true;
    }

    void printInOrder(Node *p) const
    {
        if (p->left != NULL)
            printInOrder(p->left);
        cout << p->key << " ";
        if (p->right != NULL)
            printInOrder(p->right);
    }
    Node *root;
};

#endif