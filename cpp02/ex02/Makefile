NAME = BraiiiiiiinnnzzzZ
C=c++
FLAGS= -Wall -Wextra -Werror  -std=c++98
SRSC= main.cpp Zombie.cpp newZombie.cpp randomChump.cpp
OBJS=$(SRSC:.cpp=.o)
all:$(NAME)
$(NAME):$(OBJS)
	$(C) $(FLAGS) $^ -o $(NAME)
%.o:%.cpp Zombie.hpp
	$(C) $(FLAGS) -c $< -o $@
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all