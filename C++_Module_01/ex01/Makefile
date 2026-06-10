# 1. Program name
NAME = zombieHorde

# 2. Compiler and Compilation Flags
CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98

# 3. Source and Object files
SRC = main.cpp Zombie.cpp zombieHorde.cpp
OBJ = $(SRC:.cpp=.o)

# 4. Header Dependencies (Triggers a rebuild oif the header changes)
HEADERS = Zombie.hpp

# 5. Default Target Rule
all: $(NAME)

# 6. Linking Rule (compiles the final binary executable)
$(NAME): $(OBJ)
		$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

# 7. Compilation Rule (Compiles individual .cpp files into .o obkect files)
%.o: %.cpp $(HEADERS)
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
