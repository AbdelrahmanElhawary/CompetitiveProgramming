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
int dx[] = { -1,0,1,0,-1,1,-1,1 };
int dy[] = { 0,-1,0,1,1,1,-1,-1 };
int n, m;
char grid[300][300];
bool vis[202][202];
string hex(char ch)
{
	if (ch == '0')return "0000";
	if (ch == '1')return "0001";
	if (ch == '2')return "0010";
	if (ch == '3')return "0011";
	if (ch == '4')return "0100";
	if (ch == '5')return "0101";
	if (ch == '6')return "0110";
	if (ch == '7')return "0111";
	if (ch == '8')return "1000";
	if (ch == '9')return "1001";
	if (ch == 'a')return "1010";
	if (ch == 'b')return "1011";
	if (ch == 'c')return "1100";
	if (ch == 'd')return "1101";
	if (ch == 'e')return "1110";
	if (ch == 'f')return "1111";
}
bool check(int x, int y, char ch)
{
	return x >= 0 && x < n&&y >= 0 && y < m && !vis[x][y] && grid[x][y] == ch;
}
int cnt;
void dfs(int x, int y, char ch,int cnty)
{
	vis[x][y] = 1;
	for (int i = 0; i < cnty; i++)
	{
		int xx = x + dx[i], yy = y + dy[i];
		if (check(xx,yy, ch))
			dfs(xx, yy, ch,cnty);
		else if (ch == '1'&&check(xx, yy, '0'))
			cnt++, dfs(xx, yy, '0',8);

	}
}
int main() {
	fast_in_out();
	//cout << fixed << setprecision(6);
	string hexo = "WAKJSD";
	int tt = 1;
	while (cin >> n >> m&&(n||m))
	{
		memset(vis, 0, sizeof vis);
		string ans="";
		m *= 4;
		string str;
		for (int i = 0; i <= n + 1; i++)
			grid[i][0] = grid[i][m + 1]='0';
		for (int i = 0; i <= m + 1; i++)
			grid[0][i] = grid[n + 1][i] = '0';
		for (int i = 1; i <= n; i++)
		{
			cin >> str;
			int c = 1;
			for (int j = 0; j < str.size(); j++)
			{
				string st = hex(str[j]);
				for (int k = 0; k < 4; k++)
					grid[i][c++]= st[k];
			}
		}
		n += 2; m += 2;
		char ch = '0';
		dfs(0, 0,ch,8);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (!vis[i][j] && grid[i][j] == '1')
				{
					cnt = 0;
					dfs(i, j, '1',4);
					ans += hexo[cnt];
				}
		sort(ans.begin(), ans.end());
		cout <<"Case "<<tt++<<": "<< ans << endl;
	}
	pause();
	return 0;
}