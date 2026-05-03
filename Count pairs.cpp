#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        // total pairs
        long long total = 1LL * n * (n - 1) / 2;

        // group by MSB
        map<int, int> mp;

        for (int x : a) {
            int msb = 31 - __builtin_clz(x); // highest bit
            mp[msb]++;
        }

        long long bad = 0;

        for (auto it : mp) {
            long long cnt = it.second;
            bad += cnt * (cnt - 1) / 2;
        }

        cout << total - bad << "\n";
    }

    return 0;
}
