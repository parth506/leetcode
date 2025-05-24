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
    cout<<f(n-1,a,dp)<<endl;

}

//Tabulation
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    vector<int> dp(n,-1);
    dp[0]=a[0];
    for(int i=1 ;i <n ;++i){
        int take = a[i];if(i>1) take+=dp[i-2];
        int non_take= 0+dp[i-1];
        dp[i]=max(take,non_take);
    }
    cout<<dp[n-1]<<endl;
}

//Space Optimisation
int main(){
   int n;
    cin>>n;
    vector<int> a(n);
    int prev=a[0];
    int prev2=0;
    for(int i=1 ;i <n ;++i){
        int take = a[i];if(i>1) take+=prev2;
        int non_take= 0+prev;
        int curr=max(take,non_take);
        prev2=prev;
        prev=curr;
    }
    cout<<prev<<endl;

}