#include <array>
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
void insertionSort(int* arr[],int size){
    for(int i=1;i<size;i++){
        int prev=*arr[i];
        int k=i-1;
        while(*arr[k]>prev&&k>=0){
            *arr[k+1]=*arr[k];
            k--;
        }
        *arr[k+1]=prev;
    }
}

vector<int> sequence;
void shellSort(int arr[],int size){
    for(int i=sequence.size()-1;i>=0;i--){
        int gap=sequence[i];
        for(int k=gap;k<size;k++){
            int temp=arr[k];
            int j=k;
            while(j>=gap&&arr[j-gap]>temp){
                arr[j]=arr[j-gap];
                j-=gap;
            }
            arr[j]=temp;
        }
    }
    for(int i=0;i<size;i++){
        cout << arr[i] << endl;
    }
}

void generateSequence(int size){
    int prev=1;
    while(prev<size){
        sequence.push_back(prev);
        prev=3*prev+1;
    }
}

int main(){
    int param[1000];
    for(int i=0;i<sizeof(param)/sizeof(param[0]);i++){
        param[i]=rand()%(sizeof(param)/sizeof(param[0]));
    }
    int size=sizeof(param)/sizeof(param[0]);
    generateSequence(size);
    shellSort(param,size);
    return 0;
}