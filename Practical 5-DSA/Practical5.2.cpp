#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next, *prev;
    Node(int x) {
        data = x;
        next = prev = nullptr;
    }
};

class SCLL {
    Node* head = nullptr;

public:
    void join(int x, int pos) {
        Node* n = new Node(x);

        if (!head) {
            head = n;
            n->next = head;
            return;
        }

        Node* p = head;
        for (int i = 1; i < pos && p->next != head; i++)
            p = p->next;

        n->next = p->next;
        p->next = n;
    }

    void leave(int x) {
        if (!head) return;

        if (head->data == x) {
            if (head->next == head) {
                delete head;
                head = nullptr;
                return;
            }

            Node* tail = head;
            while (tail->next != head)
                tail = tail->next;

            Node* temp = head;
            head = head->next;
            tail->next = head;
            delete temp;
            return;
        }

        Node* p = head;
        while (p->next != head && p->next->data != x)
            p = p->next;

        if (p->next->data == x) {
            Node* temp = p->next;
            p->next = temp->next;
            delete temp;
        }
    }

    void display() {
        if (!head) {
            cout << "Empty\n";
            return;
        }

        Node* p = head;
        do {
            cout << p->data << " ";
            p = p->next;
        } while (p != head);

        cout << "\n";
    }
};


class DCLL {
    Node* head = nullptr;

public:
    void join(int x, int pos) {
        Node* n = new Node(x);

        if (!head) {
            head = n;
            n->next = n->prev = n;
            return;
        }

        Node* p = head;
        for (int i = 1; i < pos && p->next != head; i++)
            p = p->next;

        n->next = p->next;
        n->prev = p;
        p->next->prev = n;
        p->next = n;
    }

    void leave(int x) {
        if (!head) return;

        Node* p = head;

        do {
            if (p->data == x) {
                if (p->next == p) {
                    head = nullptr;
                } else {
                    p->prev->next = p->next;
                    p->next->prev = p->prev;

                    if (p == head)
                        head = p->next;
                }

                delete p;
                return;
            }
            p = p->next;
        } while (p != head);
    }

    void display() {
        if (!head) {
            cout << "Empty\n";
            return;
        }

        Node* p = head;
        do {
            cout << p->data << " ";
            p = p->next;
        } while (p != head);

        cout << "\n";
    }
};

int main() {
    SCLL s;
    DCLL d;

    s.join(1, 1);
    d.join(2, 2);

    s.join(2, 1);
    d.join(2, 1);

    s.join(3, 2);
    d.join(3, 2);

    cout << "Singly Circular: ";
    s.display();

    cout << "Doubly Circular: ";
    d.display();

    s.leave(2);
    d.leave(2);

    cout << "After leaving 2:\n";
    cout << "Singly Circular: ";
    s.display();

    cout << "Doubly Circular: ";
    d.display();
}
