#include<bits/stdc++.h>
using namespace std;

int fifopagereplacement(int pages[], int n, int capacity, int &hits) {
    queue<int> q;
    unordered_set<int> s;
    int page_faults = 0;

    for (int i = 0; i < n; i++) {

        if (s.find(pages[i]) == s.end()) {
            page_faults++;


            if (q.size() == capacity) {
                s.erase(q.front());
                q.pop();
            }


            q.push(pages[i]);
            s.insert(pages[i]);
        } else {
            hits++;
        }
    }

    return page_faults;
}

int main() {
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3,  1, 2, 0};
    int n = sizeof(pages) / sizeof(pages[0]);
    int capacity = 3;
    int hits = 0;

    int page_faults = fifopagereplacement(pages, n, capacity, hits);


    cout << "Total Page Faults: " << page_faults << endl;
    cout << "Total Hits: " << hits << endl;

    return 0;
}

