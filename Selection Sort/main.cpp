#include <array>
#include <iostream>
#include <cmath>
using namespace std;
void selectionSort(int arr[],int size){
    for(int i=0;i<size-1;i++){
        int minIndex=i;
        for(int k=i+1;k<size;k++){
            if(arr[minIndex]>arr[k]){
                minIndex=k;
            }
        }
        int prev=arr[i];
        arr[i]=arr[minIndex];
        arr[minIndex]=prev;
    }
    for(int i=0;i<size;i++){
        cout << arr[i] << endl;
    }
}

int main(){
    int param[1000]={};
    for(int i=0;i<1000;i++){
        param[i]=rand()%1000;
    }
    selectionSort(param,sizeof(param)/sizeof(param[0]));
    return 0;
}