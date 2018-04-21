#include <bits/stdc++.h>
using namespace std;
//printing the subset
void print(int *c,int c_size)
{
	for(int i=0;i<c_size;i++)
		cout<<c[i]<<" ";
	cout<<"\n";
}
//generating all subsets for a particular subsequence
void subsets(int *b,int b_size,int *c,int c_size,int *v)
{
	if(c_size==b_size)
	{
		print(c,c_size);
		return;
	}
	for(int i=0;i<b_size;i++)
	{
		if(v[i]==0)
		{
			c[c_size]=b[i];
			v[i]=1;
			subsets(b,b_size,c,c_size+1,v);
			v[i]=0;//backtracking 2
		}
	}

}
//generating a subsequence
void subsequence(int *a,int *b,int idx,int b_size,int n)
{
	int *c=new int[b_size];
	int *v=new int[b_size];
	memset(v,sizeof(v),0);
	subsets(b,b_size,c,0,v);//function for generating a subsequence
	delete[] c,v;
	for(int i=idx;i<n;i++)
	{
		b[b_size]=a[i];
		subsequence(a,b,i+1,b_size+1,n);//automatic backtracking 1
	}
}

signed main()
{
	int *a,n,*b;
	cout<<"n?"<<"\n";
	cin>>n;
	a=new int[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	b=new int[n];
	subsets(a,b,0,0,n);
	return 0;
}
