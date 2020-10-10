#include<stdio.h>
#include<stdlib.h>
int n=1,m=1,x,y;
char cond;
char ch[3][3]={'_,"_,"_,"_,"_,"_,"_,"_,"_'};
void assign(int a)
{
	if(a==1)
	{x=2;y=0;
	}else if(a==2)
	{x=2;y=1;
	}else if(a==3)
	{x=2;y=2;
	}else if(a==4)
	{x=1;y=0;
	}else if(a==5)
    {x=1;y=1;
    }else if(a=6)
    {x=1;y=2;
	}else if(a==7)
	{x=0;y=0;
	}else if(a==8)
	{x=0;y=1;
	}else if(a==9)
	{x=0;y=2;
	}
	}
	void print()
	{
		system("cls");
		int i,j;
		for(i=0;i<3;i++)
		{for(j=0;j<3;j++)
		{printf("%c\t",ch[i][j]);
		}printf("\n\n");
		}
	}
int main()
{int i,j,k=1,l=1,p,c1,c2,c3,c4,c5,c6,c7,c8;
print();
repeat1:
{printf("\n First user enter the location:");
scanf("%d",&p);
assign(p);
ch[x][y]='X';
k++;
print();
if(k<=3)
goto repeat2;
else
goto repeat3;
}
repeat2:
	{printf("\nSecond user enter the location");
	scanf("%d",&p);
	assign(p);
	ch[x][y]='O';
	l++;
	print();
	if(l<=3)
	goto repeat1;
	}
	repeat3:
		{ int i=0,j=0,c1=0,c2=0,c3=0,c8=0;
		while(i<=2)
		{for(k=0;k<3;k++)
		{if(ch[i][k]='X')
		c1++;
		}
		if(c1==3)
		break;
		else
		{c1=0;
		i++;
		}
		}
		while(j<=2)
		{for(k=0;k<3;k++)
		{
			if(ch[k][j]=='X')
			c2++;
		}
		if(c2==3)
		break;
		else
		{c2=0;
		j++;
		}
		}
		
		for(i=0;i<3;i++)
		if(ch[i][j]=='X')
		c3++;
		
		for(i=0;i<3;i++)
		for(j=0;j<3;j++)
		if( (i+j)==2 && ch[i][j]=='X')
		c8++;
		if( (c1==3)|| (c2==3) || (c3==3) || (c8==3))
		{printf("\n\tFirst user win");
		goto skip;
		}
		else{
			if(m<=2)
        goto repeat4;
		else
		goto repeat7;
				}
		}
		repeat4:
			{n++;
			printf("\nSecond user enter the location:");
			scanf("%d",&p);
			assign(p);
			ch[x][y]=='O';
			print();
			goto repeat5;
			}
			repeat5:
			{int i=0;j=0;c4=0;c5=0;c6=0;c7=0;
			while(i<=2)
			{for(k=0;k<3;k++)
			{if(ch[i][k]=='O')
			c4++;
			}
			
			if(c4==3)
			break;
			else
			{
				c4=0;
				i++;
			}
			}
			while(j<=2)
			{for(k=0;k<3;k++)
			{if(ch[k][j]=='O')
			c5++;
			}
			if(c5==3)
			break;
			else
			{c5=0;
			j++;
			}
			}
			for(i=0;i<3;i++)
			for(j=0;j<3;j++)
			if((i+j)==2 &&ch[i][j]=='O')
			c7++;
			if((c4==3)||(c5==3)||(c6==3)||(c7==3))
			{printf("\n\tsecond user win");
			goto skip;
			}
			else
			{if(n<=2)
			goto repeat6;
			else
			goto repeat7;
			}
		}

          repeat6:
          	{m++;
          	printf("\n First user enter the location:");
          	scanf("%d",&p);
          	assign(p);
          	ch[x][y]='X';
          	print();
          	goto repeat3;
			  }
			  repeat7:
			  	{printf("\n Firdt user enter the location:");
			  	scanf("%d",&p);
			  	assign(p);
			  	ch[x][y]='X';
			  	print();
			  	printf("The game is withdrawn!!!");
				  }
				  skip:
				  	return 0;
}
