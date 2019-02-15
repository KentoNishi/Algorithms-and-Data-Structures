#include <array>
#include <iostream>
#include <cmath>
#include <vector>
#include <chrono>
#include <algorithm>
using namespace std;
using namespace std::chrono;

void insertionSort(vector<int>* arr,int left,int right){
    for(int i=left+1;i<right+1;i++){
        int prev=(*arr)[i];
        int k=i-1;
        while((*arr)[k]>prev&&k>=left){
            (*arr)[k+1]=(*arr)[k];
            k--;
        }
        (*arr)[k+1]=prev;
    }
}

void swap(vector<int>* param,int left,int right){
    int temp=(*param)[left];
    (*param)[left]=(*param)[right];
    (*param)[right]=temp;
}

int partition(vector<int>* arr,int left,int right,int pivot){
    int lower=left-1;
    int higher=right;
    while(true){
        while(lower<right&&(*arr)[++lower]<pivot){
        }
        while(higher>0&&(*arr)[--higher]>pivot){
        }
        if(lower>=higher){
            break;
        }else{
            swap(arr,lower,higher);
        }
    }
    swap(arr,lower,right);
    return lower;
}

void quickSort(vector<int>* arr,int left,int right){
    if(right-left+1<=3){
        insertionSort(arr,left,right);
    }
    if(left>=right){
        return;
    }
    vector<int>* three=new vector<int>(3);
    (*three)[0]=(*arr)[left];
    (*three)[1]=(*arr)[(left+right)/2];
    (*three)[2]=(*arr)[right];
    insertionSort(three,0,2);
    (*arr)[left]=(*three)[0];
    (*arr)[(left+right)/2]=(*three)[1];
    (*arr)[right]=(*three)[2];
    int pivot=(*three)[1];
    swap(arr,(left+right)/2,right);
    int part=partition(arr,left,right,pivot);
    quickSort(arr,left,part-1);
    quickSort(arr,part+1,right);
}

int main(){
    int size=100000;
    vector<int>* param=new vector<int>(size);
    for(int i=0;i<size;i++){
        (*param)[i]=(rand()%size);
    }
    vector<int> unsorted=*param;
    int right=(*param).size()-1;
    auto start = high_resolution_clock::now(); 
    quickSort(param,0,right);
    auto stop = high_resolution_clock::now(); 
    int duration = duration_cast<microseconds>(stop - start).count();
    start = high_resolution_clock::now(); 
    sort(unsorted.begin(),unsorted.end());
    stop = high_resolution_clock::now(); 
    int autoduration = duration_cast<microseconds>(stop - start).count(); 
    for(int i=0;i<unsorted.size();i++){
        cout << (*param)[i] << " == " << unsorted[i] << " : " <<((*param)[i]==unsorted[i]?"OK":"NO") << endl;
    }
    cout << "Custom sort: " << duration << "ms" << endl;
    cout << "C++ sort: " << autoduration << "ms" << endl;
    /*
    for(int i=0;i<(*param).size();i++){
        cout << (*param)[i] << endl;
    }*/
    return 0;
}