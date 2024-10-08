NAME = base
HEADER = Base.hpp A.hpp B.cpp C.hpp
SRC = Base.cpp main.cpp
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

%.o:%.cpp Makefile $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ) 
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

RM = rm -rf

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re