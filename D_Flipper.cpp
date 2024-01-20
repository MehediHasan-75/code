#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'


signed main()
{


    int t; cin>>t;
    while (t--)
    {

        int n; cin>>n;

        vector <int> a(n);

        for (auto &it : a) {cin>>it;}
        int mpos=max_element(a.begin()+1, a.end())-a.begin();

        cout<<mpos<<endl;
        for (int i=mpos; i<n; i++) cout <<a[i] <<" ";

        int i=mpos-1;
        if (mpos!=n-1) {cout <<a[mpos-1] <<" "; i--;}
        int j=0;
        while (i>=0 && a[i]>a[j]) cout <<a[i--] <<" ";
        while (j<=i) cout <<a[j++] <<" ";
        cout <<endl;

    }





}