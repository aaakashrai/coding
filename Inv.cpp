#include <bits/stdc++.h>
using namespace std;

int  merge(int A[], int B[], int  C[], int low, int high, int n)
{
	int c=0;
	int pos=0;
	int i=0,j=0;
	for(;i<low && j<high;)
	{
		if(B[i]<=C[j])
		{
			A[pos++]= B[i++];
		}
		else
		{
			A[pos++]= C[j++];
			c+= low-i;
		}
	}
	while(i<low)
	A[pos++]= B[i++];
	while(j<high)
	A[pos++]= C[j++];
	return c;
}


int sort(int A[], int n)
{

	if(n==1)
		return 0;
	int mid= n/2;
	int B[mid];
	int C[n-mid];
	int i=0;
	for(;i<mid;i++)
		B[i]= A[i];
	for(int j=0;j<n-mid;j++)
		C[j]=A[i++];
	return sort(B, mid) + sort(C, n-mid) + merge(A, B, C, mid, n-mid, n);
}


int midcheck(int A[], int pos, int max)
{
	if(pos >max)
		return 0;
	if(A[pos]>A[pos+1] && A[pos]<A[pos-1])
		return 2;
	return 0;
}
int check(int A[], int low, int high, int max)
{
	if(low==high)
		return 0;
	if(high > max || low <0)
		return 0;
	int mid= (low+ high)/2;
	return check(A, low, mid, max) + check(A, mid+1, high, max) + midcheck(A, mid, max);
	
}

int main()
{
	int A[]= {2,4,1,3,5};
	cout <<	sort(A,5)<< endl;
	for(int i=0;i<5;i++)
		cout << A[i] << "  " ;
}
