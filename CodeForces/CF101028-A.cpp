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
using namespace std;
int main()
{
	int t; cin >> t;
	while (t--) {
		int n, m, k = 0; cin >> n >> m; m -= 1500;
		for (int i = 0; i < n; i++)
		{
			int x; cin >> x;
			k += x;
		}
		if (k == m)cout << "Correct\n"; else cout << "Bug\n";
	}
	//system("pause");
	return 0;
}