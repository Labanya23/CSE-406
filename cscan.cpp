#include <bits/stdc++.h>
using namespace std;
int cscan(vector<int> requests, int head) {
    sort(requests.begin(), requests.end());
    int scount = 0;
    vector<int> left, right;

    for (int i = 0; i < requests.size(); i++) {
        if (requests[i] < head)
            left.push_back(requests[i]);
        else
            right.push_back(requests[i]);
    }
    for (int i = 0; i < right.size(); i++) {
        scount += abs(head - right[i]);
        head = right[i];
    }
    if (!left.empty()) {
        scount += abs(head - 0);
        head = 0;
        for (int i = 0; i < left.size(); i++) {
            scount += abs(head - left[i]);
            head = left[i];
        }
    }

    return scount;
}

int main() {
    vector<int> requests = {0, 14, 41, 53, 65, 67, 98, 122, 124, 183, 199};
    int head = 53;

    int total = cscan(requests, head);
    cout << total << endl;

    return 0;
}

