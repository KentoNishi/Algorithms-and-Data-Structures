#include <array>
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

//Time complex: O(N*log(N));
class mergeSort{
    public:
        vector<int> workspace;
        void merge(int low, int mid, int high){
    //        cout << low << " " << mid << " " << high << endl;
            int first=low;
            int second=mid+1;
            int temp[high-low+1];
            int index=0;
            while(first<=mid&&second<=high){
    //            cout << first << " - " << second << endl;
                if(workspace[first]<workspace[second]){
                    temp[index]=workspace[first];
                    first++;
                }else{
                    temp[index]=workspace[second];
                    second++;
                }
                index++;
            }
            while(first<=mid){
                temp[index]=workspace[first];/*
                cout << first << " "<<workspace[first] << endl;
                cout << temp[index]<<endl;
                cout << endl;*/
                first++;
                index++;
            }
            while(second<=high){
                temp[index]=workspace[second];/*
                cout << workspace[second] << endl;
                cout << temp[index]<<endl;
                cout << endl;*/
                second++;
                index++;
            }
            for(int i=low;i<=high;i++){
                workspace[i]=temp[i-low];
            }
    //        cout << "!"<<endl;
            return;
        }
        void sortPart(int low, int high){
    //        cout << low << ", " << high << endl;
            if(low>=high){
                return;
            }
            int mid=(low+high)/2;
            sortPart(low,mid);
            sortPart(mid+1,high);
            merge(low,mid,high);
            return;
        }
        mergeSort(vector<int> arr){
            workspace=arr;
            sortPart(0,arr.size()-1);
            return;
        }
};

int main(){
    vector<int> param;
    for(int i=0;i<1000;i++){
        param.push_back(random()%1000);
    }
    mergeSort sorted=mergeSort(param);
    for(int i=0;i<sorted.workspace.size();i++){
        cout << sorted.workspace[i] << endl;
    }
    return 0;
}