#include <stdio.h>

#ifdef ULOOP_PROCESS
extern int uloop_process_main(int argc, char* argv[]);
#endif

#ifdef ULOOP_TIMEOUT
extern int uloop_timeout_main(int argc, char* argv[]);
#endif

#define CMD_ULOOP_PROCESS "uloop_process"
#define CMD_ULOOP_TIMEOUT "uloop_timeout"

typedef int (*cmd_main)(int argc, char *argv[]);

struct cmd_s {
	char *name;
	cmd_main func;
};

struct cmd_s cmds[] = {
#ifdef ULOOP_PROCESS
	{
		.name = CMD_ULOOP_PROCESS,
		.func = uloop_process_main,
	},
#endif
};

int main(int argc, char *argv[]){
	char *cmdname = argv;
	char *p = NULL;
	int i;

	if((p = strrchr (cmdname, '/')) != NULL){
		cmdname = p + 1;
	}
	
	for(i = 0; i < sizeof(cmds); i++){
		if(strcmp(cmds[i].name, cmdname) == 0){
			cmds[i].func(argc, argv);
			break;
		}
	}
	
	if(i == sizeof(cmds)){
		printf("%s not found.\n", cmdname);
	}
		
	return 0;
}

