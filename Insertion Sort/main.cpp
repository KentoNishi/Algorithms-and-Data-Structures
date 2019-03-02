#include <array>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
void insertionSort(int arr[],int size){
    for(int i=1;i<size;i++){
        int prev=arr[i];
        int k=i-1;
        while(arr[k]>prev&&k>=0){
            arr[k+1]=arr[k];
            k--;
        }
        arr[k+1]=prev;
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
    insertionSort(param,sizeof(param)/sizeof(param[0]));
    return 0;
}
