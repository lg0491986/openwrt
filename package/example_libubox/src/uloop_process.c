#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <libubox/uloop.h>

#define CHILD_NUM 10

void child_process_enter(int process_num){
	printf("enter:%s:%d\n", __func__, __LINE__);
	sleep((process_num + 1));
	printf("exit:%s:%d\n", __func__, __LINE__);
	exit(process_num);
}

void child_process_exit(struct uloop_process *u_process, int ret){
	printf("%s:%d, pid=%d, status[ret]=%x\n", __func__, __LINE__, u_process->pid, ret);
}

int uloop_process_main(int argc, char *argv[]){
	int i;
	struct uloop_process u_processs[CHILD_NUM];

	uloop_init();
	
	for(i = 0; i < CHILD_NUM; i++){
		pid_t pid;

		usleep(500);
		pid = fork();

		if(pid == 0){
			//child 
			child_process_enter(i);
		}else if(pid < 0){
			printf("fork child process error.\n");
			exit(-1);
		}
	
		u_processs[i].pid = pid;
		u_processs[i].cb= child_process_exit;
		u_processs[i].pending = false;

		if (uloop_process_add(&u_processs[i]) < 0){
			printf("uloop_process_add fail...\n");
		}
		
		printf("create %d process pid: %d\n", i, u_processs[i].pid);
	}
	
	printf("uloop_runing....\n");

	//check and run the process queue.
	uloop_run();

	//clean uloop
	uloop_done();
	return 0;
}

