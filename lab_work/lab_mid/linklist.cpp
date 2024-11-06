#include <iostream>
using namespace std;

class Node
{
private:
    char data;
    Node *next;

public:
    Node()
    {
        this->data = '\0';
        this->next = nullptr;
    }

    Node(char data, Node *next = nullptr)
    {
        this->data = data;
        this->next = next;
    }

    ~Node()
    {
        cout << "Node with data '" << this->data << "' is getting destructed!!!" << endl;
    }

    char getData()
    {
        return data;
    }

    void setData(char data)
    {
        this->data = data;
    }

    Node *getNext()
    {
        return next;
    }

    void setNext(Node *next)
    {
        this->next = next;
    }
};

class LinkedList
{
private:
    Node *start;
    Node *avail;

public:
    LinkedList()
    {
        start = nullptr;
        avail = nullptr;
    }

    ~LinkedList()
    {
        cout << "LinkedList is getting destructed!!!" << endl;

        Node *current = this->start;
        while (current != nullptr)
        {
            Node *toBeDeleted = current;
            current = current->getNext();
            delete toBeDeleted;
        }

        current = this->avail;
        while (current != nullptr)
        {
            Node *toBeDeleted = current;
            current = current->getNext();
            delete toBeDeleted;
        }
    }

    Node *getStart()
    {
        return start;
    }

    void setStart(Node *start)
    {
        this->start = start;
    }

    Node *getAvail()
    {
        return avail;
    }

    void setAvail(Node *avail)
    {
        this->avail = avail;
    }

    void init()
    {
        Node *node1 = new Node('A', nullptr);
        Node *node4 = new Node('D', node1);
        Node *node8 = new Node('F', node4);
        Node *node2 = new Node('B', node8);
        Node *node7 = new Node('E', node2);
        Node *node3 = new Node('C', node7);
        Node *node5 = new Node('\0', nullptr);
        Node *node6 = new Node('\0', node5);

        this->start = node3;
        this->avail = node6;
    }

    void traverse()
    {
        if (this->start == nullptr)
        {
            cout << "List is Empty!!!" << endl;
            return;
        }

        Node *current = this->start;
        while (current != nullptr)
        {
            cout << current->getData();
            if (current->getNext() != nullptr)
            {
                cout << " ---> ";
            }
            else
            {
                cout << endl << endl;
            }

            current = current->getNext();
        }
    }

    void insertAtTheBeginning(char element)
    {
        Node *newNode = new Node(element, this->start);
        this->start = newNode;
    }

    void insertAtTheEnd(char element)
    {
        Node *newNode = new Node(element);
        if (this->start == nullptr)
        {
            this->start = newNode;
        }
        else
        {
            Node *current = this->start;
            while (current->getNext() != nullptr)
            {
                current = current->getNext();
            }
            current->setNext(newNode);
        }
    }

    void insertAfter(char element, char newElement)
    {
        Node *current = this->start;
        while (current != nullptr && current->getData() != element)
        {
            current = current->getNext();
        }
        if (current != nullptr)
        {
            Node *newNode = new Node(newElement, current->getNext());
            current->setNext(newNode);
        }
    }

    void insertBefore(char element, char newElement)
    {
        if (this->start == nullptr) return;

        if (this->start->getData() == element)
        {
            insertAtTheBeginning(newElement);
            return;
        }

        Node *current = this->start;
        while (current->getNext() != nullptr && current->getNext()->getData() != element)
        {
            current = current->getNext();
        }
        if (current->getNext() != nullptr)
        {
            Node *newNode = new Node(newElement, current->getNext());
            current->setNext(newNode);
        }
    }

    void remove(char element)
    {
        if (this->start == nullptr) return;

        if (this->start->getData() == element)
        {
            Node *toBeDeleted = this->start;
            this->start = this->start->getNext();
            delete toBeDeleted;
            return;
        }

        Node *current = this->start;
        while (current->getNext() != nullptr && current->getNext()->getData() != element)
        {
            current = current->getNext();
        }
        if (current->getNext() != nullptr)
        {
            Node *toBeDeleted = current->getNext();
            current->setNext(toBeDeleted->getNext());
            delete toBeDeleted;
        }
    }
};

int main()
{
    LinkedList list;

    cout << "Initial phase of the list: " << endl;
    list.init();
    list.traverse();

    cout << "After inserting 'G' after 'B' in the list: " << endl;
    list.insertAfter('B', 'G');
    list.traverse();

    cout << "After inserting 'H' at the end of the list: " << endl;
    list.insertAtTheEnd('H');
    list.traverse();

    cout << "After deleting 'A' from the list: " << endl;
    list.remove('A');
    list.traverse();

    cout << "After deleting 'C' from the list: " << endl;
    list.remove('C');
    list.traverse();

    cout << "After inserting 'M' at the beginning of the list: " << endl;
    list.insertAtTheBeginning('M');
    list.traverse();

    cout << "After inserting 'N' before 'E' in the list: " << endl;
    list.insertBefore('E', 'N');
    list.traverse();

    return 0;
}
