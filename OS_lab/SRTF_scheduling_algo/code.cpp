// implementation for Smallest remaining Time first (SRTF) scheduling algorithm
//TODO feeling stuck and having brain fox , will try to implement it later
#include <bits/stdc++.h>
using namespace std;

class Process
{
public:
    int AT, BT, ST, TAT, WT, Pno,RT,ET;
    bool executed;
    Process(int Pno, int AT, int BT)
    {
        this->Pno = Pno;
        this->AT = AT;
        this->BT = BT;
        this->RT = BT;
        this->executed = false;
    }
    void updateRT(){
        this->RT--;
    }
    void setET(int ET){
        this->ET = ET;
    }
    void setST(int ST)
    {
        this->ST = ST;
    }
    void setTAT(int TAT)
    {
        this->TAT = TAT;
    }
    void setWt(int WT)
    {
        this->WT = WT;
    }
    void printProcess()
    {
        cout << "P" << Pno << "\t" << AT << "\t" << BT << "\t" << ST << "\t" << TAT << "\t" << WT << endl;
    }
    void setExecuted()
    {
        this->executed = true;
    }
};
struct compareBT{
    bool operator()(const Process& p1, const Process& p2){
    return p1.BT < p2.BT;
    }
};
struct compareRT{
    bool operator()(const Process& p1, const Process& p2){
    return p1.RT < p2.RT;
    }
};
int main(){
    int totalProcess;
    cout<<"Enter total number of process: ";
    cin>>totalProcess;
    priority_queue<Process> processes;
    priority_queue<Process> readyQueue;
    for(int i=0;i<totalProcess;i++){
        int AT,BT;
        cout<<"Enter AT and BT of process "<<i+1<<": ";
        cin>>AT>>BT;
        processes.push(Process(i+1,AT,BT));
    }
    
    bool processing = false;
    int idleTime = 0;
    Process curProcess = processes.top();
    curProcess.setST(curProcess.AT);
    processes.pop();
    int curTime = curProcess.AT;
    int idleTime = cur
    while(!processes.empty() || !readyQueue.empty()){
        
    }
    return 0;
}