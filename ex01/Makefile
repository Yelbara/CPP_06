NAME = ex01
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp   Serializer.cpp Data.cpp
OBJS = $(SRCS:.cpp=.o) #name.o // also name don't have file is name 

all: $(NAME)

$(NAME): $(OBJS) # need objs=name.o= also name =:> i need make this file name.o use this row(%.o: %.cpp) if have him or work auto 
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp #when need name.o use this row auto  
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:  clean  #.PHONY: all clean re