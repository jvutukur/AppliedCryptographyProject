
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

#include "md5.h" 

// input : ./prog filename

char pass[4]; // 4 character password
int *pass_pointer, *temp;
int n, result, *temp;
MD5_CTX mdContext;  // needed to compute MD5


main(int argc, char *argv[])
{
char alphanum[]={"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"};


char pass[4];

int i=0,j=0,k=0,l=0;int a;

for(i=20;i<62;i++)
	{for(j=0;j<62;j++)
		{for(k=0;k<62;k++)
			{for(l=0;l<62;l++)

{
//05mb
//abcb4c31

pass[0]= alphanum[i];
pass[1]= alphanum[j];
pass[2]= alphanum[k];
pass[3]= alphanum[l];

//printf("%c%c%c%c\n",pass[0],pass[1],pass[2],pass[3]);




   pass_pointer = (int *) pass; // get an int pointer to the password store
   //*pass_pointer = 0; // all nulls in password field
   if (argc!= 1) {printf("Usage: No Arguments\n", argv[0]); exit(0);};
   pass_pointer = (int *) pass; // get an int pointer to the password store
  

   MD5Init(&mdContext);  // compute MD5 of password
   MD5Update(&mdContext, pass_pointer, 4);
   MD5Final(&mdContext);
   temp = (int *) &mdContext.digest[12]; 
   result = *temp; // result is 32 bits of MD5 -- there is a BUG here, oh well.
a = (int)result;
	//printf("hash:%d\n", a); // print a human readable version of hash (using hex conversion)
	//printf("hash:%d\n", result);	
	printf("%x\n", result);
// Note if you store hashes, do not use human readable HEX, 
// but write the integer to file, raw bits.

if( a==0x7e1d96fd )
{printf("FOUND!\n"); goto exit;}

			} //0x19fbc7c1
		}

	}
}

exit:
printf("xyz");


};

