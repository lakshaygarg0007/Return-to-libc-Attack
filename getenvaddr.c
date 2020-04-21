#include<stdio.h>
#include<stdlib.h>

/*
This program is used to find the address of "/bin/sh" in memory
which is to be provided as an argument to system function .
As system fucntion runs it forks new child process SO,i declared
 "/bin/sh" as shell variable which becomes enivronment variable
 of child process and from this code i can get address of that
variable.
To export shell variable we use ->
export MYSHELL="/bin/sh" 
command
*/


int main(){
char *shell =(char *)getenv("MYSHELL");

if(shell)
{
printf("value: %s\n",shell);
//%x to oprint hexadecimal value
printf("Address: %x\n",(unsigned int)shell);
}

return 1;
}
