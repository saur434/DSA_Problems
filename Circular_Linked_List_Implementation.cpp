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
    Node* temp = head;
    if (head != NULL) {
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
    }
    
    cout << endl;
    
    
}

//Function to insert in the linked list

void LinkedList::insertLinkedList(int data){
   Node* temp = new Node(data);
   temp->next = head;
   
    if(head!=NULL){
     Node* curr = head;
     while(curr->next!=head)
     {
        curr = curr->next;
     }
     curr->next = temp;
    }
    else{
        temp->next = temp;

    }
    head = temp;

}

//Function to delete the node given at the specific position

void LinkedList::deleteNode(int key)
{
    Node* p = head;
    if(head==NULL)
    {
        return;
    }
    if((head)->data==key && (head->next)==head){
         delete(head);
         head = NULL;
         return;
    }
    Node* q;
    if(head->data==key)
    {
        while(p!=head)
        {
           p = p->next;

        }
        p->next = head->next;
        delete(head);
        head = p->next;

    }
    while (p->next != head && p->next->data != key) {
        p = p->next;
    }
  
    // If node to be deleted was found
    if (p->next->data == key) {
        q = p->next;
        p->next = q->next;
        free(q);
    }

}

// Function to reverse the linked list

void LinkedList::reverseList()
{
    if(head==NULL)
    {
        return;
    }
    Node* prev = NULL;
    Node* current = head;
    Node* next;
    do {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    } while (current != (head));
 

    (head)->next = prev;
    head = prev;

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
    
    cout<<"The circular linked list is: "<<endl;
    l1.printLinkedList();
    cout<<endl;
    
    cout<<"Circular Linked List after reversed is: "<<endl;
    l1.reverseList();
    l1.printLinkedList();
    cout<<endl;

    int key = 0;
    cout<<"Enter the key that is to be deleted"<<endl;
    cin>>key;

    l1.deleteNode(key);


    cout<<"Circular Linked List after deletion is: "<<endl;
    l1.printLinkedList();

    
    
    return 0;
}