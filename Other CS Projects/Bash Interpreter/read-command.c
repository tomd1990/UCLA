// UCLA CS 111 Lab 1 command reading

#include "command.h"
#include "command-internals.h"
#include <stdio.h>
#include <error.h>
#include <stdlib.h>
#include <string.h>
void insert_cs(const void *self, char *ptr, syntax_values ab);
char* remove_front(const void *self);
int empt(const void *self);
void frem(const void *self);
command_stream_t new_command_stream();
int is_valid(int chara);
word_con front(const void*self);
command_t command(command_stream_t s);
command_t simple_command(command_stream_t s);
command_t pipeline(command_stream_t s);
command_t subshell(command_stream_t s);
command_t andors(command_stream_t s);
command_t complete_command(command_stream_t s);



command_stream_t
make_command_stream (int (*get_next_byte) (void *),
		     void *get_next_byte_argument)
{

	int temp;
	int test;
	int index;
	int max;
	char *temp_buff;
	char *temp_temp;
	command_stream_t lex = new_command_stream(); 
	while((test = get_next_byte(get_next_byte_argument)) != EOF)	
	{
		if(test =='#')
		{	//ignore white space up till newline EOF condition
			while((test = get_next_byte(get_next_byte_argument)) != '\n')
			{}	
			ungetc(test, get_next_byte_argument);
		}
		else if(test == '\n' ) 
		{
			lex->add_token(lex,NULL, NEWLINE);
			lex->line_number = lex->line_number +1;
		}
		else if( (test == '\t') || (test == ' '))
		{
			//do nothing
		}
		else if(test == '(')
		{
			lex->add_token(lex, NULL, LP);
		}
		else if(test == ')')
		{
			lex->add_token(lex, NULL, RP);
		}
		else if( test ==';')
		{
			lex->add_token(lex,NULL, SEMICOLON);
		}
		else if( test == '<')
		{
			lex->add_token(lex, NULL, LEFT_ARROW);
		}
		else if( test == '>' )
		{
			lex->add_token(lex, NULL, RIGHT_ARROW);
		}
		else if(test == '|')
		{
			//check if its pipe or OR
			temp = get_next_byte(get_next_byte_argument);
			if( temp == '|')
				lex->add_token(lex, NULL, OR);
			else {
		
				ungetc(temp, get_next_byte_argument);
				lex->add_token(lex,NULL, PIPE);
			}
		}
		else if(test == '&')
		{
			temp = get_next_byte(get_next_byte_argument);
			if(temp == '&'){
				lex->add_token(lex, NULL, AND);
			}
			else
				error(1,0, "Line Number: %d, & is not an operatior", lex->line_number);
		}
		else if(test == EOF)
		{
			lex->add_token(lex, NULL, END_OF_FILE);
		}
		else if(is_valid(test))
		{	index = 0;
			max = 11;
			temp_buff = (char*) checked_malloc(max*sizeof(char));
			while( is_valid(test))
			{	
				if(index > max - 1)
				{
				int i = 0;
				max = max*2;
				temp_temp = (char*) checked_malloc(max*sizeof(char));

				strncpy(temp_temp, temp_buff, index);
				temp_buff[index] = 0;
				free(temp_buff);
				temp_buff = temp_temp;
				
				}

				temp_buff[index] = test;
				index = index +1;
				test = get_next_byte(get_next_byte_argument);		
			}
			// 0 out string
			while(index < max)
			{
			temp_buff[index] = '\0';
			index = index +1;
			}
			lex->add_token(lex, temp_buff, WORD);
			ungetc(test,get_next_byte_argument);
		}
		else 
		{
		
			error(1,0, "Line Number: %d Unrecognized Symbol: %c", lex->line_number, test);

		}

	}
	if((lex->top(lex)->matching_syntax == PIPE) || (lex->top(lex)->matching_syntax == AND ) || (lex->top(lex)->matching_syntax == OR)) 
	{
		error(1,0, "Line Number: %d Invalid Syntax", lex->line_number);
	}
	lex->add_token(lex, NULL, END_OF_FILE);


/*	lex->iter = lex->head;
	while(lex->iter != NULL)
			{
				if(lex->iter->buffer_wc !=NULL)
					printf("%s     ", lex->iter->buffer_wc);

				printf("LINE NUMBER:%d    %d\n", lex->iter->line_num, lex->iter->matching_syntax);
				lex->iter = lex->iter->point_next;

	
			}
	
*/	


  	return lex;
}

command_t
read_command_stream (command_stream_t s)
{
 
 command_t a = complete_command(s);

 return a;
}

command_stream_t new_command_stream(void)
{
	command_stream_t nuw = (struct command_stream*) checked_malloc(sizeof(struct command_stream));
	nuw->line_number = 1;
	nuw->token_length = 10; //will resize accordingly
	nuw->head = NULL;
	nuw->tail = nuw->head;
	nuw->add_token = &insert_cs;
	nuw->empty = &empt;
	nuw->pop = &remove_front;
	nuw->free_mem = &frem;
	nuw->top = &front;
	return nuw;

}

word_con new_word_con(word_con a, char *token, command_stream_t c, syntax_values ab)
{
	word_con b = (struct word_container*) checked_malloc(sizeof(struct word_container));
	b->buffer_wc = token;
	b->matching_syntax = ab;
	b->point_prev = a;
	b->point_next = NULL;
	b->line_num =c->line_number;
	return b;
}

word_con front(const void*self)
{
	word_con a = ((command_stream_t)self)->head;
	return a;

}

int empt(const void *self)
{
	if(((command_stream_t)self)->head == NULL)
		return 1;
	else 
		return 0;
}

char* remove_front(const void *self)
{
	char *temp = ((command_stream_t)self)->head->buffer_wc;
	((command_stream_t)self)->head = ((command_stream_t)self)->head->point_next;
	return temp;
}

void frem(const void *self)
{	word_con temp = NULL;
	while(((command_stream_t)self)->tail != NULL)
	{
		temp = ((command_stream_t)self)->tail->point_prev;
		free(((command_stream_t)self)->tail->buffer_wc);
		free(((command_stream_t)self)->tail);
		((command_stream_t)self)->tail = temp; 
	}
	((command_stream_t)self)->head = NULL; 
}

void insert_cs(const void *self, char *ptr, syntax_values a)
{

if(((command_stream_t)self)->head == NULL)
	{
		((command_stream_t)self)->head = new_word_con(NULL, ptr,((command_stream_t)self),a);
		((command_stream_t)self)->tail = ((command_stream_t)self)->head;
	}
else
	{
	word_con temp = new_word_con(((command_stream_t)self)->tail, ptr,((command_stream_t)self), a);
	((command_stream_t)self)->tail->point_next = temp;
	((command_stream_t)self)->tail = temp; 
	}

}

int is_valid(int a)
{
if(a =='!' || a=='%' || a=='_' || a=='+' || a==',' || a=='-' || a=='.' || a=='/' || a==':' || a== '@' || a=='^' || ( a >= 'A' && a <= 'Z' ) || ( a >= 'a' && a <= 'z' ) || ( a >= '0' && a <= '9' ))
	{return 1;}
else
	return 0;

}


command_t righty(command_t c)
{
	while( (c->type == AND_COMMAND) || (c->type == OR_COMMAND))
	{	
		c = c->u.command[0];
	}
	return c;
}

command_t lefty(command_t c)
{	
	if( (c->u.command[1]->type != AND_COMMAND) && (c->u.command[1]->type != OR_COMMAND))
		return c;

	command_t b = lefty(c->u.command[1]);
	command_t temp = righty(b);
	command_t tempy =b;
	//b->u.command[0] = c;
	c->u.command[1] = temp;
	while( (tempy->u.command[0]->type == AND_COMMAND ) || (tempy->u.command[0]->type == OR_COMMAND))
	{
	tempy =tempy->u.command[0];	
	}
	tempy->u.command[0] = c;
	return b;
}



command_t complete_command(command_stream_t a)
{
	command_t c  = andors(a);
	if( c == NULL)
		return NULL;


	if( (c->type == AND_COMMAND) || c->type == OR_COMMAND)
		c = lefty(c);
	word_con b = a->top(a);
	
	//&& (b->point_next == WORD)

	if( ((b->matching_syntax == SEMICOLON) || (b->matching_syntax == NEWLINE)) ) 
	{
		if(b->point_next->matching_syntax == WORD) {
		a->pop(a);
		command_t d = complete_command(a);
		command_t e = (command_t) checked_malloc(sizeof(struct command));
		e->type = SEQUENCE_COMMAND;
		e->input = NULL;
		e->output = NULL;
		e->u.command[0] = c;
		e->u.command[1] = d;
		e->status = -1;
		c = e;
		}
		else
		{a->pop(a);}
	}
	return c;
}

command_t andors(command_stream_t a)
{	// consumue newlines
	command_t c = pipeline(a);
	word_con b = a->top(a);
	if(b->matching_syntax == AND)
	{
		a->pop(a);
		command_t d = andors(a);
		if(d ==NULL)
			error(1,0,"Line Number: %d NO arguments right hand side", a->top(a)->line_num);		
		command_t e = (command_t) checked_malloc(sizeof(struct command));
		e->type = AND_COMMAND;
		e->input = NULL;
		e->output = NULL;
		e->u.command[0] = c;
		e->u.command[1] = d;
		e->status = -1;
		c = e;
	
	
	}
	else if(b->matching_syntax == OR)
	{
		a->pop(a);
		command_t f = andors(a);
		if(f ==NULL)
			error(1,0,"Line Number: %d NO arguments right hand side", a->top(a)->line_num);
		command_t g = (command_t) checked_malloc(sizeof(struct command));
		g->type = OR_COMMAND;
		g->input = NULL;
		g->output = NULL;
		g->u.command[0] = c;
		g->u.command[1] = f;
		g->status = -1;
		c = g;

	}
	return c;
}

command_t pipeline(command_stream_t a)
{
	command_t c = command(a);
	word_con b = a->top(a);
	if(b->matching_syntax == PIPE)
	{
		a->pop(a);
		command_t d = pipeline(a);
		command_t e = (command_t) checked_malloc(sizeof(struct command));
		e->type = PIPE_COMMAND;
		e->input = NULL;
		e->output = NULL;
		e->u.command[0] = c;
		e->u.command[1] = d;
		e->status = -1;
		c = e;
	}
	return c;
}

command_t command(command_stream_t a)
{	
	word_con b = a->top(a);
	
		while(b->matching_syntax==NEWLINE)
		{
		a->pop(a);
		b=a->top(a);
		}
	if(b->matching_syntax == END_OF_FILE)
		return NULL;
	
	if(b->matching_syntax == LP)
	{ command_t c = subshell(a);
	b = a->top(a);
	

	if(b->matching_syntax == LEFT_ARROW)
	{
		a->pop(a);
		b = a->top(a);
		if(b->matching_syntax != WORD)
			error(1,0,"Line Number:%d Invalid Token After <", b->line_num);
		
		c->input = b->buffer_wc;
		a->pop(a);
		
	}

	b= a->top(a);
	if(b->matching_syntax == RIGHT_ARROW)
	{
		a->pop(a);
		b = a->top(a);
		if(b->matching_syntax != WORD)
			error(1,0,"Line Number:%d Invalid Token After >", b->line_num);
		c->output = b->buffer_wc;	
		a->pop(a);
	}
	
	return c;
	
	}
	else
	{
	 command_t d = simple_command(a);
	b = a->top(a);	

	if(b->matching_syntax == LEFT_ARROW)
	{
		a->pop(a);
		b = a->top(a);
		if(b->matching_syntax != WORD)
			error(1,0,"Line Number:%d Invalid Token After <", b->line_num);
		
		d->input = b->buffer_wc;
		a->pop(a);
		
	}
	b = a->top(a);
	if(b->matching_syntax == RIGHT_ARROW)
	{
		a->pop(a);
		b = a->top(a);
		if(b->matching_syntax != WORD)
			error(1,0,"Line Number:%d Invalid Token After >", b->line_num);
		d->output = b->buffer_wc;	
		a->pop(a);
	}
	
	return d;	

	}


}

command_t subshell(command_stream_t a)
{	
	command_t c;
	word_con b = a->top(a);
	if(b->matching_syntax == LP)
	{
		a->pop(a);
		c = complete_command(a);
	}
	 b = a->top(a);

	if(b->matching_syntax != RP)
	{
	error(1,0, "Line Number:%d Expect )", b->line_num); 	
	}

	a->pop(a);
	command_t e = (command_t) checked_malloc(sizeof(struct command));
	e->type = SUBSHELL_COMMAND;
	e->input = NULL;
	e->output = NULL;
	e->status = -1;
	e->u.subshell_command = c;
	
	//get rid of new lines after RP
	b = a->top(a);
	while( b->matching_syntax == NEWLINE)
	{
		a->pop(a);
		b = a->top(a);
	}


	return e;
}

command_t simple_command(command_stream_t a)
{
	int max =20;
	int index = 0;
	char **temp;
	// will resize words accordingly
	word_con b =a->top(a);

	if(b->matching_syntax == WORD)
	{	

		// consume all words that come after
		command_t simp = (command_t) checked_malloc(sizeof(struct command));
		simp->type = SIMPLE_COMMAND;
		simp->u.word= (char **) checked_malloc(max*sizeof(char*));
		simp->u.word[index] = b->buffer_wc;
		a->pop(a);
		b = a->top(a);
		index = index +1;
		while(b->matching_syntax == WORD)
		{
			if(index == max)
			{	max = max+1;
				simp->u.word = (char **) checked_realloc(simp->u.word, max); 
			}
			simp->u.word[index] = b->buffer_wc;
			index = index +1;
			a->pop(a);
			b = a->top(a);

		}
		simp->status = -1;
		simp->input = NULL;
		simp->output = NULL;
		simp->u.word[index] = 0;
		return simp;
	}
	else
	{error(1,0,"Line Number:%d Invalid Syntax", b->line_num);}
}


