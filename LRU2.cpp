#include<bits/stdc++.h>
using namespace std;

// Function to find page faults and hits using indexes
int pageFaultsAndHits(int pages[], int n, int capacity)
{
    unordered_set<int> s; // To represent the set of current pages
    unordered_map<int, int> indexes; // To store the recently used index of pages
    int page_faults = 0;
    int hits = 0;

    for (int i = 0; i < n; i++)
    {
        // Check if the set can hold more pages
        if (s.size() < capacity)
        {
            // Insert it into the set if not present, which represents page fault
            if (s.find(pages[i]) == s.end())
            {
                s.insert(pages[i]);
                page_faults++; // Increment page fault
            }
            else
            {
                hits++; // Increment hits if page is already in the set
            }

            // Store the recently used index of each page
            indexes[pages[i]] = i;
        }
        else
        {
            // If the set is full, we need to perform LRU (remove the least recently used page)
            if (s.find(pages[i]) == s.end())
            {
                // Find the least recently used page
                int lru = INT_MAX, val;
                for (auto it = s.begin(); it != s.end(); it++)
                {
                    if (indexes[*it] < lru)
                    {
                        lru = indexes[*it];
                        val = *it;
                    }
                }

                // Remove the least recently used page
                s.erase(val);

                // Insert the current page
                s.insert(pages[i]);
                page_faults++; // Increment page fault
            }
            else
            {
                hits++; // Increment hits if the page is already in the cache
            }

            // Update the current page's index
            indexes[pages[i]] = i;
        }
    }

    // Print the results
    cout << "Total Page Faults: " << page_faults << endl;
    cout << "Total Hits: " << hits << endl;

    return page_faults;
}

// Driver code
int main()
{
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1};
    int n = sizeof(pages) / sizeof(pages[0]);
    int capacity = 4;
    pageFaultsAndHits(pages, n, capacity);
    return 0;
}

