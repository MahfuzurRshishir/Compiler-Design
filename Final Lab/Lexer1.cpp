#include<iostream>
#include<fstream>
#include<sstream>
#include<string>

using namespace std;


int isKeyword(string variable, ifstream& keywordFile)
{
    string keyword;
    string dataType[8]={"int","short","long","float","double","char","bool","void"};
    string builtInNames[2]={"cin","cout"};
    string operatorList[]={"+", "-", "*", "/", "%","++", "--","=", "+=",
                           "-=", "*=", "/=", "%=","==", "!=", "<", ">",
                           "<=", ">=","&&", "||", "!","&", "|", "^", "~",
                           "<<", ">>","&","::",};
     string punctList[]={",", ".", ";", ":", "?", "!", "\"", "'", "(",
                        ")", "[", "]", "{", "}", "#", "@", "_"};
    for(int i=0;i<30;i++){
        if(variable==operatorList[i]){
            return 4;
        }
    }
    for(int i=0;i<17;i++){
        if(variable==punctList[i]){
            return 6;
        }
    }
    for(int i=0;i<variable.length(); i++){
        if(variable[i]>='0' && variable[i]<='9'){
            return 7;
        }
    }

    for(int i=0;i<8;i++){
        if(variable==dataType[i]){
            return 1;
        }
    }
    for(int i=0;i<2;i++){
        if(variable==builtInNames[i]){
            return 2;
        }
    }
    while(getline(keywordFile,keyword,',')){
                 if(variable==keyword){
                       return 3;
                }
    }
    return 0;
}
bool checkHeader(string line)
{
    if(line == "#include <iostream>"){
            return true;
    }
    else return false;
}
bool checkNameSpace(string line)
{
    if(line=="using namespace std;"){
        return true;
    }
    else return false;

}

bool isValidIdentifier(string variable)
{
    ifstream keywordFile("E:\\Compiler Design\\Lab Class 3\\CPP_keywords.txt");
    if(!keywordFile.is_open()){
        cout<<"couldn't open file"<<endl;
        return false;
    }
    if(isKeyword(variable, keywordFile)==4){
        cout<<"Operator"<<endl;
        return false;
    }
    else if(isKeyword(variable, keywordFile)==7){
        cout<<"Numeric"<<endl;
        return false;
    }
    else if(isKeyword(variable, keywordFile)==6){
        cout<<"Punctuation"<<endl;
        return false;
    }
    else if(isKeyword(variable, keywordFile)==3){
        cout<<"Built in Keyword"<<endl;
        return false;
    }
    else if(isKeyword(variable, keywordFile)==2){
        cout<<"Built in name"<<endl;
        return false;
    }
    else if(isKeyword(variable, keywordFile)==1){
        cout<<"Data Type"<<endl;
        return false;
    }
    else if(isKeyword(variable, keywordFile)==0){
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
      cout<<"Valid identifier"<<endl;
      return true;

    }
    keywordFile.close();

}

bool checkDoubleQuote(string word)
{
    if(word[0]=='"' && word[word.length() -1 ]=='"'){
                cout<<"first chaaaaar : "<<word[0]<<endl;

            char qoute='"';
            string newWord;
            for(int i=1;i<word.length()-2;i++){
                newWord[i-1]=word[i];
            }
        cout<<"Token: "<<qoute<<" punctuation";

        isValidIdentifier(newWord);
        cout<<"Token: "<<qoute<<" punctuation";
    }
    else
       isValidIdentifier(word);
}

void tokenize(string line, int lineNum) {
    cout<<"Line "<<lineNum<<" :"<<endl;
    string word;
    stringstream ss(line);

    while (getline(ss, word, ' ')) {
        cout << "Token: " << word<<"  ";
        checkDoubleQuote(word);
        //isValidIdentifier(word);
    }
}
int main()
{
    string line;
    int lineNum=0;
    ifstream File("E:\\Compiler Design\\Final 16.04.24\\demoInput.txt");
       if(!File.is_open()){
           cout<<"couldn't open file"<<endl;
        }
        else
        {
            while(getline(File >> std::ws,line))
            {
                lineNum++;
                if (checkHeader(line))
                {
                    cout<<"Line "<<lineNum<<" :"<<"Header File Declaration."<<endl;
                }
                else if(!checkHeader(line))
                {
                    if(checkNameSpace(line))
                    {
                        cout<<"Line "<<lineNum<<" :"<<"name space declaration."<<endl;
                    }
                    else if(!checkNameSpace(line))
                    {
                       tokenize(line,lineNum);
                    }
                }

            }
        }
        File.close();

}
