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
}
void dele() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
int dx[] = { 0,0,-1,1,-1,1,-1,1,0 };
int dy[] = { -1,1,0,0,-1,-1,1,1,0 };
const ld eps = 1e-6;
const int mod = 1e9 + 7;
const int N = 1e4 + 200, M = 318;
int n, m;
int dp[12][120];
int path[12][120];
int ar[12][102];
//int solve(int x, int y) {
//	if (y == m)
//		return 0;
//	int &ret = dp[x][y];
//	if (~ret)
//		return ret;
//	return ret = ar[get(x)][y] + min({solve(x + 1,y + 1),solve(x,y + 1),solve(x - 1,y + 1)});
//}
//vector<int>ans;
//void build(int x, int y) {
//	if (y == m)
//		return;
//	ans.push_back(get(x));
//	int op1 = solve(x + 1, y + 1);
//	int op2 = solve(x, y + 1);
//	int op3 = solve(x - 1, y + 1);
//	int ar[]{ op1,op2,op3 };
//	sort(ar , ar + 3);
//	if (ar[0] != ar[1]) {
//		build(x + 1, y + 1);
//	}
//	else if (ar[0] == ar[1] && ar[0] != ar[2]) {
//		if()
//	}
//}
int main() {
	fast_in_out();
	dele();
	//cout << fixed << setprecision(6);
	// kolo ray7 , ya 5raby
	while (cin >> n >> m) {
		memset(dp, 63, sizeof dp);
	//	cout << n << " " << m << endl;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				cin >> ar[i][j];
				if (j == m - 1)
					dp[i][j] = ar[i][j];
			}/*
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)
				cout << ar[i][j] << " "; cout << endl;
		}*/
		for (int j = m - 2; j > -1; j--) {
			for (int i = 0; i < n; i++) {
				//cout << i << " " << j << " ";
				for (int k = -1; k < 2; k++) {
					int ii = i + k;
					if (ii < 0)ii += n;
					if (ii >= n)ii -= n;
					if (dp[i][j] > dp[ii][j+1] + ar[i][j])
						dp[i][j] = dp[ii][j+1] + ar[i][j], path[i][j] = ii;
					if (dp[i][j] == (dp[ii][j+1] + ar[i][j]) && ii < path[i][j])
						path[i][j] = ii;
				}
				//cout << i << " " << j << endl;
				//		cout << dp[i][j] << " ";
			}//cout << endl;
		}
		// 3+1+3+3+6+1
		int mn = 1e9, idx = 0;
		for (int i = 0; i < n; i++)
		{
			if (mn > dp[i][0]) {
				mn = dp[i][0];
				idx = i;
			}
		}
	//	cout << ar[idx][0];
		cout << idx + 1;
		for (int i = 1; i < m; i++) {
			idx = path[idx][i-1];
			cout << " " << idx + 1;
		}cout << endl << mn << endl;
		// 3+1+3+3+6+6
	}
	return 0;
}
/*
*   * *** *** *** * *
*   * **    * * * * *
*   * *** *** *** ***
*   * *   *   * *   *
*   * *** *** ***   *
*/
/*
1 2 3 4 5 1
16
35
1 2 3 4 4 5
11
24
1 2
19
18

*/