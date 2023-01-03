#include <iostream.h>
#include <conio.h>

float COST[7][7]=
{
{0,0,0,0,0,0,0},
{0,0,10,20,3,9999,9999},
{0,9999,9999,8,9999,4,9999},
{0,9999,9999,9999,9999,9999,9999},
{0,9999,6,9999,9999,2,9999},
{0,7,4,5,9999,9999,9999},
{0,9999,9999,9999,9999,2,9999},
};

class GRAPH
{
		int n;
		float DIST[10];
	public:
		GRAPH(int);
		void READ_GRAPH();
		void SHOW_GRAPH();
		void DIJKSTRA(int v);
		float MIN(float,float);
		void SHOW_PATH(int);

};

GRAPH::GRAPH(int para)
{
	n=para;
}

void GRAPH::READ_GRAPH()
{
	cout<<"\n Enter the cost adjacency matrix: ";
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>COST[i][j];
		}
	}
}
void GRAPH::SHOW_GRAPH()
{
	cout<<"\n Given graph is:\n ";
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cout<<COST[i][j]<<"\t";
		}
		cout<<endl;
	}
}
void GRAPH::DIJKSTRA(int v)
{
	int num, *S=new int[n+1];
	for(int i=1;i<=n;i++)
	{
		S[i]=0;
		DIST[i]=COST[v][i];
	}
	S[v]=1;
	DIST[v]=0;
	for(num=2;num<=n-1;num++)
	{
	int u=0;
	float min=9999;
	   // find u
	for(int w=1;w<=n;w++)
	   {
			if(S[w]==0 && DIST[w]<min)
			{
				min=DIST[w];
				u=w;
			}
		}
		S[u]=1;
		//for all w with S[w]=0
		for(w=1;w<=n;w++)
		{
			if(S[w]==0)
				DIST[w]=MIN(DIST[w],DIST[u]+COST[u][w]);
		}
	}
}
float GRAPH::MIN(float x, float y)
{
	if(x<y)
		return x;
	else
		return y;
}
void GRAPH::SHOW_PATH(int v)
{
	cout<<endl<<endl<<"Source\tDesti\tLength";
	for(int i=1;i<=n;i++)
		cout<<endl<<v<<"\t"<<i<<"\t"<<DIST[i];
}
void main()
{
	clrscr();
	int n,v;
	cout<<"\n Enter the number of vertices: ";
	cin>>n;
	GRAPH obj(n);
	cout<<"\n Enter source vertex :";
	cin>>v;
	obj.SHOW_GRAPH();
	obj.DIJKSTRA(v);

	obj.SHOW_PATH(v);
	getch();
}

