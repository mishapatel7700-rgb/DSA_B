#include<iostream>
using namespace std;

int main()
{
    int marks[100];
    int n, i, j,swap1;
    int min1;

    cout<<"Enter number of answer sheets: ";
    cin>>n;

    cout<<"Enter the marks:";

  for(i = 0; i < n; i++)
    {
        cin>>marks[i];
    }

    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n-1; j++)
        {
            if(marks[j] > marks[j + 1])
            {
                swap1 = marks[j];
                marks[j] = marks[j + 1];
                marks[j + 1] = swap1;
            }
        }
    }

    cout<<"Bubble sorting:";

    for(i = 0; i < n; i++)
    {
        cout<<" "<<marks[i];
    }
    cout<<endl;

    for(i = 0; i < n - 1; i++)
    {
        min1 = i;

        for(j = i + 1; j < n; j++)
        {
            if(marks[j] < marks[min1])
            {
                min1 = j;
            }
        }

        swap1 = marks[i];
        marks[i] = marks[min1];
        marks[min1] = swap1;
    }

    cout<<"Selection Sorting:";

    for(i = 0; i < n; i++)
    {
        cout<<" "<<marks[i];
    }
    cout<<endl;

 for (int i = 1; i < n; i++) {
        int key = marks[i];
        int j = i - 1;

        while (j >= 0 && marks[j] > key) {
            marks[j + 1] = marks[j];
            j--;
        }

        marks[j + 1] = key;
    }
    cout<<"Inserted Sorting: ";
    for(i=0;i<n;i++){
        cout<<" "<<marks[i];
    }

    return 0;
}
