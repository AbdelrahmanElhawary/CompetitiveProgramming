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
const int N = 1e3 + 100;
int main() {
	fast_in_out();
	//cout << fixed << setprecision(0);
	int n;
	cin >> n;
	map<int, int>mp;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x == 1 && mp.find(1) != mp.end()) {
			cout << mp[1] << " " << i + 1 << endl;
			return 0;
		}
		mp[x]=i+1;
	}
	int f = 1, s = 1;
	bool ok = 0;
	while (s <= 1e6) {
		s += f;
		f = s - f;
		if(mp.find(s)!=mp.end()&&mp.find(f)!=mp.end())
		{
			ok = 1;
			cout << mp[f] << " " << mp[s] << endl;
			break;
		}
	}
	if (!ok)
		cout << "impossible\n";
	return 0;
}