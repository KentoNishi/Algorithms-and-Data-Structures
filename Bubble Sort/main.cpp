#include <array>
#include <iostream>
#include <cmath>
using namespace std;

void bubbleSort(int arr[],int size){
    bool swapped=true;
    for(int n=0;swapped==true;n++){
        swapped=false;
        int prev=arr[0];
        for(int i=1;i<size-n;i++){
            if(prev>arr[i]){
                arr[i-1]=arr[i];
                arr[i]=prev;
                swapped=true;
            }
            prev=arr[i];
        }
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
    bubbleSort(param,sizeof(param)/sizeof(param[0]));
    return 0;
}