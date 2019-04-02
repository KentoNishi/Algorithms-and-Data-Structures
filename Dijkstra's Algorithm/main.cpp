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

class DistPar{
    public:
        int distance;
        int parentVert;
        DistPar(int pv, int d){
            distance=d;
            parentVert=pv;
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
};

class Graph{
    private:
        const int maxVerts=20;
        vector<Vertex> vertexList;
        vector<vector<int>> adjMat;
        int nVerts;
        int nTree;
        vector<DistPar> sPath;
        int currentVert;
        int startToCurrent;
    public:
        Graph(){
            vertexList=vector<Vertex>(maxVerts);
            nVerts=0;
            nTree=0;
            for(int x=0;x<maxVerts;x++){
                adjMat.push_back({});
                for(int y=0;y<maxVerts;y++){
                    adjMat[x].push_back(INFINITY);
                }
            }
            sPath=vector<DistPar>(maxVerts);
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
                if(minDist==INFINITY){
                    cout << "Unreachable vertices" << endl;
                    break;
                }else{
                    currentVert=indexMin;
                    startToCurrent=sPath[indexMin].distance;
                }
                vertexList[currentVert].isInTree=true;
                nTree++;
                adjustSPath();
            }
            displayPaths();
            nTree=0;
            for(int j=0;j<nVerts;j++){
                vertexList[j].isInTree=false;
            }
        }
        int getMin(){
            int minDist=INFINITY;
            int indexMin=0;
            for(int j=1;j<nVerts;j++){
                if(!vertexList[j].isInTree && sPath[j].distance < minDist){
                    minDist=sPath[j].distance;
                    indexMin=j;
                }
            }
            return indexMin;
        }
        void adjustSPath(){
            int column=-1;
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
                //continue from here
            }
        }
};


//pg 730
int main(){
    return 0;
}
