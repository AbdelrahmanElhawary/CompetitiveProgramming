#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include<iostream>
#include<map>
#include<cmath>
#include<algorithm>
#include<string>
#include<set>
#include<sstream>
#include<vector>
#include<string.h>
#include<queue>
#include<list>
#include<iterator>
#include<functional> 
#include<iomanip>
#include<bitset>
#include<stack>
#define F first
#define S second
#define ll long long
#define ld long double
#define ull unsigned ll 
#define dong long
#define endl '\n'
#define mk make_pair
using namespace std;
void fast_in_out() {
	std::ios_base::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);
}
void pause() {
#ifndef ONLINE_JUDGE
	system("pause");
#endif
}
int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };
int n, m; bool vis[501][501];
string s[501];
vector<pair<pair<int, int>, int>>ans;
bool check(int x, int y)
{
	return x >= 0 && x < n&&y >= 0 && y < m&&s[x][y] == '#' && !vis[x][y];
}
void dfs(int x, int y)
{
	vis[x][y] = 1;
	for (int i = 0; i < 4; i++)
	{
		int xx = x + dx[i];
		int yy = y + dy[i];
		if (check(xx, yy))
			dfs(xx, yy);
	}
}
int main() {
	fast_in_out();
	//cout << fixed << setprecision(6);
	cin >> n >> m; int c = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
		for (int j = 0; j < s[i].size(); j++)
			if (s[i][j] == '#')c++;
	}
	if (c <= 2)
		cout << -1 << endl;
	else
	{
		bool f = 0;
		for(int i=0;i<n;i++)
			for (int j = 0; j < m; j++)
			{
				if (s[i][j] == '.')continue;
				memset(vis, 0, sizeof vis);
				int cnt = 0;
				s[i][j] = '.';
				for(int k=0;k<n;k++)
					for(int l=0;l<m;l++)
						if (!vis[k][l]&&s[k][l]=='#')
						{
							cnt++;
							dfs(k, l);
						}
				s[i][j] = '#';
				if (cnt > 1)f = 1;
			}
		if (f)cout << 1 << endl;
		else cout << 2 << endl;
	}
	pause();
	return 0;
}