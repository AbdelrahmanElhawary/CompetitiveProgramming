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

int main() {
	fast_in_out();
	//cout << fixed << setprecision(6);
	int t; cin >> t;
	while (t--)
	{
		int n, m;
		string s[9];
		cin >> n >> m;
		for (int i = 0; i < n; i++)
			cin >> s[i];
		string str = "@IEHOVA#";
		vector<pair<int, int>>v;
		for (int u = 0; u < str.size(); u++)
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					if (str[u] == s[i][j])v.push_back(mk(i, j));
				}
			}
		}
		for (int i = 0; i < v.size() - 1; i++)
		{
			if (i)cout << " ";
			if (v[i].first > v[i + 1].first)cout << "forth";
			else if (v[i].second < v[i + 1].second)cout << "right";
			else cout << "left";
		}
		cout << endl;
	}
	pause();
	return 0;
}