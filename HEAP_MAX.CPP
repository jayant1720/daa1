#include <iostream.h>
#include <conio.h>
#include <stdlib.h>

class HEAP_MAX
{
	private:
		int*A,n;
	public:
		HEAP_MAX(int size);
		void SET_DATA();
		void INSERT(int);
		void CREATE_HEAP();
		void DISPLAY();

};
//-------------------------
HEAP_MAX :: HEAP_MAX(int size)
{
	n = size;
	A= new int[n+1];
}
//-------------------------
void HEAP_MAX :: SET_DATA()
{
	for(int i=1; i<=n; i++)
	{
		A[i] = random(100);
	}
}
//-------------------------
void HEAP_MAX :: INSERT(int node)
{
	int j, i, item;
	j = node; i= node/2; item = A[node];
	while(i > 0 && A[i] < item)
	{
		A[j] = A[i];
		j=i;
		i=i/2;
	}
	A[j] = item;
}
//-------------------------
void HEAP_MAX :: CREATE_HEAP()
{
	for(int i= 2; i<=n; i++)
	{
		INSERT(i);
	}
}
//-------------------------
void HEAP_MAX :: DISPLAY(){
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
	HEAP_MAX heap(size);

	heap.SET_DATA();	// call this method to set elements in list;
	cout<<"\nElement before creating MAX_HEAP: ";
	heap.DISPLAY();

	heap.CREATE_HEAP();
	cout<<"\nElements after Creating MAX_HEAP: ";
	heap.DISPLAY();


	getch();
}