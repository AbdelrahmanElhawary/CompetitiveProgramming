/*
for:
Hussien , Ayman , Emad
Abanob , George , Genawy
Ka8eem , Mosta7il , Stawro
 
 ICPC DREAM
 */
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include<bits/stdc++.h>
#include<unordered_map>
#define ll long long
#define ld long double
#define ull unsigned ll 
#define endl '\n'
#define mk make_pair
const double PI = acos(-1.0);
using namespace std;
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
const ld eps = 1e-9;
const int mod = 1e9 + 7;
const int N = 1e7+1;
int vis[N];
void sieve() {
	vis[0] = vis[1] = 1;
	for (int i = 4; i < N; i+=2)
		vis[i] = 2;
	for (int i = 3; i < N; i += 2) {
		if (!vis[i]) {
			for (ll j = 1LL * i*i; j < N; j += i)
				vis[j] = i;
		}
	}
}
ll gcd(ll a, ll b)
{
	if (!b)return a;
	return gcd(b, a%b);
}
int main() {
	fast_in_out();
	//cout << fixed << setprecision(0);
	sieve();
	int t;
	cin >> t;
	while (t--) {
		string str1, str2;
		cin >> str1>> str2;
		int n1 = 0, n2 = 0;
		for (int i = 0; i < str1.size(); i++) {
			if (str1[i] == '.')continue;
			n1 *= 10;
			n1 += (str1[i] - '0');
		}
		for (int i = 0; i < str2.size(); i++) {
			if (str2[i] == '.')continue;
			n2 *= 10;
			n2 += (str2[i] - '0');
		}
		bool eq = (n1 == n2);
		if (eq) {
			cout << 2 << " " << 2 << endl;
			continue;
		}
		int g = gcd(n1, n2);
		n1 /= g; n2 /= g;
	//	cout << vis[n1] << " " << vis[n2] << endl;
		if (!vis[n1] && !vis[n2])
			cout << n1 << " " << n2 << endl;
		else cout << "impossible\n";
	}
	return 0;
}