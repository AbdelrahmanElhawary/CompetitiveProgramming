#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include<bits/stdc++.h>
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
	int a, b; cin >> a >> b;
	for (int i = a+1;; i++)
	{
		bool f = 0;
		for (int j = 2; j*j <= i; j++)
		{
			if (i%j == 0) f = 1;
		}
		if (!f) { if (i == b)cout << "YES\n"; else cout << "NO\n"; break; }
	}

//	system("pause");
	return 0;
}
