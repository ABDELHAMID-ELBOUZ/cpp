NAME = PhoneBook
C=c++
FLAGS= -Wall -Wextra -Werror -g  -std=c++98
SRSC= main.cpp PhoneBook.cpp Contact.cpp
OBJS=$(SRSC:.cpp=.o)
all:$(NAME)
$(NAME):$(OBJS)
	$(C) $(FLAGS) $^ -o $(NAME)
%.o:%.cpp PhoneBook.hpp
	$(C) $(FLAGS) -c $< -o $@
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all