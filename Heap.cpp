#include <bits/stdc++.h>
using namespace std;
void Heapify(int A[], int i, int size)
{
	int pos = i;	
	int left= 2*i +1;
	int right = 2*i + 2;
        int largest = A[i];
	if(left <size && A[i]<A[left])
       	{
		pos = left;
		largest = A[left];
	}
	if(right < size && A[right]>largest)
	{
		pos = right;
	}
	if(pos != i)
	{
		int temp= A[i];
		A[i]= A[pos];
		A[pos]= temp;
		Heapify(A, pos, size);	
	}
}


int main()
{
	int A[] = {4,1,3,2,16,9,10,14,8,7};
	int n= sizeof(A)/sizeof(A[0]);
	for(int i=n/2-1;i>=0;i--)
	{
		Heapify(A, i, n);
	}
	for(int i=0;i<n;i++)
	{
		cout << A[i] << "  ";
	}
	cout << endl;
	for(int i=1;i<n;i++)
	{	
		int temp=A[n-i];
		A[n-i]= A[0];
		A[0]= temp;
		Heapify(A,0,n-i);
	}
	for(int i=0;i<n;i++)
	{
		cout << A[i] << "  ";
	}
	return 0;
}
