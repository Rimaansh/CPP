#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

class Stack
{
    public:
    int size;
    char arr[20];
    int top;

    Stack(){
        top = -1;
        size = 20;
    }

    char pop()
    {
        if(top == -1) {
            cout<<"Stack Underflow"<<endl;
            return 's';
        }
        return (arr[top--]);
    }

    void push(int ele)
    {
        if(top == size-1){
            cout<<"Stack Underflow"<<endl;
            return;
        }
        arr[++top] = ele;
    }

    void display()
    {
        int temp = top;
        while(temp>-1) cout<<arr[temp--]<<" ";
        cout<<""<<endl;
    }

    int isEmpty()
    {
        return (top == -1? 1: 0);
    }
};

int main()
{
    Stack s;
    int flag = 1;
    char str[20];
    cout<<"Enter a string"<<endl;
    gets(str);
    for(int i = 0; i<strlen(str); i++)
    {
        s.push(str[i]);
    }

    for(int i = 0; i<strlen(str); i++)
    {
        if(s.pop() != str[i])
            flag = 0;
    }

    if(s.isEmpty() && flag) cout<<"PALINDROME"<<endl;
    else cout<<"NOT A PALINDROME"<<endl;

    return 0;
}