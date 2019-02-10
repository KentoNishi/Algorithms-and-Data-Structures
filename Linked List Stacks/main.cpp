#include <array>
#include <iostream>
#include <cmath>
using namespace std;

class Link{
    public:
    Link* next;
    int data;
    int key;
    Link(int d, int k){
        data=d;
        key=k;
    };
    void displayLink(){
        cout << "Data is: " << data << " - key is: "<< key << endl;
    }
};

class LinkedList{
    private: 
    Link* first;
    Link* last;
    public: 
    LinkedList(){
        first=NULL;
        last=NULL;
    };
    bool isEmpty(){
        return (first==NULL);
    }
    void prepend(int d,int k){
        Link* firstPointer=new Link(d,k);
        firstPointer->next=first;
        if(first=NULL){
            last=firstPointer;
        }
        first=firstPointer;
    }
    void append(int d,int k){
        Link* lastPointer=new Link(d,k);
        lastPointer->next=NULL;
        if(last!=NULL){
            last->next=lastPointer;
        }else{
            first=lastPointer;
        }
        last=lastPointer;
    }
    void deleteFirst(){
        first=first->next;
    }
    void displayLinkedList(){
        Link* current=first;
        while(current!=NULL){
            current->displayLink();
            current=current->next;
        }
    }
    Link* find(int k){
        Link* current=first;
        while(current!=NULL){
            if(current->key==k){
                return current;
            }
            current=current->next;
        }
        return NULL;
    }
    void erase(int k){
        Link* current=first;
        Link* previous=NULL;
        while(current!=NULL){
            if(current->key==k){
                if(current!=first){
                    previous->next=current->next;
                }else{
                    first=first->next;
                }
                return;
            }
            previous=current;
            current=current->next;
        }
        return;
    }
    void insert(int d,int k){
        Link* insertPointer=new Link(d,k);
        if(first==NULL){
            first=insertPointer;
            last=insertPointer;
            return;
        }
        if(insertPointer->data<first->data){
            insertPointer->next=first;
            first=insertPointer;
            return;
        }
        Link* current=first;
        while(current->next!=NULL&&current->next->data<insertPointer->data){
            current=current->next;
        }
        insertPointer->next=current->next;
        current->next=insertPointer;
    }
    Link* popFirst(){
        Link* toReturn=first;
        first=first->next;
        return toReturn;
    }
};

struct Stack{
    LinkedList data=LinkedList();
    void push(int d,int k){
        data.prepend(d,k);
    }
    Link* pop(){
        return data.popFirst();
    }
};

int main(){
    Stack stack=Stack();
    for(int i=0;i<10;i++){
        stack.push(i,i);
    }
    Link* current=stack.pop();
    while(true){
        cout << current->data <<endl;//<<" "<< current->next <<  endl;
        if(current->next!=NULL){
            current=stack.pop();
        }else{
            break;
        }
    }
    return 0;
}