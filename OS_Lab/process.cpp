#include <algorithm>
#include <ctime>
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
class process
{
    public:
        int pid, at, bt, pri;
        void show_data()
        {
            cout<<"Pid "<<pid<<" AT "<<at<<" BT "<<bt<<" Priority "<<pri<<endl;
        }
};
class ready_queue
{
    public:
        process pr;
        int time_in;
        int time_out;
};

void sort_by_at(int start, int stop,  vector<process> &pt)
{
    // stop = size - 1
    for (int i = start; i <= stop; i++)
    {
        process key = pt[i];
        int j = i-1;
         while (j>0 && pt[j].at > key.at) 
         {
            pt[j+1] = pt[j];
            j--;         
         }
         pt[j+1] = key;
    }
    cout<<"\nProcess sorted by arrival time\n";
}

void simulate(scheduling_algorithm sa)
{
    // process table
    vector<process> pt; // process table
    vector<ready_queue> rq;
    vector<process> open; 
    vector<process> closed;
    
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

        int pid, at, bt, pri = -1;// int to enum

        if (sa != PRIORITY)
        {
            cout<<"Enter Arrival time and burst time for process "<<i+1<<endl;
            cin>>at>>bt;
        }
        else
        {
            cout<<"Enter Arrival time, burst time and priority"<<i+1<<endl;       
            cin>>at>>bt>>pri;
        }  
        
        pr.pid = i; pr.at = at; pr.bt = bt; pr.pri = pri;
        pt.push_back(pr);
    }
    cout<<"Entered data"<<endl;
    
    for (int i=0; i<n;i++ ) pt[i].show_data();

    // schedule the algorithm

    // sort acc to AT
    int start = 0;
    int stop = pt.size() -1;
    sort_by_at(start, stop, pt);

    int time_t = 0;
    process pr = pt.front();
    ready_queue rq_t;
    switch (sa) 
    {
        case FCFS:
            cout<<"\nSimulating FCFS"<<endl;
            

            while(pt.size() != 0)
            {
                int busy=0;
                //if at<time, continue
                // if at==time, add then add to the ready queue
                if (time_t<pr.at) continue; 

                if (time_t>=pr.at && (busy == 0)) 
                {
                    rq_t.pr = pr; rq_t.time_in = time_t; rq_t.time_out = -1;
                    busy=1;
                    cout<<"\nProcess enter execution Pid "<<pr.pid<<"Time "<<time_t<<endl;
                }

                // bt done, add time_out to pr, add to the rq vector, pick next process from pt
                int executed_time = time_t - rq_t.time_in;
                int burst_time = rq_t.pr.bt;
                // TODO: VERIFY CONDITION
                if ((executed_time == burst_time) && (busy==1))
                {
                    cout<<"\nProcess execution complete Pid "<<pr.pid<<endl;
                    rq_t.time_out = time_t;
                    rq.push_back(rq_t);
                    pt.erase(pt.begin());
                    pr = pt.front();
                    busy=0;
                    // cout<<pt.size()<<endl;
                }
                time_t++;
            }
            break;
    // add all process to a queue
    // maintain open and closed
    // execute it sequentialy
    // if there is no job, continue
    // if all processes are done, stop

        case SJF:
    // add all process to a queue
    // maintain open and closed
    // sort all the process acc to at then bt
    // execute it sequentialy
    // if there is no job, continue
    // if all processes are done, stop
            break;


         case ROUND_ROBIN: // requires Time quantum

    // add all process to a queue
    // maintain open and closed
    // sort all the process acc to at then bt
    // execute it sequentialy
    // if there is no job, continue
    // if all processes are done, stop
            break;

        case PRIORITY:

    // add all process to a queue
    // maintain open and closed
    // sort all the process acc to at then priority
    // execute it sequentialy
    // if there is no job, continue
    // if all processes are done, stop
        break;
    }
    // generate average waiting time and average turn around time   
    switch (sa) 
    {
    case FCFS:

        cout<<rq.back().time_out<<endl;
        break;
    case SJF:
    case ROUND_ROBIN:
    case PRIORITY:
      break;
    }
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