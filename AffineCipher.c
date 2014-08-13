#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define MAXSIZE 8
int main()
{
	char plain[80],cipher[80];
	int i,k,a,b,s,t,x,y,inverse[26];
	inverse[0]=0;
	inverse[1]=1;
	inverse[3]=9;
	inverse[5]=21;inverse[7]=15;
	inverse[9]=3;
	inverse[11]=19;
	inverse[15]=7;
	inverse[17]=23;
	inverse[19]=11;
	inverse[21]=5;
	inverse[23]=17;
	inverse[25]=25;
	printf("Encrypted function is (ax+b)mod 26\n");
	printf("Please Enter Plain text: \n");
	for(i=0;i<MAXSIZE;i++)
	{
		scanf("%c",&plain[i]);
	}
	printf("\n");
	printf("Enter a,b values\n");
	scanf("%d %d",&a,&b);
	if(a%2==0||a==13||a>25||b>25)
		printf("(a,b)=(%d %d) is invalid\n",a,b);
	else
	{
		s=inverse[a];
		t=(s*(26-b))%26;
	}
	for(k=0;k<MAXSIZE;k++)
	{
		x=(int)plain[k]-(int)'a';
		y=(a*x+b)%26;
		cipher[k]=(char)(y+65);
	}
	printf("cipher text is:\n");
	for(i=0;i<MAXSIZE;i++)
		printf("%c",cipher[i]);
	printf("\n");
	printf("Decipher:y=%2dx+%2d\n",s,t);
	for(k=0;k<MAXSIZE;k++)
	{
		y=(int)cipher[k]-(int)'A';
		x=(s*y+t)%26;
		plain[k]=((x==23)?' ':(char)(x+97));
	}
	printf("Decryipted message: \n");
	for(i=0;i<MAXSIZE;i++)
		printf("%c",plain[i]);
		printf("\n");
		printf("\n");

}

