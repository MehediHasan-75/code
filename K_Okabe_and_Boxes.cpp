#include<bits/stdc++.h>
using namespace std;
stack<int>st,emp;
int main()
{
    long long k,n,ans=0, i=1;
    string s;
    cin>>n;
    n*=2;
    while(n--){
        cin>>s;
        if(s[0]=='a'){
            cin>>k;
            st.push(k);
        }
        else{
            if(st.empty()){}
            else if(st.top()==i) st.pop();
            else{
                st=emp;
                ans++;
            }
            i++;
        }
    }
    cout<<ans<<endl;
    return 0;
}