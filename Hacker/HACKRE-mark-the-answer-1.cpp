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
		int n, x, ans = 0; bool f1 = 0;
		cin >> n >> x;
		for (int i = 0; i < n; i++)
		{
			int y; cin >> y;
			if (y > x&&f1)break;
			else if (y > x && !f1)f1 = 1;
			else ans++;
		}
		//ans = max(max(c1, c2), ans);
		cout << ans << endl;
	//	system("pause");
	return 0;
}