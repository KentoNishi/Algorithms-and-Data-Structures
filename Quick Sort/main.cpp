#include <array>
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

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
    if(left>=right){
        return;
    }
    int pivot=(*arr)[right];
    int part=partition(arr,left,right,pivot);
    quickSort(arr,left,part-1);
    quickSort(arr,part+1,right);
}

int main(){
    vector<int>* param=new vector<int>(100);;
    for(int i=0;i<100;i++){
        (*param)[i]=(rand()%100);
    }
    int right=(*param).size()-1;
    quickSort(param,0,right);
    for(int i=0;i<(*param).size();i++){
        cout << (*param)[i] << endl;
    }
    return 0;
}