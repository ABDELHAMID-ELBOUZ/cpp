NAME = identify

CXX = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp Base.cpp functions.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp A.hpp Base.hpp B.hpp C.hpp functions.hpp
	$(CXX) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

