//This program asks the user for a string and then puts it into a queue and stack simultaneously and then determines if the sting
//is palindrome or not




#include<iostream>
#include<stack>
#include<queue>
#include<string>

using namespace std;
int main(void){//begining of main
    stack<char> k;
    queue<char> q;
    string s;
    cout<<"Enter a string "<<endl;//query the user for string
    cin>>s;// store string in s
    int x;
    for(x=0; x<s.size(); x++)//for loop to put the string into the stack and queue
    {
        k.push(s[x]);
        q.push(s[x]);
    }

     while((k.top()==q.front())&&(!(k.empty()))) //while loop as long as the top of the stack(lifo) is the same as the front of the queue(fifo)
     {
        q.pop();//remove a letter form the queue
        k.pop();//remove letter from the stack
       }
  if(k.empty()){// if the stack is empty that means all the letters were the same in both directions thus making it palindrome
      cout<<"The string is palindrome "<<endl;
  }
       else//otherwise the string must not be palindrome
       {
           cout << "The string is not palindrome "<< endl;}
return 0;//end of main

}
