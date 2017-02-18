/*
	team - bug404
	sparsh 2k17

	question - 4
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


int main() {
    int T;
    cin >> T;
    for (int t=0;t<T;t++) {
        long long T1,T2,t1,t2;

        cin >> T1 >> T2 >> t1 >> t2;


        long long ans = 2*T1*T2;
        if (T1>t2) {
            ans-=(T1-t2)*(T1-t2);
            if (T1-t2>T2) ans+=(T1-t2-T2)*(T1-t2-T2);
        }
        if (T2>t1) {
            ans-=(T2-t1)*(T2-t1);
            if (T2-t1>T1) ans+=(T2-t1-T1)*(T2-t1-T1);
        }
        printf("%1.9f\n",(double) ans/(2*T1*T2));
    }
 
    return 0;
}
 