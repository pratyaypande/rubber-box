#include <iostream>
#include <bits/c++io.h>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

class JobQueue
{
    private:
    int num_workers_;
    vector<int> jobs_;
    vector<int> assigned_workers_;
    vector<long long> start_times_;
    void WriteResponse() const
    {
        for (int i = 0; i < jobs_.size(); ++i)
            cout << assigned_workers_[i] << " " << start_times_[i] << "\n";
    }
    void ReadData()
    {
        int m;
        cin >> num_workers_ >> m;
        jobs_.resize(m);
        for(int i = 0; i < m; ++i)
            cin >> jobs_[i];
    }

    void AssignJobs()
    {
        // TODO: replace this code with a faster algorithm.
        assigned_workers_.resize(jobs_.size());
        start_times_.resize(jobs_.size());
        vector<long long> next_free_time(num_workers_, 0);
        int j = 0;
        for (int i = 0; i < jobs_.size();i++)
        {
            int duration = jobs_[i];
            int next_worker = 0,preVj=j;
            bool b = true;
            while(j != preVj || b)
            {
                b = false;
                if (next_free_time[j] < next_free_time[next_worker])
                {
                    next_worker = j;
                }
                if(j != num_workers_-1)
                    j++;
                else
                    j = 0;
            }
            assigned_workers_[i] = next_worker;
            start_times_[i] = next_free_time[next_worker];
            next_free_time[next_worker] += duration;
        }

    }
    public:
    void Solve()
    {
        ReadData();
        AssignJobs();
        WriteResponse();
    }
};

int main()
{
    std::ios_base::sync_with_stdio(false);
    JobQueue job_queue;
    job_queue.Solve();
    return 0;
}
