#include <array>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

bool notAll(vector<int> arr,int num){
    for(int i=arr.size()-1;i>=0;i--){
        if(arr[i]!=num){
            return true;
        }
    }
    return false;
}

bool shouldShow(vector<int> arr){
    for(int i=1;i<arr.size();i++){
        if(arr[i-1]>arr[i]){
            return false;
        }
    }
    return true;
}

int main(){
    vector<int> numbers;
    vector<int> digits;
    int size=10;
    int count=2;
    for(int i=0;i<size;i++){
        numbers.push_back(i);
    }
    for(int i=0;i<count;i++){
        digits.push_back(0);
    }
    for(int i=0;i<digits.size();i++){
        cout << digits[i] << " ";
    }
    cout << endl;
    while(notAll(digits,size-1)){
        digits[digits.size()-1]++;
        for(int i=digits.size()-1;i>0&&digits[i]>=size;i--){
            digits[i-1]++;
            digits[i]=0;
        }
        if(shouldShow(digits)){
            for(int i=0;i<digits.size();i++){
                cout << digits[i] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}