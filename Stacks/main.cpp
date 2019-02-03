#include <array>
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

struct Stack{
    vector<int> stack;
    int peek(){
        return stack[stack.size()-1];
    }
    int push(int x){
        stack.push_back(x);
    }
    int pop(){
        int last=stack[stack.size()-1];
        stack.erase(stack.begin()+stack.size()-1);
        return last;
    }
    int size(){
        return stack.size();
    }
};

int main(){
    Stack stack=Stack();
    for(int i=0;i<100;i++){
        stack.push(i);
    }
    for(int i=0;i<stack.size();i+=0){
        cout << stack.pop() << endl;
    }
    return 0;
}