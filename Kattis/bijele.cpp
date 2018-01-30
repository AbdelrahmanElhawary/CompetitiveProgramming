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
    //  cout << fixed << setprecision(4);
        int n, arr[]{1,1,2,2,2,8};
        for (int i = 0; i < 6; i++)
        {
            cin >> n;
            cout << arr[i] - n << " ";
        }
        //system("pause");
    return 0;
}