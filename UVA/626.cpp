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
#define holla(x) cout << #x << " is " << x << endl;
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
int lx[] = { 2, 2, -1, 1, -2, -2, -1, 1 };
int ly[] = { -1, 1, 2, 2, 1, -1, -2, -2 };
const int N = 2e5 + 300, M = 100 + 5, mod = 1e9+7;
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
bool grid[M][M];
int main() {
	fast_in_out();
	//cout << fixed << setprecision(9);
	//kolo ray7 , ya 5raby
	int n; 
	while (cin>>n)
	{
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				cin >> grid[i][j];
		vector < pair<int, pair<int, int>>>ans;
		for (int i = 1; i <= n; i++)
			for (int j = i + 1; j <= n; ++j)
				for (int k = j + 1; k <= n; ++k)
					if (grid[i][j] && grid[j][k] && grid[k][i])
						ans.push_back({ i,{j,k} });

		for (int i = n; i; --i)
			for (int j = i - 1; j; --j)
				for (int k = j - 1; k; --k)
					if (grid[i][j] && grid[j][k] && grid[k][i])
						ans.push_back({ i,{ j,k } }); 
		sort(ans.begin(), ans.end());
		for (auto e : ans)
			cout << e.first << " " << e.second.first << " " << e.second.second << endl;
		cout << "total:"<<ans.size()<<"\n\n";

	}
	return 0;
}