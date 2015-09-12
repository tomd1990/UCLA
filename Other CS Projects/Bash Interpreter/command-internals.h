// UCLA CS 111 Lab 1 command internals
#include <sys/types.h>
typedef struct word_container *word_con;
typedef struct dependancy_node *dnode;
typedef struct dependancy_list *dlist;
typedef struct pid_dependencies *pdep;

enum command_type
  {
    AND_COMMAND,         // A && B
    SEQUENCE_COMMAND,    // A ; B
    OR_COMMAND,          // A || B
    PIPE_COMMAND,        // A | B
    SIMPLE_COMMAND,      // a simple command
    SUBSHELL_COMMAND,    // ( A )
  };

typedef enum {

	SEMICOLON,
	NEWLINE,
	PIPE,
	AND,
	OR,
	LEFT_ARROW,
	RIGHT_ARROW,
	WORD,
	LP,
	RP,
	END_OF_FILE
} syntax_values;





// Data associated with a command.
struct command
{
  enum command_type type;

  // Exit status, or -1 if not known (e.g., because it has not exited yet).
  int status;

  // I/O redirections, or 0 if none.
  char *input;
  char *output;

  union
  {
    // for AND_COMMAND, SEQUENCE_COMMAND, OR_COMMAND, PIPE_COMMAND:
    struct command *command[2];

    // for SIMPLE_COMMAND:
    char **word;

    // for SUBSHELL_COMMAND:
    struct command *subshell_command;
  } u;
};

struct command_stream
{
void (*add_token)(const void *self, char *ptr, syntax_values ab); //add token to stack
char* (*pop)(const void *self);
int (*empty)(const void *self);
void (*free_mem)(const void *self);
word_con (*top)(const void*self);
int line_number;
int token_length;
word_con head;
word_con tail;
word_con iter;
};

struct word_container 
{
char *buffer_wc;
syntax_values matching_syntax;  
int line_num;
word_con point_next;
word_con point_prev;
};

struct dependancy_node
{
char *in;
char *out;
char RWO;
dnode prev;
dnode next;
};

struct dependancy_list
{
command_t a;
dnode head;
dnode tail;
};

struct pid_dependencies
{
char stat;
pid_t run;
int pid_index;
pid_t *a; 
command_t b;
int sequence_num;
int *arr;
int index;
};








