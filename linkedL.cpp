#include <iostream>
using namespace std;

class Node
{
    int data;
    Node *next;

public:
    void insertAtBegin(int);
    void display();
} * head;

void Node::insertAtBegin(int n)
{
    Node *temp = new Node;
    temp->data = n;
    temp->next = NULL;
    if (head == NULL)
        head = temp;
    else
    {
        temp->next = head;
        head = temp;
    }
}

void Node::display()
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    Node n;

    n.insertAtBegin(5);
    n.insertAtBegin(52);
    n.insertAtBegin(524);
    n.insertAtBegin(53);
    n.display();
}