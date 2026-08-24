#include <iostream>
#include <vector>
using namespace std;

enum scheduling_algorithm
{
    FCFS,
    SJF,
    ROUND_ROBIN,
    PRIORITY
};
enum process_state
{
    NEW,
    RUNNING,
    WAITING,
    READY,
    TERMINATED,
    SUSPENDED_READY,
    SUSPENDED_WAIT 
};
enum priority
{
    NO,
    LOW,
    MEDIUM,
    HIGH
};
class process
{
    public:
        int pid, at, bt;
        priority pri = NO;
        void show_data()
        {
            cout<<"Pid "<<pid<<" AT "<<at<<" BT "<<bt<<" Priority "<<pri<<endl;
        }
};


void simulate(scheduling_algorithm sa)
{
    // process table
    vector<process> pt; // process table
    
    // take input
    cout<<"Enter no. of processes"<<endl;
    int n; cin>>n; 
    if (n <1)
    {
        cout<<"Invalid input, no. of processes can't be less than 1. Please try again.";
        exit(1);
    } 
    for (int i=0; i<n;i++ )
    {
        process pr; // process row
        // input at and bt
        // input priority if priority

        int pid, at, bt;
        int pr_int=-1;  priority pri = NO;// int to enum
        cout<<"Priority (NO<--0, LOW<--1, MEDIUM<--2, HIGH<--3)"<<endl;
        if (sa != PRIORITY)
        {
            cout<<"Enter Arrival time and burst time for process "<<i+1<<endl;
            cin>>at>>bt;
            pri = NO;
        }
        else
        {
            cout<<"Enter Arrival time, burst time and priority"<<i+1<<endl;       
            cin>>at>>bt>>pr_int;
            switch(pr_int) // set pr
            {
                case 0:
                    cout<<"Can't manualy set priority to NO, please pick LOW, MEDIUM or HIGH for PRIORITY algorithm"<<endl;
                    exit(0);
                    break;
                case 1:
                    pri=LOW;
                    break;
                case 2:
                    pri=MEDIUM;
                    break;
                case 3:
                    pri=HIGH;
                    break;
                default:
                    cout<<"Invalid input, please try again..."<<endl;
                    exit(0);
                    break;
            }
        }  

        pr.pid = i; pr.at = at; pr.bt = bt; pr.pri = pri;
        pt.push_back(pr);
    }
    cout<<"Entered data"<<endl;
    
    for (int i=0; i<n;i++ ) pt[i].show_data();

    // schedule the algorithm

    // generate average waiting time and average turn around time   
}

int main()
{
    int n; scheduling_algorithm sa;
    cout<<"Input n to simulate algorithm"<<endl;
    cout<<"0 to exit, 1 for FCFS, 2 for SJF, 3 for ROUND_ROBIN, 4 for PRIORITY"<<endl;
    cin>>n;
    switch (n) 
    {
        case 0:
            exit(0);
            break;
        case 1:
            sa = FCFS;
            break;
        case 2:
            sa = SJF;
            break;
        case 3:
            sa = ROUND_ROBIN;
            break;
        case 4:
            sa = PRIORITY;
            break;
        default:
            cout<<"Invalid input, try again..."<<endl;
            exit(0);
            break;       
    }
    simulate(sa);
    return 0;
}