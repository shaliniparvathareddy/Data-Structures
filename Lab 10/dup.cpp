//Program to calculate word game points
#include<cstdio>
#include<iostream>
#include<vector>
#include<cstdlib>
#include<unordered_map>
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
//Function to calculate word game points
void solve(){
    int n;
    printf("Enter the number of words by each person:");
    scanf("%d",&n);

    vector<vector<string>>words(3, vector<string>(n));
    unordered_map<string,int> freq;
    printf("Enter the words:");
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < n; ++j){
            cin >> words[i][j];
            freq[words[i][j]]++;
        }
    }

    vector<int>points(3,0);
    for(int i=0;i<3;i++){
        for(const string& word:words[i]){
            switch(freq[word]){
                case 1:
                       points[i]+=3;
                       break;
                case 2:
                       points[i]+=1;
                       break;
                case 3:
                       break;
                       
            }
        }
    }
    for(int i=0;i<3;i++){
    printf("%d ",points[i]);
    }
}
