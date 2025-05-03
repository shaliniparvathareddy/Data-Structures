#include<cstdio>
#include<cstdlib>
#include<unordered_set>
#include<vector>
#include<iostream>
using namespace std;
void solve();
int main(){
    int t;
    printf("Enter the number of testcases:");
    scanf("%d",&t);
    while(t--){
        solve();
        printf("\n");
    }
}
void solve(){
    int n;
    printf("Enter the length of sequence:");
    cin >> n;
    vector<int> a(n);
    printf("Enter the sequence:");
        for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    unordered_set<int>out;
    int left=0;
    for(int i=n-1;i>=0;i--){
        if(out.count(a[i])){
            left=i+1;
            break;
        }

        out.insert(a[i]);
    }

    printf("%d",left);
}
