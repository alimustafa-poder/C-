#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

class stack
{
private:
    node *head;

public:
    stack()
    {
        head = NULL;
    }

    void push(int a)
    {
        node *temp = new node;
        temp->data = a;
        temp->next = NULL;
        if (head == NULL)
        {
            head = temp;
        }
        else
        {
            node *temp2 = head;
            temp->next = head;
            head = temp;
        }
    }

    void pop()
    {
        if (head == NULL)
        {
            cout << "The stack is empty." << endl;
            return;
        }
        node *temp = head;
        int data = temp->data;
        head = temp->next;
        cout << "The value " << data << " has been popped of the stack." << endl;
        delete temp;
    }

    void printStack()
    {
        node *temp = head;
        while (temp != NULL)
        {
            cout << "The value " << temp->data << " has been added to the stack." << endl;
            temp = temp->next;
        }
    }

    int length()
    {
        node *temp = head;
        int size = 0;
        while (temp != NULL)
        {
            size++;
            temp = temp->next;
        }
        cout << "The size of the stack is " << size << "." << endl;
        return size;
    }
};

int main()
{
    stack k;
    k.push(10);
    k.push(20);
    k.push(30);
    k.printStack();
    k.pop();
    k.pop();
    k.pop();
    k.pop();
    k.push(80);
    k.push(90);
    k.pop();
    k.pop();
    k.length();
    k.printStack();
    return 0;
}