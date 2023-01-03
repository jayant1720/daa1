#include <iostream.h>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>

class HEAPSORT
{
	private:
		int*A,n;
	public:
		HEAPSORT(int size);
		void SET_DATA();
		void ADJUST(int node, int n);
		void HEAPIFY();
		void DISPLAY();
		void HSORT();

};
//-------------------------
HEAPSORT :: HEAPSORT(int size)
{
	n = size;
	A= new int[n+1];
}
//-------------------------
void HEAPSORT :: SET_DATA()
{
	for(int i=1; i<=n; i++)
	{
		A[i] = random(100);
	}
}
//-------------------------
void HEAPSORT :: ADJUST(int node, int n)
{
	int j, item;
	j = 2*node;
	item = A[node];
	while(j<=n)
	{
		if(j < n && A[j] < A[j+1])
		{
			j = j + 1;
		}
		if(item>A[j])
			break;
		else
			A[j/2] = A[j];
		j = 2*j;
	}
	A[j/2] = item;
}
//-------------------------
void HEAPSORT :: HEAPIFY()
{
	for(int i= n/2; i>=1; i--)
	{
		ADJUST(i,n);
	}
}
//-------------------------
void HEAPSORT :: HSORT()
{
	HEAPIFY();
	for(int i = n; i>=2; i--)
	{
		int temp = A[1];
		A[1] = A[i];
		A[i] = temp;
		ADJUST(1,i-1);
	}
}
//-------------------------
void HEAPSORT :: DISPLAY()
{
	for(int i=1; i<=n; i++)
	{
		cout<<A[i]<<" ";
	}
}
//-------------------------
void main()
{
	clrscr();
	int size;
	cout<<"Enter the size of list: ";
	cin>>size;	// set the size for creating list; pass that value to constructor of HEAP;
	HEAPSORT heap(size);

	heap.SET_DATA();	// call this method to set elements in list;
	cout<<"\nElement before HEAPSORT: ";
	heap.DISPLAY();

	heap.HEAPIFY();
	heap.HSORT();
	cout<<"\nElements after HEAPSORT: ";
	heap.DISPLAY();


	getch();
}