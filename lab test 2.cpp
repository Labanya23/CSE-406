#include<bits/stdc++.h>
using namespace std;
int main()
{
    int head=55;
    int n=8;
    int a[]={137,240,179,75,118,29,15,51};

    sort(a,a+n);
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


