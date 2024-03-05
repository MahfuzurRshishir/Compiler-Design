#include<iostream>
#include<fstream>
#include<string>

using namespace std;

bool isKeyword(string variable, ifstream& keywordFile)
{
    string keyword;
    //string whiteSpace;
    while(getline(keywordFile,keyword,',')){
          //  if(getline())
                 if(variable==keyword){
                       return true;
                }
    }
    return false;
}

bool isValidIdentifier(string variable)
{
    ifstream keywordFile("E:\\Compiler Design\\Lab Class 3\\CPP_keywords.txt");
    if(!keywordFile.is_open()){
        cout<<"couldn't open file"<<endl;
        return false;
    }
    if(isKeyword(variable, keywordFile)){
        cout<<"0. Invalid Identifier: can not have the name of a keyword"<<endl;
        return false;
    }
    else{
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
      cout<<"1.Valid identifier"<<endl;
      return true;

    }

    keywordFile.close();

}
int main()
{
    string input;
    cout<<"give identifier to check validity:";
    cin>>input;
    isValidIdentifier(input);

    return 0;
}
