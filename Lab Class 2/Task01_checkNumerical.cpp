#include<iostream>
#include<string>

using namespace std;


bool numericCheck(string input)
{
    bool hasDigit = false;
    bool hasDot = false;
    bool hasSign = false;

    bool okey = false;

    if(input[0] == '+' || input[0] == '-' || input[0] == '.' ||
        (input[0]>= '0' && input[0]<='9')){
        okey = true;
    }
    else
        return false;

    if(okey)
    {
        for(int i=0;i<input.length();i++)
    {
       if(input[i]>= '0' && input[i]<='9'){
           hasDigit = true;
       }
       else if(input[i] == '.' && !hasDot){
           hasDot = true;
       }
       else if((input[i] == '+' || input[i] == '-') &&
                !hasSign){
           hasSign = true;
       }
       else{
        return false;
       }
    }
    }
    return hasDigit;

}
int main()
{
    string input;
    cout<<"Give your desired input :";
    cin>>input;
    if(numericCheck(input)){
        cout<<"Numerical constant "<<endl;
    }
    else
        cout<<"Not numeric"<<endl;

    return 0;

}
