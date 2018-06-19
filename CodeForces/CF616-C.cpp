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
#define ll long long
#define ld long double
#define ull unsigned ll 
#define endl '\n'
#define mk make_pair
#define pb push_back
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
string s[1002];
int n, m;
int vis[1000][1000],ary[1001][1001], vis_num = 0,cnt;
vector<int>ans;
bool check(int x,int y)
{
	return x >= 0 && x < n&&y >= 0 && y < m&&s[x][y] == '.'&&!vis[x][y];
}
bool check1(int x, int y)
{
	return x >= 0 && x < n&&y >= 0 && y < m&&s[x][y] == '.';
}
void dfs(int x, int y)
{
	vis[x][y] = 1;
	ary[x][y]=vis_num;
	cnt++;
	for (int i = 0; i < 4; i++)
	{
		int xx = x + dx[i], yy = y + dy[i];
		if (check(xx, yy))
			dfs(xx, yy);
	}
}
int main() {
	fast_in_out();
	//cout << fixed << setprecision(6);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> s[i];
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if (s[i][j] == '.'&&!vis[i][j])
			{
				dfs(i, j);
				ans.push_back(cnt);
				vis_num++;
				cnt = 0;
			}
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if (s[i][j] == '*')
			{
				int ansy = 1;
				map<int,bool>tempvis;
				for (int k = 0; k < 4; k++)
				{
					if (check1(i + dx[k], j + dy[k])&&!tempvis[ary[i + dx[k]][j + dy[k]]])
						ansy += ans[ary[i + dx[k]][j + dy[k]]],tempvis[ary[i + dx[k]][j + dy[k]]]=1;
				}
				s[i][j] = (char)(ansy % 10 + '0');
			}

	for (int i = 0; i < n; i++)
		cout << s[i] << endl;
	pause();
	return 0;
}