NAME = log
CC=c++
FLAGS= -Wall -Wextra -Werror  -std=c++98
SRSC= tests.cpp Account.cpp
OBJS=$(SRSC:.cpp=.o)
all:$(NAME)
$(NAME):$(OBJS)
	$(CC) $(FLAGS) $^ -o $(NAME)
%.o:%.cpp Account.hpp
	$(CC) $(FLAGS) -c $< -o $@
clean:
	rm -f $(OBJS)
fclean: clean
	rm $(NAME)
re: fclean all