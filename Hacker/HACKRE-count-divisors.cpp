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
		ll a, b, c; cin >> a >> b >> c;
		if (b < a)swap(a, b);
		if (a%c != 0) { a /= c; a++; }
		else a /= c;
		b /= c;
		cout << b - a + 1 << endl;
	//	system("pause");
	return 0;
}