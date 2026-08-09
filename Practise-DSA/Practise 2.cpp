#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    float f1[n];

    cout<<"Enter the no.s: ";
    for(int i=0;i<n;i++){
        cin>>f1[i];
    }
    for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if (f1[i]==f1[j]){
            cout<<"Duplicate number";
            return 0;
        }
            }
    }
        cout<<"No duplicate no."<<endl;

    return 0;
}
