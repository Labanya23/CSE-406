#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

int main() {
    int input[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1};
    int capacity = 4;
    int n = sizeof(input) / sizeof(input[0]);

    list<int> cache;
    unordered_map<int, list<int>::iterator> map;
    int hits = 0, misses = 0;

    for (int i = 1; i < n; ++i) {
        int page = input[i];

        if (map.find(page) == map.end()) {
            // MISS
            misses++;
            cout << page << " -> Miss" << endl;
            if (cache.size() == capacity) {
                int lru = cache.back();
                cache.pop_back();
                map.erase(lru);
            }
        } else {
            // HIT
            hits++;
            cout << page << " -> Hit" << endl;
            cache.erase(map[page]);
        }

        // Add/move page to front
        cache.push_front(page);
        map[page] = cache.begin();
    }

    cout << "\nTotal Hits: " << hits << endl;
    cout << "Total Misses: " << misses << endl;

    return 0;
}
