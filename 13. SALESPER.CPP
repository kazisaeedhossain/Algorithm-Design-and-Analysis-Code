#include<iostream.h>
#include<stdio.h>
#define INF 25000
#define N 15
#define R 60

/*******************Global Variable********************/
long s, V, cost[N][N], src, g[N][R][N], i[N], T[N], c,k;

/*******************Input Function********************/
void dataInput()
{
	long x,y, len;

	cout<<"Enter number of Vertices : ";
	cin>>V;

	for(x=1;x<=V;x++)			// [ elements of cost[][] is
	{	for(y=1;y<=V;y++)		//   initializing by Infinite ]
		{
			cost[x][y]=INF;
			cost[y][x]=INF;
		}
	}
	cout<<"\nEnter edges and costs:-\n";
	cout<<" * Vertex must be started from 1.\n";
	cout<<" * Enter negative edge to quit.\n";
	do
	{	cout<<"Enter edge : ";
		cin>>x>>y;
		if(x<0 || y<0) break;
		cout<<"Enter edge cost : ";
		cin>>len;
		cost[x][y]=len;
	}while(1);
	cout<<"Enter Source : ";
	cin>>src;
}
/******Travering Salesperson Promlem Functions*****/

long subTourCost()
{
	long j,k,t=s-1,x;

	for(j=1,k=1;T[k+1]!=g[t][j][k];j++);  // find the frist position of T[]
	k++;
	while(k<=t)					// finding the previous SubTour cost of T[]
	{
		if(T[k+1]==g[t][j][k])
		{
			for(x=k+1; x<=t&&T[x+1]==g[t][j][x]; x++);
			x>t? k=x: j++;
		}
		else j++;
	}
	g[s][c][0]=g[s][c][s+1]=cost[T[1]][T[2]]+g[t][j][0];
								// calc cost of the sub tour.
	return j;
}
void Min()
{
	long j, p,min=g[s][c-1][0]+1;
	for(j=c-1;(c-j)<s;j--)
	{
		if(g[s][j][0]<min)
		{	min=g[s][j][0]; p=j; }
	}
	g[s][j+1][0]=min;
	g[s][j+1][s+2]=p;
}
void genSubTourPermutation()
{
	long t,j,k;

	T[1]=i[1];
	for(j=2;j<=s;j++)
	{	t=2;
		T[t++]=i[j];
		for(k=2;k<=s;k++)
		{
			if(k==j) continue;
			T[t++]=i[k];
		}
		for(k=1;k<=s;k++) g[s][c][k]=T[k];	// storing sub tour
		subTourCost();
		c++;
	}
	Min();
}
void initialSubTours()
{
	long j,k;
	for(j=c=1;j<=V;j++)
	{
		g[1][j][1]=j; g[1][j][2]=src;	// for step 1
		g[1][j][0]=cost[j][src];		// needed only when V=2

		for(k=1;k<=V;k++)
		{
			g[2][c][1]=j; g[2][c][2]=k;		// for step 2
			g[2][c][0]=cost[j][k]+cost[k][src];
			c++;
		}
	}
}
long isItValidNode()
{
	long j;
	if(i[k]==src||(k>2&&i[k]<=i[k-1]))
		return 0;
	if(i[k]>V)
	{	k--; return 0; }
	for(j=1;j<k;j++)
		if(i[k]==i[j])
			return 0;
	return 1;				// No invalidity found.
}
void endingSubTour()
{
	i[1]=src; c=2;
	for(k=1;k<=V;k++)		// store sub tour
	{	if(k==src) continue;
		i[c++]=k;
	}
	c=1;
	genSubTourPermutation();
	//g[s][0][0]=c-1;
}
void optimalTour()
{
	initialSubTours();
	for(s=3;s<V;s++)
	{
		c=1;
		for(k=1;k<=s;k++) i[k]=1;		// initializing subTour's nodes
		k=1;
		while(i[1]<=V)
		{
			if(isItValidNode()==1)	// i.e. node i[k]
			{
				k++;
				k>2? i[k]=i[k-1]+1: i[k]=1;
				if(k>s)
				{
					genSubTourPermutation();
					k--; i[k]++;
				}
			}
			else i[k]++;
		}//while loop
		g[s][0][0]=c-1;
	}
	if(V==2) s=2;
	endingSubTour();
}
void pickAndShow_TheOptimalTour()
{
	cout<<"\n\nThe Shortest Tour cost : "<<g[s][1][0]<<"\n";
	cout<<"The Shortest Tour is : "<<src<<" ";

	c=k=g[s][1][s+2];
	for(; s>2; s--)
	{
		cout<<g[s][c][2]<<" ";
		for(k=1;k<=s;k++) T[k]=g[s][c][k];
		k=c=subTourCost();
		c=g[s-1][c][s+1];
	}
	cout<<g[s][k][2]<<" "<<src<<"\n\n\n";
}
/**********************Main Function**********************/
void main()
{
	//freopen("c:\\tc\\Bin\\salesper.txt","r",stdin);
	long q;

	cout<<"  *** Traveling Salesperson Problem ***\n";
	do
	{	cout<<"\n 1. Input data\n";
		cout<<  " 2. Evaluate Optimal Tour\n";
		cout<<  " 3. Quit\n";
		cout<<"Enter your choice : ";
		cin>>q;

		if(q==1) dataInput();
		else if(q==2)
		{
			optimalTour();
			pickAndShow_TheOptimalTour();

		}
	}while(q!=3);
}