#include<iostream.h>
#include<conio.h>

class MAT
{
	private:
		int A[3][3],B[3][3],C[3][3];
	public:
		MAT();
		void READ();
		void SHOW();
		void ST_MAT();
};

void MAT::MAT()
{
	for(int i=1;i<=2;i++)
	{
		for(int j=1;j<=2;j++)
		{
			C[i][j] = 0;
		}
	}
}

void MAT::READ()
{
	cout<<"\nEnter values for first matrix: ";
	for(int i=1;i<=2;i++)
	{
		for(int j=1;j<=2;j++)
		{
			cin>>A[i][j];
		}
	}
	cout<<"\nEnter values for second matrix: ";
	for(i=1;i<=2;i++)
	{
		for(int j=1;j<=2;j++)
		{
			cin>>B[i][j];
		}
	}
}

void MAT::SHOW()
{
	cout<<"\nThe first matrix: ";
	for(int i=1;i<=2;i++)
	{
		cout<<endl;
		for(int j=1;j<=2;j++)
		{
			cout<<A[i][j]<<"\t";
		}
	}

	cout<<"\nThe second matrix: ";
	for(i=1;i<=2;i++)
	{
		cout<<endl;
		for(int j=1;j<=2;j++)
		{
			cout<<B[i][j]<<"\t";
		}
	}
	cout<<"\nThe result matrix: ";
	for(i=1;i<=2;i++)
	{
		cout<<endl;
		for(int j=1;j<=2;j++)
		{
			cout<<C[i][j]<<"\t";
		}
	}
}
//------------------------------------------------------------------
void MAT:: ST_MAT()
{
	int P = (A[1][1] + A[2][2]) * (B[1][1] + B[2][2]) ;
	int Q = (A[2][1] + A[2][2]) * B[1][1];
	int R = A[1][1] * (B[1][2] - B[2][2]);
	int S = A[2][2] * (B[2][1] - B[1][1]);
	int T = (A[1][1] + A[1][2]) * B[2][2];
	int U = (A[2][1] - A[1][1]) * (B[1][1] + B[1][2]);
	int V = (A[1][2] - A[2][2]) * (B[2][1] + B[2][2]);

	C[1][1] = P + S - T + V;
	C[1][2] = R + T;
	C[2][1] = Q + S;
	C[2][2] = P + R - Q + U;
}
//-----------------------------------------------------------------
void main()
{
	clrscr();
	MAT obj;
	obj.READ();
	obj.ST_MAT();
	obj.SHOW();
	getch();
}


































