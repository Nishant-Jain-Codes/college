// smallest job first scheduling algorithm
//TODO : add gantt chart
//TODO : fix the idle time bug
#include <bits/stdc++.h>
using namespace std;
class Process{
    public:
    int AT,BT,ST,TAT,WT,Pno;
    bool executed;
    Process (int Pno,int AT,int BT){
        this->Pno = Pno;
        this->AT=AT;
        this->BT=BT;
        this->executed=false;
    }
    void setST(int ST){
        this->ST=ST;
    }
    void setTAT(int TAT){
        this->TAT=TAT;
    }
    void setWt(int WT){
        this->WT=WT;
    }
    void printProcess(){
        cout<<"P"<<Pno<<"\t"<<AT<<"\t"<<BT<<"\t"<<ST<<"\t"<<TAT<<"\t"<<WT<<endl;
    }
    void setExecuted(){
        this->executed=true;
    }
};
Process scheduler(int curTime, vector<Process> &processes){
    int minBT=INT_MAX;
    int minBTIndex=-1;
    for(int i=0;i<processes.size();i++){
        if(processes[i].AT<=curTime && processes[i].BT<minBT && !processes[i].executed){
            minBT=processes[i].BT;
            minBTIndex=i;
        }
    }
    if(minBTIndex!=-1){
        processes[minBTIndex].setST(curTime);
        processes[minBTIndex].setTAT(curTime+processes[minBTIndex].BT-processes[minBTIndex].AT);
        processes[minBTIndex].setWt(curTime - processes[minBTIndex].AT);
        processes[minBTIndex].setExecuted();
        return processes[minBTIndex];
    }
    else {
        int minAT = INT_MAX;
        int minATIndex=-1;
        for(int i=0;i<processes.size();i++){
        if( processes[i].AT<minAT && !processes[i].executed){
            minAT=processes[i].AT;
            minATIndex=i;
        }
        processes[minATIndex].setST(processes[minATIndex].AT);
        processes[minATIndex].setTAT(processes[minATIndex].BT);
        processes[minATIndex].setWt(0);
        processes[minATIndex].setExecuted();
    }
    return processes[minATIndex];
    }
}

int main(){
    int totalProcess;
    cout<<"Enter total number of process: ";
    cin>>totalProcess;
    vector<Process> processes;
    for(int i=0;i<totalProcess;i++){
        int AT,BT;
        cout<<"Enter AT and BT of process "<<i+1<<": ";
        cin>>AT>>BT;
        processes.push_back(Process(i+1,AT,BT));
    }
    int curTime=0;
    int idleTime=0;
    int totalWT=0;
    int totalTAT=0;
    cout<<"Pno:    AT:     BT:     ST:     TAT:    WT:"<<endl;
    for(int i=0;i<totalProcess;i++){
        Process p=scheduler(curTime,processes);
        
        p.printProcess();
        if(p.ST>curTime){
            idleTime+=p.ST-curTime;
            curTime=p.ST+p.BT;
        }
        else{
            curTime+=p.BT;
        }
        totalWT += p.WT;
        totalTAT += p.TAT;
        
    }
    int cpuEfficiency = ((curTime-idleTime)/curTime)*100;
    float avgWT = (totalWT*1.0)/totalProcess;
    float avgTAT = (totalTAT*1.0)/totalProcess;
    cout<<"cpu efficiency: "<<cpuEfficiency<<"%"<<endl;
    cout<<"average waiting time: "<<avgWT<<endl;
    cout<<"average turn around time: "<<avgTAT<<endl;
    return 0;
}