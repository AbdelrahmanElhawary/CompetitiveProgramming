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
int n, m;
string s[1501];
pair<pair<int, int>, bool>mp[1501][1501];
bool f;
int mod(int x, int nn)
{
	x %= nn;
	x += nn;
	x %= nn;
	return x;
}
void dfs(int x,int y)
{
	
	mp[mod(x, n)][mod(y, m)] = mk(mk(x, y), 1);
	for (int i = 0; i < 4; i++)
	{
		int xx = x + dx[i];
		int yy = y + dy[i];
		if (s[mod(xx,n)][mod(yy,m)] == '#')continue;
		if (!mp[mod(xx, n)][mod(yy, m)].second)
			dfs(xx, yy);
		else if (mp[mod(xx, n)][mod(yy, m)].first.first != xx || mp[mod(xx, n)][mod(yy, m)].first.second != yy)
		{
			f = 1; return;
		}
		
	}
}
int main() {
	fast_in_out();
	//cout << fixed << setprecision(6);
	cin >> n >> m;
	pair<int, int>str;
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
		for (int j = 0; j < s[i].size(); j++)
			if (s[i][j] == 'S')str.first = i, str.second = j;
	}
	dfs(str.first,str.second);
	if (f)cout << "Yes\n"; else cout << "No\n";
	pause();
	return 0;
}