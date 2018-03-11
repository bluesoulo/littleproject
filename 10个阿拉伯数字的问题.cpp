
/*任意由10个阿拉伯数字组成的数，比他略大的那个数字。   */

#include<stdio.h>
int main()
{
	int a[10];
	for(int i=0;i<10;i++)
	scanf("%d",&a[i]);  
	int k,l,s,h;
	int t,b,m=9;
	while(1)
	{
	if(a[m]<a[m-1])
	m--;
	if(a[m]>a[m-1])
	break;
	}
	k=m;
	l=a[m]-a[m-1];
	for(;k<10;k++)
	{
		s=a[k]-a[m-1];
		if(s>0&&s<=l)
		{
			h=k;
			l=s;
		}
	}
	t=a[m-1];a[m-1]=a[h];a[h]=t;
	for(int i=m;i<9;i++)
	{
		
		for(int j=i,p=a[j]=a[i];j<=9;j++)
		{
			if(a[j]-a[i]<=p)
			{
				t=j;
				p=a[j]-a[i];
			}
		}
		b=a[i];a[i]=a[t];a[t]=b;	
	}
	for(int i=0;i<10;i++)
	printf("%5d",a[i]);
return 0;
}
