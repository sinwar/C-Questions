/*
	team - bug404
	sparsh 2k17

	question - 6
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

typedef long long ll;


int memo[501][100],price[100],fun[100];

int solve(int b, int n){
    if(n < 0) return 0;
    
    int &ret = memo[b][n];
    
    if(ret == -1){
        ret = solve(b,n-1);
        if(price[n] <= b) ret = max(ret,fun[n] + solve(b-price[n],n-1));
    }
    
    return ret;
}

int main(){
    int B,N;
    
    while(true){
        cin >> B >> N;
        if(B == 0 && N == 0) break;
        
        for(int i = 0;i < N;++i)
        {
        	cin >> price[i] >> fun[i];
        }
        
        memset(memo,-1,sizeof(memo));
        
        int F = solve(B,N-1),lo = 0,hi = B,mi;
        
        while(lo < hi){
            mi = (lo + hi)>>1;
            
            if(solve(mi,N-1) < F) lo = mi+1;
            else hi = mi;
        }
        
        printf("%d %d\n",lo,F);
    }
    
    return 0;
}
