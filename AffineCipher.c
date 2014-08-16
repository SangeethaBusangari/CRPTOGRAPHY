/*
 * Decryption:Implementing Affine cipher
 * DATE:16-08-2014
 * varsion:1.0
 * */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define MAXSIZE 80
int main()
{
	char plain[MAXSIZE],cipher[MAXSIZE];
	int i,j,a,b,c,d,x,y,inverse[26],len;
	inverse[0]=0;
	inverse[1]=1;
	inverse[3]=9;
	inverse[5]=21;
	inverse[7]=15;
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
	gets(plain);

	len=strlen(plain);
	for(i=0;i<len;i++)
	{
		if(isalpha(plain[i]))//allowing only charecters to be the plain text.
			continue;
		else
		{
			printf("Ente only characters\n");
			return -1;
		}
	}
	printf("\n");
	printf("Enter a,b values\n");
	scanf("%d %d",&a,&b);
	if(a%2==0||a==13||a>25||b>25)//checking for valid a,b values.
	{
		printf("(a,b)=(%d %d) is invalid\n",a,b);
		exit(0);
	}
	else
	{
		c=inverse[a];
		d=(c*(26-b))%26;
	}
	printf("plain text is:\t");
	for(i=0;i<len;i++)
		printf("%c",plain[i]);
	printf("\nEncrypting...\n");
	for(j=0;j<len;j++)
	{
		x=(int)plain[j]-(int)'a';//assigning 0-25 values for entered chatecters
		y=(a*x+b)%26;//calculating encryption function
		cipher[j]=(char)(y+65);//converting cipher into uppercase
	}
	printf("cipher text is:\t");
	for(i=0;i<len;i++)
		printf("%c",cipher[i]);
	printf("\n");
	for(j=0;j<len;j++)
	{
		y=(int)cipher[j]-(int)'A';//assigning 0-25 values
		x=(c*y+d)%26;//Decryption function
		plain[j]=((char)(x+97));//converting to lowercase
	}
	printf("Decrypting...\n");
	printf("Decryipted text is:\t");
	for(i=0;i<len;i++)
		printf("%c",plain[i]);
		printf("\n");
}
