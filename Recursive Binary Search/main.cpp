#include <array>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

//Time complex: O(log(N));
int binarySearch(vector<int> arr,int query,int low, int high){
    if(low>high){
        return -1;
    }else{
        int mid=(low+high)/2;
        if(arr[mid]==query){
            return mid;
        }else if(arr[mid]>query){
            return binarySearch(arr,query,low,mid-1);
        }else{
            return binarySearch(arr,query,mid+1,high);
        }
    }
}

int main(){
    vector<int> param;
    for(int i=0;i<1000;i++){
        param.push_back(rand()%1000);
    }
    sort(param.begin(),param.end());
    for(int i=0;i<param.size();i++){
        cout << param[i] << endl;
    }
    int query;
    cout << "Int to search: ";
    cin >> query;
    cout << "Fount at index " << binarySearch(param,query,0,param.size()-1) << endl;
    return 0;
}