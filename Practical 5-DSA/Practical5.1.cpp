#include<iostream>
using namespace std;

int count1=0;
struct Node{
    string s;
    Node* prev;
    Node* next;
};
Node* head=NULL;
Node* tail=NULL;

void insert_front(string song){
    Node* newNode = new Node;
    newNode->s = song;
    newNode->next = head;
    newNode->prev = NULL;

    if (head != NULL)
        head->prev = newNode;
    else
        tail = newNode;
    head = newNode;
    count1++;
}

void insert_end(string song) {
    Node* newNode = new Node;
    newNode->s = song;
    newNode->next = NULL;
    newNode->prev = tail;

    if(tail !=NULL){

    tail->next = newNode;
    }
else{
    head = newNode;
}

tail = newNode;
count1++;
    }

void insert_After(string target, string song) {
    Node* temp = head;

    while (temp != NULL && temp->s != target)
        temp = temp->next;

    if (temp == NULL) {
        cout << "Song not found"<<endl;
        return ;
    }

    Node* newNode = new Node;
    newNode->s = song;

    newNode->prev = temp;
    newNode->next = temp->next;

if (temp->next != NULL){
        temp->next->prev = newNode;
}
    else{
        tail = newNode;
    }
    temp->next = newNode;
    count1++;
}
void remove_First() {
    if (head == NULL) {
        cout << "No songs"<<endl;
        return ;
    }

    Node* temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;
if (head != NULL)
        head->prev = NULL;
    else
        tail = NULL;

    delete temp;
    count1--;
}
int main() {
    int choice;
    string song, target;

    do {
        cout<<"ENTER YOUR CHOICE"<<endl;
        cout << "1. Add song at beginning"<<endl;
        cout << "2. Add song at end"<<endl;
        cout << "3. Insert song after a song"<<endl;
        cout << "4. Remove first song"<<endl;
        cout << "0. Exit!!"<<endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                cout << "Enter song: ";
                cin >> song;
                insert_front(song);
                break;

            case 2:
                cout << "Enter song: ";
                cin >> song;
                insert_end(song);
                break;

            case 3:
                cout << "Enter song after which to insert: ";
                cin >> target;

                cout << "Enter new song: ";
                cin >> song;

                insert_After(target, song);
                break;

            case 4:
                remove_First();
                break;

            case 0:
                cout << "Exit!!";
                break;

            default:
                cout << "Invalid choice.";
        }

    } while (choice != 0);

    return 0;
}
