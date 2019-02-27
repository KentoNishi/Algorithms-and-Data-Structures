#include <array>
#include <iostream>
#include <cmath>
#include <vector>
#include <chrono>
#include <algorithm>
using namespace std;

class Node{
    public:
        int key;
        int data;
        Node* left;
        Node* right;
        void display(){
            cout << key << ": " << data << endl;
        }
};

class Tree{
    public:
        Node* root=NULL;
        bool erase(int key){
            Node* current=root;
            Node* parent=root;
            bool toLeft=true;
            while((*current).key!=key){
                parent=current;
                if(key<(*current).key){
                    toLeft=true;
                    current=(*current).left;
                }else{
                    toLeft=false;
                    current=(*current).right;
                }
                if(current==NULL){
                    return false;
                }
            }
            if((*current).left==NULL&&(*current).right==NULL){
                if(current==root){
                    root=NULL;
                }else if(toLeft){
                    (*parent).left=NULL;
                }else{
                    (*parent).right=NULL;
                }
            }else if((*current).right==NULL){
                if(current==root){
                    root=(*current).left;
                }else if(toLeft){
                    (*parent).left=(*current).left;
                }else{
                    (*parent).right=(*current).right;
                }
            }else if((*current).left==NULL){
                if(current==root){
                    root=(*current).right;
                }else if(toLeft){
                    (*parent).left=(*current).right;
                }else{
                    (*parent).right=(*current).right;
                }
            }else{
                Node* succeeding=successor(current);
                if(current==root){
                    root=succeeding;
                }else if(toLeft){
                    (*parent).left=succeeding;
                }else{
                    (*parent).right=succeeding;
                }
                (*succeeding).left=(*current).left;
            }
            return true;
        }
        Node* successor(Node* node){
            Node* parent=node;
            Node* successor=node;
            Node* current=(*node).right;
            while(current!=NULL){
                parent=successor;
                successor=current;
                current=(*current).left;
            }
            if(successor!=(*node).right){
                (*parent).left=(*successor).right;
                (*successor).right=(*node).right;
            }
            return successor;
        }
        void insert(int key, int data){
            Node* node=new Node();
            (*node).key=key;
            (*node).data=data;
            if(root==NULL){
                root=node;
            }else{
                Node* current=root;
                Node* parent;
                while(true){
                    parent=current;
                    if(key<(*current).key){
                        current=(*current).left;
                        if(current==NULL){
                            (*parent).left=node;
                            return;
                        }
                    }else{
                        current=(*current).right;
                        if(current==NULL){
                            (*parent).right=node;
                            return;
                        }
                    }
                }
            }
        }
        Node* find(int key){
            Node* current=root;
            while((*current).key!=key){
                if(key<(*current).key){
                    current=(*current).left;
                }else{
                    current=(*current).right;
                }
                if(current==NULL){
                    return NULL;
                }
            }
            return current;
        }
        void preorderTraversal(Node* localRoot){
            if(localRoot!=NULL){
                (*localRoot).display();
                preorderTraversal((*localRoot).left);
                preorderTraversal((*localRoot).right);
            }
        }
        void reverseTraversal(Node* localRoot){
            if(localRoot!=NULL){
                reverseTraversal((*localRoot).right);
                (*localRoot).display();
                reverseTraversal((*localRoot).left);
            }
        }
        void inorderTraversal(Node* localRoot){
            if(localRoot!=NULL){
                inorderTraversal((*localRoot).left);
                (*localRoot).display();
                inorderTraversal((*localRoot).right);
            }
        }
        void postorderTraversal(Node* localRoot){
            if(localRoot!=NULL){
                postorderTraversal((*localRoot).left);
                postorderTraversal((*localRoot).right);
                (*localRoot).display();
            }
        }
};

int main(){
    Tree tree=Tree();
    int size=1000;
    for(int i=0;i<size;i++){
        tree.insert(rand()%size,i);
    }
    tree.inorderTraversal(tree.root);
    return 0;
}

