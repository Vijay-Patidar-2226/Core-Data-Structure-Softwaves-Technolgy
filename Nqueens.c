#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
void display(int x[4][4]);

bool isValid(int x[4][4],int r,int c)
{
int i,j;
for(i=r;i>=0;i--)//same column
{
if(x[i][c])
{
return false;
}

}

for(j=c;j>=0;j--)//same row
{
if(x[r][j])
{
return false;
}

}


for(i=r,j=c;i>=0 && j>=0;i--,j--)//left diagonal
{
if(x[i][j])
{
return false;
}



}


for(i=r,j=c;i>=0 && j<4;i--,j++)//right diagonal
{
if(x[i][j])
{
return false;
}
}

return true;

}





bool show(int x[4][4],int r)
{
	
if(r>=4)return true;	
int i,j;

for(j=0;j<4;j++)
{
	
if(isValid(x,r,j))	
{
	x[r][j]=1;
	display(x);
	
	
	if(show(x,r+1))return true;
	
	x[r][j]=0;
	display(x);
}
	
}	
	
	return false;
	
}


void display(int x[4][4])
{
	
	int i,j;
	
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			printf("%d ",x[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
void main()
{

int x[4][4]={0};
display(x);
show(x,0);
}