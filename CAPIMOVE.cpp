#include <iostream>
#include <set>
#include <vector>
#include <map>
using namespace std;
int main() {
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    set<int> s;
    int T, n;
    int tm, u, v;
    cin >> T;
    while (T--) {
        cin >> n;
        int P[n+1];
        vector<int> na;
        vector<int> *adj = new vector<int>[n+1];
        set<int> st;

        map<int, int> mp;
        for (int t=1;t<=n;++t) {
            cin >> P[t];
            mp[P[t]] = t;
            st.insert(P[t]);
        }

        int u, v;
        for (int t=0;t<n-1;++t) {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for (int t=1;t<=n;++t) {
            st.erase(P[t]);
            for (auto el: adj[t]) {
                st.erase(el);
            }

            if (!st.empty())
                na.push_back(*st.rbegin());

            st.insert(P[t]);
            for (auto el: adj[t])
                st.insert(el);
        }

        for (int t=0;t<n;++t) cout << na[t] << " ";
    }

    // cout << "Time Taken: " << (double)(clock() - tStart)/CLOCKS_PER_SEC << endl;
}
