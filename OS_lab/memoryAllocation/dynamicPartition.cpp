//take memory size
//take memory fragments
//take process size
//caclulate internal fragmentation
//calculate total internal fragmentation

#include<bits/stdc++.h>
using namespace std;
class DynamicMemory{
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
    void allocateProcess(){
        cout<<"<><><><><><><><Best fit><><><><><><><>"<<endl;
        vector<bool> allocated(noOfMemoryFragments,false);
        int noOfProcessAllocated = 0;
        int internalFragmentation=0;
        int totalExternalFragmentation=0;
        for(int i=0;i<noOfProcess;i++){
            int minFragment = INT_MAX;
            int minFragmentIndex = -1;
            for(int j=0;j<noOfMemoryFragments;j++){
                if(processSize[i]<=memoryFragments[j]){
                    if(minFragment>memoryFragments[j]){
                        minFragment = memoryFragments[j];
                        minFragmentIndex = j;
                    }
                }
            }
            if(minFragmentIndex!=-1){
                allocated[minFragmentIndex]=true;
                noOfProcessAllocated++;
                memoryFragments[minFragmentIndex]-=processSize[i];
                cout<<"process "<<i+1<<" is allocated to memory fragment "<<minFragmentIndex+1<<" memory left "<<memoryFragments[minFragmentIndex]<<endl;
                
            }
        }
        for(int i=0;i<noOfMemoryFragments;i++){
            totalExternalFragmentation+=memoryFragments[i];
            if(allocated[i])
                internalFragmentation+=memoryFragments[i];
        }
        cout<<"no of process allocated "<<noOfProcessAllocated<<" out of "<<noOfProcess<<endl;
        cout<<"internal fragmentation "<<internalFragmentation<<" out of "<<totalMemorySize<<endl;
        cout<<"external fragmentation "<<totalExternalFragmentation<<" out of "<<totalMemorySize<<endl;
    }
};
int main(){
    DynamicMemory m;
    m.memoryInput();
    m.processInput();
    m.allocateProcess();
    return 0;
}

// enter memory fragments No 2
// 101
// 220
// enter process size No 5
// 1
// 50
// 50
// 100
// 110
// <><><><><><><><Best fit><><><><><><><>
// process 1 is allocated to memory fragment 1 memory left 100
// process 2 is allocated to memory fragment 1 memory left 50
// process 3 is allocated to memory fragment 1 memory left 0
// process 4 is allocated to memory fragment 2 memory left 120
// process 5 is allocated to memory fragment 2 memory left 110
// no of process allocated 5 out of 5
// internal fragmentation 110 out of 321
// external fragmentation 110 out of 321