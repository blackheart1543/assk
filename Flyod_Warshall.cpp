#include<iostream>
using namespace std;
class Flyod_Warshall{
 int A[100][100];
 int n;
public:
 Flyod_Warshall()
 {
 cout<<"\n\tWelcome to All-pairs Shortest Path of a Graph";
 cout<<"\nEnter number of verƟces: ";
 cin>>n;
 for(int i=0; i<n; i++)
 A[i][i]=0;
 }
 void create();
 void display();
 void algo();
};
void Flyod_Warshall::create()
{
 char ans='y';
 int v1,v2, cost;
 cout<<"\nEnter Directed edges of graph below:\n";
 do{
 cout<<"\nEnter edge pair in (v1-v2) form: ";
 cin>>v1>>v2;
 cout<<"\nEnter cost of edge: ";
 cin>>cost;
 A[v1][v2]=cost;
 cout<<"\nConƟnue?(Y/N): ";
 cin>>ans;
 }while(ans=='y' || ans=='Y');
}
void Flyod_Warshall::display()
{
 for(int i=0; i<n; i++)
 {
 cout<<endl;
 for(int j=0; j<n; j++)
 cout<<A[i][j]<<" ";
 }
}
void Flyod_Warshall::algo()
{
 cout<<"\nAdjacency Matrix of graph: ";
 this->display();
 for(int k=0; k<n; k++)
 {
 for(int i=0; i<n; i++)
 {
 for(int j=0; j<n; j++)
 {
 if((i!=j) && (A[i][j]!=0) && (A[i][j]>(A[i][k]+A[k][j])))
 A[i][j]=A[i][k]+A[k][j];
 }
 }
 if(k!=n-1)
 {
 cout<<"\nMatrix aŌer "<<k+1<<" iteraƟon: ";
 this->display();
 }
 }
 cout<<"\nFinal Matrix with shortest path b/w all pairs aŌer last iteraƟon is: ";
 this->display();
}
int main()
{
 Flyod_Warshall o;
 o.create();
 o.algo();
 cout<<"\n\tProgram Ends!";
 return 0;
} 
