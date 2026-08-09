#include<iostream>
#include<string>
using namespace std;

int main (){
    string namel;
    string name2;
    int ch;
    cout<<"Enter name 1: ";
    cin>>namel;
    cout<<"Enter name 2: ";
    cin>>name2;

    if (namel.length() > name2.length()){
    cout<<namel<<" greater than "<<name2<<endl;
    cout<<"Length is: "<<namel.length();
    }
    else if(name2.length() > namel.length()){
  cout<<name2<<" greater than "<<namel<<endl;
   cout<<"Length is: "<<name2.length();
}
else{
    cout<<namel<<" is Equal to "<<name2<<endl;
     cout<<"Length is: "<<namel.length();
}
return 0;
}
