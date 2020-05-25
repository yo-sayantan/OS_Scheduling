#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int n,top=-1,m,rqc=0,buffc=0,q,pct=0,z;
int clk=-1,b=0;
int arr[20][10],buffer[2][1000];
int rq[2][1000],ioex[1000],allex[1000], flag[1000], buffx[1000];

typedef struct proc
{
	int no;
	int burst;
}p;

int getdata()
{
	int i,j;
	for(i=1;i<=n;i++)
		for(j=1;j<=10;j++)
			arr[i][j]=0;
	for(i=1;i<=n;i++)
		arr[i][0]=i;
	printf("\nEnter the Arrival Times:\n");
	for(i=1;i<=n;i++)
		scanf("%d",&arr[i][1]);
	printf("Enter the 1st CPU Burst Times:\n");
	for(i=1;i<=n;i++)
		scanf("%d",&arr[i][2]);
	printf("Enter the I/O Burst Times:\n");
	for(i=1;i<=n;i++)
		scanf("%d",&arr[i][3]);
	printf("Enter the 2nd CPU Burst Times:\n");
	for(i=1;i<=n;i++)
		scanf("%d",&arr[i][4]);
}

void sortrq()
{
	int i,j;
	for(i=0;i<top-1;i++)
	{
		for(j=1;j<=top-i-1;j++)
		{
			if(arr[rq[0][j]][8]>arr[rq[0][j+1]][8])
			{
				rq[0][j]^=rq[0][j+1]^=rq[0][j]^=rq[0][j+1];
				rq[1][j]^=rq[1][j+1]^=rq[1][j]^=rq[1][j+1];
			}
		}
	}
}

void push(int x,int y)
{
	int i=0,j;
	if(rq[0][1]==-1)
	{
		rq[0][1]=x;
		rq[1][1]=y;
		top=1;
	}
	else
	{
		top++;
		for(j=rqc;j>=1;j--)
		{
			rq[0][j+1]=rq[0][j];		//for name in 0th row
			rq[1][j+1]=rq[1][j];		//for burst in 1st row
		}
		rq[0][1]=x;
		rq[1][1]=y;	
	}	
	rqc++;
	if(top>1)
		sortrq();
}

int pop()
{
	int i=0,x;
	if(top>0)
	{
		x=rq[0][top];
		z=rq[1][top];
		top--;
	}
	else if(top<=0);
	return x;
}

void pushbuff(int x)
{
	int i=0,j;
	buffc++;
	buffx[buffc]=x;
	if(x==buffer[0][b]);
	if(b<=0)
	{
		buffer[0][1]=x;
		buffer[1][1]=arr[x][3];
		b=1;
	}
	else if(b>0)
	{
		b++;
		for(j=b;j>=1;j--)
		{
			buffer[0][j+1]=buffer[0][j];
			buffer[1][j+1]=buffer[1][j];
		}
		buffer[0][1]=x;
		buffer[1][1]=arr[x][3];
	}
	
	for(i=1;i<=n-1 && b>1;i++)
	{
		for(j=1;j<=n-i-1;j++)
		{
			if(buffer[1][j]<buffer[1][j+1])
			{
				buffer[0][j]^=buffer[0][j+1]^=buffer[0][j]^=buffer[0][j+1];
				buffer[1][j]^=buffer[1][j+1]^=buffer[1][j]^=buffer[1][j+1];
			}
		}
	}
}

int popbuff()
{
	int x;
	if(b>0)
	{
		x=buffer[0][b];
		b--;
	}
	else;
	return x;
}

int max()
{
	int i,m=0;
	for(i=1;i<=n;i++)
		m+=arr[i][2]+arr[i][3]+arr[i][4];
	return m;
}

void avg()
{
	float a=0,b=0;
	int i;
	for(i=1;i<=n;i++)
	{
		a+=arr[i][5];
		b+=arr[i][6];
	}
	a=a/n;
	b=b/n;
	printf("Avg. WT = %.2f\nAvg. TAT = %.2f\n",a,b);
}

void flagging()
{
	int i,j;
	for(i=1;i<100;i++)
		flag[i]=0;
	for(i=1;i<=n;i++)
		for(j=2;j<=4;j++)
			if(arr[i][j]>0)
				flag[i]+=1;
}

void display()
{
	int i,j;
	printf("\n");
	for(i=0;i<=80;i++)
		printf("-");
	printf("\nThe output is:\n");
	printf("Process\tAT\tBT-1\tI/OT\tBT-2\tPrt\tWT\tTAT\tCT\n");
	for(i=1;i<=n;i++)
	{
		printf("P-%d\t",arr[i][0]);
		for(j=1;j<=4;j++)
			printf("%d\t", arr[i][j]);
		printf("%d\t",arr[i][8]);
		for(j=5;j<=7;j++)
			printf("%d\t", arr[i][j]);
		printf("\n");
	}
	printf("\n");
	for(i=0;i<=80;i++)
		printf("-");
	printf("\n\nThe ready queue is:\n");
	for(i=rqc;i>=1;i--)
		if(rq[0][i]!=0 && rq[0][i]!=-1)
			printf("P-%d:%d  ",rq[0][i],rq[1][i]);
	printf("\n\nThe execution array is:\n");
	for(i=0;i<=1000;i++)
	{
		if(allex[i]>0 && allex[i]!=allex[i-1])
			printf("%d  P-%d  ",i, allex[i]);
		else if(allex[i]==-4 && allex[i]!=allex[i-1])
			printf("%d  --  ",i);
	}
	printf("\n\nThe buffer is:\n");
	for(i=1;i<=buffc;i++)
		if(buffx[i]!=-1)
			printf("P-%d  ", buffx[i]);
	printf("\n");
	avg();
}

int check()
{
	int i;
	for(i=0;i<=n;i++)
		if(flag[i]>0)
			return 1;
	return 0;
}

void pr_pre()
{
	int i,j,t,f,pc=0;
	p pro;j=4;
	printf("\nEnter the priorities of each process: \n");
	for(i=1;i<=n;i++)
		scanf("%d",&arr[i][8]);
	m=max();
	
	for(i=1;i<=m;i++)
	{
		rq[0][i]=-1;
		rq[1][i]=-1;
		buffer[0][i]=-1;
		buffer[1][i]=-1;
		buffx[i]=-1;
	}
	
	flagging();
	clk=0;
	push(arr[1][0],arr[1][2]);
	clk=arr[rq[0][top]][1];
	
	for(j=2;j<=n;j++)
		if(arr[j][1]==clk)
			push(arr[j][0],arr[j][2]);
			
	pc++;
	
	if(top>0)
	{
		pro.no=pop();
		flag[pro.no]--;
		pro.burst=z;
		allex[clk]=pro.no;
	}

	clk++;	
	while(clk<=m+1)
	{
		for(j=2;j<=n;j++)
			if(arr[j][1]==clk)
				push(arr[j][0],arr[j][2]);
		
		if(top>0)
			for(i=1;i<=top;i++)
				arr[rq[0][i]][5]++;
		
		if(pro.burst>1)
		{
			pro.burst--;
			allex[clk]=pro.no;
			push(pro.no,pro.burst);
			flag[pro.no]++;
			pro.burst=0;	
		}
		
		if(pro.burst==1)
		{
			pro.burst--;
			allex[clk]=pro.no;
			pro.burst=0;	
		}

		if(b>0)
		{
			for(i=b;i>=1;i--)
			{
				if(buffer[1][i]>0)
					buffer[1][i]--;
				if(buffer[1][i]==0)
				{
					f=popbuff();
					push(f,arr[f][4]);
				}
			}
		}
		
		if(pro.burst==0)
		{
			int x=check();
			if(top>0)
			{			
				if(flag[pro.no]==2)
				{
					flag[pro.no]--;
					pushbuff(pro.no);
				}
				
				if(flag[pro.no]==0)
				{
					arr[pro.no][7]=clk;
					allex[clk]=pro.no;
				}
				
				if(flag[rq[0][top]]==3)
				{
					pro.no=pop();
					flag[pro.no]--;
					pro.burst=z;
					allex[clk]=pro.no;
				}	
				
				else if(flag[rq[0][top]]==1)
				{
					pro.no=pop();
					pro.burst=z;
					flag[pro.no]--;
					allex[clk]=pro.no;
				}
				
				if(x==0)
					break;
			}
			
			else if(top<=0)
			{
				if(flag[pro.no]==2)
				{
					flag[pro.no]--;
					pushbuff(pro.no);
					allex[clk]=pro.no;
				}
				
				else if(flag[pro.no]==0)
				{
					arr[pro.no][7]=clk;
					allex[clk]=pro.no;
				}
				
				else if(flag[pro.no]==1)
				{
					flag[pro.no]--;
					allex[clk]=pro.no;
				}
				
				pro.no=0;
				pro.burst=0;
				allex[clk]=-4;
				
				if(x==0)
					break;
			}
		}

		if(flag[rq[1]==0])
			break;
			
		clk++;
	}
	
	for(i=1;i<=n;i++)
		arr[i][6]=arr[i][7]-arr[i][1];
	
	display();	
}

int main()
{
	int i;
	printf("\n");
	for(i=0;i<=80;i++)
		printf("-");
	printf("\nEnter the number of processes: ");
	scanf("%d",&n);
	
	getdata();
	pr_pre();

	printf("\n");
	for(i=0;i<=40;i++)
		printf("-x");	
	printf("\n");
	
	char key = getch();
    if(key=='T' || key=='t')
        exit(0);
        
	return 0;
}
