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
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
string s[1001];
int ans[1000001], vis[1002][1002];
int main() {
	fast_in_out();
	//cout << fixed << setprecision(6);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
		cin >> s[i];
	int cnt = 0;
	while (k--)
	{
		int x, y; cin >> x >> y;
		x--, y--;
		if (vis[x][y])
		{
			cout << ans[vis[x][y]] << endl;
			continue;
		}
		vis[x][y] = ++cnt;
		queue<pair<int, int>>q;
		q.push(mk(x, y));
		int ansy = 0;
		while (q.size())
		{
			pair<int, int>cur = q.front(),temp;
			q.pop();
			for (int i = 0; i < 4; i++)
			{
				temp.first = cur.first + dx[i];
				temp.second = cur.second + dy[i];
				if (vis[temp.first][temp.second])continue;
				if (s[temp.first][temp.second] == '.')
				{
					q.push(temp);
					vis[temp.first][temp.second] = cnt;
				}
				else ansy++;
			}
			ans[cnt] = ansy;
		}
		cout << ans[vis[x][y]] << endl;

	}
	pause();
	return 0;
}