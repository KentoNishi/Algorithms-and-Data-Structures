#include <array>
#include <iostream>
#include <cmath>
#include <vector>
#include <random>
#include <queue>
using namespace std;

int main(){
    priority_queue<int> queue;
    for(int i=0;i<100;i++){
        queue.push(rand()%100);
    }
    for(int i=0;i<queue.size();i+=0){
        cout << queue.top() << endl;
        queue.pop();
    }
    return 0;
}