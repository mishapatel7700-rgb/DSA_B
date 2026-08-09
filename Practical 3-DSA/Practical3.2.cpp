#include<iostream>
using namespace std;

int main(){
int arr[100];
int n,i,j,swap1;

cout<<"Enter no. of buckets: ";
cin>>n;
cout<<"Enter the values: ";
for(i=0;i<n;i++){

        cin>>arr[i];
        }
        for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                swap1 = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = swap1;
            }
        }
    }

for(i=0;i<n;i++){
    cout<<" "<<arr[i];
}
return 0;

}
