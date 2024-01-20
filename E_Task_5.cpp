#include <iostream>

using namespace std;

bool func(string s) {
		int i=-1;
		for(auto& ch:s){
			if(ch=='(' || ch=='{' || ch=='[')
				s[++i]=ch;
			else{
				if(i>=0 && ((s[i]=='(' && ch==')') || (s[i]=='{' && ch=='}') || (s[i]=='[' && ch==']')))
					i--;
				else
					return false;
			}
		}
		return i==-1;
}
void solve(){
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        string s;
        cin>>s;
        if(func(s))cout << "YES\n";
        else cout << "NO\n";
    }
}
int main()
{
	int t=1;
    // cin>>t;
    while(t--)solve();
}
