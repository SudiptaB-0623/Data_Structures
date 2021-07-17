#include <bits/stdc++.h>
using namespace std;
int root=0;
int main()
{
  int n;
  cin>>n;
  vector< vector<int> >nodes(n);
  queue<int>q;
  int a[n];
  for(int i=0;i<n;i++)
  {
	  cin>>a[i];
	  if(a[i]==-1)root=i;
	  else {
		  nodes[a[i]].push_back(i);
	  }
  }
  q.push(root);
  int height=0;
  while(true)
  {
	  int nodecount=q.size();
	  if(nodecount==0){
		  cout<<height<<endl;
		  return 0;
	  }
	  height+=1;
	  while(nodecount>0){
		  int node=q.front();
		  q.pop();
		  if(!nodes[node].empty()){
			  for(int i=0;i<nodes[node].size();i++)
				  q.push(nodes[node][i]);
		  }
		  nodecount--;
	  }
  }
    return 0;
}
