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
BigInt  message;

unsigned long int *a;
unsigned long int arr[10];
a=&arr[0];

//a.Alice obtains the public key and Modulus N of the person (Bob) who is to sign the message
RSA alice;
RSA bob_CA(31729,31741);
alice.setPublicKey(bob_CA.getPublicKey());
alice.setN(bob_CA.getModulus());
BigInt ModulusOfBob=bob_CA.getModulus();
std::cout<<"Modulus of BOB_CA is: "<<ModulusOfBob.toHexString()<<std::endl;


//b.Obtain a random number and its inverse with respect to the Modulus [Not phi] of Bob
BigInt randomNumber= int(((double)(std::rand())/RAND_MAX)*RAND_LIMIT32);
std::cout<<"Random Number Selected is: "<<randomNumber.toHexString()<<std::endl;;

BigInt inverseRandomNumber=modInverse(randomNumber,ModulusOfBob);
std::cout<<"Inverse of Random Number Selected is: "<<inverseRandomNumber.toHexString()<<std::endl;;
BigInt multiplied=randomNumber.operator*(inverseRandomNumber);
BigInt modapplied=multiplied.operator%(ModulusOfBob);
std::cout<<"verifying inverse Random Number"<<modapplied.toHexString();


//c.Alice obtains/generates a message to be signed.
message = 610683084;//   int(((double)(std::rand())/RAND_MAX)*RAND_LIMIT32); 
std::cout<<std::endl<<"Message to be signed is: "<<message.toHexString()<<std::endl<<std::endl;

//d.Alice encrypts the random number with the public key.
BigInt encRandNumb = alice.encrypt(randomNumber);
std::cout<<"Random Number Encrypted with public Key of Bob_CA is: "<<encRandNumb.toHexString()<<std::endl;;

//e.Alice multiplies this value by the message
BigInt modifiedMessage=message.operator*(encRandNumb);
std::cout<<"Message multiplied with Encrypted Random Number is: "<<modifiedMessage.toHexString()<<std::endl;;

//f.Alice then takes a modulus over N
BigInt modifiedMessageModN=modifiedMessage.operator%(ModulusOfBob);
std::cout<<"Multiplied Message Mod n is: "<<modifiedMessageModN.toHexString()<<std::endl;;

//g.Alice sends it to Bob
BigInt modifiedMessageReceivedByBob=modifiedMessageModN;
std::cout<<"Message Recevied by  Bob is: "<<modifiedMessageReceivedByBob.toHexString()<<std::endl;

//h.Bob simply decrypts the received value with the private key
BigInt signedMsgWithRandomNumber=bob_CA.decrypt(modifiedMessageReceivedByBob);
std::cout<<"Unknown message signed by Bob is: "<<signedMsgWithRandomNumber.toHexString()<<std::endl;;

//i.Bob sends it back to Alice
BigInt signedMsgWithRreceivedByAlice=signedMsgWithRandomNumber;
std::cout<<"Unknown message signed by Bob is: "<<signedMsgWithRreceivedByAlice.toHexString()<<std::endl;;

//j.Alice then multiplied the received value with the inverse and takes a modulus over N.
BigInt signedMsg=signedMsgWithRreceivedByAlice.operator*(inverseRandomNumber);
std::cout<<"Signed Message Without Random Number  is: "<<signedMsg.toHexString()<<std::endl;     

//k.The value obtained above is the signed message. To obtain the original message from it, again encrypt it with Bob’s Public Key.
BigInt decryptedMsg=bob_CA.encrypt(signedMsg);
 std::cout<<std::endl<<"Signed Message decrypted  is: "<<decryptedMsg.toHexString()<<std::endl;     
}
