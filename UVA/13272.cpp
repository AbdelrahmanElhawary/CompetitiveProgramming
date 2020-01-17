#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include<bits/stdc++.h>
#include<chrono>
#include<unordered_map>
#include<random>
#include<complex> 
using namespace std;
#define ll long long
#define ld long double
#define ull unsigned ll 
#define endl '\n'
#define mk make_pair
#ifndef ONLINE_JUDGE
int __builtin_popcount(int mask) {
	int cnt = 0;
	for (int i = 0; i < 23; i++)
		if (mask & (1 << i)) ++cnt;
	return cnt;
}
#endif
void fast_in_out() {
	std::ios_base::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
int dx[] = { 0,0,-1,1,-1,1,-1,1,0 };
int dy[] = { -1,1,0,0,-1,-1,1,1,0 };
int lx[] = { 2, 2, -1, 1, -2, -2, -1, 1 };
int ly[] = { -1, 1, 2, 2, 1, -1, -2, -2 };
const ld eps = 1e-9;
const int N = 2e5 + 50, M = 1e5 + 10, mod = 998244353;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { ll t = gcd(a, b); return t ? (a / t * b) : 0; }
ll ans[N];
int main() {
	fast_in_out();
	//cout << fixed << setprecision(9);
	unordered_map<char, int>mp;
	mp['('] = 1; mp[')'] = -1;
	mp['{'] = 2; mp['}'] = -2;
	mp['['] = 3; mp[']'] = -3;
	mp['<'] = 4; mp['>'] = -4;
	int t; cin >> t;
	int tt = 1;
	while (t--) {
		string s; cin >> s;
		int n = s.size();
		for (int i = 0; i < n+n; i++)
			ans[i] = 0;
		stack<int>st;
		for (int i = 0; i < n; i++) {
			int x = mp[s[i]];
			if (x > 0)st.push(i);
			else if (st.size() && mp[s[st.top()]] + x == 0) {
				ans[st.top()] = i - st.top() + 1;
				st.pop();
			}
			else {
				while (st.size())st.pop();
			}
		}
		for (int i = n - 1; i > -1; i--) {
			if (ans[i] && ans[ans[i] + i])
				ans[i] += ans[ans[i] + i];
		}
		cout << "Case "<<tt++<<":\n";
		for (int i = 0; i < n; i++)
			cout << ans[i] << endl;
	}
	return 0;
}