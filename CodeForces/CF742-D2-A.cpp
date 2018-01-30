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
		//cout << fixed << setprecision(0);
		int n; cin >> n;
		if (n % 4 == 0)cout << 6 << endl;
		else if (n % 4 == 1)cout << 8 << endl;
		else if (n % 4 == 2)cout << 4 << endl;
		else if (n % 4 == 3)cout << 2 << endl;
	//	system("pause");
	return 0;
}