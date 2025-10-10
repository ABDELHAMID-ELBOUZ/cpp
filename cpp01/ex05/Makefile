NAME = Harl
C=c++
FLAGS= -Wall -Wextra -Werror  -std=c++98
SRSC= main.cpp Harl.cpp
OBJS=$(SRSC:.cpp=.o)
all:$(NAME)
$(NAME):$(OBJS)
	$(C) $(FLAGS) $^ -o $(NAME)
%.o:%.cpp Harl.hpp
	$(C) $(FLAGS) -c $< -o $@
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all