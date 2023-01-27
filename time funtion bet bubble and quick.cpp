#include<iostream.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
void bubble(int a[],int n)
{int i,j,temp;
for(i=0;i<n-1;i++)
{ for(j=0;j<n-1;j++)
{ if(a[j]>a[j+1])
{ temp=a[j+1];
 a[j+1]=a[j];
 a[j]=temp;
}
}
}
}
void quick(int a[],int left,int right)
{ int i=left,j=right,mid;
mid=(a[i]+a[j])/2;
while(i<=j)
{ while(a[i]<mid)
i++;
while(a[j]>mid)
j--;
if(i<=j)
{ int temp;
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
void main()
{ int i; int b[4500];
clock_t sb,eb,sq,eq;
for(i=0;i<4500;i++)
b[i]=(4500);
sb=clock();
bubble(b,4500);
eb=clock();
cout<<"Buble"<<((eb-sb)/CLK_TCK)<<"\n";
sq=clock();
quick(b,1,2500);
eq=clock();
cout<<"Quick"<<((eq-sq)/CLK_TCK);
getch();
}
