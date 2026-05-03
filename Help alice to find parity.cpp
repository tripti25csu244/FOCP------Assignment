#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int parity = 0;

        while (n > 0) {
            parity ^= (n & 1);  // take last bit
            n >>= 1;            // shift right
        }

        if (parity == 0)
            cout << "EVEN\n";
        else
            cout << "ODD\n";
    }

    return 0;
}
