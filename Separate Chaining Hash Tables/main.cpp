#include <array>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

class Link{
    public:
    Link* next;
    string key;
    Link(string d){
        key=d;
    };
    void displayLink(){
        cout << key << " ";
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
    void prepend(string d){
        Link* firstPointer=new Link(d);
        firstPointer->next=first;
        if(first=NULL){
            last=firstPointer;
        }
        first=firstPointer;
    }
    void append(string d){
        Link* lastPointer=new Link(d);
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
    Link* find(string d){
        Link* current=first;
        while(current!=NULL){
            if(current->key==d){
                return current;
            }
            current=current->next;
        }
        return NULL;
    }
    void erase(string d){
        Link* current=first;
        Link* previous=NULL;
        while(current!=NULL){
            if(current->key==d){
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
    void insert(string d){
        Link* insertPointer=new Link(d);
        if(first==NULL){
            first=insertPointer;
            last=insertPointer;
            return;
        }
        if(insertPointer->key<first->key){
            insertPointer->next=first;
            first=insertPointer;
            return;
        }
        Link* current=first;
        while(current->next!=NULL&&current->next->key<insertPointer->key){
            current=current->next;
        }
        insertPointer->next=current->next;
        current->next=insertPointer;
    }
};

class HashTable{
    public:
        vector<LinkedList> table;
        int hashString(string key,int size){
            int val=0;
            for(int i=0;i<key.length();i++){
                int letter=int(key.at(i))-96;
                val=(val*27+letter)%size;
            }
            return val;
        }
        HashTable(int size){
            table=vector<LinkedList>(size);
        }
        void insert(string key){
            int hash=hashString(key,table.size());
            table[hash].prepend(key);
        }
        void display(){
            for(int i=0;i<table.size();i++){
                table[i].displayLinkedList();
                cout << endl;
            }
        }
        int find(string key){
            int hash=hashString(key,table.size());
            Link* found=table[hash].find(key);
            if(found!=NULL){
                return hash;
            }
            return NULL;
        }
        void erase(string key){
            int hash=hashString(key,table.size());
            table[hash].erase(key);
        }
};

int main(){
    ifstream fin ("dict.txt");
    vector<string> items;
    string contents;
    while(getline(fin,contents)) {
        items.push_back(contents);
    }
    HashTable hashTable=HashTable(items.size());
    for(int i=0;i<items.size();i++){
        hashTable.insert(items[i]);
    }
    hashTable.display();
    return 0;
}