NAME = philo
CC = gcc
CFLAGS = -g3 -Wall -Wextra -Werror -pthread
SRCS = main.c utils.c parse_args.c init_setup_table.c setup_mutexes.c setup_table.c thread_routine.c thread_routine_2.c monitor.c actions.c actions_2.c create_threads.c time_utils.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c philo.h philo_utils.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
