NAME = BraiiiiiiinnnzzzZ
CC=c++
FLAGS= -Wall -Wextra -Werror  -std=c++98
SRSC= main.cpp Zombie.cpp zombieHorde.cpp 
OBJS=$(SRSC:.cpp=.o)
all:$(NAME)
$(NAME):$(OBJS)
	$(CC) $(FLAGS) $^ -o $(NAME)
%.o:%.cpp Zombie.hpp
	$(CC) $(FLAGS) -c $< -o $@
clean:
	rm -f $(OBJS)
fclean: clean
	rm $(NAME)
re: fclean all