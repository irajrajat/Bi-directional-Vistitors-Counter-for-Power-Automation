#include<reg51.h>


sbit h=P1^6;		  //ENTRANCE GATE
sbit g=P1^7;		  //EXIT GATE
sbit r=P0^0;		  // MOTOR #1
sbit s=P0^2;		  // MOTOR #2
sbit t=P0^4;   		  // MOTOR #3
sbit u=P0^6; 		  // MOTOR #4
int m=0;
int n=0;
int a,b;			  //7 SEGMENT DISPLAY
int arr[10]={0x3F,0X06,0X5B,0X4F,0X66,0X6D,0X7D,0X07,0XFF,0X67};


void main()		 // MAIN PROGRAM STARTS
{
P2=0x3F;
P3=0x3F;
while(1)  // TO MAKE THE FUNCTION REPEAT FOREVER
{
P1=0xFF;   //INPUT PORT

// IF SOMEONE COMES INSIDE

if(h==0)             // IF ONE PERSON COMES IN
	 {
	 	if(n==99&&m==99)
		{
			P2=0x67;
			P3=0x67;
		}
			else
		{
			 m=m+1;		// INCREMENT OF M BY 1
			 n=n+1;		// INCREMENT OF N BY 1
			 a=m/10;
			 b=n%10;
			 P2=arr[a];
			 P3=arr[b];
		if(n==0)		// IF NOONE IS INSIDE
		{
			r=0;
			s=0;
			t=0;
			u=0;
		}
		else if(n>0&&n<=25)
		{
			r=1;
			s=0;
			t=0;
			u=0;
		}
		else if(n>25&&n<=50)
		{
			r=1;
			s=1;
			t=0;
			u=0;
		}
		else if(n>50&&n<=75)
		{
			r=1;		
			s=1;
			t=1;
			u=0;
		}
		else if(n>75&&n<=100)
		{
			r=1;
			s=1;
			t=1;
			u=1;
		}
		while(h==0);
		}
	}

			
// IF SOMEONE COMES OUT

if(g==0)
{
if(n==0&&m==0)
{
P2=0x3F;
P3=0x3F;
}
else
{
m=m-1;
n=n-1;
a=m/10;
b=n%10;
P2=arr[a];
P3=arr[b];
   if(n==0) // IF NO ONE IS INSIDE
   {
r=0;
			s=0;
			t=0;
			u=0;
		}
		else if(n>0&&n<=25)
		{
			r=1;
			s=0;
			t=0;
			u=0;
		}
		else if(n>25&&n<=50)
		{
			r=1;
			s=1;
			t=0;
			u=0;
		}
		else if(n>50&&n<=75)
		{
			r=1;		
			s=1;
			t=1;
			u=0;
		}
		else if(n>75&&n<=100)
		{
			r=1;
			s=1;
			t=1;
			u=1;
		}
while(g==0);
}

}
}
}


			
			
			
			
			
			
									


