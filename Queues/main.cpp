#include <array>
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

struct Queue{
    vector<int> queue;
    int peek(){
        return queue[0];
    }
    int push(int x){
        queue.push_back(x);
    }
    int pop(){
        int first=queue[0];
        queue.erase(queue.begin());
        return first;
    }
    int size(){
        return queue.size();
    }
};

int main(){
    Queue queue=Queue();
    for(int i=0;i<100;i++){
        queue.push(i);
    }
    for(int i=0;i<queue.size();i+=0){
        cout << queue.pop() << endl;
    }
    return 0;
}