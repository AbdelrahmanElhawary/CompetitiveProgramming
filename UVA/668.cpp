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
using namespace std;
#define ll long long
#define ld long double
#define ull unsigned ll 
#define endl '\n'
#define mk make_pair
const double PI = acos(-1.0);
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
const int N = 1e3 + 10, M = 1e4 + 5, mod = 10056;
int main() {
	fast_in_out();
	//	cout << fixed << setprecision(2);
	//kolo ray7 , ya 5raby
	int t; cin >> t;
	bool f = 0;
	while (t--) {
		if (f)cout << endl;
		f = 1;
		int n; cin >> n;
		int sum = 0;
		vector<int>v;
		for (int i = 2;; i++) {
			if (sum + i > n)break;
			v.push_back(i);
			sum += i;
		}
		int lft = n - sum;
		while (lft > 0) {
			for (int i = v.size() - 1; i > -1; --i)
			{
				if (lft == 0)break;
				v[i]++;
				lft--;
			}
		}
		for (int i = 0; i < v.size(); i++) {
			if (i)cout << " ";
			cout << v[i];
		}cout << endl;
	}

	return 0;
}