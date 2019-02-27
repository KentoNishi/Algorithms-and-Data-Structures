#include <chrono>
#include <array>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include <iostream>
#include <unordered_map>
using namespace std;

class Node{
    public:
        int key;
        Node(int k){
            key=k;
        }
};

class Heap{
    private:
    public:
        vector<Node> arr;
        bool empty(){
            return arr.empty();
        }
        void trickleUp(int index){
            int parent=(index-1)/2;
            Node bottom=arr[index];
            while(index>0&&arr[parent].key<bottom.key){
                arr[index]=arr[parent];
                index=parent;
                parent=(parent-1)/2;
            }
            arr[index]=bottom;
        }
        void trickleDown(int index){
            int larger;
            Node top=arr[index];
            while(index<arr.size()/2){
                int left=2*index+1;
                int right=left+1;
                if(right<arr.size()&&arr[left].key<arr[right].key){
                    larger=right;
                }else{
                    larger=left;
                }
                if(top.key>=arr[larger].key){
                    break;
                }
                arr[index]=arr[larger];
                index=larger;
            }
            arr[index]=top;
        }
        int size(){
            return arr.size();
        }
        Node erase(){
            Node root=arr[0];
            arr[0]=arr[arr.size()-1];
            arr.erase(arr.end()-1);
            trickleDown(0);
            return root;
        }
        void insert(int key){
            Node node=Node(key);
            arr.push_back(node);
            trickleUp(arr.size()-1);
        }
        bool change(int index,int newval){
            if(index<0||index>=arr.size()){
                return false;
            }
            int old=arr[index].key;
            arr[index].key=newval;
            if(old<newval){
                trickleUp(index);
            }else{
                trickleDown(index);
            }
            return true;
        }
};

int main(){
    Heap heap=Heap();
    heap.insert(0);
    for(int i=0;i<100;i++){
        heap.insert(rand()%100);
    }
    cout << "Memory:"<<endl;
    for(int i=0;i<heap.arr.size();i++){
        cout << (heap.arr)[i].key << endl;
    }
    cout << endl<<"Sorted order:"<<endl;
    while(heap.size()>0){
        cout << heap.erase().key << endl;
    }
    return 0;
}