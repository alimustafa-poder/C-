#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
};

// class definition
class BTree
{
private:
    node *root;
    node *tempRoot = root;
    void pushNode(node *temp);

public:
    node *start;
    BTree()
    {
        root = NULL;
    }

    void push(int a);

    void print(node *temp);
};

void BTree::print(node *temp)
{
    node *start = temp;
    if (start == NULL)
    {
        return;
    }

    print(start->left);
    cout << start->data << endl;
    print(start->right);
}

void BTree::push(int a)
{
    node *temp = new node;
    temp->data = a;
    temp->left = NULL;
    temp->right = NULL;
    if (root == NULL)
    {
        root = temp;
        tempRoot = root;
        start = root;
        return;
    }
    pushNode(temp);
}

void BTree::pushNode(node *temp)
{
    if (temp->data < tempRoot->data)
    {
        if (tempRoot->left == NULL)
        {
            tempRoot->left = temp;
        }
        else
        {
            tempRoot = tempRoot->left;
            pushNode(temp);
        }
    }
    else if (temp->data > tempRoot->data)
    {
        if (tempRoot->right == NULL)
        {
            tempRoot->right = temp;
        }
        else
        {
            tempRoot = tempRoot->right;
            pushNode(temp);
        }
    }
    else
    {
        // pick any side left or right and append
        if (tempRoot->left == NULL)
        {
            tempRoot->left = temp;
        }
        else if (tempRoot->right = NULL)
        {
            tempRoot->right = temp;
        }
        else
        {
            tempRoot = tempRoot->left;
            pushNode(temp);
        }
    }
    tempRoot = root;
}

int main()
{
    BTree t;
    t.push(9);
    t.push(8);
    t.push(7);
    t.push(6);
    t.push(19);
    t.push(19);
    t.push(29);
    t.push(1);
    t.push(54);
    t.print(t.start);
    return 0;
}
