#include<bits/stdc++.h>
using namespace std;

int fifopagereplacement(int pages[], int n, int capacity, int &hits) {
    queue<int> q; // Queue to keep track of pages in FIFO order
    unordered_set<int> s; // Set to keep track of pages in the cache
    int page_faults = 0;

    for (int i = 0; i < n; i++) {
        // If the page is not found in the cache (set)
        if (s.find(pages[i]) == s.end()) {
            page_faults++; // A page fault occurred

            // If the cache is full, remove the oldest page (FIFO)
            if (q.size() == capacity) {
                s.erase(q.front()); // Remove the page from the set
                q.pop(); // Remove the page from the queue
            }

            // Insert the new page into the queue and set
            q.push(pages[i]);
            s.insert(pages[i]);
        } else {
            hits++; // A hit occurred when the page is already in the cache
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

    // Output the results
    cout << "Total Page Faults: " << page_faults << endl;
    cout << "Total Hits: " << hits << endl;

    return 0;
}

