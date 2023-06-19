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