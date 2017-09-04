#include <sys/types.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <microhttpd.h>
#include <stdio.h>
#include <string.h>
//Includes para daemonizar
#include "apue.h"
#include <syslog.h>
#include <fcntl.h>
#include <sys/resource.h>

#define PORT 8888
#define buflen 100
char *ip = "127.0.0.1";

//Funcion para daemonizar
void daemonize(const char *cmd){
    int i, fd0, fd1, fd2;
    pid_t pid;
    struct rlimit rl;
    struct sigaction sa;

    /*
     * Clear file creation mask.
     */
    umask(0);

    /*
     * Get maximum number of file descriptors.
     */
    if (getrlimit(RLIMIT_NOFILE, &rl) < 0)
        err_quit("%s: can't get file limit", cmd);

    /*
     * Become a session leader to lose controlling TTY.
     */
    if ((pid = fork()) < 0)
        err_quit("%s: can't fork", cmd);
    else if (pid != 0) /* parent */
        exit(0);
    setsid();

    /*
     * Ensure future opens won't allocate controlling TTYs.
     */
    sa.sa_handler = SIG_IGN;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    if (sigaction(SIGHUP, &sa, NULL) < 0)
        err_quit("%s: can't ignore SIGHUP", cmd);
    if ((pid = fork()) < 0)
        err_quit("%s: can't fork", cmd);
    else if (pid != 0) /* parent */
        exit(0);

    /*
     * Change the current working directory to the root so
     * we won't prevent file systems from being unmounted.
     */
    if (chdir("/") < 0)
        err_quit("%s: can't change directory to /", cmd);

    /*
     * Close all open file descriptors.
     */
    if (rl.rlim_max == RLIM_INFINITY)
        rl.rlim_max = 1024;
    for (i = 0; i < rl.rlim_max; i++)
        close(i);

    /*
     * Attach file descriptors 0, 1, and 2 to /dev/null.
     */
    fd0 = open("/dev/null", O_RDWR);
    fd1 = dup(0);
    fd2 = dup(0);

    /*
     * Initialize the log file.
     */
    openlog(cmd, LOG_CONS, LOG_DAEMON);
    if (fd0 != 0 || fd1 != 1 || fd2 != 2) {
        syslog(LOG_ERR, "unexpected file descriptors %d %d %d",
          fd0, fd1, fd2);
        exit(1);
    }
}


int answer_to_connection (void *cls, struct MHD_Connection *connection, const char *url, const char *method, const char *version,
                          const char *upload_data, size_t *upload_data_size, void **con_cls){

	const char *page  =  "<html><body>AHHHHHHHHH</body></html>";
	struct MHD_Response *response;
	int ret;
	
	response = MHD_create_response_from_buffer (strlen (page),(void*) page, MHD_RESPMEM_PERSISTENT);
	ret = MHD_queue_response (connection, MHD_HTTP_OK, response);
	MHD_destroy_response (response);

	return ret;
}

int main (){
  	/*struct MHD_Daemon *daemon;
	daemon = MHD_start_daemon (MHD_USE_SELECT_INTERNALLY, PORT, NULL, NULL,&answer_to_connection,NULL, MHD_OPTION_END);
  	if (NULL == daemon) return 1;

	getchar ();

  	MHD_stop_daemon (daemon);
  	return 0;*/

	int socketServidor;
	struct sockaddr_in direccionServidor=(sockaddr_in)malloc(sizeof(sockaddr_in));

	direccionServidor.sin_family = AF_INET;
	direccionServidor.sin_port = htons(PORT);
	direccionServidor.sin_addr.s_addr = inet_addr(ip);

	socketServidor = socket(((struct sockaddr*)&direccionServidor->sa_family, SOCK_STREAM, 0);

	if(bind(socketServidor,(struct sockaddr *)&direccionServidor,sizeof(direccionServer)) < 0)){
		printf("Ocurrio un error con el bind");
		return(-1);
	}

	if(listen(socketServidor, 100) < 0){
		printf("Ocurrio un error en el listen");
		return(-1);
	}

	struct sockaddr_in cli_addr;
	int clilen = sizeof(cli_addr);

	while(1){
		
	}
}
