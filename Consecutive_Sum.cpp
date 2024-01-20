#include<bits/stdc++.h>
using namespace std;
struct Node{
    Node* arr[2];
    Node *containsKey(int bit){
        return arr[bit];
    }
    void setKey(int bit){
        arr[bit]=new Node();
    }
};
class Trie{
    private: Node* root;
    public:
    Trie(){
        root = new Node();
    }
    void insert(int num){
        Node* temp=root;
        for(int i=31; i>=0; i--){
            int bit=(num&(1<<i));
            bit=bit>0;
            // cout<<bit<<" ";
            if(temp->containsKey(bit)==NULL){
                temp->setKey(bit);
            }
            temp=temp->containsKey(bit);
        }
        // cout<<endl;
    }
    int find_max(int num){
        Node *temp=root;
        int ans=0;
        for(int i=31; i>=0; i--){
            int bit=1;
            if(num&(1<<i))bit=0;
            if(temp->containsKey(bit)){
                ans|=(1<<i);
                temp=temp->containsKey(bit);
            }
            else temp=temp->containsKey(!bit);
        }
        return ans;
    }
};
void solve(int i){
    cout<<"Case "<<i<<": ";
    int n;
    cin>>n;
    vector<int> nums(n);
    for(auto &it:nums)cin>>it;
    Trie tri;
    for(auto &it: nums){
        tri.insert(it);
    }
    int mx=0;
    for(auto &it: nums){
        mx=max(tri.find_max(it), mx);
    }  
    cout<<mx<<" ";  
}
int main(){
    int t;
    cin>>t;
    for(int i=1; i<=t; i++)solve(i);
}