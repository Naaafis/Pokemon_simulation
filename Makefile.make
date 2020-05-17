CC = g++ -g -std=c++11

OBJS=main.o Building.o Point2D.o Vector2D.o GameObject.o GameCommand.o PokemonCenter.o Model.o Pokemon.o PokemonGym.o View.o Rival.o BattleArena.o 

default: PA4

PA4: $(OBJS)
	$(CC) -o PA4 $(OBJS) 

Vector2D.o: Vector2D.cpp Vector2D.h
	$(CC) -c Vector2D.cpp -o Vector2D.o 
	
Point2D.o: Point2D.cpp Point2D.h Vector2D.h
	$(CC) -c Point2D.cpp -o Point2D.o 

Building.o: Building.cpp Building.h
	$(CC) -c Building.cpp -o Building.o

GameObject.o: GameObject.cpp GameObject.h Point2D.h Vector2D.h
	$(CC) -c GameObject.cpp -o GameObject.o 

PokemonCenter.o: PokemonCenter.cpp PokemonCenter.h GameObject.h Point2D.h
	$(CC) -c PokemonCenter.cpp -o PokemonCenter.o

Model.o: Model.cpp Model.h GameObject.h Pokemon.h PokemonGym.h PokemonCenter.h View.h Rival.h BattleArena.h
	$(CC) -c Model.cpp -o Model.o 

PokemonGym.o: PokemonGym.cpp PokemonGym.h GameObject.h Point2D.h
	$(CC) -c PokemonGym.cpp -o PokemonGym.o

View.o: View.cpp View.h GameObject.h Point2D.h 
	$(CC) -c View.cpp -o View.o 

Pokemon.o: Pokemon.cpp Pokemon.h GameObject.h Point2D.h Vector2D.h PokemonGym.h PokemonCenter.h Rival.h
	$(CC) -c Pokemon.cpp -o Pokemon.o

Rival.o: Rival.cpp Rival.h Point2D.h Vector2D.h GameObject.h BattleArena.h Pokemon.h 
	$(CC) -c Rival.cpp -o Rival.o

BattleArena.o: BattleArena.cpp BattleArena.h Point2D.h Building.h
	$(CC) -c BattleArena.cpp -o BattleArena.o

GameCommand.o: GameCommand.cpp GameCommand.h Model.h GameObject.h Pokemon.h PokemonGym.h PokemonCenter.h
	$(CC) -c GameCommand.cpp -o GameCommand.o

main.o: main.cpp Building.h Point2D.h Vector2D.h GameCommand.h PokemonCenter.h Model.h Pokemon.h PokemonGym.h GameObject.h View.h
	$(CC) -c main.cpp

clean: 
	rm $(OBJS) PA4

