#include<bits/stdc++.h>
using namespace std;

//Tabulation
int main(){
    int n;
    cin>>n;
    vector<int> h(n);
    for(int i=0 ; i<n ;++i){
        cin>>h[i];
    }
    vector<int> dp(n,-1);
    dp[0]=0;
    for(int i=1 ;i<n ;++i){
        int left=dp[i-1]+abs(h[i]-h[i-1]);
        int right=INT_MAX;
        if(i>1) right=dp[i-2]+abs(h[i]-h[i-2]);

        dp[i]=min(left,right);
    }
    cout<<dp[n-1]<<endl;
}

//Space Optimisation 
int main(){
    int n;
    cin>>n;
    vector<int> h(n);
    for(int i=0 ; i<n ;++i){
        cin>>h[i];
    }
    int prev=0;
    int prev2=0;

    for(int i=1 ;i<n ;++i){
        int left=prev+abs(h[i]-h[i-1]);
        int right=INT_MAX;
        if(i>1) right=prev2+abs(h[i]-h[i-2]);

        int curr=min(left,right);
        prev2=prev;
        prev=curr;

    }
    cout<<prev<<endl;
}

//Frog Jumps till k Steps
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> h(n);
    for(int i=0 ; i<n ;++i){
        cin>>h[i];
    }
    vector<int> dp(n,-1);
    dp[0]=0;
    for(int i=1 ;i<n ;++i){
        int min_steps=INT_MAX;
        for(int j=1 ;j<=k ;++j){
            if(i>=j){
                 int jumps=dp[i-j]+abs(h[i]-h[i-j]);
                 
                min_steps=min(min_steps,jumps);
            }
           
        }
        dp[i]=min_steps;
        

        
    }
    cout<<dp[n-1]<<endl;
}