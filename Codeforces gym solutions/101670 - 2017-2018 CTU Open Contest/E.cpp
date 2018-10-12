#include <bits/stdc++.h>
using namespace std;
typedef complex<double> point;
#define angle(a) ( atan2( (a).imag(), (a).real()) )
#define ll long long
char grid[105][105];
int n,m;
void full1(int n)
{
	for(int i=0;i<n+2;i++)
		for(int j=0;j<n+2;j++)
			grid[i][j]='.';
}
void put(char ch,int x,int y)
{
	if(x>=n||x<0||y>=n||y<0)
		return;
//cout<<"holla\n";
	grid[x][y]=ch;
}
void tree(int s,int x,int y)
{
	put((char)124,x,y);
	put('_',x,y-1);
	put('_',x,y+1);
	for(int i=1;i<=s;i++)
	{
		put((char)124,x-i,y);
		put((char)47,x-i,y-1);
		put((char)92,x-i,y+1);
	}
	put('^',x-s-1,y);
}
int main() {

	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	while(cin>>n)
	{
		cin>>m;
	
		full1(n);
		for(int i=0;i<m;i++)
		{
			int s,x,y;
			cin>>s>>x>>y;
			swap(x,y);
			x=n-x-1;
		//	cout<<x<<" "<<y<<endl;
			if(!s)
			{
				put((char)111,x,y);
				put((char)95,x,y-1);
				put((char)95,x,y+1);
			}
			else {
				tree(s,x,y);
			}
		}
		for(int i=0;i<n+2;i++)
			cout<<'*';cout<<endl;
		for(int i=0;i<n;i++)
		{
			cout<<'*';
			for(int j=0;j<n;j++)
			{
				cout<<grid[i][j];
			}
			cout<<"*\n";
		}
		for(int i=0;i<n+2;i++)
			cout<<'*';cout<<endl;
		cout<<endl;
		
	}
	return 0;
}