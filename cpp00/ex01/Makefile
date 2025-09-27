NAME = PhoneBook
CC=c++
FLAGS= -Wall -Wextra -Werror -g # -std=c++98
SRSC= main.cpp PhoneBook.cpp Contact.cpp
OBJS=$(SRSC:.cpp=.o)
all:$(NAME)
$(NAME):$(OBJS)
	$(CC) $(FLAGS) $^ -o $(NAME)
%.o:%.cpp PhoneBook.hpp
	$(CC) $(FLAGS) -c $< -o $@
clean:
	rm -f $(OBJS)
fclean: clean
	rm $(NAME)
re: fclean all