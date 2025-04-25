#include<bits/stdc++.h>
using namespace std;
 int search(int n,int pages[],int capacity)
 {

     for(int i=0;i<capacity;i++)
        if(pages[i] == n)
            return 1;
        return 0;


 }

 int predict(int ref_str[],int pages[],int refStrlen,int index,int capacity)
 {

     int result =-1 , farthest=index;
     for(int i=0;i<capacity;i++){
        int j;
        for(j=index;j<refStrlen;j++){
                if(pages[i] == ref_str[j]){
            if(j>farthest){
                farthest = j;
                result = i;
            }
            break;
        }
     }
     if(j==refStrlen)
        return i;
 }
 return (result==-1)?0:result;
 }
 void optimalPage(int ref_str[],int refStrlen,int pages[],int max_frame){

 int capacity = 0;
 int hits=0;
 for(int i=0;i<refStrlen;i++){
    if(search(ref_str[i],pages,capacity)){
        hits++;
        continue;
    }
    if(capacity<max_frame){
        pages[capacity]=ref_str[i];
        capacity++;

    }
    else{
        int pos=predict(ref_str,pages,refStrlen,i+1,capacity);
        pages[pos] = ref_str[i];

    }
 }
 cout<<"Hits:"<<hits<<endl;
 cout<<"Miss:"<<refStrlen-hits<<endl;


 }
 int main()
 {
     int ref_str[] = {7, 0, 1, 2, 0, 3, 0,4,2,3,0,3,2,3};
    int refStrLen = sizeof(ref_str) / sizeof(ref_str[0]);
    int max_frame = 4;
    int pages[max_frame];

    optimalPage(ref_str, refStrLen,pages,max_frame);
    return 0;
 }
