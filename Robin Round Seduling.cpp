#include <iostream>
#include <queue>
using namespace std;

struct Process {
    int no, arrival, burst, remaining, completion, turnAround, waiting, response;
};

void roundRobin(Process proc[], int n, int quantum) {
    queue<int> q;
    int time = 0, completed = 0;
    bool inQueue[n] = {false};
    bool firstResponse[n] = {false};

    q.push(0);
    inQueue[0] = true;

    while (completed < n) {
        int i = q.front();
        q.pop();

        if (!firstResponse[i]) {
            proc[i].response = time - proc[i].arrival;
            firstResponse[i] = true;
        }

        if (proc[i].remaining > quantum) {
            time += quantum;
            proc[i].remaining -= quantum;
        } else {
            time += proc[i].remaining;
            proc[i].remaining = 0;
            proc[i].completion = time;
            proc[i].turnAround = proc[i].completion - proc[i].arrival;
            proc[i].waiting = proc[i].turnAround - proc[i].burst;
            completed++;
        }

        for (int j = 0; j < n; j++) {
            if (proc[j].arrival <= time && proc[j].remaining > 0 && !inQueue[j]) {
                q.push(j);
                inQueue[j] = true;
            }
        }

        if (proc[i].remaining > 0) {
            q.push(i);
        }
    }
}

void printProcesses(Process proc[], int n) {
    cout << "No\tArrival Time\tBurst Time\tCompletion Time\tTurn Around Time\tWaiting Time\tResponse Time\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << proc[i].no << "\t"
             << proc[i].arrival << "\t\t"
             << proc[i].burst << "\t\t"
             << proc[i].completion << "\t\t"
             << proc[i].turnAround << "\t\t"
             << proc[i].waiting << "\t\t"
             << proc[i].response << "\n";
    }
}

int main() {
    Process proc[] = {{1, 0, 5, 5, 0, 0, 0, 0},
                      {2, 1, 4, 4, 0, 0, 0, 0},
                      {3, 2, 2, 2, 0, 0, 0, 0},
                      {4, 4, 1, 1, 0, 0, 0, 0}};
    int n = sizeof(proc) / sizeof(proc[0]);
    int quantum = 2;

    roundRobin(proc, n, quantum);
    printProcesses(proc, n);
    return 0;
}

