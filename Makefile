GCC = g++


Checkpoint3: TestCheckpoint3.o GameObject.o Point2D.o Vector2D.o Building.o PokemonCenter.o PokemonGym.o Pokemon.o 
	$(GCC) TestCheckpoint3.o GameObject.o Point2D.o Vector2D.o Building.o PokemonCenter.o PokemonGym.o Pokemon.o -o Checkpoint3

TestCheckpoint3.o: TestCheckpoint3.cpp
	$(GCC) -c TestCheckpoint3.cpp -o TestCheckpoint3.o

GameObject.o: GameObject.cpp
	$(GCC) -c GameObject.cpp -o GameObject.o

Point2D.o: Point2D.cpp
	$(GCC) -c Point2D.cpp -o Point2D.o

Vector2D.o: Vector2D.cpp
	$(GCC) -c Vector2D.cpp -o Vector2D.o

Building.o: Building.cpp
	$(GCC) -c Building.cpp -o Building.o

PokemonCenter.o: PokemonCenter.cpp
	$(GCC) -c PokemonCenter.cpp -o PokemonCenter.o

PokemonGym.o: PokemonGym.cpp
	$(GCC) -c PokemonGym.cpp -o PokemonGym.o

Pokemon.o: Pokemon.cpp
	$(GCC) -c Pokemon.cpp -o Pokemon.o

clean:
	rm TestCheckpoint3.o GameObject.o Point2D.o Vector2D.o Building.o PokemonCenter.o PokemonGym.o Pokemon.o Checkpoint3
