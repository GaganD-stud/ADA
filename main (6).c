#include<stdio.h>
#include<conio.h>

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

int search(int a[],int n,int mobile)
{
	for(int i=0;i<n;i++)
	{
		if(a[i]==mobile)
			return i+1;
	}
	return -1;
}

int findmobile(int a[], int dir[],int n)
{
	int mobile=0;
	int mobile_prev=0;
	for(int i=0;i<n;i++)
	{
		if(dir[a[i]-1]==0 && i!=0)
		{
			if(a[i]>a[i-1] && a[i]>mobile_prev)
			{
				mobile=a[i];
				mobile_prev=mobile;
			}
		}
		if(dir[a[i]-1]==1 && i!=n-1)
		{
			if(a[i]>a[i+1] && a[i]>mobile_prev)
			{
				mobile=a[i];
				mobile_prev=mobile;
			}
		}
	}
	if(mobile_prev==0 && mobile==0)
		return 0;
	else
		return mobile;
}

void printperm(int a[],int dir[], int n)
{
	int mobile=findmobile(a,dir,n);
	int pos=search(a,n,mobile);
	if(dir[a[pos-1]-1]==0)
		swap(&a[pos-1],&a[pos-2]);
	else
		swap(&a[pos-1],&a[pos]);
	for(int i=0;i<n;i++)
	{
		if(a[i]>mobile)
		{
			if(dir[a[i]-1]==0)
				dir[a[i]-1]=1;
			else
				dir[a[i]-1]=0;
		}
	}
	for(int i=0;i<n;i++)
		printf("%d\t",a[i]);
	printf("\n");
}
int fact(int n)
{
	int f=1;
	for(int i=2;i<=n;i++)
		f=f*i;
	return f;
}
int main()
{
	int n;
	printf("Enter n value\n");
	scanf("%d",&n);
	int dir[n],a[n];
	for(int i=0;i<n;i++)
	{
		dir[i]=0;
		a[i]=i+1;
		printf("%d\t",a[i]);
	}
	printf("\n");
	for(int i=1;i<fact(n);i++)
		printperm(a,dir,n);
	return 0;
}