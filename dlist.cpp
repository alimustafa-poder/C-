#include <iostream>
using namespace std;

struct node
{
    int data;
    node *prev;
    node *next;
};

class double_llist
{
private:
    node *head, *tail;

public:
    double_llist()
    {
        head = NULL;
        tail = NULL;
    }
    void add_item(int a)
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
    void printList()
    {
        node *temp = new node;
        temp = head;
        cout << "Linked List" << endl;
        while (temp != NULL)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
    void printReverseList()
    {
        node *temp = new node;
        temp = tail;
        cout << "Reversed Linked List" << endl;
        while (temp != NULL)
        {
            cout << temp->data << endl;
            temp = temp->prev;
        }
    }
    void insertAtHead(int a)
    {
        node *temp = new node;
        temp->data = a;
        temp->next = head;
        temp->prev = NULL;
        head->prev = temp;
        head = temp;
    }
    void insertAtPos(int pos, int n)
    {
        if (pos >= nodeLength())
        {
            add_item(n);
            return;
        }
        node *current = head;
        node *previous = NULL;
        node *temp = new node;
        temp->data = n;
        if (pos == 0)
        {
            temp->next = current;
            temp->prev = NULL;
            current->prev = temp;
            head = temp;
            return;
        }
        for (int i = 1; i <= pos; i++)
        {
            current = current->next;
            previous = current->prev;
        }
        previous->next = temp;
        temp->next = current;
        current->prev = temp;
        temp->prev = previous;
    }
    void deleteAtPos(int pos)
    {
        if (pos >= nodeLength())
        {
            cout << "Please enter a valid index." << endl;
            return;
        }
        node *current = head;
        node *next = NULL;
        if (pos == 0)
        {
            head = current->next;
            head->prev = NULL;
            delete current;
            return;
        }
        for (int i = 1; i <= pos; i++)
        {
            current = current->next;
            next = current->next;
        }
        node *previous = current->prev;
        previous->next = next;
        next->prev = previous;
        delete current;
    }

    int nodeLength()
    {
        node *temp = new node;
        temp = head;
        int length = 0;
        while (temp != NULL)
        {
            temp = temp->next;
            length++;
        }
        // cout << "Length of the Nodelist:" << length << endl;
        return length;
    }

    ~double_llist()
    {
        node *headTemp = new node;
        headTemp = head;
        while (headTemp != NULL)
        {
            head = head->next;
            delete headTemp;
            headTemp = head;
        }
        cout << "Linked List deleted." << endl;
        delete headTemp;
    }
};

int main()
{
    double_llist a;
    a.add_item(33333);
    a.add_item(4);
    a.add_item(7);
    a.add_item(80);
    a.add_item(85);
    a.add_item(90);
    a.add_item(95);
    a.nodeLength();
    a.insertAtPos(6, 76);
    a.nodeLength();
    a.deleteAtPos(1);
    a.nodeLength();
    a.printList();
    a.printReverseList();
    return 0;
}