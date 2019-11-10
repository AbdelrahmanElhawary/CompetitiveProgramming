#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

const double PI = acos(-1.0);
const long double EPS = (1e-7);
const long long   OO = 1e9;
const long long   mod = 1e9 + 7;
int dcmp(long double x, long double y) { return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1; }

int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

#define ll long long
void fast(){
#ifndef ONLINE_JUDGE
	freopen("D:\\Competitve\\solving\\input.txt", "r", stdin);
	freopen("D:\\Competitve\\solving\\output.txt", "w", stdout);

#endif
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
}

const int MLOG = 35;
const int MAX = 2 * 100 * 1000 + 5;
bool vis[505][5005];
int main(){
	fast();
	int d, s;
	cin >> d >> s;
	queue<pair<pair<int, int>, string>>q;
	q.push({ { 0, 0 }, "" });
	string ans = "-1";
	while (q.size())
	{
		auto cur = q.front();
		q.pop();
		int dd = cur.first.first; int ss = cur.first.second;
		if (dd == 0 && ss == s)
		{
			ans = cur.second;
			break;
		}
		for (int i = 0; i <= 9; i++)
		{
			int nd = dd * 10 + i;
			int ns = ss + i;
			nd %= d;
			if (ns <= s&&!vis[nd][ns])
			{
				vis[nd][ns] = 1;
				string str = cur.second + (char)(i + '0');
				q.push({ { nd, ns }, str });
			}
		}
	}
	cout << ans << endl;

	return 0;
}