#include<bits/stdc++.h>
using namespace std;

void linearSearch(vector<int>& nums, int idx ,const int x,vector<int>& ans){
    if(idx>=nums.size())
        return ;
    if(nums[idx]==x)
        ans.push_back(idx);

    linearSearch(nums,idx+1,x,ans);
        
}
void printer(vector<int>& nums,string str){
    cout<<str<<endl;;
    //cout<<nums.size();
    for(auto &x:nums){
        cout<<x<<" ";
    }
    cout<<endl;
}
void input(vector<int>&nums,int & n,int &x){
    cout<<"enter n\n";
    cin>>n;
    cout<<"enter "<<n<<" values\n";
    for(int i =0;i<n;i++){
        int in;
        cin>>in;
        nums.push_back(in);
    }
    cout<<"enter x\n";
    cin>>x;
}
int main(){
    int n,x;
    vector<int> nums;
    input(nums,n,x);
    vector<int> ans;
    linearSearch(nums,0,x,ans);
    printer(nums,"answer ...");
    return 0;
}