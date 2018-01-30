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
		int t; cin >> t;
		while (t--)
		{
			ll a, b; cin >> a >> b;
			if (a < b)cout << "<\n";
			else if (a > b)cout << ">\n";
			else cout << "=\n";
		}
	//	system("pause");
	return 0;
}