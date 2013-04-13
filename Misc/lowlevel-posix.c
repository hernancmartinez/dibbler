/*
 * Dibbler - a portable DHCPv6
 *
 * author: Tomasz Mrugalski <thomson@klub.com.pl>
 *
 * released under GNU GPL v2 licence
 *
 */

#include "Portable.h"
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int execute(const char *filename, const char * argv[], const char *env[])
{

#ifdef LOWLEVEL_DEBUG
    char ** x = argv;
    printf("Execute script: %s\n", filename);
    while (*x) {
        printf("Param: %s\n", *x);
        ++x;
    }

    x = env;
    while (*x) {
        printf("env: %s\n", *x);
        ++x;
    }
#endif

    pid_t pid;
    int status = 0;

    pid = fork();
    if (!pid) {
        int result = execve(filename, (char * const *)argv, (char * const *)env);
        result = errno;
        /* printf("#### Error during attempt to execute %s script: %s\n", filename, strerror(result)); */
        /* errors only. if execution succeeds, this process is replaced by instance of filename */
        if (result>0) {
            result = -result;
        }
        exit(-1);
    } else {
        /* printf("#### before waitpid() pid=%d status=%d\n", pid, status); */
        waitpid(pid, &status, 0);
        /* printf("#### after waitpid() pid=%d status=%d\n", pid, status); */
        if (WIFEXITED(status))
            return WEXITSTATUS(status);
        else
            return LOWLEVEL_ERROR_UNSPEC;
    }
}

/** @brief returns host name of this host
 *
 * @param hostname buffer (hostname will be stored here)
 * @param hostname_len length of the buffer
 * @return LOWLEVEL_NO_ERROR if successful, appropriate LOWLEVEL_ERROR_* otherwise
 */
int get_hostname(char* hostname, int hostname_len) {
    int status = gethostname(hostname, hostname_len);
    if (status == 0) {
        return LOWLEVEL_NO_ERROR;
    } else {
        return LOWLEVEL_ERROR_UNSPEC;
    }
}
