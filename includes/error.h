#ifndef ERROR_H
# define ERROR_H

/*Not enough arguements given to the program at launch*/
int arguement_error();

/*There was an error, that a path could not be found*/
char *error_paths();

/*The pipe didn't get initalizted correctly*/
int pipe_error();

/*THere was an issue splitting the commands*/
int command_error();
#endif