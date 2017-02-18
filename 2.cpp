/*
	team - bug404
	sparsh 2k17

	question - 2
*/

#include<bits/stdc++.h>
using namespace std;
 
#define MP make_pair
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,a,b) for(int i=a;i<=b;i++)
#define PER(i,a,b) for(int i=b;i>=a;i--)
#define X first
#define Y second
 
 
 
//cost
#define MOD 10000000
#define MOD_INV 1000000006
#define MAX 100009
#define INF 999999999
#define mp make_pair
typedef long long ll;
typedef pair< pair<ll,ll>,ll > pairs;

int dp[1001],H[501],K[501];
int N;
 
int main(){
int T;
cin>>T;
dp[0]=0;
while(T>0){
cin>>N;
 
for(int i=1;i<=N;i++){
        cin>>H[i];
}
 
for(int j=1;j<=N;j++){
        cin>>K[j];
}
// calculate max of H(i)
int max=H[1];
for(int i=1;i<=N;i++){
if(max<H[i])
            max=H[i];
}
for(int j=1;j<=2*max;j++){
                      dp[j]=1000000000;
}
for(int i=1;i<=N;i++){
                  for(int j=K[i];j<=2*max;j++){
                                           if(dp[j]>(1+dp[j-K[i]]))
                                                                   dp[j]=1+dp[j-K[i]];
                  }
}
int res=0;
for(int i=1;i<=N;i++){
                  res=res+dp[2*H[i]];
                 
}
cout<<res<<endl;
 
T--;
}
return 0;
}
 