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
	int n; cin >> n;
	ll ar1[51], ar2[5], ans[5]{ 0 };
	ll sum = 0;
	for (int i = 0; i < n; i++)
		cin >> ar1[i];
	for (int i = 0; i < 5; i++)
		cin >> ar2[i];
	for (int i = 0; i < n; i++)
	{
		sum += ar1[i];
		for (int j = 4; j > -1; j--)
			if (sum >= ar2[j]) { ll c = sum / ar2[j]; ans[j] += c; sum -= c * ar2[j]; }
	}
	for (int i = 0; i < 4; i++)
		cout << ans[i] << " "; cout << ans[4] << endl;
	cout << sum << endl;
	//system("pause");
		return 0;
}