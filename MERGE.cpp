#include <iostream>
using namespace std;

void merge(int *A, int *R, int *L, int Rl, int Ll, int Al)
{
int k=0;
int i=0;
int j=0;
  while(i<Rl && j< Ll)
{
  if(R[i] < L[j])
{
A[k]= R[i];
i++;
}
else
{
A[k]= L[j];
j++;
}
k++;
}
while(i<Rl)
{
A[k++]= R[i++];
}
while(j<Ll)
A[k++]= L[j++];
}

void MERGE(int *A, int n)
{
if(n==1)
return;
 int R[n/2];
int k=0;
int L[n- n/2];
for(int i=0;i<n/2;i++)
{
R[i]=A[k++];
}
k=0;
for(int j=n/2; j<n;j++)
L[k++]=A[j];
MERGE(R, n/2);
MERGE(L, n- n/2);
merge(A, R, L, n/2, n- n/2, n); 
}



int main()
{
 int A[]= {57,288,4,2,1,4};
int n= sizeof(A)/ sizeof(A[0]);
MERGE(A, n);
cout << n << endl;
for(int i=0;i<n;i++)
{
cout << A[i] << "   ";
}
}
