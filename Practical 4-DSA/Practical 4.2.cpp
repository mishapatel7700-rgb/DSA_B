#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

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

void deleteValue(int x) {
    if (head == NULL)
        return;

    if (head->data == x) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* temp = head;

    while (temp->next != NULL && temp->next->data != x)
        temp = temp->next;

    if (temp->next != NULL) {
        Node* del = temp->next;
        temp->next = del->next;
        delete del;
    }
}

void forward() {
    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void reversePrint(Node* temp) {
    if (temp == NULL)
        return;

    reversePrint(temp->next);
    cout << temp->data << " ";
}

int main() {
    int n, x;

    cout << "Enter number of patients: ";
    cin >> n;

    cout << "Enter patient tokens: ";
    for (int i = 0; i < n; i++) {
        cin >> x;
        insertEnd(x);
    }

    cout << "Queue from front to back: ";
    forward();

    cout << "Enter token to delete: ";
    cin >> x;
    deleteValue(x);

    cout << "Queue after deletion: ";
    forward();

    cout << "Queue from last to first: ";
    reversePrint(head);
    cout << endl;

    return 0;
}
