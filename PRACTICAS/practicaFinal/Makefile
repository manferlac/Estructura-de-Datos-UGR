SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c --std=c++11

all:$(BIN)/test_imagen $(BIN)/test_quadtree $(BIN)/descubre_objetivos

# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile


# ************ Compilación de módulos ************

$(BIN)/descubre_objetivos: $(OBJ)/descubre_objetivos.o $(OBJ)/ciudades.o $(OBJ)/ciudad.o $(OBJ)/posicion.o $(OBJ)/Quadtree.o $(OBJ)/imagenES.o $(OBJ)/imagen.o $(OBJ)/pintaformas.o
	$(CXX) -o $(BIN)/descubre_objetivos $(OBJ)/descubre_objetivos.o $(OBJ)/ciudades.o $(OBJ)/ciudad.o $(OBJ)/posicion.o $(OBJ)/Quadtree.o $(OBJ)/imagenES.o $(OBJ)/imagen.o $(OBJ)/pintaformas.o -Iinclude

$(BIN)/test_imagen: $(OBJ)/test_imagen.o $(OBJ)/imagenES.o $(OBJ)/imagen.o $(OBJ)/pintaformas.o 
	$(CXX) -o $(BIN)/test_imagen $(OBJ)/test_imagen.o $(OBJ)/imagenES.o $(OBJ)/imagen.o $(OBJ)/pintaformas.o -Iinclude

$(BIN)/test_quadtree: $(OBJ)/test_quadtree.o $(OBJ)/Quadtree.o
	$(CXX) -o $(BIN)/test_quadtree $(OBJ)/test_quadtree.o $(OBJ)/Quadtree.o

$(OBJ)/descubre_objetivos.o: $(SRC)/descubre_objetivos.cpp 
	$(CXX) -c -o $(OBJ)/descubre_objetivos.o $(SRC)/descubre_objetivos.cpp -Iinclude 

$(OBJ)/test_quadtree.o: $(SRC)/test_quadtree.cpp $(INC)/ArbolGeneral.h $(INC)/ArbolGeneral.cpp
	$(CXX) $(CPPFLAGS)  $(SRC)/test_quadtree.cpp -o  $(OBJ)/test_quadtree.o

$(OBJ)/test_imagen.o: $(SRC)/test_imagen.cpp 
	$(CXX) -c -o $(OBJ)/test_imagen.o $(SRC)/test_imagen.cpp -Iinclude 





$(OBJ)/ciudades.o: $(SRC)/ciudades.cpp $(INC)/ciudades.h
	$(CXX) -c -o $(OBJ)/ciudades.o $(SRC)/ciudades.cpp -Iinclude

$(OBJ)/ciudad.o: $(SRC)/ciudad.cpp $(INC)/ciudad.h
	$(CXX) -c -o $(OBJ)/ciudad.o $(SRC)/ciudad.cpp -Iinclude

$(OBJ)/posicion.o: $(SRC)/posicion.cpp $(INC)/posicion.h
	$(CXX) -c -o $(OBJ)/posicion.o $(SRC)/posicion.cpp -Iinclude

$(OBJ)/Quadtree.o: $(SRC)/Quadtree.cpp $(INC)/Quadtree.h $(INC)/ArbolGeneral.h $(INC)/ArbolGeneral.cpp
	$(CXX) $(CPPFLAGS)  $(SRC)/Quadtree.cpp -o  $(OBJ)/Quadtree.o

$(OBJ)/imagenES.o: $(SRC)/imagenES.cpp $(INC)/imagenES.h
	$(CXX) -c -o $(OBJ)/imagenES.o $(SRC)/imagenES.cpp -Iinclude

$(OBJ)/imagen.o: $(SRC)/imagen.cpp $(INC)/imagen.h
	$(CXX) -c -o $(OBJ)/imagen.o $(SRC)/imagen.cpp -Iinclude

$(OBJ)/pintaformas.o: $(SRC)/pintaformas.cpp $(INC)/pintaformas.h
	$(CXX) -c -o $(OBJ)/pintaformas.o $(SRC)/pintaformas.cpp -Iinclude




# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
