#include<bits/stdc++.h>
using namespace std;

int main()
{
    int sum = 0;
    int a[] = {82, 170, 43, 140, 24, 16, 190};
    int head = 50;
    int n = sizeof(a)/sizeof(a[0]);


    bool visited[n] = {false};

    for (int i = 0; i < n; i++) {
        int min_dist = INT_MAX;
        int index = -1;


        for (int j = 0; j < n; j++) {
            if (!visited[j]) {
                int dist = abs(a[j] - head);
                if (dist < min_dist) {
                    min_dist = dist;
                    index = j;
                }
            }
        }


        sum += min_dist;
        head = a[index];


        visited[index] = true;
    }

    cout << sum << endl;
    return 0;
}

