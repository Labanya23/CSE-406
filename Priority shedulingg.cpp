#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Process {
    int id, priority, arrival, burst, remaining, ct, tat, wt;
};

bool compare(Process a, Process b) {
    if (a.arrival == b.arrival)
        return a.priority > b.priority; // Higher priority first
    return a.arrival < b.arrival;
}

void prioritySchedulingPreemptive(vector<Process>& proc) {
    int n = proc.size();
    int currentTime = 0, completed = 0;
    int minPriorityIndex;

    while (completed < n) {
        minPriorityIndex = -1;
        for (int i = 0; i < n; i++) {
            if (proc[i].arrival <= currentTime && proc[i].remaining > 0) {
                if (minPriorityIndex == -1 || proc[i].priority > proc[minPriorityIndex].priority)
                    minPriorityIndex = i;
            }
        }

        if (minPriorityIndex == -1) {
            currentTime++;
            continue;
        }

        proc[minPriorityIndex].remaining--;
        currentTime++;

        if (proc[minPriorityIndex].remaining == 0) {
            proc[minPriorityIndex].ct = currentTime;
            proc[minPriorityIndex].tat = proc[minPriorityIndex].ct - proc[minPriorityIndex].arrival;
            proc[minPriorityIndex].wt = proc[minPriorityIndex].tat - proc[minPriorityIndex].burst;
            completed++;
        }
    }
}

void printProcesses(vector<Process>& proc) {
    cout << "Process\tPriority\tArrival\tBurst\tCT\tTAT\tWT\n";
    for (auto& p : proc) {
        cout << p.id << "\t" << p.priority << "\t\t" << p.arrival << "\t" << p.burst
             << "\t" << p.ct << "\t" << p.tat << "\t" << p.wt << "\n";
    }
}

int main() {
    vector<Process> proc = {{1, 10, 0, 5, 5, 0, 0, 0}, {2, 20, 1, 4, 4, 0, 0, 0}, {3, 30, 2, 2, 2, 0, 0, 0}, {4, 40, 4, 1, 1, 0, 0, 0}};

    prioritySchedulingPreemptive(proc);
    printProcesses(proc);

    return 0;
}
