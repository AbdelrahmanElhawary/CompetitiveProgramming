#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include<unordered_map>
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
	ll n; cin >> n;
	ll cnt = 0;
	ll ans = 0;
	priority_queue<ll>v1, v2, v3;
	for (int i = 0; i < n; i++)
	{
		string s; int c;
		cin >> s >> c;
		if (s == "11")
		{
			ans += c;
			cnt++;
		}
		else if (s == "01")
		{
			v1.push(c);
		}
		else if (s == "10")
		{
			v2.push(c);
		}
		else {
			v3.push(c);
		}
	}
	ll m = min(v1.size(), v2.size());
	ll left1 = cnt + m;
	for (int i = 0; i < m; i++)
	{
		cnt += 2;
		ans += v1.top(); ans += v2.top();
		v1.pop(); v2.pop();
		
	}
	//cout << m << " " << cnt << " " << ans << endl;
	while ((2*left1>cnt)&&(v1.size()||v2.size()||v3.size()))
	{
		ll a=0, b=0;
		if (v1.size())
			a = v1.top();
		else if (v2.size())
			a = v2.top();
		if (v3.size())
			b = v3.top();
		if (a > b)
		{
			if (v1.size())
				v1.pop();
			else if (v2.size())
				v2.pop();
			ans += a;
		}
		else{
			if (v3.size())
				v3.pop();
			ans += b;
		}
		cnt++;
	}
	cout << ans << "\n";
		

	return 0;
}