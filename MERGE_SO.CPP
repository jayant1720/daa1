
Assignment No: 4.8
Title: Implementation of program for merge sort.
Roll No: 36
Name: MESHRAM DHANSHREE DHARMPAL
-------------------------------------------------------------------------

#include<iostream.h>
#include<conio.h>
int arr[10];
void MERGE(int low,int mid,int high)
{
	int i=low,j=mid+1,k=low;
	int brr[10];
	while(i<=mid && j<=high)
	{
		if(arr[i]<arr[j])
		{
		    brr[k]=arr[i];
		    i++;
		}
		else
		{
		    brr[k]=arr[j];
		    j++;
		}
		k++;
	}
	while(i<=mid)
	{
	    brr[k]=arr[i];
	    i++;
	    k++;
	}
	while(j<=high)
	{
	    brr[k]=arr[j];
	    j++;
	    k++;
	}
	for(k=low;k<=high;k++)
	{
	     arr[k]=brr[k];
	}
}
void MERGE_SORT(int low,int high)
{
      if(low!=high)
      {
	int mid=(low+high)/2;
	MERGE_SORT(low,mid);
	MERGE_SORT(mid+1,high);
	MERGE(low,mid,high);
      }
}
void main()
{
	clrscr();
	int n;
	cout<<"Enter size of an array"<<endl;
	cin>>n;
	cout<<"Enter elements into array"<<endl;
	for(int i=0;i<n;i++)
	{
	    cin>>arr[i];
	}
	MERGE_SORT(0,n-1);
	cout<<"After sort"<<endl;
	for(i=0;i<n;i++)
	{
	   cout<<arr[i]<<"\t";
	}
	getch();
}
