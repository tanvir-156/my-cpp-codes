#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[100], n;

    cout<< "Enter the number of elements: ";{
    cin>> n;
    }
    cout<< "Enter elements: ";
    {
        for (int i=0; i<100; i++){
            cin>> arr[i];
        }
        for(int i=0; i<99; i++){
        for (int j=0; j<99-i; j++){
            if(arr[j]>arr[j+1]){
                swap (arr[j], arr[j+1]);
            }
        }
        }
    }
    cout<<"Sorted Array: ";
    for (int i=0; i<100; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}
