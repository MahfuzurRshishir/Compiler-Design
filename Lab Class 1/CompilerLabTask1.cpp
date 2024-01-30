#include<iostream>
using namespace std;

int avgArr(int arr[], int size)
{
    int total = 0;
    int avg;
    for(int i=0; i<size; i++)
    {
        total += arr[i];
    }
    avg = total/size;
    return avg;


}
int main()
{
    int size;
    cout<<"enter the size of the array"<<endl;
    cin>>size;

    int arr[size];
    cout<<"enter "<<size<<" elements for the array"<<endl;
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    cout<<"your average is : "<<avgArr(arr, size)<<endl;


}
