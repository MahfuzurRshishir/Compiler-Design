#include<iostream>
using namespace std;

int maxOfArr(int arr[], int size)
{
    int maxVal = arr[0];
    for(int i=0; i<size; i++)
    {
        if(maxVal < arr[i])
        {
            maxVal = arr[i];
        }
    }
    return maxVal;

}
int minOfArr(int arr[], int size)
{
    int minVal = arr[0];
    for(int i=0; i<size; i++)
    {
        if(minVal > arr[i])
        {
            minVal = arr[i];
        }
    }
    return minVal;

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
    cout<<"Max value of the array is : "<<maxOfArr(arr, size)<<endl;
    cout<<"Min value of the array is : "<<minOfArr(arr, size)<<endl;

}
