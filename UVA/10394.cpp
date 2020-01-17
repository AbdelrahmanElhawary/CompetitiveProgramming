// i'm a failure
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
const int N = 2e7 + 50, M = 1e5 + 10, mod = 1e9 + 7;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { ll t = gcd(a, b); return t ? (a / t * b) : 0; }
bool pr[N];
vector<int>prime;
vector<pair<int, int>>ans;
void sieve() {
	for (int i = 2; i < N; i += 2)
		pr[i] = 1;
	prime.emplace_back(2);
	for (int i = 3; i < N; i += 2) {
		if (!pr[i]) {
			prime.emplace_back(i);
			if (1LL * i * i >= N)continue;
			for (int j = i * i; j < N; j += i)
				pr[j] = 1;
		}
	}
}
void pre() {
	
	for (int i = 1,j=0; i < prime.size(); i++) {
		if (prime[i] - prime[i - 1] == 2)
			ans.emplace_back(prime[i-1], prime[i]);
	}
}
int main() {
	fast_in_out();
	//cout << fixed << setprecision(9);
	//kolo ra7
	sieve();
	pre();
	int n; 
	while (cin >> n) {
		cout << "("<<ans[n - 1].first << ", " << ans[n - 1].second << ")\n";
	}
	return 0;
}