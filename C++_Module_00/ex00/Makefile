# 1. Program name
NAME = megaphone

# 2. Compiler and Compilation Flags
CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98

# 3. Source and Object files
SRC = megaphone.cpp
OBJ = $(SRC:.cpp=.o)

# 5. Default Target Rule
all: $(NAME)

# 6. Linking Rule (compiles the final binary executable)
$(NAME): $(OBJ)
		$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

# 7. Compilation Rule (Compiles individual .cpp files into .o obkect files)
%.o: %.cpp
		$(CXX) $(CXXFLAGS) -c $< -o $@

# 8. Clean Rules
clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)
		
# 9. Rebuild Rule
re: fclean all

# 10. Phony Targets (Prevents conflicts with files named clean/fclean/re)
.PHONY: all clean fclean re
