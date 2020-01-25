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
const int N = 1e5 + 50, M = 1e5 + 10, mod = 1e9;
ll gcd(ll a, ll b) {  return b ?gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { ll t = gcd(a, b); return t ? (a / t * b) : 0; }
vector<int>prime;
bool prm[N];
void sieve() {
	for (int i = 4; i < N; i += 2)
		prm[i] = 1;
	prime.push_back(2);
	for(int i=3;i<N;i+=2)
		if (!prm[i]) {
			prime.push_back(i);
			for (int j = i + i; j < N; j += i)
				prm[j] = 1;
		}
}
bool check(ll a, int p, int cnt) {
	for (int i = p; i <= a; i += p) {
		int x = i;
		while (x % p == 0)x /= p, cnt--;
		if (cnt <= 0)return 1;
	}
	return 0;
}
int main() {
	fast_in_out();
	//	cout << fixed << setprecision(6);
	ll k;
	while (cin >> k) {
		int n = k;
		k *= k;
		vector<pair<int, int>>v;
		for (int i = 1; i * i <= k; i++) {
			if (k % i == 0) {
				v.emplace_back(k / i+n, i+n);
			}
		}
		cout << v.size() << endl;
		for (auto e : v) {
			cout << "1/"<<n<<" = 1/"<<e.first<<" + 1/"<<e.second<<"\n";
		}
	}
	return 0;
}