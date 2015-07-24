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
int primearray[5]={31607,31627,31643,31649,31657};
int primearry1[5]={31729,31741,31751,31769,31771};

message = int(((double)(std::rand())/RAND_MAX)*RAND_LIMIT32);

for(int i=0;i<5;i++)
{	
std::cout<<std::endl<<"Prime numbers Selected for RSA"<<i+1<<" are: "<<primearray[i]<<","<<primearry1[i]<<std::endl;
RSA rsa(primearray[i],primearry1[i]);
pubkey= rsa.getPublicKey(); 
pubkey.toULong(a,4);
std::cout<<"Public Key : "<<*a<<std::endl;     
privatekey= rsa.getPrivateKey(); 
privatekey.toULong(a,4);
std::cout<<"Private Key : "<<*a<<std::endl;     

cipher = rsa.encrypt(message);
deciphered = rsa.decrypt(cipher);
std::cout<<"message: "<<message.toHexString()<<"\tcipher: "<<cipher.toHexString()<<"\tdeciphered: "<<deciphered.toHexString()<<std::endl<<std::endl;     

}
}
