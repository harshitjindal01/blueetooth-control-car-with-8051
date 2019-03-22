#include<reg51.h>
sbit mot1p=P2^0;
sbit mot1n=P2^1;
sbit mot2p=P2^2;
sbit mot2n=P2^3;
void main()
{
    unsigned char x;
  	SCON=0X50;
	TMOD=0X20;
	TH1=-3;
	TR1=1;
	while(1)
	{
	while(RI==0);
	x=SBUF;
	RI=0;
	SBUF=x;
	while(TI==0);
	TI=0;
	if(x=='f')
	{
	  mot1p=1;
      mot1n=0;
      mot2p=1;
      mot2n=0;
	}
	if(x=='b')
	{
	 mot1p=0;
     mot1n=1;
     mot2p=0;
     mot2n=1;
	}
		if(x=='r')
	{
	 mot1p=0;
     mot1n=1;
     mot2p=1;
     mot2n=0;
	}
		if(x=='l')
	{
	 mot1p=1;
     mot1n=0;
     mot2p=0;
     mot2n=1;
    }
	    if(x=='s')
	{
	 mot1p=0;
     mot1n=0;
     mot2p=0;
     mot2n=0;
	 }
   }
}
