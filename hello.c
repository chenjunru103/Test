#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
int main()
{
	pid_t pid,ppid;
	int ret;
	printf("hello world!\n");
	
	pid = getpid();
	ppid = getppid();
	printf("process id:%d\n",pid);
	printf("father process id:%d\n",ppid);

	ret = system("sudo ping www.baidu.com -c 3");
	printf("return:%d\n",ret);

	pid_t pidf;
	pidf = fork();
	if(-1 == pidf)
	{
		printf("fork failed!\n");
	}
	else if(0 == pidf)
	{
		printf("subprogress,fork return:%d,pid:%d,ppid:%d\n",pidf,getpid(),getppid());
	}
	else
	{
		printf("fatherprogress,fork return:%d,pid:%d,ppid:%d\n",pidf,getpid(),getppid());
	}
	return 0;
}
