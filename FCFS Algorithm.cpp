#include<bits/stdc++.h>
using namespace std;
int main(){



    int arrival[3];
    int burst[3];
    int completition[3];
    int turnaround[3];
    int waiting[3];

    for(int i=0;i<3;i++){

        cin>>arrival[i];
        cin>>burst[i];
    }
    for(int i=0;i<2;i++){
      for(int j=0;j<2-i;j++){
        if(arrival[j]>arrival[j+1]){
            swap(arrival[j],arrival[j+1]);
            swap(burst[j],burst[j+1]);

        }

      }

    }
    int times=0;
    for(int i=0;i<3;i++){
        if(times<arrival[i])
            times=arrival[i];
            completition[i]=times+burst[i];
            turnaround[i]=completition[i]-arrival[i];
            waiting[i]=turnaround[i]-burst[i];
            times=completition[i];
    }
    cout<<"The result of the FCPS algorithm output"<<endl;


        for(int i=0;i<3;i++){
            cout<<arrival[i]<<" ";
            cout<<burst[i]<<" ";
            cout<<completition[i]<<" ";
            cout<<turnaround[i]<<" ";
            cout<<waiting[i]<<endl;
        }
    return 0;



}
