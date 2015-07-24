#include "RSA.h"
#include "BigInt.h"
#include <cmath>
#include <cstdlib>
#include <limits>
#include <ctime>
#include <unistd.h>	
#define RAND_LIMIT32 0x7FFFFFFF
#include<iostream>

using namespace RSAUtil;

int main(int argc, char *arv[])
{
BigInt  cipher, deciphered,message;
BigInt pubkey, privatekey;
BigInt gnm;
unsigned long int *a;
unsigned long int arr[10];
a=&arr[0];
int nonprimearray[5]={31608,31628,31644,31648,31658};
int nonprimearry1[5]={31720,31742,31752,31762,31772};

message = int(((double)(std::rand())/RAND_MAX)*RAND_LIMIT32);
int count=0;
for(int i=0;i<5;i++)
{	
std::cout<<std::endl<<"Non Primes Selected for RSA"<<i+1<<" are: "<<nonprimearray[i]<<","<<nonprimearry1[i]<<std::endl;
RSA rsa(nonprimearray[i],nonprimearry1[i]);
pubkey= rsa.getPublicKey(); 
pubkey.toULong(a,4);
std::cout<<"Public Key : "<<*a<<std::endl;     
privatekey= rsa.getPrivateKey(); 
privatekey.toULong(a,4);
std::cout<<"Private Key : "<<*a<<std::endl;     

cipher = rsa.encrypt(message);
deciphered = rsa.decrypt(cipher);
if(message.toHexString()==deciphered.toHexString())
count++;
std::cout<<"message: "<<message.toHexString()<<"\tcipher: "<<cipher.toHexString()<<"\tdeciphered: "<<deciphered.toHexString()<<std::endl<<std::endl;   
}
if(count==0)
std::cout<<"In all 5 cases decryped message is not equal to original message"<<std::endl;
else
std::cout<<"RSA worked "<<count+1<<" times for not prime p and q values"<<std::endl;

}
