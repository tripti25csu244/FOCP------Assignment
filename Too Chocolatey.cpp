#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        sort(a.begin(), a.end(), greater<int>()); // descending

        int alex = 0, bob = 0;
        bool turn = true; // true = Alex, false = Bob

        for (int i = 0; i < n; i++) {
            // skip duplicates
            if (i > 0 && a[i] == a[i - 1]) continue;

            if (turn) alex += a[i];
            else bob += a[i];

            turn = !turn;
        }

        if (alex > bob)
            cout << "Alex\n";
        else
            cout << "Bob\n";
    }

    return 0;
}
