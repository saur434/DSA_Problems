#include <bits/stdc++.h>
using namespace std;
//Node class Implementation
class Node{
    public:
        int data;
        Node* link;

        Node(int data)
        {
            this->data = data;
            this->link = NULL;
        }

};

class Stack{
    public:

        Node* top; 
        Stack(){
            top=NULL;
        }
            void push(int data);

            void pop();

            bool isEmpty();

            int peek();

            void display();

};

void Stack::push(int data){
    Node* temp = new Node(data);
    if(!temp)
    {
        cout<<"Stack Overflow"<<endl;
        return;
    }

    temp->link = top;

    top = temp;
}

void Stack::pop()
{
    Node* temp;
    if(top==NULL)
    {
        cout<<"Stack is Empty"<<endl;
        return;
    }

    temp = top;
    top = top->link;
    delete(temp);
}

int Stack::peek(){
    if(!isEmpty())
    {
        return top->data;
    }
    else{
        cout<<"Cannot print top element"<<endl;
        exit(1);
    }
}

void Stack::display(){
    Node* temp = top;
    if(temp==NULL)
    {
        cout<<"Stack underflow"<<endl;
        return;
    }
    else{
        temp = top;
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp = temp->link;
            if (temp != NULL)
                cout << " -> ";
        }

    }

}

bool Stack::isEmpty()
{
    if(top==NULL)
    {
        cout<<"Stack is Empty"<<endl;
       return true;
    }
    return false;

}


int main()
{
    Stack s;
    s.push(23);
    s.push(22);
    s.push(10);
    s.push(12);
    cout<<"The stack is: "<<endl;
    s.display();

    s.pop();
    cout<<endl;
    cout<<"Stack after popping an element: "<<endl;
    s.display();
cout<<endl;
    cout<<"The top element in the stack is: "<<s.peek()<<endl;
    return 0;
}