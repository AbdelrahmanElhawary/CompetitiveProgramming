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
int arr[101][101],n;
bool vis[101][101];
bool check(int x, int y)
{
	return x > 0 && x <= n && y > 0 && y <= n && !vis[x][y];
}
void dfs(int x, int y)
{
	vis[x][y]=1;
	for (int i = 0; i < 4; i++)
	{
		int xx = x + dx[i], yy = y + dy[i];
		if (check(xx, yy)&&arr[x][y]==arr[xx][yy])
			dfs(xx, yy);
	}
}
int main() {
	fast_in_out();
	//cout << fixed << setprecision(6);
	while (cin >> n&&n)
	{
		int cnt = 1;
		memset(vis, 0, sizeof vis);
		memset(arr, 0, sizeof arr);
		cin.ignore();
		for (int i = 0; i < n - 1; i++)
		{
			string s;
			getline(cin, s);
			//cout << s << endl;
			istringstream str(s);
			int x, y;
			while (str >> x >> y)
			{
				//cout << x <<" "<< y << endl;
				arr[x][y] = cnt;
			}
			cnt++;
		}
		cnt = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
			{
				if (!vis[i][j])
					dfs(i, j),cnt++;
			}
		if (cnt == n)
			cout << "good\n";
		else cout << "wrong\n";
	}
	pause();
	return 0;
}