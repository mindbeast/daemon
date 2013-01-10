#include <unistd.h>
#include <stdlib.h>

int main() {
    pid_t pid, sid;
    
    /* Fork off the parent process */
    pid = fork();
    if (pid < 0) {
            exit(EXIT_FAILURE);
    }
    /* If we got a good PID, then
       we can exit the parent process. */
    if (pid > 0) {
            exit(EXIT_SUCCESS);
    }

    /* Change the file mode mask */
    umask(0);       
    
    /* Open any logs here */
    
    /* Create a new SID for the child process */
    sid = setsid();
    if (sid < 0) {
            /* Log any failures here */
            exit(EXIT_FAILURE);
    }
    
    
    /* Change the current working directory */
    if ((chdir("/")) < 0) {
            /* Log any failures here */
            exit(EXIT_FAILURE);
    }
    
    /* Close out the standard file descriptors */
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);
    
    /* Daemon-specific initialization goes here */
    
    /* The Big Loop */
    while (1) {
       /* Do some task here ... */
       sleep(1); /* wait 30 seconds */
    }
}

