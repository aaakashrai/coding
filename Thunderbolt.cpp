#include <bits/stdc++.h>
using namespace std;


void dis(char **a,  int n, int m)
{
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    cout << a[i][j];
    cout << endl;
  }
}

bool check(char **a, int n, int m, int i, int j)
{
  return (a[i][j] == 'b' || a[i+1][j] == 'b' || a[i-1][j] == 'b' || a[i][j+1] == 'b' || a[i][j-1] == 'b' );
}

bool checki1(char **a, int n, int m, int i, int j, int *p)
{
  if(a[i][j] == 'b' || a[i+1][j] == 'b' || a[i-1][j] == 'b'){
    p-=2;
    return true;
  }
  return false;
}
bool checki2(char **a, int n, int m, int i, int j, int *p)
{
  if(a[i][j] == 'b' || a[i][j+1] == 'b' || a[i][j-1] == 'b'){
    p-=1;
    return true;
  }
  return false;
}

bool checkj1(char **a, int n, int m, int i, int j, int *p)
{
  if(a[i][j] == 'b' || a[i+1][j] == 'b' || a[i-1][j] == 'b'){
    p-=1;
    return true;
  }
  return false;
}

bool checkj2(char **a, int n, int m, int i, int j, int *p)
{
  if(a[i][j] == 'b' || a[i][j+1] == 'b' || a[i][j-1] == 'b'){
    p-=2;
    return true;
  }
  return false;
}



int cal(char **aa, int n, int m, int i, int j);

int main()
{
  int n,m;
  cin >> n >> m;
  char *a[n];
  for(int i=0;i<n;i++)
  {
    a[i]= new char[m];
  }
  for(int i=0;i<n;i++)
  for(int j=0;j<m;j++)
  cin >> a[i][j];
  int ans[2]= {1,1};
  for(int i=1;i<n-1;i++)
  for(int j=1;j<m-1;j++)
  {
    if(a[i][j]== 'G' && a[i+1][j]== 'G' && a[i-1][j]== 'G' && a[i][j+1]== 'G' && a[i][j-1]== 'G')
    {
      int p=(cal(a,n,m,i,j));
      {
        sort(ans,ans+2);
        if(ans[0]< p)
        ans[0]=p;
      }
    }
  }
  cout << ans[0]*ans[1];
}

int cal(char **aa, int n, int m, int i, int j)
{

  int p=1, p1=1;
  while((i+p) < n && (i-p) >-1 && (aa[i+p][j]=='G' && aa[i-p][j]=='G') )
  {
    if(check(aa, n, m, i+p, j) || check(aa, n, m, i-p, j) )
      {
        checki1(aa,n,m,i+p,j,p1);
        checki2(aa,n,m,i+p,j,p1);
        checki1(aa,n,m,i-p,j,p1);
        checki2(aa,n,m,i-p,j,p1);
      }
    p1++;
    p++;
  }
  int q=1, q1=1;
  while((j+q) < m && (j-q) > -1 && (aa[i][j+q]=='G' && aa[i][j-q]=='G') )
  {
    if(!check(aa, n, m, i, j+q) || !check(aa, n, m, i, j-q))
    {
      q1-=2;
      break;
    }
    q1++;
    q++;
  }
  int r=(p1>q1?q1:p1);
  int check =0;
  while(check<=r && i+check < n && i-check >-1 && j+check <m && j-check > -1)
  {
    //cout  << "here" << endl;
    aa[i+check][j]= 'b';
    aa[i-check][j]= 'b';
    aa[i][j+check]= 'b';
    aa[i][j-check]= 'b';
    check++;
  }
  r--;
  //cout << p1 << "  " <<q1 << "  " << i << "  " <<j << "  " << r << endl;
  return r*4 +1;
}
