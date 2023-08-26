#include <bits/stdc++.h>
using namespace std;

// Intizalization of the Node

class Node{
    public:
        int data;
        Node* next;
        
        Node(){
            data = 0;
            next = NULL;
        }

        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }

};

//Linked List implementation

class LinkedList{
    Node* head;
    public:
        LinkedList() { head = NULL; }

        void printLinkedList();

        void insertLinkedList(int);

        void deleteNode(int);

        void reverseList();

        void deltewholelist();
};
//Function to print the linked list

void LinkedList::printLinkedList(){
    if(head==NULL)
    {
        cout<<"Linked List is Empty"<<endl;
        return ;
    }
    Node* temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    
}

//Function to insert in the linked list

void LinkedList::insertLinkedList(int data){
   Node* temp = new Node(data);
   
   if(head==NULL)
   {
       head = temp;
       return;
   }
 
     Node* curr = head;
     while(curr->next!=NULL)
     {
        curr = curr->next;
     }
     curr->next = temp;

}

//Function to delete the node given at the specific position

void LinkedList::deleteNode(int pos)
{
    Node* p = head;
    int length=0;
    while(p!=NULL)
    {
        length++;
        p = p->next;
    }
    if(pos>length)
    {
        cout<<"Cannot delete the Node"<<endl;
    }

    Node* temp = head;
     if(head==NULL)
     {
        cout<<"Linked List is Empty"<<endl;
        return;
     }
     
     if(pos==1)
     {
        head = head->next;
        delete(temp);
        return;
     }
     Node* q = NULL;
     for(int i=0;i<pos;i++)
     {
        q = temp;
        temp = temp->next;
     }
     q->next = temp->next;
     delete(temp);
     return;
}

// Function to reverse the linked list

void LinkedList::reverseList()
{
    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;
   while(curr!=NULL)
   {
     next = curr->next;
     curr->next = prev;
     prev = curr;
     curr = next;
   }
   head = prev;
   return;

}

//Function to delete the whole linked list

void LinkedList::deltewholelist()
{
   Node*curr = head;
   Node* next;
   while(curr!=NULL)
   {
       curr->next = next;
       delete(curr);
       curr = next;
   }
   head = NULL;
   return;
}



int main(){

    LinkedList l1;
    
    l1.insertLinkedList(2);
    l1.insertLinkedList(3);
    l1.insertLinkedList(4);
    l1.insertLinkedList(10);
    l1.insertLinkedList(9);
    
    cout<<"The linked list is: "<<endl;
    l1.printLinkedList();
    cout<<endl;
    
    cout<<"Linked List after reversed is: "<<endl;
    l1.reverseList();
    l1.printLinkedList();
    cout<<endl;

    int pos = 0;
    cout<<"Enter the position at which the node is to be deleted"<<endl;
    cin>>pos;

    l1.deleteNode(pos);


    cout<<"Linked List after deletion is: "<<endl;
    l1.printLinkedList();

    
    
    return 0;
}