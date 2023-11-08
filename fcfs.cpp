#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, sum = 0;
    float total_tt = 0, total_waiting = 0;
    cout << "Enter Number Of Processes you want to execute: ";
    cin >> n;

    vector<int> arrival(n);
    vector<int> cpu(n);
    vector<int> finish(n);
    vector<int> turntt(n);
    vector<int> wait(n);
    vector<int> process(n);

    for (int i = 0; i < n; i++)
    {
        cout << "Enter arrival time of Process " << (i + 1) << ": ";
        cin >> arrival[i];
        cout << "Enter CPU time of Process " << (i + 1) << ": ";
        cin >> cpu[i];
        process[i] = i + 1;
    }

    for (int i = 0; i < n; i++)
    {
        sum += cpu[i];
        finish[i] = sum;
    }

    for (int i = 0; i < n; i++)
    {
        turntt[i] = finish[i] - arrival[i];
        total_tt += turntt[i];
        wait[i] = turntt[i] - cpu[i];
        total_waiting += wait[i];
    }

    cout << "\n\nProcess\t\tAT\tCPU_T\n";
    for (int i = 0; i < n; i++)
    {
        cout << process[i] << "\t\t" << arrival[i] << "\t" << cpu[i] << endl;
    }
    cout << "\n\n";
    cout << "Total turn around time is: " << (total_tt / n) << endl;
    cout << "Total waiting time is: " << (total_waiting / n) << endl;

    return 0;
}
