#include <iostream>
using namespace std;

int main(){

    int n,m;
    string target;

    cout<<"Enter number of cars: ";
    cin>>n;
    cout<<"Enter the number where cars stops: ";
    cin>>m;
    string license[n];
    cout<<"Enter number plates: ";
    for(int i=0;i<n;i++){
    cin>>license[i];
    }
    cout<<"Enter the target plate: ";
    cin>>target;

     for(int i=0;i<n;i++)
        {
            if(license[i] == target){
                cout<<"Target plate found at "<<i<<" position"<<endl;
               return 0;
            }
        }

            cout<<"Target plate not found! "<<endl;
            for(int i=-1;i=m;i++)
        {
            if(license[i] == target){
                cout<<"Target plate found at "<<i<<" position"<<endl;
                return 0;
            }
        }
     return 0;
}

