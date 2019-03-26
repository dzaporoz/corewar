#ifndef ASMCW_ASM_H
#define ASMCW_ASM_H
#include <fcntl.h>
#include "op.h"
#include <stdio.h>
#include "../libft/libft.h"
#define NAME 1
#define COMMENT 2
# define RED   "\x1B[31m"
# define CYN   "\x1B[36m"
# define RESET "\x1B[0m"
# define MAG   "\x1B[35m"
#define IS_SEPARATOR(a) (a == ' ' || a == '\t' || a == '\v')
#define SRC_NOT_READ(name) ft_printf("%sCan't read source file %s%s\n%s",CYN, RED, name, RESET); exit(0)
#define IS_COMMENT(file) (file == COMMENT_CHAR || file ==  ALT_COMMENT_CHAR)

typedef struct s_lable t_lable;

typedef struct s_inst
{
    char *name;
    unsigned char nb_arg;
    char    *args[3];
    t_arg_type types[3];
    size_t size;
    t_lable *lable;
    size_t incr;
}          t_inst;
typedef struct s_lable
{
    char *name;
    unsigned addr;
    t_inst *opp;
}              t_lable;
char *read_from_file(char *file_name);
void        skip_comment(char **file);
void        skip_separators(char **file);
t_list    *tokenize(char *file);
void	free_str_arr(char **arr, int size);
int						count_size(char **arr);
void		put_err_msg_exit(char *str);
t_list		*add_to_the_end_of_list(t_list *head, t_list *new);
t_list *validate_command(t_op *op, int *line_nbr, char *line);
size_t validate_lable(t_list **lables, char *line, int *line_nbr);
int         full(t_list *info);
t_list		*find_last(t_list *head);
void    give_op_lable(t_list *op, t_list **lables);
int         is_free(char *line);
int         is_lable(char *line);
void    save_instruction(char **file, t_list **instructions, t_list **lables, int *line_nbr);
void    write_binary(t_list *arguments);
unsigned int		reverse_byte(unsigned int byte);
int     give_op_index(char *op_name);
int						spec_atoi(const char *str);
extern size_t g_written_bytes;
extern size_t g_size;
extern char *g_champ_name;
t_op    *find_op(char **crawler);
#endif
