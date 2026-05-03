#include <iostream>
#include <unordered_map>
using namespace std;

class Bank {
    unordered_map<string, int> acc;

public:
    bool create(string x, int y) {
        if (acc.count(x)) {
            acc[x] += y;
            return false;
        }
        acc[x] = y;
        return true;
    }

    bool debit(string x, int y) {
        if (!acc.count(x) || acc[x] < y)
            return false;

        acc[x] -= y;
        return true;
    }

    bool credit(string x, int y) {
        if (!acc.count(x))
            return false;

        acc[x] += y;
        return true;
    }

    int balance(string x) {
        if (!acc.count(x)) return -1;
        return acc[x];
    }
};

int main() {
    int Q;
    cin >> Q;
    Bank bank;

    while (Q--) {
        string q;
        cin >> q;

        if (q == "CREATE") {
            string x;
            int y;
            cin >> x >> y;
            cout << (bank.create(x, y) ? "true" : "false") << endl;
        }
        else if (q == "DEBIT") {
            string x;
            int y;
            cin >> x >> y;
            cout << (bank.debit(x, y) ? "true" : "false") << endl;
        }
        else if (q == "CREDIT") {
            string x;
            int y;
            cin >> x >> y;
            cout << (bank.credit(x, y) ? "true" : "false") << endl;
        }
        else if (q == "BALANCE") {
            string x;
            cin >> x;
            cout << bank.balance(x) << endl;
        }
    }
}
