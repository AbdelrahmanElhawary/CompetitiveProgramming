#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include<iostream>
#include<map>
#include<cmath>
#include<algorithm>
#include<string>
#include<set>
#include<sstream>
#include<vector>
#include<string.h>
#include<queue>
#include<list>
#include<iterator>
#include<functional> 
#include<iomanip>
#include<bitset>
#include<stack>
#include <assert.h>
#include<complex>
#include<unordered_map>
#define ll long long
#define ld long double
#define ull unsigned ll 
#define endl '\n'
#define mk make_pair
const double PI = acos(-1.0);
#define point complex<double> // it can be long long not double
#define cp(a,b)   ( (conj(a)*(b)).imag() )	// a*b sin(T), if zero -> parllel cross product = area of parllelogram
using namespace std;
void fast_in_out() {
	std::ios_base::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);
}
void pause() {
#ifndef ONLINE_JUDGE
	system("pause");
#endif
}
int dx[] = { 0,0,-1,-1,-1,1,1,1 };
int dy[] = { -1,1,0,1,-1,-1,0,1 };
const int MAX = 3 * 1000 * 100 + 5;
pair<int, int> a[MAX];
int main() {
	fast_in_out();
	//cout << fixed << setprecision(6);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n;
	set<string>ss1, ss2, ss3;
	multiset<string>ss4;
	map<string, int>mp1, mp2, mp3, mp4;
	int cnt1 = 0, cnt2 = 0, cnt3 = 0;
	for (int i = 0; i < n; i++) {
		string s1, s2, s3, s4;
		cin >> s1 >> s2 >> s3 >> s4;
		//mp4[s4]++;
		if (s1 == s4)
		{
			mp1[s1] = 1;
			ss1.erase(s1);
		}
		else {
			if (mp1[s1] == 0)
				ss1.insert(s1);
		}
		if (s2 == s4)
		{
			mp2[s2] = 1;
			ss2.erase(s2);
		}
		else {
			if (mp2[s2] == 0)
				ss2.insert(s2);
		}
		if (s3 == s4)
		{
			mp3[s3] = 1;
			ss3.erase(s3);
		}
		else {
			if (mp3[s3] == 0)
				ss3.insert(s3);
		}
		
		cout << ss1.size() << " " << ss2.size() << " " << ss3.size() << endl;

	}

	pause();
	return 0;
}