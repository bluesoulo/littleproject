#include<stdio.h>			//恕我愚钝，暂时无法用函数做出来这个效果 
#define j 5				/*更改你所需要的人数*/ 
#define a 3 				//更改每多少个人退出一个人 
int main()
{
	printf("你需要我从%d中的人帮你找到她\n",j);
	int search(int arr[],int d,int b);  	//声明这个函数	 
	int arr[j];					
	for(int i=0,q=1;i<j;i++,q++)		//做出从1到j 的数组 。 
	arr[i]=q;
	int z;		
	z=search(arr,j,a);
	printf("怎么感谢我？\n我帮你找到的是：%d，哈哈哈~",z);					//利用函数找出这个最后的值 
return 0;
}
int search(int arr[],int d,int b)		 
{
	int n=0;					/*把每一个需要退出的人对应的数组元素赋值为0，遇到0对应的数组元素时跳过这样即类似于将这个 
							数组元素删除，最后的结果一定是有j-1个元素为0，利用这个来作为结束循环的标志*/ 
	int m=0,k;
	for(int i=0;n<d-1;)							
	{
		if(arr[i]!=0)
		{
			m=m+1;				//利用m来计数来判断什么时候将元素赋值为0 。 
			if(m>=b)
			{
				m=0;
				arr[i]=0;
				n=n+1;	
			}	
			if(i==d-1)		//利用if这个步骤来保证这个数组成为一个圆。 
			i=0;
			else
			i=i+1;
		}
		else
		{
			if(i==j-1)
			i=0;
			else
			i=i+1;
		}
	}
	for(int i=0;i<=d-1;i++)			//找到最后的这个值，并将他返回到主函数之中。 
	{
		if(arr[i]!=0)
		k=arr[i];
	}
	return(k);
}
