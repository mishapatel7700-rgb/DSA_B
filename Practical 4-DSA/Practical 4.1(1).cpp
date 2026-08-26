#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void insertFront(int x) {
    Node* newNode = new Node;
    newNode->data = x;
    newNode->next = head;
    head = newNode;
}

void insertEnd(int x) {
    Node* newNode = new Node;
    newNode->data = x;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

void insertPosition(int x, int pos) {
    if (pos <= 0) {
        insertFront(x);
        return;
    }

    Node* temp = head;

    for (int i = 1; i < pos && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        insertEnd(x);
        return;
    }

    Node* newNode = new Node;
    newNode->data = x;
    newNode->next = temp->next;
    temp->next = newNode;
}

void display() {
    Node* temp = head;

    cout << "Queue: ";

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main() {
    int n, type, x, pos;

    cout << "Enter number of Patients: ";
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cout << "Enter operation: ";
        cin >> type;
        cout<<"Enter value of ID: ";
        cin>>x;


        if (type == 1) {
            insertFront(x);
        }
        else if (type == 2) {
            insertEnd(x);
        }
        else if (type == 3) {
            cin >> pos;
            insertPosition(x, pos);
        }

        cout << "After operation " << i << ": ";
        display();
    }

    return 0;
}
