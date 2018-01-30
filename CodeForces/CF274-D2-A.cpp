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
vector<int>v;
int main() {
		fast_in_out();
	//	cout << fixed << setprecision(4);
		int ar[3], ans = 0;
		cin >> ar[0] >> ar[1] >> ar[2];
			ans = max(ans, ar[0] + ar[1] * ar[2]);
			ans = max(ans, ar[0] * (ar[1] + ar[2]));
			ans = max(ans, ar[0] * ar[1] * ar[2]);
			ans = max(ans, (ar[0] + ar[1])*ar[2]);
			ans = max(ans, ar[0] + ar[1] + ar[2]);
		
		cout << ans << endl;
	//	system("pause");
	return 0;
}