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
#include<map>
#define ll long long
using namespace std;
void fast_in_out() {
	std::ios_base::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);
}
bool ch[1005];
map<string, string>mp;
int main() {
		fast_in_out();
	//	cout << fixed << setprecision(4);
		int s = 0, e = 1; ch[0] = 1; ch[1] = 1;
		for (int i = 0; i <= 1002; i++)
		{
			if (s + e >= 1003)break;
			ch[s + e] = 1;
			e += s;
			s = e - s;
		}
		int n; cin >> n;
		for (int i = 1; i <= n; i++)
			if (ch[i])cout << 'O';
			else cout << 'o';
			cout << endl;
		/*int n, m;
		cin >> n >> m;
		for (int i = 0; i < n; i++)
		{
			string s1, s2; cin >> s1 >> s2;
			mp[s2] = s1;
		}
		for (int i = 0; i < m; i++)
		{
			string s1, s2;
			cin >> s1 >> s2;
			s2.erase(s2.size()-1);
			//cout << mp[s2] << endl;
			cout << s1 << " " << s2 << "; #" << mp[s2] << endl;
		}*/
		//system("pause");
	return 0;
}