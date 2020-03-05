/*
 * Problem Link: https://www.codechef.com/JULY17/problems/IPCTRAIN
 */
#include <iostream>
#include <map>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <float.h>
#include <limits.h>
#include <stack>
#include <queue>
#include <time.h>
#include "unordered_map"
using namespace std;
#define MAX INT_MAX
#define MIN INT_MIN
#define INF 1e9
#define FASTER cin.sync_with_stdio(false);cin.tie(NULL);
#define pb push_back
#define ll long long int
typedef vector<ll> vi;
typedef pair<ll,int> pi;

int main() {
    FASTER;
    // clock_t tStart = clock();
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    priority_queue<pair<ll, int> > hp;
    ll T, n, d;
    cin >> T;
    for (ll n1=0;n1<T;++n1) {
        while (!hp.empty()) {
            hp.pop();
        }
        cin >> n >> d;
        ll arv[n+1], dur[n+1], cost[n+1];
        ll sm = 0;
        for (ll t=1;t<=n;++t) {
            cin >> arv[t] >> dur[t] >> cost[t];
            sm += dur[t] * cost[t];
        }


        for (ll smm=1;smm<=d;++smm) {
            for (ll t=1;t<=n;++t) {
                if (arv[t] <= smm && dur[t] > 0)
                    hp.push(make_pair(cost[t], t));
            }

            if (hp.size() == 0) continue;
            auto pr = hp.top();
            hp.pop();

            sm -= pr.first;
            --dur[pr.second];
        }
        cout << sm << '\n';
    }
}
