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
#define F first
#define S second
#define ll long long
using namespace std;
void fast_in_out() {
	std::ios_base::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);
}
int main() {
	fast_in_out();
	//cout << fixed << setprecision(0);
	int n, t, m, d; cin >> n >> t >> m >> d;
	int ans1 = 0, ans2 = 0,ans; bool f = 0;
	for (int i = 1,j=0;; i++)
	{
		if (f)j++;
		if (i%t == 0) { ans1 += m; ans2 += m; }
		if (f&&j%t == 0)ans2 += m;
		if (i >= d) f = 1;
	//	cout << ans1 << " " << ans2 << endl;
		if (ans1 >= n) { ans = 1; break; }
		if (ans2 >= n) { ans = 2; break; }
	}
	if (ans == 1)cout << "NO\n"; else cout << "YES\n";
	//system("pause");
		return 0;
}