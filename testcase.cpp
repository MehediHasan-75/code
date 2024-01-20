#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("C:\\Users\\Mehedi\\Desktop\\t1.txt", "r", stdout);
    //freopen("jediacademy.out", "w", stdout);
    const int N=10;
    cout<<N<<endl;
    int k=0, shi=0;
    for(int i=2; i<=N; i++){
        int type =rand() % 2 + 1;
        cout<<type<<" ";
        cout<<k<<" ";
        for(int i=1; i<=k; i++){
            cout<<i<<" ";
        }
        cout<<endl;
        k=k+(1<<shi);
        shi++;
    }
    cout<<rand() %10000+1<<" "<<rand() % 10000 + 1<<endl;
}