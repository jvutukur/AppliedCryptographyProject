
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

#include "md5.h" 

char pass[4],cpwd[4],hashstring[12]; 
int *pass_pointer, *temp;
int n, hash, *temp;
int first, second, third, fourth;
int one,two,three,four;
int i,j,flag,k,p,q,r,w,x,y,z;
int count,rowcount,valuecount;
int outfile;
int rand1, rand2,rand3,rand4;
char rowcountstring[4],space[3]="   ",newline[2]=" \n";
char *ipset="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
char *ipset2="aejlmAL12"; //9
char *ipset3="aowAOW1"; //7
char *ipset4="buvxBV2"; //7
char *ipset5="bdeuBEX12";//9


char *ipset6="ciuvwxyzABFHJKLMNOTVWXYZ018";
MD5_CTX mdContext;  // needed to compute MD5


void computehash()
{
   MD5Init(&mdContext);  // compute MD5 of password
   MD5Update(&mdContext, pass_pointer, 4);
   MD5Final(&mdContext);
   temp = (int *) &mdContext.digest[12]; 
   hash = *temp; // hash is 32 bits of MD5 -- there is a BUG here, oh well.
//printf("%x\n",hash);   
}

void computehashrev()
{
   
x=0;
y=0;
   fourth = hash%4096 ;
   if(fourth<0)   	   
    fourth = hash%4096 - 0xfffff000; 
//printf("fourth %x \n",fourth);

   third = (hash/4096)%4096;
   if(third<0)
      third = (hash/4096)%4096 -0xfffff000-1;
     // printf("third %x \n\n",third);
three=fourth/62;
four=fourth%62;
one=third/62;
two=third%62;

  // second =(hash/65536)%256;
   //if(second<0)
   //second =(hash/65536)%256 -0xffffff00-1;
   
  // first = (hash/16777216)%256 ;
   //if(first<0)
   //first = (hash/16777216)%256 -0xffffff00-1;
   
//   one = first%62;
  // two = second%62;
   //three =third%62;
   //four = fourth%62;
   
//   printf("fourth %x -- %d -- %d\n",fourth,three,four);
   //printf("%x-- %d\n", second,two);
  // printf("third %x-- %d -- %d\n", third,one,two);
   //printf("%x-- %d\n",fourth,four);
   cpwd[0]=ipset[one];
   cpwd[1]=ipset[two];
   cpwd[2]=ipset[three];
   cpwd[3]=ipset[four];           
   cpwd[4]='\0';
   pass_pointer=cpwd;  
   
   
}
main(int argc, char *argv[])
{
   pass_pointer = (int *) pass; // get an int pointer to the password store
   *pass_pointer = 0; // all nulls in password field
   pass_pointer = (int *) pass; // get an int pointer to the password store
   //read(0, pass_pointer, 4); // get 4 bytes, ignore extra   
  //printf("%s \n",ipset); 
   
//   pass_pointer="aaaa";
   
//outfile = open ("table.txt", O_RDWR|O_CREAT|O_TRUNC, 0700);
//if (outfile<0) { printf("Cannot access file: output\n"); exit(0); }
rowcount=0;

flag=0;
valuecount=0;
for (i=0;i<9*7*7*9;i++)
{
	rowcount++;
	count=0;
	k=(i/(9*7*7))%9;
	p=(i/63)%7;
	q=(i/9)%7;
	r=i%9;

   cpwd[0]=ipset2[k];
   cpwd[1]=ipset3[p];
   cpwd[2]=ipset4[q];
   cpwd[3]=ipset5[r];
   pass_pointer=cpwd;
   printf("pwd for %d row is %s\n",rowcount,pass_pointer);	//sprintf(rowcountstring, "%d", rowcount);
	//write(outfile, &rowcountstring, sizeof(rowcountstring));
	
//write(outfile, &space, sizeof(space));
    
   // write(outfile, &cpwd, sizeof(cpwd));
//	write(outfile, &space, sizeof(space));
	
for(j=0;j<62*62;j++)
{

   count++;
   //printf("\nIteration %d\n",count);	
  // printf("pwd for iteration %d in %d row is %s\n",count,rowcount,pass_pointer);
   computehash();
   //||hash==0xb362796a
  // printf("hash value is %x\n\n", hash); // print a human readable version of hash (using hex conversion)   
   //hash==0x19fbc7c1||hash==0x7e1d96fd||hash==0x88df723c||hash=3974cffc||hash=0x8f6bb61b||hash=0x8e564270||hash=0x655ca818||hash=0x58712b2b||hash=0x97e75d32||hash=0x14928501
   if(hash==0x19fbc7c1||hash==0x7e1d96fd||hash==0x88df723c||hash==0x3974cffc||hash==0x8f6bb61b||hash==0x8e564270||hash==0x655ca818||hash==0x58712b2b||hash==0x97e75d32||hash==0x14928501)//0xe234b2fe
   {
   	printf("found in line %d colum %d \n", rowcount,count);
valuecount++;
   	//flag=1;
//   	break;
   }
   computehashrev();  
          
   //printf("hash rev calculated is %s \n",pass_pointer);
   //sprintf(hashstring, "%x", hash);
  // sprintf(hashstring, "%d", hash);
}
if(flag==1)
{
	printf("rowcount is %d ",rowcount);
 printf("count is %d ",count);
 printf("password is %s",cpwd);
//break;
}
//write(outfile, &hashstring, sizeof(hashstring));
//write(outfile, &newline, sizeof(newline));
}    
//close(outfile); 
 
// Note if you store hashes, do not use human readable HEX, 
// but write the integer to file, raw bits.
 
 printf(" found %d times",valuecount);
 
};


