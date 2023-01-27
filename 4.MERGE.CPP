#include<stdio.h>
#include<iostream>
#include<conio.h>
using namespace std;

void Merge(int a[],int low,int mid,int high)
{
  int b[80];
  int h=low;
  int i=low;
  int j=mid+1;
  int k;

  while((h<=mid)&&(j<=high))
  {
    if ( a[h] <= a[j] )
    b[i++]=a[h++];

    else
    b[i++]=a[j++];
  }

  if(h>mid)

  for(k=j;k<=high;k++)
  {
    b[i++]=a[k];
  }
  else

  for(k=h;k<=mid;k++)
  {
    b[i++]=a[k];
  }

  for(k=low;k<=high;k++)
  a[k]=b[k];
}

  void Mergesort(int a[],int low,int high)
  {
    if (low<high)
    {
      int mid=(low+high)/2;
      Mergesort(a,low,mid);
      Mergesort(a,mid+1,high);
      Merge(a,low,mid,high);
    }

  }

  int main()
  {
    int n,a[100];

    cout<<"How Many elements U want to enter: ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
      cin>>a[i];
    }

    Mergesort(a,0,n-1);
    cout<<endl<<"\nAFTER Merge sort:............" ;

    for(int i=0;i<n;i++)
        cout<<" "<<a[i];
    return 0;
  }
