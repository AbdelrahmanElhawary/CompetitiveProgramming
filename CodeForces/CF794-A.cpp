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
#define F first
#define S second
#define ll long long
using namespace std;
int main()
{
	int a, b, c; cin >> a >> b >> c;
	int n, ans = 0;; cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x; cin >> x;
		if (x > b&&x < c)ans++;
	}cout << ans << endl;
	
//	system("pause");
	return 0;
}
