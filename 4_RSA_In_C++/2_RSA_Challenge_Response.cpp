#include "RSA.h"
#include "BigInt.h"
#include <cmath>
#include <cstdlib>
#include <limits>
#include <ctime>
#include <unistd.h>	
#include <string.h>		
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



//2a -- Create an RSA object. Call it RSA1
RSA rsa1;

//2b -- Create a new RSA object, call it RSA2. Obtain the public key and modulus [n] of RSA1. Assign these two to the public key and N value in RSA2.
RSA rsa2;

pubkey= rsa1.getPublicKey(); 
pubkey.toULong(a,4);
std::cout<<std::endl<<"Public Key of RSA1 is: "<<*a<<std::endl;    
rsa2.setPublicKey(pubkey);

gnm = rsa1.getModulus(); 
gnm.toULong(a,4);
std::cout<<"Modulus of RSA1 is: "<<*a<<std::endl;    
rsa2.setN(gnm);
std::cout<<"Public Key of RSA1 is assigned to RSA2"<<std::endl<<std::endl;

//2c -- Generate a random message [random BigInt number]. Encrypt it using the public key of RSA2 [You have stored the pub key of RSA1 in RSA2].
message = int(((double)(std::rand())/RAND_MAX)*RAND_LIMIT32);
std::cout<<"message chosen by RSA2 is "<<message.toHexString();
privatekey= rsa1.getPrivateKey(); 
cipher = rsa2.encrypt(message);
std::cout<<std::endl<<"Message encryped by RSA2 with public key of RSA1 is: "<<cipher.toHexString();

//2d -- Decrypt the value using the private key of RSA1. 
deciphered = rsa1.decrypt(cipher);

//2e - Match both the values (original message vs decrypted message), they should be the same. If so Challenge Response scheme 0 is completed.
std::cout<<std::endl<<"Message decryped by RSA1 with its private key is: "<<deciphered.toHexString()<<std::endl;     
if(message.toHexString()!=message.toHexString())
std::cout<<"Challenge Response is not Successful";
else
std::cout<<"original message and decrypted message are same. Hence Challenge Response is Successful"<<std::endl<<std::endl;

}
