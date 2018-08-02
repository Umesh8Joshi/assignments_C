
// Headers files
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
 * Builtin functions for shell command
 * Will add some later on
 */

int ush_cd(char **args);
int ush_help(char **args);
int ush_exit(char **args);

/*
 * List of command
 * Will be added as per the functions
 */

char *builtin_str[] = {
    "cd",
    "help",
    "exit"
};

int (*builtin_func[])(char **) = {
    &ush_cd,
    &ush_help,
    &ush_exit
};

int ush_numof_builtins(){
    return sizeof(builtin_str)/sizeof(char *);
}

/*
 * Function implementations
 * Each function will take data from command line
 */

/*
 * @func  :      ush_cd
 * @brief :      function to change directory
 * @param :      list of arguments args[0] is cd and args[1] is directory
 * @return:      Return 1 to execution
 */

int ush_cd(char **args){
    if(args[1] == NULL){
        fprintf(stderr, "ush: expected argument");
    }else{
        if(chdir(args[1]) != 0){
            perror("ush");
        }
    }
    return 1;
}

/*
 * @func  :      ush_help
 * @brief :      function to print help and all command available
 * @param :      list of arguments not examined
 * @return:      Return 1 to execution 
 */

int ush_help(char **args){
    int i;
    printf("Umesh Joshi's USH (shell)\n");
    printf("Type command and arguments and hit enter\n");
    printf("Following are the commands available\n");

    for(i = 0; i < ush_numof_builtins();i++){
        printf(" %s\n", builtin_str[i]);
    }
    return 1;
}

/*
 * @func  :      ush_exit
 * @brief :      function to exit terminal
 * @param :      list of arguments not examined
 * @return:      Return 0 to terminate
 */

int ush_exit(char **args){
    return 0;
}

/*
 * @func  :      ush_launch
 * @brief :      function to launch program
 * @param :      list of arguments and program to be launched
 * @return:      Return 1 to execution
 */

int ush_launch(char **args){
    pid_t pid;
    int status;

    pid = fork();
    if(pid == 0){
        if(execvp(args[0], args) == -1){
            perror("ush");
        }
        exit(EXIT_FAILURE);
    }else if(pid < 0){
        // Error
        perror("ush");
    }else{
        do{
            waitpid(pid, &status, WUNTRACED);
        }while( !WIFEXITED(status) && !WIFSIGNALED(status));
    }
    return 1;
}

/*
 * @func  :      ush_execute
 * @brief :      function to execute or launch terminal
 * @param :      NULL terminted arguments
 * @return:      Return 1 to execution if shell should continue or 0 to terminate
 */

int ush_execute(char **args){
    int i;
    if(args[0] == NULL){
        //no command
        return 1;
    }
    for(i=0; i < ush_numof_builtins(); i++){
        if(strcmp(args[0], builtin_str[1]) == 0){
            return (*builtin_func[i])(args);
        }
    }

    return ush_launch(args);
}

#define USH_RL_BUF 1024
/*
 * Read a line from command line
 * @return line to stdin
 */

char *ush_read_line(void){
    int bufsize = USH_RL_BUF;
    int position = 0;
    char *buffer = malloc(sizeof(char) * bufsize);
    int c;

    if(!buffer){
        fprintf(stderr, "ush: error allocation problem");
        exit(EXIT_FAILURE);
    }

    while(1){
        c = getchar();

        if(c == EOF){
            exit(EXIT_SUCCESS);
        }else if(c == '\n'){
            buffer[position] = '\0';
            return buffer;
        }else{
            buffer[position] = c;
        }

        position++;

        //Let us reallocate the buffer
        if(position >= bufsize){
            bufsize += USH_RL_BUF;
            buffer = realloc(buffer, bufsize);
            if(!buffer){
                fprintf(stderr, "ush: error allocationg buffer");
                exit(EXIT_FAILURE);
            }
        }
    }
}

#define USH_TOCK_SIZE 64
#define USH_TOCK_DELIM " \t\r\n\a"

/*
 * @brief  :     split line into tokens
 * @param  :     line
 * @return :     NULL terminated array of tokens
 */

char **ush_split_line(char *line){
    int bufsize = USH_TOCK_SIZE;
    int position = 0;
    char **tokens = malloc(bufsize * sizeof(char *));
    char *token, **tokens_backup; //Backups are important

    if(!tokens){
        fprintf(stderr, "ush: allocation err");
        exit(EXIT_FAILURE);
    }

    token = strtok(line, USH_TOCK_DELIM);
    while(token != NULL){
        tokens[position] = token;
        position++;

    if(position >=  bufsize){
        bufsize += USH_TOCK_SIZE;
        tokens_backup = tokens;
        tokens = realloc(tokens,bufsize * sizeof(char *));
        if(!tokens){
            free(tokens_backup);
            fprintf(stderr, "ush: allocation problem");
            exit(EXIT_FAILURE);
        }
    }

    token = strtok(NULL, USH_TOCK_DELIM);
    }

    tokens[position] = NULL;
    return tokens;
}

/*
 * Loop to get input and execute it
 */

void ush_loop(void){
    char *line;
    char **args;
    int status;

    do{
        printf("> ");
        line = ush_read_line();
        args = ush_split_line(line);
        status = ush_execute(args);

        free(line);
        free(args);
    }while(status);
}


// Main menu for the program

int main(int argc, char const *argv[])
{
    ush_loop();
    return EXIT_SUCCESS;
}
