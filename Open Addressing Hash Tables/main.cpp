#include <array>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

class HashTable{
    public:
        vector<string> table;
        int hashString(string key,int size){
            int val=0;
            for(int i=0;i<key.length();i++){
                int letter=int(key.at(i))-96;
                val=(val*27+letter)%size;
            }
            return val;
        }
        HashTable(int size){
            table=vector<string>(size*2);
        }
        void insert(string key){
            int hash=hashString(key,table.size());
            int i=hash;
            while(table[i]!=""){
                i++;
                i=i%table.size();
            }
            table[i]=key;
        }
        void display(){
            for(int i=0;i<table.size();i++){
                cout << table[i] << endl;
            }
        }
        int find(string key){
            int hash=hashString(key,table.size());
            int i=hash;
            while(table[i]!=""){
                if(table[i]==key){
                    return i;
                }
                i++;
                i=i%table.size();
            }
            return NULL;
        }
        void erase(string key){
            int found=find(key);
            if(found!=NULL){
                table[found]="";
            }
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