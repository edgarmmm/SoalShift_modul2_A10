/* localtime example */
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>


int main ()
{
	pid_t pid, sid;
	pid = fork();

	if (pid < 0) {
		exit(EXIT_FAILURE);
	}

	if (pid > 0) {
		exit(EXIT_SUCCESS);
	}

	umask(0);

	sid = setsid();

	if (sid < 0) {
		exit(EXIT_FAILURE);
	}

	if ((chdir("/home/edgar/")) < 0) {
		exit(EXIT_FAILURE);
	}

	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);

	time_t rawtime;
	struct tm * timeinfo;
	time ( &rawtime );
	timeinfo = localtime ( &rawtime );
        char waktuku[100];
        strftime(waktuku,sizeof(waktuku), "%d:%m:%Y-%H:%M:%S", timeinfo);
	char direku[]="/home/edgar/log/";
        strcat(direku, waktuku);
  	int direct=mkdir(direku, 0777);
	time_t folder=time(NULL);
	time_t program=time(NULL);
	int counter=1;
	while(1)
	{
		FILE *fp1, *fp2;
		char ch;
		int pos;

		time_t program=time(NULL);
		if(difftime(program, folder)<=30)
		{
			char waktumu[100]="log";
			char angka[10];
			char sementara[100];
			sprintf(angka, "%d", counter);
			fp1 = fopen("/var/log/syslog","r");
			strcpy(sementara, direku);
			strcat(sementara, "/");
			strcat(sementara, waktumu);
			strcat(sementara, angka);
			fp2 = fopen(sementara, "w");
			fseek(fp1, 0L, SEEK_END); // file pointer at end of file
			pos = ftell(fp1);
			fseek(fp1, 0L, SEEK_SET); // file pointer set at start
			while (pos--)
			{
				ch = fgetc(fp1);  // copying file character by character
			        fputc(ch, fp2);
			}
			fclose(fp1);
			fclose(fp2);
			counter++;
		}
		else
		{
		  	time_t rawnew;
		  	time ( &rawnew );
			timeinfo = localtime ( &rawnew );
			strftime(waktuku,sizeof(waktuku), "%d:%m:%Y-%H:%M:%S", timeinfo);
			direku[0]='\0';
			strcpy(direku, "/home/edgar/log/");
			strcat(direku, waktuku);
			direct= mkdir(direku, 0777);
			time_t folder2=time(NULL);
			folder=folder2;
			counter=1;
		}
		sleep(2);
	}
	return 0;
}
