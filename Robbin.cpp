#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Process
{
    int pid;            // Process ID
    int bt;             // Burst Time
    int remaining_time; // Remaining Burst Time
};

void roundRobinScheduling(vector<Process> &processes, int time_quantum)
{
    int n = processes.size();
    queue<Process> ready_queue;

    int time = 0;
    int completed = 0;

    while (completed < n)
    {
        for (int i = 0; i < n; i++)
        {
            if (processes[i].remaining_time > 0 && processes[i].bt > time_quantum)
            {
                processes[i].remaining_time -= time_quantum;
                time += time_quantum;
                cout << "Process " << processes[i].pid << " executed for " << time_quantum << " units of time." << endl;
            }
            else if (processes[i].remaining_time > 0)
            {
                time += processes[i].remaining_time;
                processes[i].remaining_time = 0;
                completed++;
                cout << "Process " << processes[i].pid << " completed." << endl;
                cout << "Total time taken by Process " << processes[i].pid << " is " << time << " units." << endl;
            }
        }
    }
}

int main()
{
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    vector<Process> processes(n);

    for (int i = 0; i < n; i++)
    {
        processes[i].pid = i + 1;
        cout << "Enter burst time for Process " << processes[i].pid << ": ";
        cin >> processes[i].bt;
        processes[i].remaining_time = processes[i].bt;
    }

    int time_quantum;
    cout << "Enter the time quantum: ";
    cin >> time_quantum;

    roundRobinScheduling(processes, time_quantum);

    return 0;
}
