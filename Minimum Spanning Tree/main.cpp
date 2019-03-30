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

struct Edge{
    int srcVert;
    int destVert;
    int dist;
    Edge(int src, int dest, int dst){
        srcVert=src;
        destVert=dest;
        dist=dst;
    }
    Edge(){
        
    }
};

struct PriorityQueue{
    private:
        const int arrSize=20;
        vector<Edge> queueArray=vector<Edge>(arrSize);
    public:
        PriorityQueue(){
        }
        int size=0;
        void insert(Edge item){
            int j=0;
            while(j<size){
                if(item.dist>=queueArray[j].dist){
                    break;
                }
                j++;
            }
            for(int k=size-1;k>=j;k--){
                queueArray[k+1]=queueArray[k];
            }
            queueArray[j]=item;
            size++;
        }
        Edge removeMin(){
            return queueArray[--size];
        }
        void remove(int n){
            for(int j=n;j<size-1;j++){
                queueArray[j]=queueArray[j+1];
            }
            size--;
        }
        Edge peekMin(){
            return queueArray[size-1];
        }
        bool empty(){
            return size==0;
        }
        Edge peek(int n){
            return queueArray[n];
        }
        int find(int n){
            for(int j=0;j<size;j++){
                if(queueArray[j].destVert==n){
                    return j;
                }
            }
            return -1;
        }
};

struct Vertex{
    string label;
    bool inTree=false;
    Vertex(string id){
        label=id;
    }
    Vertex(){
    }
};

class Graph{
    private:
        static const int maximum=20;
        vector<Vertex> vertexList=vector<Vertex>(maximum);
        vector<vector<int>> adjMat;
        int nVerts=0;
        int currentVert=0;
        PriorityQueue queue=PriorityQueue();
        int nTree=0;
    public:
        Graph(){
            for(int x=0;x<maximum;x++){
                adjMat.push_back({});
                for(int y=0;y<maximum;y++){
                    adjMat[x].push_back(NULL);
                }
            }
        }
        void addVertex(string label){
            vertexList[nVerts++]=Vertex(label);
        }
        void addEdge(int start, int end,int weight){
            adjMat[start][end]=weight;
            adjMat[end][start]=weight;
        }
        void display(int n){
            cout << vertexList[n].label << endl;
        }
        void putInQueue(int newVert, int newDist){
            int index=queue.find(newVert);
            if(index!=-1){
                Edge temp=queue.peek(index);
                int oldDist=temp.dist;
                if(oldDist>newDist){
                    queue.remove(index);
                    Edge edge=Edge(currentVert,newVert,newDist);
                    queue.insert(edge);
                }
            }else{
                Edge edge=Edge(currentVert,newVert,newDist);
                queue.insert(edge);
            }
        }
        void minSpanTree(){
            currentVert=0;
            while(nTree<nVerts-1){
                vertexList[currentVert].inTree=true;
                nTree++;
                for(int j=0;j<nVerts;j++){
                    if(j==currentVert){
                        continue;
                    }
                    if(vertexList[j].inTree){
                        continue;
                    }
                    int dist=adjMat[currentVert][j];
                    if(dist==NULL){
                        continue;
                    }
                    putInQueue(j,dist);
                }
                if(queue.size==0){
                    cout << "Graph not connected" << endl;
                    return;
                }
                Edge edge=queue.removeMin();
                int srcVert=edge.srcVert;
                int currentVert=edge.destVert;
                cout << vertexList[srcVert].label;
                cout << vertexList[currentVert].label;
                cout << " ";
            }
            cout << endl;
            for(int j=0;j<nVerts;j++){
                vertexList[j].inTree=false;
            }
        }
};

int main(){
    Graph graph=Graph();
    graph.addVertex("A");    
    graph.addVertex("B");    
    graph.addVertex("C");    
    graph.addVertex("D");    
    graph.addVertex("E");    
    graph.addVertex("F");    
    graph.addEdge(0, 1, 6);  
    graph.addEdge(0, 3, 4);
    graph.addEdge(1, 2, 10); 
    graph.addEdge(1, 3, 7);  
    graph.addEdge(1, 4, 7);  
    graph.addEdge(2, 3, 8);  
    graph.addEdge(2, 4, 5);  
    graph.addEdge(2, 5, 6);  
    graph.addEdge(3, 4, 12); 
    graph.addEdge(4, 5, 7);
    graph.minSpanTree();
    return 0;
}
