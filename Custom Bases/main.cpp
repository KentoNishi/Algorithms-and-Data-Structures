#include <array>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    vector<int> numbers;
    for(int i=0;i<10;i++){
        numbers.push_back(i);
    }
    do{
        for(int i=0;i<10;i++){
            cout << numbers[i] << " ";
        }
        cout << endl;
    }while(next_permutation(numbers.begin(),numbers.end()));
    return 0;
}
