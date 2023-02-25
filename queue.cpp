#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
    node *prev;
};

class queue
{
private:
    node *head;
    node *tail;

public:
    queue()
    {
        head = NULL;
        tail = NULL;
    }
    void push(int a)
    {
        node *temp = new node;
        temp->data = a;
        temp->next = NULL;
        if (head == NULL)
        {
            temp->prev = NULL;
            head = temp;
            tail = head;
        }
        else
        {
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
    }

    void pop()
    {
        if (head == NULL)
        {
            cout << "The Queue is empty." << endl;
            return;
        }
        node *tempTail = head;
        node *tempHead = tempTail->next;
        delete tempTail;
        if (tempHead == NULL)
        {
            head = NULL;
            cout << "The Queue is empty." << endl;
            return;
        }
        tempHead->prev = NULL;
        head = tempHead;
    }
    void printQueue()
    {
        node *temp = new node;
        temp = head;
        while (temp != NULL)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
};

int main()
{
    queue a;
    a.push(3);
    a.push(58);
    a.push(45);
    a.pop();
    a.pop();
    a.pop();
    a.pop();
    a.push(98);
    a.push(78);
    a.pop();
    a.printQueue();
    return 0;
}