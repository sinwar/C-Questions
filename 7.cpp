/*
	team - bug404
	sparsh 2k17

	question - 7
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


int a[1000000];
int main(){
  int t,i,n;
  long long d;
  cin>>t;
  while(t--){
    cin>>n;
    d=1;
    for(i=0;i<n;i++)
      cin>>a[i];
    for(i=0;i<n-1;i++)
      d=(d-a[i])*2;
    if(d==a[n-1])
      cout<<"Yes"<<endl;
    else
      cout<<"No"<<endl;
  }
}