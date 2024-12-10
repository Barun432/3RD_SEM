#include<iostream>
#include<vector>
using namespace std;

int main(){
 
    vector<int>v;
    while(1){
        int data;
        cin>>data;
        v.push_back(data);
        cout<<v.size()<<endl;
    cout<<v.capacity();
    }
    
}