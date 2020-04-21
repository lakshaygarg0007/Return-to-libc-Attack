#include<stdio.h>
#include<string.h>

/*
In this Program input is taken by user in the form of badfile
and resultant file content is stored in character array  we as 
attacker input data so that char array get overflows and return address 
of vul_func gets changed to system() function address . 

In system() function we give argument as "/bin/sh" which gives a shell.
As this function is root owned setuid program we get access to root shell.
By which our attack get successful

Note -> To perform this attack i have made some default enivronment setup

1. Program is root owned set-uid program
2. Address Space Layout Randomization (ASLR) is = 0
3. Program has stack protector disabled
*/


int vul_func(char *str)
{
 
   char buffer[50];
/*copy in buffer of size 50 
here buffer overflow occcurs if size of str is >50*/	 
   strcpy(buffer,str);
//If returned properly
   return 1;
}


int main(int argc,char ** argv)
{

char str[240];

//Input by user stored in file (Name-> Badfile)
FILE *badfile;
//open file in read mode
badfile=fopen("badfile","r");
//store first 200 bytes of badfile in char array(str)
fread(str,sizeof(char),200,badfile);
//call vul_func 
vul_func(str);

printf("Returned Properly\n");
return 1;
}
