#include <stdio.h>
#include <unistd.h>

int main()
{
	char *kill[]={"killall", "soal5", NULL};
	execv("/usr/bin/killall", kill);
}
