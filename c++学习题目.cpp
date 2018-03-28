#include<iostream>
#include<stdlib.h>
using namespace std;
int main()
{	
	int search(int arrby[],int a,int b);
	int finally;
	int n,k;
	int *array;
	cout<<"please scanf n"<<endl; 
	cin>>n;
	cout<<"please scanf k"<<endl; 
	cin>>k;
	array=(int*)calloc(n,sizeof(int));//建立动态数组 
	for(int i=0,j=1;i<n;i++,j++)
	array[i]=j;
	finally=search(array,n,k);
	cout<<"the end is "<<finally<<endl;
	free(array);
return 0;	
}
int search(int arrby[],int a,int b)
{
	int d=1,e=0,g;
	for(int i=0;e<a-1;)//利用循环完成不断地寻找 
	{
		if(arrby[i]==0)
		{
			if(i==a-1)
			i=0;
			else
			i++;
		}
		else
		{
			if(d==b)
			{
				arrby[i]=0;
				d=1;
				e++;	
			}
			else
			{
				d++;
			}
			if(i==a-1)
			i=0;
			else
			i++;
		}
	}
	for(int i=0;i<a;i++)
	if(arrby[i]!=0)
	{
	g=arrby[i];
	break;
	}
return g;
}
