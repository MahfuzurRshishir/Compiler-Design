#include<iostream>
using namespace std;

class MyStack
{
public:
    char *datas;
    int maxSize = 0;
    int top = 0;

public:
    MyStack(int maxSize){
        this->maxSize = maxSize;
        datas = new char[maxSize];
    }
    bool isFull(){
        return (top == maxSize);
    }
    bool isEmpty(){
        return (top == 0);
    }

    void push(char ch){
        if (!isFull()){
            datas[top] = ch;
            top++;
        }
        else
            cout << "stack is over flow" << endl;
    }
    char topElement(){
        return datas[top - 1];
    }
    char pop(){
        if (!isEmpty()){
            return datas[--top];
        }
        else
            return '\0';
    }
    void stackResize(int newMaxSize){
        char *temp = new char[newMaxSize];
        for (int i = 0; i < this->maxSize; i++){
            temp[i] = datas[i];
        }
        delete[] datas;
        this->maxSize = newMaxSize;
        datas = temp;
    }
};

void checkOperator(string input)
{
    MyStack stack(100);
    bool okey = true;
    int equalSignCount = 0;
    int stackSize=0;

    for(int i = 0; i < input.length(); i++){
        if((input[i] >= '0' && input[i] <= '9') ||
             input[i] == '+' || input[i] == '-' ||
             input[i] == '/' || input[i] == '*' ||
             input[i] == '%' || input[i] == '='){

                if(input[i] == '='){
                   equalSignCount++;
            }
        }
        else{
            okey = false;
            break;
        }
    }

    if(equalSignCount != 1 || !okey){
        cout<<"Invalid input"<<endl;
        return;
    }

    for(int i = 0; i < input.length(); i++){
        if(input[i] == '+' || input[i] == '-' ||
           input[i] == '/' || input[i] == '*' ||
           input[i] == '%' || input[i] == '='){
            stack.push(input[i]);
            stackSize++;
        }
    }
    char arr[stackSize];
    for(int i=0;i<stackSize;i++){
        arr[i]=stack.topElement();
        stack.pop();
    }
    int j = 1;
    for(int i=stackSize-1;i>=0;i--){
        cout<<"Operator "<<j<<" : "<<arr[i]<<endl;
        j++;
    }
}



int main()
{
    string input;
    int option;
    bool running = true;
    while(running){
        cout<<"1. Check operators"<<endl;
        cout<<"2. Exit"<<endl;
        cout<<"Select option: ";
        cin>>option;
        switch(option){
            case 1:
                cout<<"Enter your desired input: ";
                cin>>input;
                checkOperator(input);
                break;
            case 2:
                running = false;
                cout<<"Program terminated"<<endl;
                break;
            default:
                cout<<"Invalid option"<<endl;
        }
    }
    return 0;
}
