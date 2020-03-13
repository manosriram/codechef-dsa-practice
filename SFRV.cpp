#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <math.h>
#include "unordered_map"
#define F first
#define S second
#define ll long long int
#define pb push_back
#define debug(i) cout << "hi " << i << '\n';
#define FASTER cin.sync_with_stdio(false);cin.tie(NULL);
using namespace std;
int n;

void printA(int *a, int in, int sum) {
    for (int t=1;t<=n;++t) cout << a[t] << " "; 

    cout << in << " " << sum << endl;
}

int Solve(int *a, int in, bool *select, int sum) {
    printA(a, in, sum);
    if (in > n)
        return sum;

    if (select[in] || select[in+1])
        return Solve(a, in+1, select, sum);

    int lf = Solve(a, in + 1, select, sum);
    swap(a[in], a[in+1]);
    select[in] = select[in+1] = true;

    int rg = Solve(a, in + 1, select, (sum - ((a[in] * in) + (a[in+1] * (in+1))) + ((a[in] * (in+1)) + (a[in+1] * in))));

    swap(a[in], a[in+1]);
    select[in] = select[in+1] = false;

    return max(lf, rg);
}

int main() {
    FASTER;
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        int a[n+1], sum = 0;
        bool select[n+1];
        for (int t=1;t<=n;++t) {
            cin >> a[t];
            sum += a[t] * t;
            select[t] = false;
        }
        cout << Solve(a, 1, select, sum) << endl;
        cout << endl;
    }
}
