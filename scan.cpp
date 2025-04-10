#include<bits/stdc++.h>
using namespace std;
int main()
{
    int head=53;
    int n=10;
    int a[]={14, 41, 53, 65, 67, 98, 122, 124, 183, 199};

    vector<int>left,right;
    for(int i=0;i<n;i++){
        if(a[i]<head) left.push_back(a[i]);
        else right.push_back(a[i]);
    }
    sort(left.begin(),left.end());
    sort(right.begin(),right.end());
    int total_distance=0;


        total_distance+=abs(a[n-1]-head);
        head=a[n-1];
        total_distance+=abs(head-left[0]);



    cout<<total_distance<<endl;
    return 0;
}


