#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Process
{
    int pid; // Process ID
    int bt;  // Burst Time
    int at;  // Arrival Time
};

bool comparison(Process a, Process b)
{
    return a.at < b.at; // Sort by arrival time
}

void findWaitingTime(vector<Process> &processes, vector<int> &wt)
{
    int n = processes.size();
    vector<int> remaining_time(n);

    for (int i = 0; i < n; i++)
    {
        remaining_time[i] = processes[i].bt;
    }

    int complete = 0, t = 0, min_bt = INT_MAX;
    int shortest = 0, finish_time;

    while (complete < n)
    {
        for (int j = 0; j < n; j++)
        {
            if ((processes[j].at <= t) && (remaining_time[j] < min_bt) && (remaining_time[j] > 0))
            {
                min_bt = remaining_time[j];
                shortest = j;
            }
        }

        remaining_time[shortest] = 0;
        min_bt = INT_MAX;

        if (remaining_time[shortest] == 0)
        {
            complete++;
            finish_time = t + 1;
            wt[shortest] = finish_time - processes[shortest].bt - processes[shortest].at;
            if (wt[shortest] < 0)
            {
                wt[shortest] = 0;
            }
        }

        t++;
    }
}

void findTurnAroundTime(vector<Process> &processes, vector<int> &wt, vector<int> &tat)
{
    int n = processes.size();
    for (int i = 0; i < n; i++)
    {
        tat[i] = processes[i].bt + wt[i];
    }
}

void findavgTime(vector<Process> &processes)
{
    int n = processes.size();
    vector<int> wt(n, 0);
    vector<int> tat(n, 0);

    findWaitingTime(processes, wt);
    findTurnAroundTime(processes, wt, tat);

    float total_wt = 0;
    float total_tat = 0;

    cout << "Process\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time" << endl;

    for (int i = 0; i < n; i++)
    {
        total_wt += wt[i];
        total_tat += tat[i];
        cout << processes[i].pid << "\t\t" << processes[i].bt << "\t\t" << processes[i].at << "\t\t" << wt[i] << "\t\t" << tat[i] << endl;
    }

    cout << "Average waiting time = " << total_wt / n << endl;
    cout << "Average turnaround time = " << total_tat / n << endl;
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
        cout << "Enter arrival time for Process " << processes[i].pid << ": ";
        cin >> processes[i].at;
        cout << "Enter burst time for Process " << processes[i].pid << ": ";
        cin >> processes[i].bt;
    }

    sort(processes.begin(), processes.end(), comparison);
    findavgTime(processes);

    return 0;
}
