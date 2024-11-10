#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int val)
    {
        data = val;
        next = NULL;
    };
};

void insertAtHead(node *&head, int val)
{
    node *n = new node(val);
    n->next = head;
    head = n;
}

void insertAtTail(node *&head, int val)
{
    node *n = new node(val);

    if (head == NULL)
    {
        head = n;
        return;
    }

    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}

void display(node *head)
{
    node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << "-->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

bool search(node *&head, int key)
{
    node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void deleteAtHead(node *&head)
{
    node *toDelete = head;
    head = head->next;

    delete toDelete;
}

void deletion(node *&head, int val)
{
    node *temp = head;

    if (head == NULL)
    {
        return;
    }
    else if (head->next == NULL)
    {
        deleteAtHead(head);
    }
    else
    {
        while (temp->next->data != val)
        {
            temp = temp->next;
        }
        node *toDelete = temp->next;
        temp->next = temp->next->next;

        delete toDelete;
    }
}

node *reverse(node *&head)
{
    node *prePtr = NULL;
    node *currPtr = head;
    node *nextPtr;

    while (currPtr != NULL)
    {
        nextPtr = currPtr->next;
        currPtr->next = prePtr;

        prePtr = currPtr;
        currPtr = nextPtr;
    }
    return prePtr;
}

int main()
{
    node *head = NULL;
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtTail(head, 6);
    insertAtTail(head, 7);
    cout << "Initial linked list: " << endl;
    display(head);

    cout << "After insert 1 at first linked list: " << endl;
    insertAtHead(head, 1);
    display(head);

    cout << "Searching '3' on linked list: " << endl;
    cout << search(head, 3) << endl;

    cout << "Delete from linked list: " << endl;
    deletion(head, 2);
    display(head);

    cout << "Delete from 1st item on linked list: " << endl;
    deleteAtHead(head);
    display(head);

    cout << "After reverse current linked list: " << endl;
    node* newHead = reverse(head);
    display(newHead);

    return 0;
}
