#include"iostream.h"
#include"conio.h"
#include"stdlib.h"
int A[][9]=
{
{0,0,0,0,0,0,0,0,0},
{0,0,1,1,0,0,0,0,0},
{0,1,0,0,1,1,0,0,0},
{0,1,0,0,0,0,1,1,0},
{0,0,1,0,0,0,0,0,1},
{0,0,1,0,0,0,0,0,1},
{0,0,0,1,0,0,0,0,1},
{0,0,0,1,0,0,0,0,1},
{0,0,0,0,1,1,1,1,0}
};



class GRAPH
{
	private:
		//int n,A[10][10];
		int n;
		int VISITED[10];
	public:
		GRAPH(int);
		void READ_GRAPH();
		void SHOW_GRAPH();
		void DFS_R(int);
		void DFS_S(int);
		void BFS_Q(int);
};
GRAPH::GRAPH(int par)
{
	n=par;
	for(int i=1;i<=n;i++)
		VISITED[i]=0;
}
void GRAPH::READ_GRAPH()
{
 /*	cout<<"\nEnter Adj matrix : ";
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>A[i][j];
 */
}
void GRAPH::SHOW_GRAPH()
{
	cout<<endl;
	for(int i=1;i<=n;i++)
	{
		cout<<endl;
		for(int j=1;j<=n;j++)
			cout<<A[i][j]<<"  ";
	}
}
void GRAPH::DFS_R(int v)
{
	VISITED[v]=1;
	cout<<v<<" ";
	for(int i=1;i<=n;i++)
	{
		if(A[v][i]==1 && VISITED[i]==0)
			DFS_R(i);
	}

}
void GRAPH::DFS_S(int v)
{
	int STK[10],top=0;
	int u=v;
	VISITED[v]=1;
	do
	{
		cout<<u<<" ";
		for(int w=1;w<=n;w++)
		{       // adj      &&    not visited
			if(A[u][w]==1 && VISITED[w]==0)
			{
				top=top+1;
				STK[top]=w;
				VISITED[w]=1;
			}
		}
		if(top==0)
			break;
		else
		{
			u=STK[top];
			top=top-1;
		}
	} while(1);
}
void GRAPH::BFS_Q(int v)
{
	int QUE[10],rear=0,front=0;
	int u=v;
	VISITED[v]=1;
	do
	{
		cout<<u<<" ";
		for(int w=1;w<=n;w++)
		{       // adj      &&    not visited
			if(A[u][w]==1 && VISITED[w]==0)
			{
				rear=rear+1;
				QUE[rear]=w;
				if(front==0)
					front=1;
				VISITED[w]=1;
			}
		}
		if(front==0) // Q empty
			break;
		else
		{
			u=QUE[front];
			if(front==rear)
				front=0;
			else
				front=front+1;
		}
	} while(1);
}
void main()
{
	int n;
	clrscr();
	cout<<"\n Enter no of nodes : ";
	cin>>n;
	GRAPH obj(n);
	obj.READ_GRAPH();
	obj.SHOW_GRAPH();
	for(int i=1;i<=n;i++)
	{
		obj.DFS_R(i);
	}
	//obj.DFS_S(1);
	obj.BFS_Q(4);
	getch();
}

