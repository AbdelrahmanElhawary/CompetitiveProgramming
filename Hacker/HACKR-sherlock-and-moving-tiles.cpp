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
		cout << fixed << setprecision(4);
	//	int t,tt=1; cin >> t;
		//while (t--) {
			double n, v1, v2; cin >> n >> v1 >> v2;
			int q; cin >> q;
			for (int i = 0; i < q; i++)
			{
				double x; cin >> x;
				x = sqrt(x);
				cout << sqrt(2*pow((n - x),2)) / abs(v1- v2) << endl;
			}
			
//		}
		//system("pause");
	return 0;
}