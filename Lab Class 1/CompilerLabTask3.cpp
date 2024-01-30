#include<iostream>
#include<cstring>
#include<stack>
using namespace std;
const int maxLen =100;

int main()
{
    char* firstName = new char[maxLen];
    char* lastName = new char[maxLen];

    cout<<"Enter your first name : ";
    for(int i=0; i<)
    cin>>firstName;
    cout<<"Enter your last name : ";
    cin>>lastName;



    char* fullName = new char[maxLen*2];

    int length = 0;
    while(firstName != '\0')
    {
        ++length;
    }
    cout<<length;
    strcpy(fullName, firstName);
    strcat(fullName, " ");
    strcat(fullName,lastName);

    cout<<"Full name is : "<<fullName;



}
