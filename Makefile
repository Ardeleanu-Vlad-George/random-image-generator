TRG := out/randimagen
OBJ := obj/main.o obj/io.o obj/comp.o obj/rnd_rgba_img.o obj/cla.o

$(TRG): $(OBJ)
	g++ -o $@ $^ -lsfml-graphics -lsfml-system #-lcommon_cla_op

$(OBJ): obj/%.o : src/%.cpp
	g++ -g -c -I inc/ -std=c++98 -o $@ $^

clean:
	rm $(OBJ)

