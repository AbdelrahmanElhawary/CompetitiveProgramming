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
int dx[] = { 0,0,-1,1,-1,1,-1,1,0 };
int dy[] = { -1,1,0,0,-1,-1,1,1,0 };
int lx[] = { 2, 2, -1, 1, -2, -2, -1, 1 };
int ly[] = { -1, 1, 2, 2, 1, -1, -2, -2 };
const ld eps = 1e-9;
const int N = 1e5 + 50, M = 1e5 + 10, mod = 1e9 + 7;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { ll t = gcd(a, b); return t ? (a / t * b) : 0; }
class MessageMess {
        public:
	map<string, int>mp;
	string str,ans="";
	int dp[55][55];
	int solve(int i, int j) {
		if (i == str.size())return 1;
		if (j == str.size())return 0;
		int& ret = dp[i][j];
		if (ret != -1)return ret;
		ret = 0;
		if (mp.find(str.substr(i, j - i + 1)) != mp.end())
			ret = solve(j + 1, j + 1);
		ret += solve(i, j + 1);
		if (ret > 2)ret = 2;
		return ret;
	}
	void build(int i, int j) {
		if (i == str.size())return;
		if (mp.find(str.substr(i, j - i + 1)) != mp.end()) {
			if (solve(j + 1, j + 1))
			{
				if (ans.size())ans += " ";
				ans += str.substr(i, j - i + 1);
				build(j + 1, j + 1);
				return;
			}
		}
		build(i, j + 1);
		return;
	}
	string restore(vector<string> dic, string s) {
		str = s;
		memset(dp, -1, sizeof dp);
		for (auto e : dic)
			mp[e] = 1;
		int x = solve(0, 0);
		if (x == 0) { return "IMPOSSIBLE!"; }
		if (x > 1) { return "AMBIGUOUS!"; }
		build(0, 0);
		return ans;
	}
};