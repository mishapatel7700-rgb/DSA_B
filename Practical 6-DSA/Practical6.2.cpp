#include <iostream>
using namespace std;

struct Node {
    string page;
    Node* next;
};

int main() {
    Node* top = NULL;
    int n;

    cout << "Enter number of operations: ";
    cin >> n;

    while (n--) {
        string op;
        cout << "Enter operation: ";
        cin >> op;

        if (op == "visit") {
            string page;
            cout << "Enter page: ";
            cin >> page;

            Node* newNode = new Node;
            newNode->page = page;
            newNode->next = top;
            top = newNode;

            cout << "Current page: " << top->page << endl;
        }
        else if (op == "back") {
            if (top == NULL) {
                cout << "No history available\n";
            }
            else if (top->next == NULL) {
                cout << "Already on first page\n";
            }
            else {
                Node* temp = top;
                top = top->next;
                delete temp;

                cout << "Current page: " << top->page << endl;
            }
        }
    }

    return 0;
}
