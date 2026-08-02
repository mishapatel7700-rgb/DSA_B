#include<iostream>
using namespace std;

 void Display(int ns,int ID){
        cout<<ns<<" Students borrowed more than 1 book of "<<ID<<endl;
    }
    
int main(){
    int ID;
    int n, ns;
    
     cout<<"Enter no. of books issued: ";
    cin>>n;
    for(int i=0;i<n;i++){
    cout<<"Enter book IDS: ";
    cin>>ID;

    cout<<"Enter no. of students borrowed the book of ID: ";
    cin>>ns;

    if(ns>1){
        Display(ns,ID);
    }
    }
}
