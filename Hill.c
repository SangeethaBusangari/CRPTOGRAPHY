
void hill(char* plaintext)
{
	int i,j,det,detinv,k,sum,input[1][2],output[1][2],q,x;
	char keyinv[2][2],key[2][2]={'l','i','d','h'};
	char cipher[max],decryplain[max];
	printf("plai text\n");
	for(i=0;i<strlen(plaintext);i++)
		printf("%c",plaintext[i]);
	printf("key is:\n");
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{

			key[i][j]=(int)((key[i][j])-97);
			printf("%d\t",key[i][j]);

		}
		printf("\n");
	}
	det=(key[0][0]*key[1][1]-key[0][1]*key[1][0]);
	det=det%26;
	if(det<0)
	det=det+26;
	printf("%d\n",det);
	for(i=2;i<=det;i++)
	{
		if((det%i==0)&&(26%i==0))
		{
			printf("gcd of det and 26 is not 1");
			exit(0);
		}
	}
	for(i=1;i<26;i++)
	{
		if((i*det)%26==1)
		{
			detinv=i;

			break;
		}

	}
	printf("%d\n",detinv);
	q=0;
	for(x=0;x<strlen(plaintext);x=x+2)
	{
		input[0][0]=(int)plaintext[x]-97;
		input[0][1]=(int)plaintext[x+1]-97;
		for(i=0;i<1;i++)
		{
			for(j=0;j<2;j++)
			{
				sum=0;
				for(k=0;k<2;k++)
				{
					sum=sum+(input[i][k]*((int)key[k][j]));
				}
				sum=sum%26;
				cipher[q]=sum+97;
				q++;
			}
		}
	}
	printf("cipher\n");
	for(i=0;i<strlen(plaintext);i++)
	{
		printf("%c",cipher[i]);
	}

keyinv[0][0]=((int)key[1][1]);
keyinv[1][1]=((int)key[0][0]);
keyinv[0][1]=26-((int)key[0][1]);
keyinv[1][0]=26-((int)key[1][0]);
printf("inv matrix\n");
for(i=0;i<2;i++)
{
for(j=0;j<2;j++)
{
keyinv[i][j]=((detinv*keyinv[i][j])%26);
printf("%d\t",keyinv[i][j]);
}
printf("\n");
}
     q=0;
        for(x=0;x<strlen(plaintext);x=x+2)
        {
                output[0][0]=(int)cipher[x]-97;
                output[0][1]=(int)cipher[x+1]-97;
                for(i=0;i<1;i++)
                {
                        for(j=0;j<2;j++)
                        {
                                sum=0;
                                for(k=0;k<2;k++)
                                {
                                        sum=sum+(output[i][k]*((int)keyinv[k][j]));
                                }
                                sum=sum%26;
                                decryplain[q]=sum+97;
                                q++;
                        }
                }
        }
printf("dec plain text\n");
for(i=0;i<strlen(plaintext);i++)
{
printf("%c",decryplain[i]);
}
printf("\n");
}
