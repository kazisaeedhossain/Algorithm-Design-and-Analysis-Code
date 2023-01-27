#include<iostream>
using namespace std;

int main()
{
    int a[1000],beg,end,i,n,mid,loc=0;
    cout<<"Enter number of data: ";
    cin>>n;
    cout<<"Enter sorted data set: "<<endl;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int data;
    cout<<"Enter item to search: ";
    cin>>data;
    beg = 1;
    end = n;

    while(beg<=end)
    {
        mid = (beg+end)/2;
        if(a[mid]==data)
        {
            loc = mid;
            cout<<"Data found at location: "<<loc<<endl;
            break;
        }
        else if(a[mid]<data)
            beg = mid + 1;
        else
            end = mid - 1;
    }
    if(loc==0)
        cout<<"Data not found"<<endl;



    return 0;
}
