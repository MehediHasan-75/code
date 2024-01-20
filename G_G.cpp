#include <stdio.h>

int main() {
    int i, j;

    int arr[7]={0, 3, 1, 4, 1, 5, 9};// arr[0] will represent point A, arr[1] will B and so on.
    char p, q;
    int d = 0;

    scanf("%c %c", &p, &q);

    int x=p-'A', y=q-'A';// let's represnet character with a integer value.
    // if p='A' then x='A'-'A' =0, if p='B' then x='B'-'A'=1 and so on also same thig will happen for y

    // swap in case of p>q (exaple input: B A) so that x always less than y.
    if(x>y){
        int temp=x;
        x=y;
        y=temp;
    }
    // let x=1 and y=4 that means we need distance from B to E which is equal to arr[2]+arr[3](means D)+arr[5](means E);
    for(x=x+1; x<=y; x++){
        d+=arr[x];
    }
    printf("%d", d);
    return 0;
}