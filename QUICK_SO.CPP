#include<iostream.h>
#include<conio.h>

void QUICK_SORT(int *arr,int low,int high)
{
	int pivot,i,j,temp;
	if(low<high)
	{
		pivot=arr[low];
		i=low+1;
		j=high;
		while(i<j)
		{
			while(arr[i]<pivot && i<=high)
			   i++;
			while(arr[j]>pivot && j>=low)
			   j--;
			if(i<j)
			{
			   temp=arr[i];
			   arr[i]=arr[j];
			   arr[j]=temp;
			}
		}
		arr[low]= arr[j];
		arr[j]=pivot;
		QUICK_SORT(arr,low,j-1);
		QUICK_SORT(arr,j+1,high);
	}
}
void main()
{
	clrscr();
	int n,arr[10];
	cout<<"Enter size of an array"<<endl;
	cin>>n;
	cout<<"****Enter elements in an array****"<<endl;
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
	}
	QUICK_SORT(arr,1,n);
	cout<<"Array after sort"<<endl;
	for(i=1;i<=n;i++)
	{
		cout<<arr[i]<<" ";
	}
	getch();
}