#include <iostream>
#include <string>
using namespace std;

int main() {
    string sen, word = "", longest = "";

    cout << "Enter a sentence: ";
    getline(cin, sen);

    for (int i = 0; i <= sen.length(); i++) {
        if (i == sen.length() || sen[i] == ' ') {

            if (word.length() > longest.length()) {
                longest = word;
            }

            word = "";
        }
        else {
            word += sen[i];
        }
    }

    cout << "Longest word: " << longest << endl;
    cout << "Length: " << longest.length() << endl;

    return 0;
}
