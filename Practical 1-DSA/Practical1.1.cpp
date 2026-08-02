#include<iostream>
using namespace std;

int main(){
    int n,i,j;
    cout<<"enter no. of items: ";
    cin>>n;
    int arr[n];
    int h;
    cout<<"Enter no. of hours: ";
    cin>>h;
    

    cout<<"Enter elements: ";
    for(i=0;i<n;i++){
        cin>>arr[i];
    }

     for(int j = 0; j < h; j++) {
    int FE = arr[0];

    for(int i = 0; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    arr[n - 1] = FE;
}
    cout<<"Final Array: ";
    for(i=0;i<n;i++){
    cout<<arr[i]<<" ";
    }
}
    