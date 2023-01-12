#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include"shell_header.h"
int main();
void    func()
{
    printf("hmm");
    main();
}
int main()
{
	func();
	// printf("%s\n",en->var);
}