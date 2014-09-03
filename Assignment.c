/*
 * Decryption:Implementing Affine cipher,vignere cipher and Hill cipher
 * Team members:14MCMT05, 14MCMT40,14MCMT06,14MCMT51,14MCMT02,14MCMT32
 * DATE:01-09-2014
 * varsion:1.0
 * */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 5000
#include "af.c"
#include "Hill.c"
char plaintext[max];
void vigenere( char *plaintext);
int main(void)
{
        int choice,i,len,m;
	printf("Please Enter Plain text: \n");
	gets(plaintext);
        printf("\n-----Implementation of Various Ciphers-----\n\n");
        printf("MENU\n");
        printf("\n1.Affine Cipher\n2.Vigenere Cipher\n3.Hill Cipher");
        printf("\n\nSelect the cipher of your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
                case 1:affine(plaintext);
                       break;
                case 2:vigenere(plaintext);
                      break;
                case 3:hill(plaintext);
                       break;
                default:exit(0);
		
        } 
	return 0;
}
void encryption(char* key)
{ 
	int i,j,p,c;	
	for(i=0,j=0;i<strlen(plaintext);)
	{
		j=0;	
		while(j<strlen(key))
		{
			if(97<=plaintext[i]<=122)
			{
				if(plaintext[i]!='\0')
				{
					p=plaintext[i]-97;
					c=key[j]-97;
					p=(p+c)%26;
					plaintext[i]=p+97;
				} 
				else
					break;
			}
			else if(65<=plaintext[i]<=90)
			{ 
				if(plaintext[i]!='\0')
				{
					p=plaintext[i]-65;
					c=key[j]-65;
					p=(p+c)%26;
					plaintext[i]=p+65;
				}
				else
					break;
			}
			printf("%c",plaintext[i]);
			j++;
			i++;
		} 
	} 
	printf("\n");
}
void decryption(char *key)
{ 
	int i,j,p,c;	
	for(i=0,j=0;i<strlen(plaintext);)
	{
		j=0;	
		while(j<strlen(key))
		{
			if(97<=plaintext[i]<=122)
			{
				if(plaintext[i]!='\0')
				{
					p=plaintext[i]-97;
					p=p+26;
					c=key[j]-97;
					p=(p-c)%26;
					plaintext[i]=p+97;
				} 
				else
					break;
			}
			else if(65<=plaintext[i]<=90)
			{ 
				if(plaintext[i]!='\0')
				{
					p=plaintext[i]-65;
					p=p+26;
					c=key[j]-65;
					p=(p-c)%26;
					plaintext[i]=p+65;
				}
				else
					break;
			}
			printf("%c",plaintext[i]);
			j++;
			i++;
		} 
	} 
	printf("\n");
}


void vigenere(char *plaintext)
{       char key[50]={'c','i','p','h','e','r'};
	int ch;
	printf("\nThe encrypted code is:\n");
	encryption(key);
	printf("\nThe decrypted  code is:\n");
	decryption(key);  
}
