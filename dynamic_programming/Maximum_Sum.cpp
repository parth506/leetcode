// Adjacent wala 
#include<bits/stdc++.h>
using namespace std ;

//Memoisation

int f(int n,vector<int> &a,vector<int> &dp){
    if(n==0) return a[0];
    if(n<0) return 0;
    if(dp[n]!=-1) return dp[n];
    int pick=a[n]+f(n-2,a,dp);
    int non_pick=0+f(n-1,a,dp);
    return dp[n]=max(pick,non_pick);
}
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    vector<int> dp(n,-1);
    dp[0]=0;
    cout<<f(n,a,dp)<<endl;

}