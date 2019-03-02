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

vector<string> split(string str, string character){
    vector<string> result;
    long long s=0;
    long long i=0;
    while(i<str.length()){
        if(str[i]==character[0]||i==str.length()-1){
            long long x=i-s;
            if(i==str.length()-1){
                x++;
            }
            result.push_back(str.substr(s,x));
            s=i+1;
        }
        i++;
    }
    return result;
}

class Vertex{
    public:
        string label;
        bool wasVisited;
        Vertex(string lab){
            label=lab;
            wasVisited=false;
        }
};

struct Stack{
    vector<int> stack;
    int peek(){
        return stack[stack.size()-1];
    }
    int push(int x){
        stack.push_back(x);
    }
    int pop(){
        int last=stack[stack.size()-1];
        stack.erase(stack.begin()+stack.size()-1);
        return last;
    }
    int size(){
        return stack.size();
    }
};

class Graph{
    private:
        static const int MAX_VERTS=20;
        vector<Vertex> vertexList;
        int adjMat[MAX_VERTS][MAX_VERTS];
        int nVerts=0;
    public:
        Graph(){
            for(int j=0;j<MAX_VERTS; j++){
                for(int k=0;k<MAX_VERTS;k++){
                    adjMat[j][k]=0;
                }
            }
        }
        void addVertex(string lab){
            vertexList.push_back(Vertex(lab));
            nVerts++;
        }
        void addEdge(int start, int end){
            adjMat[start][end]=1;
            adjMat[end][start]=1;
        }
        void displayVertex(int V){
            cout << vertexList[V].label << endl;
        }
        int getAdjUnvisitedVertex(int v){
            for(int j=0;j<nVerts;j++){
                if(adjMat[v][j]==1&&vertexList[j].wasVisited==false){
                    return j;
                }
            }
            return -1;
        }
        void dfs(){
                if(vertexList.size()!=0){
                vertexList[0].wasVisited=true;
                displayVertex(0);
                Stack stack=Stack();
                stack.push(0);
                while(stack.size()!=0){
                    int v=getAdjUnvisitedVertex(stack.peek());
                    if(v==-1){
                        stack.pop();
                    }else{
                        vertexList[v].wasVisited=true;
                        displayVertex(v);
                        stack.push(v);
                    }
                }
                for(int j=0;j<nVerts;j++){
                    vertexList[j].wasVisited=false;
                }
            }
        }
};


int main(){
    Graph graph=Graph();

    system("clear");
    cout <<"\033[1;32m";
    cout << "ctrl+c: quit" << endl;
    cout << "insert [key]: insert node" << endl;
    cout << "add [int] [int]: add edge" << endl;
    cout << "run: run dfs" << endl;
    cout << "\033[0m\n";
    while(true){
        string command;
        cout << "root@Graphs:~$: ";
        getline(cin,command);
        try{
            vector<string> splitln;
            int(command.at(0));
            splitln=split(command," ");
            if(splitln[0]=="insert"){
                graph.addVertex(splitln[1]);
            }else if(splitln[0]=="add"){
                graph.addEdge(stoi(splitln[1]),stoi(splitln[2]));
            }else if(splitln[0]=="run"){
                break;
            }
        }catch(...){
        }
    }
    graph.dfs();
    return 0;
}
