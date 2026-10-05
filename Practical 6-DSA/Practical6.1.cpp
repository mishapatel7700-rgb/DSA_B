#include<iostream>
using namespace std;

class Stack {
    int *tray;
    int top;
    int capacity;

public:
    Stack(int n) {
        capacity = n;
        tray= new int[n];
        top = -1;
    }

    void place(int value) {
        if (top == capacity - 1) {
            cout << "Error: Stack Overflow" << endl;
            return;
        }

        tray[++top] = value;
        cout << "Top: " << tray[top] << endl;
    }

    void take() {
        if (top == -1) {
            cout << "Error: Stack Underflow" << endl;
            return;
        }

        top--;

        if (top == -1)
            cout << "Top: Empty" << endl;
        else
            cout << "Top: " << tray[top] << endl;
    }

    ~Stack() {
        delete[] tray;
    }
};

int main() {
    int n, operations;
    cout<<"Enter n: ";
    cin >> n;
    cout<<"Enter number of operations:";
    cin >> operations;

    Stack s(n);

    for (int i = 0; i < operations; i++) {
        string operation;
        cout<<"Enter operation:";
        cin >> operation;

        if (operation == "place") {
            int value;
            cout<<"Enter position to place: ";
            cin >> value;
            s.place(value);
        }
        else if (operation == "take") {
            s.take();
        }
    }

    return 0;
}

