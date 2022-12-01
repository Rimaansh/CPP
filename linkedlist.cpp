#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* head;
int c;

void insertAtFirst(int data)
{
    Node* temp = new Node(); // or This - (Node*)malloc(sizeOf(Node));
    temp -> data = data;
    temp -> next = head;
    head = temp;
    c++;
}

void displayLL()
{
    Node* temp = head;
    while(temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp -> next;
    }
    cout << "NULL \n";
}

void deletek(Node* head, int k, int m)
{
    Node* curr = head, *prev = head;
    while(curr -> next != NULL || k-->0)
    {
        for(int i = 0; curr -> next != NULL && i<m; curr = curr->next, i++);
        Node* temp = curr;
        prev -> next = curr;
        prev = curr;
        delete(temp);
    }
}

int main()
{
    head = NULL;
    c = 0;
    cout << "How many nos?" << endl;
    int n;
    cin >> n;
    for(int i = 0; i<n; i++)
    {
        cout << "Enter the number - \n";
        int data;
        cin >> data;
        insertAtFirst(data);
    }
    displayLL();
    deletek(head, 2, 2);
    displayLL();
}
