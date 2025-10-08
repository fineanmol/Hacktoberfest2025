#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
    Node* prev ;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL ;
    }
};

class List
{
    Node *head;
    Node *tail;

public:
    List()
    {
        head = tail = NULL;
    }

    void PushFront(int data)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = tail = newNode;
            return;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode ;
            head = newNode;
        }
    }

    void PushBack(int data)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = tail = newNode;
            return;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail ;
            tail = newNode;
        }
    }
    
    void PopFront(){
        if(head == NULL){
            return ;
        }
        
        Node* temp = head ;
        head = head->next ;
        
        if(head != NULL){
            head->prev = NULL ;
        }else tail=NULL ;
        delete temp ;
    }

    void PopBack(){

        if(head==NULL){
            cout<<"LL is empty \n" <<endl ;
        }
        Node* temp = head ;
        while(temp->next != tail){
            temp = temp->next ;
        }
        temp->next = NULL ;
        delete tail ;
        tail = temp ;

    }
    
    void PopAt(int pos){
        Node* temp = head ;
        for(int i = 0 ; i<pos-1 ; i++){
            temp = temp->next;
        }
        
        Node* curr = temp->next ;
        temp->next = curr->next ;
        delete curr ;
    }
    
    void Display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }

        cout << "NULL" << endl;
    }

    
};

int main()
    {
        List ll;
        ll.PushFront(10);
        ll.PushFront(20);
        ll.PushFront(30);
        ll.PushBack(40);
        ll.PopAt(1) ;
        ll.Display();

        return 0;
    }
