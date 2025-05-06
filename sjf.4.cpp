#include <bits/stdc++.h>
using namespace std;

struct Process {
    int id;
    int arrival;
    int burst;
    int remaining;
    int finish_time;
    int waiting_time;
    int turnaround_time;
};


bool compareArrival(Process &a, Process &b) {
    return a.arrival < b.arrival;
}

void preemptiveSJF(vector<Process>& processes) {
    int n = processes.size();
    vector<bool> completed(n, false);
    int currentTime = 0;
    int completedProcesses = 0;

    while (completedProcesses < n) {
        int minRemaining = INT_MAX;
        int idx = -1;


        for (int i = 0; i < n; i++) {
            if (processes[i].arrival <= currentTime && !completed[i] && processes[i].remaining < minRemaining) {
                minRemaining = processes[i].remaining;
                idx = i;
            }
        }

        if (idx != -1) {

            currentTime++;
            processes[idx].remaining--;


            if (processes[idx].remaining == 0) {
                processes[idx].finish_time = currentTime;
                processes[idx].waiting_time = processes[idx].finish_time - processes[idx].arrival - processes[idx].burst;
                processes[idx].turnaround_time = processes[idx].waiting_time + processes[idx].burst;
                completed[idx] = true;
                completedProcesses++;
            }
        }
        else {

            currentTime++;
        }
    }

    // Print results
    int totalWaitingTime = 0, totalTurnaroundTime = 0;
    cout << "Process ID\tArrival Time\tBurst Time\tCompletion Time\tWaiting Time\tTurnaround Time\n";
    for (int i = 0; i < n; i++) {
        cout << processes[i].id << "\t\t"
             << processes[i].arrival << "\t\t"
             << processes[i].burst << "\t\t"
             << processes[i].finish_time << "\t\t"
             << processes[i].waiting_time << "\t\t"
             << processes[i].turnaround_time << endl;
        totalWaitingTime += processes[i].waiting_time;
        totalTurnaroundTime += processes[i].turnaround_time;
    }

    cout << "\nAverage Waiting Time: " << (float)totalWaitingTime / n << endl;
    cout << "Average Turnaround Time: " << (float)totalTurnaroundTime / n << endl;
}

int main() {
    int n = 4;
    vector<Process> processes(n);


    int arrivalTimes[] = {0, 1, 2, 4};
    int burstTimes[] = {5, 3, 4, 1};


    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        processes[i].arrival = arrivalTimes[i];
        processes[i].burst = burstTimes[i];
        processes[i].remaining = processes[i].burst;
    }

    sort(processes.begin(), processes.end(), compareArrival);

    preemptiveSJF(processes);

    return 0;
}

