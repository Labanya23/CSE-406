#include<bits/stdc++.h>
using namespace std;

int fifopagereplacement(int pages[],int n,int capacity){
queue<int>q;
unordered_set<int>s;
int page_faults=0;
for(int i=0;i<n;i++){
    if(s.find(pages[i])==s.end()){
        page_faults++;
        if(q.size()==capacity){
            s.erase(q.front());
            q.pop();
        }
        q.push(pages[i]);
        s.insert(pages[i]);
    }
}

return page_faults;
}
int main(){
  int pages[]={1,3,0,3,5,6,3};
  int n=sizeof(pages)/sizeof(pages[0]);
  int capacity=3;
  int page_faults=fifopagereplacement(pages, n, capacity);
  cout<<page_faults<<endl;
  return 0;

}
