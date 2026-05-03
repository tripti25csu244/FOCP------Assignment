#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;   // IMPORTANT
        string s;
        cin >> s;

        int count = 0;
        int flip = 0;

        for (int i = 0; i < n; i++) {
            int bulb = s[i] - '0';

            // actual state after flips
            if ((bulb ^ flip) == 1) {
                count++;
                flip ^= 1;
            }
        }

        cout << count << endl;
    }

    return 0;
}
