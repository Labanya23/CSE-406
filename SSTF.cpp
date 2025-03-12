#include<bits/stdc++.h>
using namespace std;
int main()
{
    int sum=0;
    int a[]={176,79,34,60,92,11,41,114};
    int head=50;
    sort(a,a+8);
    for(int i=0;i<8;i++){
        sum+=abs(a[i]-head);
        head=a[i];
    }
    cout<<sum<<endl;
    return 0;

}

