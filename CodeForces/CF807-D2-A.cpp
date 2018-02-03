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
	int n,mx,ans=0;// 1 rated 0 maybe -1 unrated
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x, y; cin >> x >> y;
		if (x < y||x>y) { ans = 1; break; }
		if (!i) { mx = y; continue; }
		if (y > mx) { ans = -1; }
		mx = y;
	}
	if (ans == 1)cout << "rated\n";
	else if (!ans)cout << "maybe\n";
	else cout << "unrated\n";


	system("pause");
		return 0;
}