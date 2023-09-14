#include<bits/stdc++.h>
using namespace std;
void binarySearchRecursive(vector<int>& nums, int si , int ei, int x, vector<int>& ans){
    if(si>ei)
        return ;
    int mid = (si+ei)/2;
    if(nums[mid]>x){
        ei=mid-1;
        binarySearchRecursive(nums,si,mid-1,x,ans);
    }
    else if(nums[mid]<x){
        si=mid+1;
        binarySearchRecursive(nums,mid+1,ei,x,ans);
    }
    else{
        int i=mid;
        //cout<<i<<endl;
        while(i>0&&nums[i-1]==x){
            i--;
        }
        while(i<nums.size()&&nums[i]==x){
            ans.push_back(i);
            i++;
        }
    }
}
vector<int> binarySearchIterative(vector<int> & nums,int x){

    int si=0;
    int ei=nums.size()-1;
    vector<int> ans;
    while(si<=ei){
        int mid = (si+ei)/2;
        if(nums[mid]>x){
            ei=mid-1;
        }
        else if(nums[mid]<x){
            si=mid+1;
        }
        else{
            int i=mid;
            //cout<<i<<endl;
            while(i>0&&nums[i-1]==x){
                i--;
            }
            while(i<nums.size()&&nums[i]==x){
                ans.push_back(i);
                i++;
            }
            break;
        }
    }
    return ans;
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
    sort(nums.begin(),nums.end());
    vector<int> ans;
    binarySearchRecursive(nums,0,nums.size()-1,x,ans);
    printer(nums,"array after sorting for binary Search");
    printer(ans,"Recursive");
    ans=binarySearchIterative(nums,x);
    printer(ans,"iterative");
    return 0;
}