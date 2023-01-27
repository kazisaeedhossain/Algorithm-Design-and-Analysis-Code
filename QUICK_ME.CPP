//This program sort the number of elements by using Quicksort Algorithm

#include<iostream>
#include<conio.h>
#include<time.h>
#include<stdlib.h>

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
void quick(int a[],int left,int right)
{
  int i=left,j=right,mid;
  mid=(a[i]+a[j])/2;
  while(i<=j)
  {
    while(a[i]<mid)
    i++;
    while(a[j]>mid)
    j--;
    if(i<=j)
    {
      int temp;
      temp=a[i];
      a[i]=a[j];
      a[j]=temp;
      i++;
      j--;
    }
  }

  if(left<j)
  quick(a,left,j);
  if(i<right)
  quick(a,i,right);
 }
 int main()
  {
    int i;
    int b[200];
    clock_t sb,eb,sq;
    randomize();
    for(i=0;i<200;i++)
    b[i]=random(200);
    sb=clock();

    Mergesort(b,1,200);
    eb=clock();

    cout<<"merge sort "<<((eb-sb)/CLK_TCK)<<"\n";

    sq=clock();
    quick(b,1,200);
    eq=clock();
    cout<<"Quick "<<((eq-sq)/CLK_TCK);
    getch();
  }
