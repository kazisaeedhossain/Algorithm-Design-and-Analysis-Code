#include<stdio.h>
#include<iostream>
#include<conio.h>
#define max 100
#define inf 1000
using namespace std;
int n;
int m[max][max],W[max][max];
void input_data()
{
  int i,j,x,y,w;
  cout<<"Enter the number of vertices: ";
  cin>>n;
  for(i=0;i<n;i++)
    for(j=0;j<n;j++)
        m[i][j]=inf;

  cout<<"input -1,-1,-1,-1 to stop inputting edges.\n";
  cout<<"Enter the value of x: ";cin>>x;
  cout<<"Enter the value of y: ";cin>>y;
  cout<<"Enter the value of w: ";cin>>w;

  while(!((x==-1)&&(y==-1)&&(w==-1)))
  {
	if((x<0)||(x>n)||(y<0)||(y>n))
        cout<<"Invalid node numbers given.Must be between 0 and n-1\n";
	else
        m[x][y]=w;
	cout<<"Enter the value of x: ";cin>>x;
	cout<<"Enter the value of y: ";cin>>y;
	cout<<"Enter the value of w: ";cin>>w;
  }
}

int min(int x,int y)
{
  if(x<y)
  return x;
  else
  return y;
}
void shortestpath()
{
    int i,j,k,x,y;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            W[i][j]=m[i][j];

      for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            for(k=0;k<n;k++)
                W[i][j]=min(W[i][j],W[i][k]+W[k][j]);
  cout<<"Enter source & destination node numders: (-1 -1 to exit)\n";
  cin>>x>>y;
  while((x!=-1)&&(y!=-1))
  {
	 if(W[x][y]==inf)

	  cout<<"No path.\n";
	  else
	  cout<<"Path length is: "<<W[x][y];
	  cin>>x>>y;

  }}
  int main()
  {
	int option;
	do
	{
	  cout<<"Graph manipulation program\n";
	  cout<<"----------------------------\n";
	  cout<<"Enter option: ";cin>>option;
	  cout<<"----------------------------\n";
	  switch(option)
	  {
		case 1: input_data();
				break;
		case 2: if(n!=0)
				shortestpath();
				break;
	  }
	  }while(option!=3);
	  return 0;

getch();
}


