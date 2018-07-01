#include <iostream>
using namespace std;

int count(int n)
{
int c=0;
  while(n!=0)
{
	c++;
	n= n/10;
}
//  cout <<c << endl;
  return c;
}



void radix(int *A, int n)
{
  int max= A[0];
  for(int i=0;i<n;i++)
{
 	if(max<A[i])
		max=A[i];
}
 int p= count(max);
//cout << max << "    ";
int B[n];
int C[n];
for(int i=0;i<n;i++)
	B[i]= A[i];
for(int i=0;i<p;i++)
{
	for(int j=0;j<n;j++)
		C[j]= B[j]%10;
	for(int j=0;j<n;j++)
		B[j]= B[j]/10;
	for(int j=0;j<n;j++)
	{
		for(int i=0;i<n-1;i++)
		{ 
	if(C[i]>C[i+1])
		{
			int t= C[i];
			C[i]= C[i+1];
			C[i+1]= t;
			t= B[i];
			B[i]= B[i+1];
			B[i+1]= t;
			t= A[i];
			A[i]= A[i+1];
			A[i+1]= t;

}
}
}
}
}

int main()
{
	int A[]= {3,97, 1258, 8, 42785,205,17};
	radix(A, 7);
       for(int i=0;i<7;i++)
		cout << A[i] << endl;


return 0;
}
