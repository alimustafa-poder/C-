#include <iostream>
using namespace std;

/*
@Param add_item <int>
@Param insertAtHead <int>
@Param insertAtPos <int, int>
@Param deleteAtPos <int, int>
@Param sortList <string>
*/

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
        while (temp != NULL)
        {
            cout << temp->data << endl;
            temp = temp->prev;
        }
    }
    void insertAtHead(int a)
    {
        if (head == NULL)
        {
            cout << "The list is empty. Cannot insert at the start.";
            return;
        }
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
            insertAtHead(n);
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
        if (pos >= nodeLength() || nodeLength() == 0)
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

    void sortList(string order)
    {
        if (head == NULL)
        {
            return;
        }
        node *temp = NULL;
        temp = head;
        cout << "Sorted List" << endl;
        while (temp != NULL)
        {
            if (temp->next == NULL)
                break;
            node *key = temp->next;
            if (key->data < temp->data)
            {
                cout << key->data << " " << temp->data << endl;
                node *previous = key->prev;
                while (previous != NULL)
                {
                    // Travering back to compare every element.
                    cout << previous->data << " traverse back " << key->data << endl;
                    if (previous->data < key->data)
                    {
                        break;
                    }
                    else
                    {
                        int tempData = key->data;
                        key->data = previous->data;
                        previous->data = tempData;
                        key = key->prev;
                        previous = previous->prev;
                    }
                }
            }
            temp = temp->next;
        }
        if (order == "ASC")
        {
            printList();
        }
        else
        {
            printReverseList();
        }
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
    a.add_item(43);
    a.add_item(7652);
    a.add_item(1);
    a.insertAtPos(4, 5);
    a.add_item(-1);
    a.add_item(0);
    a.add_item(1);
    a.deleteAtPos(3);
    a.add_item(-9999);
    a.add_item(9);
    a.add_item(-9989898);
    a.add_item(87);
    a.add_item(-323);
    a.sortList("DSC");
    return 0;
}