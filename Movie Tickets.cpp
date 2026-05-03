#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class MovieTicket {
    unordered_map<string, unordered_set<string>> movie;

public:
    bool book(string x, string y) {
        if (movie[y].count(x)) return false;
        if (movie[y].size() >= 100) return false;

        movie[y].insert(x);
        return true;
    }

    bool cancel(string x, string y) {
        if (!movie.count(y) || !movie[y].count(x))
            return false;

        movie[y].erase(x);
        return true;
    }

    bool is_booked(string x, string y) {
        return movie.count(y) && movie[y].count(x);
    }

    int available_tickets(string y) {
        if (!movie.count(y)) return 100;
        return 100 - movie[y].size();
    }
};

int main() {
    int Q;
    cin >> Q;
    MovieTicket mt;

    while (Q--) {
        string q;
        cin >> q;

        if (q == "BOOK") {
            string x, y;
            cin >> x >> y;
            cout << (mt.book(x, y) ? "true" : "false") << endl;
        }
        else if (q == "CANCEL") {
            string x, y;
            cin >> x >> y;
            cout << (mt.cancel(x, y) ? "true" : "false") << endl;
        }
        else if (q == "IS_BOOKED") {
            string x, y;
            cin >> x >> y;
            cout << (mt.is_booked(x, y) ? "true" : "false") << endl;
        }
        else if (q == "AVAILABLE_TICKETS") {
            string y;
            cin >> y;
            cout << mt.available_tickets(y) << endl;
        }
    }
}
