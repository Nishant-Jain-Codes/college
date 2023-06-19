//take memory size
//take memory fragments
//take process size
//caclulate internal fragmentation
//calculate total internal fragmentation

#include<bits/stdc++.h>
using namespace std;
class fixedMemory{
    vector<int> memoryFragments;
    vector<int> processSize;
    int totalMemorySize;
    int noOfMemoryFragments;
    int noOfProcess;
public:
    void memoryInput(){
        cout<<"enter memory fragments No ";
        cin>>noOfMemoryFragments;
        totalMemorySize=0;
        for(int i=0;i<noOfMemoryFragments;i++){
            int x;
            cin>>x;
            totalMemorySize+=x;
            memoryFragments.push_back(x);
        }
    }
    void processInput(){
        cout<<"enter process size No ";
        cin>>noOfProcess;
        for(int i=0;i<noOfProcess;i++){
            int x;
            cin>>x;
            processSize.push_back(x);
        }
    }
    void firstFit(){
        cout<<"<><><><><><><><first fit><><><><><><><>"<<endl;
        vector<bool> allocated(noOfMemoryFragments,false);
        int noOfProcessAllocated = 0;
        int internalFragmentation=0;
        for(int i=0;i<noOfProcess;i++){
            for(int j=0;j<noOfMemoryFragments;j++){
                if(processSize[i]<=memoryFragments[j] && !allocated[j]){
                    internalFragmentation+=(memoryFragments[j]-processSize[i]);
                    allocated[j]=true;
                    noOfProcessAllocated++;
                    cout<<"process "<<i+1<<" is allocated to memory fragment "<<j+1<<endl;
                    break;
                }
            }
        }
        cout<<"no of process allocated "<<noOfProcessAllocated<<" out of "<<noOfProcess<<endl;
        cout<<"internal fragmentation "<<internalFragmentation<<" out of "<<totalMemorySize<<endl;

    }
    void worstFit(){
        cout<<"<><><><><><><><Worst Fit><><><><><><><>"<<endl;
        vector<bool> allocated(noOfMemoryFragments,false);
        int noOfProcessAllocated = 0;
        int internalFragmentation=0;
        for(int i=0;i<noOfProcess;i++){
            int maxFragment = -1;
            int maxFragmentIndex = -1;
            for(int j=0;j<noOfMemoryFragments;j++){
                if(processSize[i]<=memoryFragments[j] && !allocated[j]){
                    if(maxFragment<memoryFragments[j]){
                        maxFragment = memoryFragments[j];
                        maxFragmentIndex = j;
                    }
                }
            }
            if(maxFragmentIndex!=-1){
                internalFragmentation+=(memoryFragments[maxFragmentIndex]-processSize[i]);
                allocated[maxFragmentIndex]=true;
                noOfProcessAllocated++;
                cout<<"process "<<i+1<<" allocated to memory fragment "<<maxFragmentIndex+1<<endl;
            }
        }
        cout<<"no of process allocated "<<noOfProcessAllocated<<" out of "<<noOfProcess<<endl;
        cout<<"internal fragmentation "<<internalFragmentation<<" out of "<<totalMemorySize<<endl;
    }
    void bestFit(){
        cout<<"<><><><><><><><Best fit><><><><><><><>"<<endl;
        vector<bool> allocated(noOfMemoryFragments,false);
        int noOfProcessAllocated = 0;
        int internalFragmentation=0;
        for(int i=0;i<noOfProcess;i++){
            int minFragment = INT_MAX;
            int minFragmentIndex = -1;
            for(int j=0;j<noOfMemoryFragments;j++){
                if(processSize[i]<=memoryFragments[j] && !allocated[j]){
                    if(minFragment>memoryFragments[j]){
                        minFragment = memoryFragments[j];
                        minFragmentIndex = j;
                    }
                }
            }
            if(minFragmentIndex!=-1){
                internalFragmentation+=(memoryFragments[minFragmentIndex]-processSize[i]);
                allocated[minFragmentIndex]=true;
                noOfProcessAllocated++;
                cout<<"process "<<i+1<<" is allocated to memory fragment "<<minFragmentIndex+1<<endl;
            }
        }
        cout<<"no of process allocated "<<noOfProcessAllocated<<" out of "<<noOfProcess<<endl;
        cout<<"internal fragmentation "<<internalFragmentation<<" out of "<<totalMemorySize<<endl;
    }
};
int main(){
    fixedMemory m;
    m.memoryInput();
    m.processInput();
    m.firstFit();
    m.worstFit();
    m.bestFit();
    return 0;
}

// enter memory fragments No 5
// 100
// 200
// 300
// 400
// 500
// enter process size No 7
// 10
// 20
// 500
// 250
// 150
// 5
// 10
// <><><><><><><><first fit><><><><><><><>
// process 1 is allocated to memory fragment 1
// process 2 is allocated to memory fragment 2
// process 3 is allocated to memory fragment 5
// process 4 is allocated to memory fragment 3
// process 5 is allocated to memory fragment 4
// no of process allocated 5 out of 7
// internal fragmentation 570 out of 1500
// <><><><><><><><Worst Fit><><><><><><><>
// process 1 allocated to memory fragment 5
// process 2 allocated to memory fragment 4
// process 4 allocated to memory fragment 3
// process 5 allocated to memory fragment 2
// process 6 allocated to memory fragment 1
// no of process allocated 5 out of 7
// internal fragmentation 1065 out of 1500
// <><><><><><><><Best fit><><><><><><><>
// process 1 is allocated to memory fragment 1
// process 2 is allocated to memory fragment 2
// process 3 is allocated to memory fragment 5
// process 4 is allocated to memory fragment 3
// process 5 is allocated to memory fragment 4
// no of process allocated 5 out of 7
// internal fragmentation 570 out of 1500