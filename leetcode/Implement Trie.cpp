#include <bits/stdc++.h>
using namespace std;
struct Node{
    Node* arr[26];
    bool isEnd=false;
    Node* containKey(char ch){
        return arr[ch-'a'];
    }
    void setKey(char ch,Node* node){
        arr[ch-'a']=node;
    }
    void setEnd(){
        isEnd=true;
    }
    Node * getNext(char ch){
        return arr[ch-'a'];
    }
};
class Trie {
private: 
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* temp=root;
        for(auto &it: word){
            if(temp->containKey(it) == NULL)
             temp->setKey(it,new Node());
            temp=temp->containKey(it);
        }
        temp->setEnd();
    }
    
    bool search(string word) {
        
    }
    
    bool startsWith(string prefix) {
        Node* temp=root;
        for(auto &it: prefix){
            if(temp->containKey(it) == NULL)return false;
            temp=temp->containKey(it);
        }
        return true;
    }
};
int main(){

}