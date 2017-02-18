/*
	team - bug404
	sparsh 2k17

	question - 1
*/

// as asked in question any correct arrangement should be printed so this program will give output one of the correct
// solution. Answer of test cases may be differ from your solution because there is possibility of more than one solution for one testcase

#include<bits/stdc++.h>
using namespace std;
 
#define MP make_pair
#define pb push_back
#define X first
#define Y second
 
 
 
//cost
#define MOD 10000000
#define MOD_INV 1000000006
#define MAX 100009

//loops

#define FF(i,m,n) for(int (i)=(m);((i)<(n));(i++)) 
#define F(i,n) FF(i,0,n) 
#define CLR(s,v) memset(s,v,sizeof(s)) 
typedef pair<int,int> PI; 
// For Pair -> First & Second
#define f first 
#define s second 
#define S(t) scanf("%d",&t)

typedef long long ll;

int N,K,arr[501][501],x,y,queenboard[501][501];
//
void disp( )
{
	
	for ( int i = 1 ; i <=N ; i++)
	{
		cout<<"\n";
		//queenboard
		for ( int j = 1 ; j <=N ; j++)
		{
			if(queenboard[i][j]==-1)
				cout << "#";
			else if(queenboard[i][j] == 0)
				cout << " ";
			else
				cout<< queenboard[i][j];
		}
		cout<<"   ";
		for ( int j = 1 ; j <=N ; j++)
		{
			if(arr[i][j]==2)
				cout << "#";
			else if(arr[i][j]==1)
				cout << "Q";
			else 
				cout << "-";
		}
 
	}
	cin.get();
 
}
 
void place_queen( int i , int j  )
{
	
	int ii = i , jj = j,x,y;
	//For that row and column
	if(queenboard[i][j]==0)
		queenboard[i][j]=j;
	for(x=i-1;x>=1;x--)
	{
		if(queenboard[x][j]==-1)
			break;
		if(queenboard[x][j]==0)
			queenboard[x][j]=j;
	}
	for(x=i+1;x<=N;x++)
	{
		if(queenboard[x][j]==-1)
			break;
		if(queenboard[x][j]==0)
			queenboard[x][j]=j;
	}
	for(y=j-1;y>=1;y--)
	{
		if(queenboard[i][y]==-1)
			break;
		if(queenboard[i][y]==0)
			queenboard[i][y]=j;
	}
	for(y=j+1;y<=N;y++)
	{
		if(queenboard[i][y]==-1)
			break;
		if(queenboard[i][y]==0)
			queenboard[i][y]=j;
	}
	x=i+1;
	y=j+1;
	while(x<=N && y<=N)
	{
		if(queenboard[x][y]==-1)
			break;
		if(queenboard[x][y]==0)
			queenboard[x][y]=j;
		x++;
		y++;
	}
	x=i-1;
	y=j-1;
	while(x>=0&& y>=0)
	{
		if(queenboard[x][y]==-1)
			break;
		if(queenboard[x][y]==0)
			queenboard[x][y]=j;
		x--;
		y--;
	}
	x=i-1;
	y=j+1;
	while(x>=0&& y<=N)
	{
		if(queenboard[x][y]==-1)
			break;
		if(queenboard[x][y]==0)
			queenboard[x][y]=j;
		x--;
		y++;
	}
	x=i+1;
	y=j-1;
	while(x<=N&& y>=0)
	{
		if(queenboard[x][y]== -1)
			break;
		if(queenboard[x][y]==0)
			queenboard[x][y]=j;
		x++;
		y--;
	}
 
}
void remove_queen(int jj)
{
 
	for ( int i = 1 ; i <= N ; i++ )
		 for ( int j = 1 ; j <= N ; j++)
		 {
			if(queenboard[i][j]==jj)
				queenboard[i][j]=0;
		 }
}
int recurse(int j )
{
	if ( j > N )
		return 1;
	/*cout << endl ;
	disp();
	cout << endl;*/
	for ( int i =1 ; i <=N ; i ++)
	{
		
		if ( queenboard[i][j] == 0 )
		{
			place_queen(i,j);
			arr[i][j] = 1 ;
			
			if(recurse(j+1))
			{
				
				return 1;
			}
			arr[i][j] = 0;
		
			remove_queen(j);
		}
	}
	return 0;
}

int main()
{
	
	int t;
	cin >> t;
	while(t--)
	{

			cin >> N >> K;
			CLR(arr,0);
			CLR(queenboard,0);
			
		 
			F(i,K)
			{
				cin>>x>>y;
				
				arr[x][y]  =2;
				queenboard[x][y]=-1 ;
			}
			if(recurse(1))
			{
			//	disp();
				for(int j=1;j<=N;j++)
				{
					for(int i=1 ;i<=N ;i++)
					{
						if(arr[i][j]==1)
						{
							cout << i << " ";
							break;
						}
					}
				}
		 
			}
			cout<<endl;
	}
	return 0;
} 