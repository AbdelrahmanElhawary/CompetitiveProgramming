#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
#include<iomanip>
#include<vector>
#include <utility>
#include<set>
#include<string.h>
#include <deque>
#define ll long long
using namespace std;
void fast_in_out() {
	std::ios_base::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);
}
int main() {
		fast_in_out();
	//	cout << fixed << setprecision(4);
		int n; cin >> n; int x = 0, y = 0, z = 0;
		for (int i = 0; i < n; i++)
		{
			int a, b, c; cin >> a >> b >> c;
			x += a; y += b; z += c;
		}
		if (!x && !y && !z)cout << "YES\n"; else cout << "NO\n";
	//	system("pause");
	return 0;
}