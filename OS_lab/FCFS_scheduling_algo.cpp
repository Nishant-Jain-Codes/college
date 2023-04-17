 #include<bits/stdc++.h>
using namespace std;
    bool comp(pair<int,int> p1, pair<int,int> p2){
        return p1.first<=p2.first;
    }

    void FCFS_scheduling_algorithm(){
        int processes;
        cout<<"enter the number of processes\n";
        cin>>processes;
        vector<pair<int,int>> Pn;
        for(int i=0;i<processes;i++){
            int AT,BT;
            cout<<"p"<<i+1<<" AT BT ";
            cin>>AT>>BT;
            Pn.push_back({AT,BT});
        }
        cout<<"Pn\tAT\tBT\tWT\tTAT"<<endl;
        
        sort(Pn.begin(),Pn.end(),comp);
        int timePassed =0;
        int totalWaitTime =0;
        int total_TAT =0;
        int i=1;
        int cpu_idle_time =0;
        for(auto x: Pn){
            pair<int,int> curProcess = x;
            int curAt = curProcess.first;
            int curBt = curProcess.second;
            int curWt =0;
            int curTAT =0;
            if(curAt<timePassed){
                curWt = timePassed-curAt;
                totalWaitTime+=curWt;
            }
            if(curAt>timePassed){
                cpu_idle_time += curAt-timePassed;
            }
            timePassed+=curBt;
            curTAT = curWt + curBt;
            total_TAT += curTAT;
            cout<<i<<"\t"<<curAt<<"\t"<<curBt<<"\t"<<curWt<<"\t"<<curTAT<<"\t"<<endl;
            i++;
        }
        cout<<Pn.size()<<endl;
        int cpu_total_run_time = total_TAT;
        int cpu_eff = ((cpu_total_run_time - cpu_idle_time)*100.0)/cpu_total_run_time;
        float average_WT = (totalWaitTime*(1.0)) / Pn.size();
        float average_TAT = (total_TAT*(1.0))/Pn.size();
        cout<<" average wait time = "<<average_WT<<"units"<<endl;
        cout<<" average Turn Around Time = "<<average_TAT<<"units"<<endl;
        cout<<" CPU utilisation % = "<<cpu_eff<<"%"<<endl;
    }

 int main(){
    cout<<"running FCFS scheduling algorithm \n";
    FCFS_scheduling_algorithm();
    cout<<endl;
    return 0;
 }