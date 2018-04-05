#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include<iostream>
#include<map>
#include<cmath>
#include<algorithm>
#include<string>
#include<set>
#include<sstream>
#include<vector>
#include<string.h>
#include<queue>
#include<list>
#include<iterator>
#include<functional> 
#include<iomanip>
#include<bitset>
#include<stack>
#define F first
#define S second
#define ll long long
#define ld long double
#define ull unsigned ll 
#define dong long
#define endl '\n'
#define mk make_pair
using namespace std;
void fast_in_out() {
	std::ios_base::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);
}
int n, m,ans;
bool arr[100][100];
void solve(int x, int y)
{
	if (arr[x][y])return;
	if (x == n - 1 && y == m - 1) { ans++; return; }
	if (x < n - 1)solve(x + 1, y);
	if (y < m - 1)solve(x, y + 1);
}
vector<int>v;
int main() {
	fast_in_out();
	//cout << fixed << setprecision(4);
	int t; cin >> t;
	while (t--)
	{
		cin >> n >> m;
		for (int i = 0; i < n; i++)
		{
			cin.ignore();
			string s;
			getline(cin, s);
			bool f = 0, f2 = 0; int num = 0;
			for (int j = 0; j < s.size(); j++)
			{
				if (isdigit(s[j])) { num *= 10; num += s[j] - '0'; if (f2)f = 1; continue; }
				else if (!f2) { num = 0; f2 = 1; continue; }
				else { arr[i][num - 1] = 1; num = 0; continue; }
			}
			if (f)arr[i][num - 1] = 1;
		}
		solve(0, 0);
		v.push_back(ans);
		ans = 0;
		memset(arr, 0, sizeof arr);
	}
	for (int i = 0; i < v.size(); i++)
	{
		if (i)cout << '\n';
		cout << v[i] << endl;
	}
	//system("pause");
	return 0;
}