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
		int n, ans = 0, cnt = 0, b, d; cin >> n >> b >> d;
		for (int i = 0; i < n; i++)
		{
			int x; cin >> x;
			if (x > b)continue;
			cnt += x;
			if (cnt > d)ans++, cnt = 0;
		}
		cout << ans << endl;
		//system("pause");
	return 0;
}