NAME = Weapon
C=c++
FLAGS= -Wall -Wextra -Werror  -std=c++98
SRSC= HumanA.cpp HumanB.cpp Weapon.cpp main.cpp
OBJS=$(SRSC:.cpp=.o)
all:$(NAME)
$(NAME):$(OBJS)
	$(C) $(FLAGS) $^ -o $(NAME)
%.o:%.cpp Weapon.hpp
	$(C) $(FLAGS) -c $< -o $@
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all