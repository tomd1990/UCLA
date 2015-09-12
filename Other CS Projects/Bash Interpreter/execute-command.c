// UCLA CS 111 Lab 1 command execution

#include "command.h"
#include "command-internals.h"
#include <sys/types.h>
#include <unistd.h> 
#include <sys/wait.h> 
#include <sys/stat.h>
#include <fcntl.h>
#include <error.h>
#include "alloc.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* FIXME: You may need to add #include directives, macro definitions,
   static function definitions, etc.  */

int
command_status (command_t c)
{
  return c->status;
}

int* I_O(command_t c, int in, int out)
{	int *ret = (int*) checked_malloc(3*sizeof(int));

ret[0] = -1;
ret[1] = -1;
ret[2] = 0;
	//io managment
	
		if( (c->input != NULL) && (c->output != NULL) )
		{
			int fdi = open(c->input, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
			int fdo = open(c->output, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
			if( (fdi < 0) || (fdo <0 ))
				error(1,0, "Problem Opening files");
			if(dup2(fdo, 1) <0 )
				error(1,0,"Problem Redirecting IO");
			if(dup2(fdi, 0) < 0)
				error(1,0,"Problem Redirection IO");
			ret[0] = fdi;
			ret[1] = fdo;
			ret[2] = 3;	
		}
		else if(c->output != NULL)
		{
			int fdo = open(c->output, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR); 
			if(fdo < 0 )
				error(1,0, "Problem opening output file");
			if(dup2(fdo, 1) <0 )
				error(1,0,"Problem Redirecting IO");
			ret[1] = fdo;
			ret[0] = in;	
			ret[2] = 0;	
		}
		else if (c->input != NULL)
		{
			int fdi = open(c->input, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
			if(fdi <0)
				error(1,0, "Problem Opening input file");
			if(dup2(fdi, 0) <0 )
				error(1,0,"Problem Redirecting IO");
			ret[0] = fdi;
			ret[1] = out;
			ret[2] = 0;
		}
return ret;

}



int seq_ex(command_t c, int file, int file2)
{

int e = execute( c->u.command[0], file, file2);
int f = execute( c->u.command[1], file, file2);

c->status = f;

return c->status;

}


int and_ex(command_t c, int file, int file2)
{
	pid_t a;
	int e = execute(c->u.command[0], file, file2);
	int d;
	if(e ==0)
	{
		//execute right side
		d = execute(c->u.command[1], file, file2);
		c->status = d;
		
	}
	else 
	{
		c->status = e;
	}

	return c->status;
	
	

}

int or_ex(command_t c, int file, int file2)
{
	int d = execute(c->u.command[0], file, file2);
	if( d == 0)
	{		
		c->status = d;
	}
	else
	{
	int e = execute(c->u.command[1], file, file2);
	c->status = e;
	
	}

	return c->status;

}


int pipe_ex(command_t c, int file, int file2)
{	pid_t a;
	int fd[2];
	pipe(fd);
	int left_stat = 0;
	int right_stat = 0;
	
		a = fork();
		if( a == 0)
		{	
			close(fd[0]);
			if(dup2(fd[1], 1) <0 )
				error(1,0,"Problem Redirecting IO/PIPE");
			
			int a = execute(c->u.command[0], file, fd[1]);
			a = a%255;
			_exit(a);

		}
		else if(a >0)
		{
			waitpid(a, &left_stat, 0);
			
			
			//close write side
			close(fd[1]);
			//process right hand side
			a = fork();
			if(a == 0)
			{	
				
				if(dup2(fd[0], 0) < 0)
					error(1,0,"Problem Redirecting IO/PIPE");
				//evaluate right side  then exit need to be more general
				int b = execute(c->u.command[1], fd[0], file2);
				b = b%255;
				_exit(b);

			}
			else if (a>0)
			{
				waitpid(a, &right_stat, 0);
				
			}
			else
				error(1,0,"Problem Forking/PIPE");

		}
		else
			error(1,0,"Problem Forking/PIPE");
		
		
		//revise to meet more general exit codes
	c->status = right_stat;

		
	
	close(fd[0]);
	close(fd[1]);
	return (c->status);
}

int subshell_ex(command_t c, int file, int file2)
{
	pid_t a;
	a = fork();
	int e;
	if(a == 0)
	{
	int *d = I_O(c, file, file2);
	if(d[2] ==0)
		e = execute(c->u.subshell_command, file, file2);
	if(d[2] == 1)
		e = execute(c->u.subshell_command, d[0], file2);
	if(d[2] == 2)
		e = execute(c->u.subshell_command, file, d[1]); 
	if(d[3] == 3)
		e = execute(c->u.subshell_command, file, file2);
	 //free(d);
	e = e%255;
	_exit(e);
	}
	else if(a>0)
	{
		waitpid(a, &(c->status), 0);
	}
	else
		error(1,0, "ERROR FORKING");

return c->status;
}

int simple_ex(command_t c, int file, int file2) 
{
	pid_t a;
	
		a = fork();
		if(a == 0)
		{		
		I_O(c, file, file2);
		execvp(c->u.word[0], c->u.word);
		//should never get here
		error(1,0, "Error execvp");
		}
		else if(a >0)
		{
			waitpid(a, &(c->status), 0);
		}
		else 
			error(1,0, "ERROR FORKING");


	
	return (c->status);
}

int execute(command_t c, int file, int file2)
{
int d = 1;
switch(c->type)
{
case SIMPLE_COMMAND :
	d =simple_ex(c, file, file2);
	break;
case SUBSHELL_COMMAND :
	d =subshell_ex(c, file, file2);
	break;
case PIPE_COMMAND :
	d = pipe_ex(c, file, file2);
	break;
case OR_COMMAND :
	d = or_ex(c, file, file2);
	break;
case AND_COMMAND :
	d = and_ex(c, file, file2);
	break;
case SEQUENCE_COMMAND :
	d = seq_ex(c, file, file2);
	break;

}

return d;
}



void add_rows(dlist *temp, int *max_row, int current_row)
{	if(current_row >= *max_row) 
	{
	*max_row *=2;
	*temp = checked_realloc(*temp, (*max_row)*sizeof(dlist));
	
	}
	temp[current_row] = checked_malloc(sizeof(struct dependancy_list));
	temp[current_row]->head = NULL;
	temp[current_row]->tail = temp[current_row]->head;
}

void add_dependency(dlist temp, char *file, char *file2, char type)
{
	dnode temps = (dnode) checked_malloc(sizeof(struct dependancy_node));
	temps->in = file;
	temps->out = file2;
	temps->RWO = type;
	
	if(temp->head == NULL)
	{
		temp->head = temps;
		temps->prev = NULL;
		temps->next = NULL;
		temp->tail = temps;
	}
	else
	{
	temp->tail->next = temps;
	temps->prev = temp->tail;
	temps->next = NULL;
	temp->tail = temps; 
	}



}



void visit_leafs(int *seq, int *max, dlist *sequences,  command_t c )
{
	if(c->type == SIMPLE_COMMAND)
	{	int x =*seq;
		if( (c->input != NULL) && (c->output != NULL) )
		{
			add_dependency(sequences[x], c->input, c->output, 'B');
			//printf("write to %s Read from  %s seq %d\n", c->output, c->input, *seq);	
		}
		else if(c->output != NULL)
		{
			add_dependency(sequences[x], NULL, c->output, 'W');
			//printf("write to %s seq %d\n", c->output, *seq);
		}
		else if(c->input != NULL)
		{
			add_dependency(sequences[x], c->input, NULL, 'R');
			//printf("Read from %s seq %d \n", c->input, *seq);
	
		}
	// add options as readers
		int iter =1;
		while(c->u.word[iter] != NULL)
		{
		add_dependency(sequences[x], c->u.word[iter], NULL, 'R');
		//printf("%s   \n",c->u.word[iter]);
		iter = iter +1;
		}
		


	}
	else
	{	if( (c->type == SEQUENCE_COMMAND) && (c->u.command[0]->type != SEQUENCE_COMMAND) ) 
		{*seq += 1; add_rows(sequences, max, *seq); sequences[*seq]->a =c->u.command[0];}
		visit_leafs(seq, max, sequences,  c->u.command[0]);
		if( (c->type == SEQUENCE_COMMAND) && (c->u.command[1]->type != SEQUENCE_COMMAND) ) 
		{*seq += 1; add_rows(sequences, max, *seq);sequences[*seq]->a =c->u.command[1];}
		visit_leafs(seq,  max, sequences, c->u.command[1]);
	}

	
	
	
}

int cmp(char *a, char *b)
{
int i =0;
int j=0;
while(a[i]!='\0' && a[i]!='\0')
{
 	if(a[i]!=b[i])
	{
            j=1;
            break;
        }
       i+=1;
}
if(j==0 && (a[i]=='\0') && (b[i]=='\0'))
	return 0;
else
	return 1;	
}

void shift(int *a, int *ind, int del)
{
	int x =0;
	while(x<*ind)
	{
	if(a[x] == del)
	{	*ind = *ind -1;
		while(x<*ind)
		{
		a[x] = a[x+1];
		x+=1;
		}
	break;
	}
	
	x+=1;
	}

}

void time_saver( command_t c)
{
// dependency list
if(c->type == SEQUENCE_COMMAND)
{	
	int seq_num = -1;
	int max_rows = 20;
	dlist *seqs;
	seqs =  (dlist*) checked_malloc(sizeof(dlist)*20);
	// processes all read/ writes
	visit_leafs(&seq_num, &max_rows, seqs, c);


	//analysis

pdep set = (pdep) checked_malloc(sizeof(struct pid_dependencies)*(seq_num+1));

int iter =0;

while(iter <= seq_num)
{
set[iter].b = seqs[iter]->a;
set[iter].index = 0;
set[iter].sequence_num = iter;
set[iter].arr = (int*) checked_malloc(sizeof(int)*(seq_num+1));
set[iter].a = (pid_t *) checked_malloc(sizeof(pid_t)*(seq_num+1));
set[iter].pid_index = 0;
set[iter].stat='N';
int z =0;
while(z<=seq_num)
{
set[iter].arr[z] =-1;
z+=1;
}
iter+=1;
}

iter = 0;
dnode a;
dnode b;
int iter2;
int c;
while(iter <=seq_num)
{

	iter2 = 1;
	while( iter2+iter<=seq_num)
	{
			
		a = seqs[iter]->head;
		while( a != NULL)
		{	 c =0;
			 b = seqs[iter2+iter]->head;
			//if already not in queue
			while( b != NULL)
			{	
				if((a->out != NULL) && (b->out != NULL)){
				if( cmp(a->out, b->out) == 0)
				{
				set[iter+iter2].arr[set[iter+iter2].index] = iter;
				set[iter+iter2].index = set[iter+iter2].index +1;
				c = 1;
				break;
				}
				}
				if((a->out != NULL) && (b->in != NULL)) {
				if( cmp(a->out, b->in) ==0 )
				{
				
				set[iter+iter2].arr[set[iter+iter2].index] = iter;
				set[iter+iter2].index = set[iter+iter2].index +1;
				c = 1;
				break;
				}
				}
				if((a->in != NULL) && (b->out != NULL)) 
				{
				if( cmp(a->in, b->out) == 0)
				{
				
				set[iter+iter2].arr[set[iter+iter2].index] = iter;
				set[iter+iter2].index = set[iter+iter2].index +1;
				c = 1;
				break;
				}
				}
			b = b->next;
			}

		if(c ==1)
		{break;}

		a = a->next;	
		}	
	iter2+=1;
	}
iter+=1;
	
}	



//master list 
int mast = seq_num+1;
//execute 
while(mast != 0)
{
int rdy =0;
while(rdy<=seq_num)
{
//if its not waiting
if((set[rdy].index == 0) && (set[rdy].stat == 'N'))
{
	pid_t a =fork();
	if(a==0)
	{
	int exer = execute(set[rdy].b,0,1);
	exer = exer%255;
	_exit(exer);

	}
	else if(a>0)
	{
	set[rdy].run = a;
	set[rdy].stat = 'R';
	


	}
	else
		error(1,0, "Error Forking");
	//waitpid(a, &set[rdy].b->status, 0);
}
rdy+=1;
}
int status =0;
	if(mast !=0) 
	{
	 pid_t random= waitpid(-1, &status, 0);
 	int u =0;
	while(u<=seq_num)
	{
		if(random == set[u].run)
		{
		set[u].stat ='D';
		mast = mast -1;
		break;
		}
	u+=1;
	} 
	//remove u from dependcy lists
	int g = 0;
	while(g<=seq_num)
	{
		if(set[g].stat == 'N')
		{	
		shift(set[g].arr, &set[g].index, u);
		}
	g+=1;
	}
	}













	
 }
}
else
	execute(c,0,1);

}






























void
execute_command (command_t c, int time_travel)
{
if(time_travel == 0)
	execute(c,0,1);
else
	time_saver(c);

}
