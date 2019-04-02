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

int inf=1000000;

class DistPar{
    public:
        int distance;
        int parentVert;
        DistPar(int pv, int d){
            distance=d;
            parentVert=pv;
        }
        DistPar(){
            
        }
};

class Vertex{
    public:
        string label;
        bool isInTree;
        Vertex(string lab){
            label=lab;
            isInTree=false;
        }
        Vertex(){

        }
};

class Graph{
    private:
        const int MAX_VERTS=20;
        vector<Vertex> vertexList;
        vector<vector<int>> adjMat;
        int nVerts;
        int nTree;
        vector<DistPar> sPath;
        int currentVert;
        int startToCurrent;
    public:
        Graph(){
            vertexList=vector<Vertex>(MAX_VERTS);
            for(int x=0;x<MAX_VERTS;x++){
                adjMat.push_back({});
                for(int y=0;y<MAX_VERTS;y++){
                    adjMat[x].push_back(inf);
                }
            }
            sPath=vector<DistPar>(MAX_VERTS);
            nVerts=0;
            nTree=0;
        }
        void addVertex(string lab){
            vertexList[nVerts++]=Vertex(lab);
        }
        void addEdge(int start, int end, int weight){
            adjMat[start][end]=weight;
        }
        void path(){
            int startTree=0;
            vertexList[startTree].isInTree=true;
            nTree=1;
            for(int j=0;j<nVerts;j++){
                int tempDist=adjMat[startTree][j];
                sPath[j]=DistPar(startTree,tempDist);
            }
            while(nTree<nVerts){
                int indexMin=getMin();
                int minDist=sPath[indexMin].distance;
                if(isinf(minDist)){
                    cout << "Unreachable vertices" << endl;
                    break;
                }else{
                    currentVert=indexMin;
                    startToCurrent=sPath[indexMin].distance;
                }
                vertexList[currentVert].isInTree=true;
                nTree++;
                adjust_sPath();
            }
            displayPaths();
            nTree=0;
            for(int j=0;j<nVerts;j++){
                vertexList[j].isInTree=false;
            }
        }
        int getMin(){
            int minDist=inf;
            int indexMin=0;
            for(int j=1;j<nVerts;j++){
                if(!vertexList[j].isInTree && sPath[j].distance<minDist){
                    minDist=sPath[j].distance;
                    indexMin=j;
                }
            }
            return indexMin;
        }
        void adjust_sPath(){
            int column=1;
            while(column<nVerts){
                if(vertexList[column].isInTree){
                    column++;
                    continue;
                }
                int currentToFringe=adjMat[currentVert][column];
                int startToFringe=startToCurrent+currentToFringe;
                int sPathDist=sPath[column].distance;
                if(startToFringe<sPathDist){
                    sPath[column].parentVert=currentVert;
                    sPath[column].distance=startToFringe;
                }
                column++;
            }
        }
        void displayPaths(){
            for(int j=0;j<nVerts;j++){
                cout << vertexList[j].label << "=";
                if(isinf(sPath[j].distance)){
                    cout << "inf";
                }else{
                    cout << sPath[j].distance;
                }
                string parent=vertexList[sPath[j].parentVert].label;
                cout << "(" << parent << ")" << endl;
            }
            cout << endl;
        }
};

int main(){
    Graph graph=Graph();
    graph.addVertex("A");
    graph.addVertex("C");
    graph.addVertex("B");
    graph.addVertex("D");
    graph.addVertex("E");
    graph.addEdge(0,1,50);
    graph.addEdge(0,3,80);
    graph.addEdge(1,2,60);
    graph.addEdge(1,3,90);
    graph.addEdge(2,4,40);
    graph.addEdge(3,2,20);
    graph.addEdge(3,4,70);
    graph.addEdge(4,1,50);
    cout << "Shortest paths: " << endl;
    graph.path();
    cout << endl;
    return 0;
}


