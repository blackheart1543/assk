#include <iostream>
using namespace std;
class cost{
int n, graph[10][10], v1, v2, visited[100];
public:
 int total_cost=0;
cost()
{
n=0;
cout<<"\nEnter number of Offices: ";
cin>>n;
for(int i=0; i<n;i++)
{
visited[i]=0;
graph[i][i]=0;
}
}
void create();
void display();
void Prims_Algo();
};
void cost::create()
{
int ans=1, c=0;
do{
cout<<"\nEnter two office numbers in range 0 to "<<n-1<<" :";
cin>>v1>>v2;
cout<<"Enter cost(in denomination of 1000rs) of leasing a phone line between above
two offices: ";
cin>>c;
graph[v1][v2]=graph[v2][v1]=c;
cout<<"\tDo you want to continue(1/0): ";
cin>>ans;
}while(ans==1);
}
void cost::display()
{
cout<<"\nAdjacency matrix of graph having "<<n<<" offices is: "<<endl<<" ";
for(int i=0; i<n; i++)
{
cout<<endl;
for(int j=0; j<n; j++)
cout<<graph[i][j]<<" ";
}
}
void cost::Prims_Algo()
{
int sv;
cout<<"\nEnter starting office number: ";
cin>>sv;
visited[sv]=1;
int min=999;
for(int e=0; e<n-1; e++)
{
min=999;
for(int i=0; i<n; i++)
{
if(visited[i]==0)
continue;
for(int j=0; j<n; j++)
{
if(visited[j]==0 && i!=j)
{
if(graph[i][j]<min)
{
min=graph[i][j];
v1=i;
v2=j;
}
}
}
}
cout<<"\nPhone line "<<e+1<<" selected between office-> "<<v1<<"-"<<v2<<" with
cost: "<<graph[v1][v2]<<"000 RS";
visited[v2]=1;
total_cost+=graph[v1][v2];
}
}
int main() {
cost c;
c.create();
c.display();
c.Prims_Algo();
cout<<"\nTotal cost required for leasing all above selected lines is "<<c.total_cost<<"000 RS
Only!";
return 0;
}
