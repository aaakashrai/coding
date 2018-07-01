#include <iostream>
using namespace std;
int partition(int A[], int p, int q)
{
	int i=p;
	int j=p;
	int check = A[q];
	for(;j<q;j++)
	{
		if(A[j] < check)
		{
			int temp= A[i];
			A[i]=A[j];
			A[j]= temp;
			i++;
		}
	}
	A[q]= A[i];
	A[i]= check;
	return i;
}
void quicksort(int A[], int p, int q)
{	
	if(p<q)
	{
		int r= partition(A,p,q);
		quicksort(A,p, r-1);
		quicksort(A,r+1,q);
	}
}
int main()
{
	int A[]= {2,5,88,34,26,17,82,222};
	quicksort(A,0,6);
	for(int i=0;i<8;i++)
	cout << A[i] << "  ";
	return 0;
}
