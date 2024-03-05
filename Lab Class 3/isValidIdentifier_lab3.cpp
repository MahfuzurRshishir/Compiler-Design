#include<iostream>
#include<string>
using namespace std;

bool isValidIdentifier(string variable){
     if (variable.empty()) {
        cout << "0. Invalid Identifier: Empty input" << endl;
        return false;
    }
    if(variable[0]>='0' && variable[0]<='9'){
        cout<<"0. Invalid Identifier : identifier can't start with number"<<endl;
        return false;
    }
    else if(!(variable[0]>='A' && variable[0]<='Z' ||
               variable[0]>='a' && variable[0]<='z' ||
               variable[0]>='0' && variable[0]<='9' ||
               variable[0] == '_')){
                  cout<<"0. Invalid Identifier : identifier can't start with a special character"<<endl;
                  return false;
    }
    for(int i=1; i<variable.length(); i++){
           if(!(variable[i]>='A' && variable[i]<='Z' ||
                variable[i]>='a' && variable[i]<='z' ||
                variable[i]>='0' && variable[i]<='9' ||
                variable[i] == '_')){
                  cout<<"0. Invalid Identifier : identifier can't have any special character"<<endl;
                  return false;
              }
    }
    cout<<"1. Valid identifier"<<endl;
    return true;
}
int main(){
    string input;
    cout<<"give identifier to check validity:";
    cin>>input;
    isValidIdentifier(input);
}
