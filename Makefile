TRG := out/randimagen
OBJ := obj/main.o

$(TRG): $(OBJ)
	g++ -o $@ $^ -lsfml-graphics -lsfml-system

$(OBJ): obj/%.o : src/%.cpp
	g++ -c -I inc/ -std=c++98 -o $@ $^

clean:
	rm $(OBJ)

