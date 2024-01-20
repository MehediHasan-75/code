#include<bits/stdc++.h>
using namespace std;
struct Node{
    Node *arr[26];
    int sz=0;
    Node * containKey(char ch){
        return arr[ch-'a'];
    }
    void put(char ch, Node *node) {
		arr[ch - 'a'] = node;
	}
    Node * get(char ch) {
        return arr[ch - 'a'];
    }
    void setSize(){
        sz++;
    }
    int getSize(){
        return sz;
    }
};
class Trie {
private:
	Node* root;
public:
	Trie() {
		//creating new obejct
		root = new Node();
	}

	void insert(string word) {
		//initializing dummy node pointing to root initially
		Node *node = root;
        node->setSize();
		for (int i = 0; i < word.size(); i++) {
			if (!node->containKey(word[i])) {
				node->put(word[i], new Node());
			}
			//moves to reference trie
			node = node->get(word[i]);
            node->setSize();
		}
	}

	string search(string &word, int n) {
		Node *node = root;
        string ans="";
		for (int i = 0; i < word.size(); i++) {
			node = node->get(word[i]);
            if(node->getSize()!=n)break;
            ans+=word[i];
		}
        return ans;
	}
};
string longestCommonPrefix(vector<string>& strs) {
    Trie tri;
    for(auto &it: strs){
        //cout<<it<<endl;
        tri.insert(it);
    }
    return tri.search(strs.back(), strs.size());
    // cout<<tri.find(strs.back())<<endl;
}
int main(){
    int n;
    cin>>n;
    vector<string>v(n);
    for(auto &it: v)cin>>it;
    longestCommonPrefix(v);
}