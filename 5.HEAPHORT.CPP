//***********Heapsort**********//

#include<iostream.h>
#include<conio.h>
void heapify(int a[],int n);
void adjust(int a[],int i,int n);
void heapsort(int a[],int n)
{
  int t,i;
  heapify(a,n);
  for(i=n;i>=2;i--)
  {
	t=a[i];
	a[i]=a[1];
	a[1]=t;

	adjust(a,1,i-1);
  }
}

void heapify(int a[],int n)
{
  for(int i=n/2;i>=1;i--)
  adjust(a,i,n);
}
void adjust(int a[],int i,int n)
{
  int l,r,large,t;
  l=2*i;
  r=l+1;
  large=i;
  if((l<=n)&&(a[l]>a[i]))
  large=l;
  if((r<=n)&&(a[r]>a[large]))
  large=r;
  if(i!=large)
  {
	t=a[i];
	a[i]=a[large];
	a[large]=t;
	adjust(a,large,n);
  }
}

void main()
{
  clrscr();
  int n,a[20];
  cout<<"How many number you want: ";cin>>n;
  cout<<"Enter number: \n";
  for(int i=1;i<=n;i++)
  {
	cout<<i<<". ";
	cin>>a[i];
  }

  heapsort(a,n);
  cout<<"The Sorted list is:\n";
  for(i=1;i<=n;i++)
  cout<<"\t\t"<<a[i]<<"\n";

  getch();
}





