NAME = megaphone
CC=c++
FLAGS= -Wall -Wextra -Werror  -std=c++98
SRSC= HumanA.cpp HumanB.cpp Weapon.cpp main.cpp
OBJS=$(SRSC:.cpp=.o)
all:$(NAME)
$(NAME):$(OBJS)
	$(CC) $(FLAGS) $^ -o $(NAME)
%.o:%.cpp
	$(CC) $(FLAGS) -c $< -o $@
clean:
	rm -f $(OBJS)
fclean: clean
	rm $(NAME)
re: fclean all