#include<bits/stdc++.h>
using namespace std;
int main(){

int n=5;
int burst_time[]={6,2,8,3,4};
//for(int i=0;i<n;i++){
    //cin>>burst_time[i];
//}
//int wait_time[n],turnaround_time[n];
int wait_time[5],turnaround_time[5];
for(int i=0;i<n-1;i++){
    int min_index=i;
    for(int j=i+1;j<n;j++){
        if(burst_time[j]<burst_time[min_index]){
            min_index=j;
        }
    }
    int temp=burst_time[i];
    burst_time[i]=burst_time[min_index];
    burst_time[min_index]=temp;
}
wait_time[0]=0;
for(int i=1;i<n;i++){
    wait_time[i]=wait_time[i-1]+burst_time[i-1];

}
for(int i=0;i<n;i++){
    turnaround_time[i]=burst_time[i]+wait_time[i];

}
cout<<"Process\t BurstTime\t WaitingTime\t TurnAroundTime\n";
for(int i=0;i<n;i++){
    cout<<i+1<<"\t"<<burst_time[i]<<"\t\t"<<wait_time[i]<<"\t\t"<<turnaround_time[i]<<endl;
}

return 0;
}
