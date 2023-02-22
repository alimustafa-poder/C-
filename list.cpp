#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

class linkedList
{
private:
    node *head, *tail;

public:
    linkedList()
    {
        head = NULL;
        tail = NULL;
    }
    void addNode(int n)
    {
        node *tmp = new node;
        tmp->data = n;
        tmp->next = NULL;
        if (head == NULL)
        {
            head = tmp;
            tail = tmp;
        }
        else
        {
            tail->next = tmp;
            tail = tmp;
        }
    }
    void insertStart(int n)
    {
        node *tmp = new node;
        tmp->data = n;
        tmp->next = head;
        head = tmp;
    }
    void display()
    {
        node *tmp = new node;
        tmp = head;
        while (tmp != NULL)
        {
            cout << tmp->data << endl;
            tmp = tmp->next;
        }
    }
    ~linkedList()
    {
        node *tmp = new node;
        tmp = head;
        while (tmp != NULL)
        {
            head = head->next;
            delete tmp;
            tmp = head;
        }
        cout << "List deleted" << endl;
    }
};

int main()
{
    linkedList a;
    a.addNode(1);
    a.addNode(2);
    a.addNode(3);
    a.addNode(4);
    a.insertStart(0);
    a.display();
    return 0;
}