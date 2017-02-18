/*
	team - bug404
	sparsh 2k17

	question - 5
*/


#include <bits/stdc++.h>
using namespace std;
 
#define MP make_pair
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,a,b) for(int i=a;i<=b;i++)
#define PER(i,a,b) for(int i=b;i>=a;i--)
#define X first
#define Y second
 
 
 
//cost
#define MOD_INV 1000000006
#define MAX 100009

typedef long long ll;
const int MOD=(1e9+7);
#define size 5007
int Z[size],nc[size][size],ans[size],cnt[size],temp[size];
void init()
{
		for(int i=1;i<=5001;i++)
		{
			nc[i][1]=i;
		}
		for(int i=2;i<5001;i++)
		{
			for(int j=2;j<i+1;j++)
			{			
				nc[i][j]=(nc[i-1][j-1]+nc[i-1][j])%MOD;
			}
		}
}
void zalgo(string str)
{
	int n=str.length();
	 int L, R, k;
    	L = R = 0;
	Z[0]=n;
    	for (int i = 1; i < n; ++i)
    	{
        	if (i > R)
        	{
        		    L = R = i;
 
            		while (R<n && str[R-L] == str[R])
                		R++;
            		Z[i] = R-L;
            		R--;
        	}
        	else
        	{
        	
        		    k = i-L;
 			    if (Z[k] < R-i+1)
                		 Z[i] = Z[k];
 
		            else
        		    {
                
                		L = i;
                		while (R<n && str[R-L] == str[R])
                			    R++;
               			 Z[i] = R-L;
                		R--;
            			}
        	}
    	}
}
int main()
{ios_base::sync_with_stdio(false);cin.tie(NULL);
	init();
	int T;
	cin>>T;
	while(T--)
	{
		int n,q;
		cin>>n>>q;
		string s;
		cin>>s;
		for(int i=0;i<=n;i++)
		{
			temp[i]=Z[i]=cnt[i]=ans[i]=0;
		}
		for(int i=0;i<n;i++)
		{
			//memset(Z,0,sizeof(Z));
			//memset(temp,0,sizeof(temp));
			for(int j=0;j<=n;j++)
			{
				Z[j]=0;
				temp[j]=0;
			}
			zalgo(s.substr(i,n-i));
			for(int j=0;j<n;j++)
			{
				temp[Z[j]]++;
			}
			for(int j=n-1;j>=1;j--)
			{
				temp[j]+=temp[j+1];
			}
			for(int j=1;j<=n;j++)
			{
				cnt[temp[j]]++;
			}
		}
		ans[1]=(n*(n+1))/2;
		for(int i=2;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
			{
				ans[i]=(ans[i]+((cnt[j]-cnt[j+1])*1LL*nc[j][i])%MOD)%MOD;
			}
		}
		while(q--)
		{
			int len;
			cin>>len;
			if(len>n){cout<<"0\n";}
			else{cout<<ans[len]<<"\n";}
		}
	}
}
 