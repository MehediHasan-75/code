#include <bits/stdc++.h>
using namespace std;
struct Node{
    Node *arr[26];
    bool isEnd=false;
    Node * containKey(char ch){
        return arr[ch-'a'];
    }
    void put(char ch, Node * node){
        arr[ch-'a']=node;
    }
    Node * getNext(char ch){
        return arr[ch-'a'];
    }
    void setEnd(){
        isEnd=true;
    }

};
class WordDictionary {
private:
Node* root;
public:
    WordDictionary() {
        root=new Node();
    }
    
    void addWord(string &word) {
        Node *temp=root;
        for(auto &it: word){
            if(temp->containKey(it)==NULL){
                temp->put(it, new Node());
            }
            temp=temp->getNext(it);
        }
        temp->setEnd();
    }
    bool search(string word) {
        Node *temp=root;
        for(auto &it: word){
            if(temp->containKey(it)==NULL){
                return false;
            }
            temp=temp->getNext(it);
        }
        return temp->isEnd;
    }
};
int main(){
    int n;
    cin>>n;
    vector<string>v(n);
    for(auto &it: v){
        cin>>it;
    }
    WordDictionary *obj=new  WordDictionary();
    for(auto &it: v){
        obj->addWord(it);
        cout<<it<<endl;
    }
    // cout<<obj->search("f");
}

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */