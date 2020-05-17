#include <iostream>
#include "Point2D.h"
#include "Vector2D.h"
#include "GameObject.h"
#include "Building.h"
#include "PokemonCenter.h"
#include "PokemonGym.h"
using namespace std;

int main()
{
	Point2D testPoint(1.0,0.0);
	Building Building1('A', 1, testPoint);
	Building1.AddOnePokemon();
	Building1.AddOnePokemon();
	Building1.RemoveOnePokemon();
	Building1.ShowStatus();

	PokemonCenter PokeCenter1;

	if (PokeCenter1.HasStaminaPoints() == true)
	{
		cout << "\nworking";
	}

	cout << PokeCenter1.GetNumStaminaPointsRemaining();

	if (PokeCenter1.CanAffordStaminaPoints(5, 10000000) == 1)
	{
		cout << "\nworking";
	}

	cout << PokeCenter1.GetDollarCost(5);

	PokeCenter1.Update();

	cout << "\n" << PokeCenter1.DistributeStamina(1000000);
	cout << "\nRemaining points: " << PokeCenter1.GetNumStaminaPointsRemaining();


	PokeCenter1.Update();
	if (PokeCenter1.Update() == 0)
	{
		cout << "\n Working";
	}

	PokemonGym PokeGym1;
	cout << "\n" << PokeGym1.GetDollarCost(5);
	cout << "\n" << PokeGym1.GetStaminaCost(5);
	cout << "\n" << PokeGym1.GetNumTrainingUnitsRemaining();

	if (PokeGym1.IsAbleToTrain(1,1000,1000) == 1)
	{
		cout << "\nworking";
	}

	cout << "\n" << PokeGym1.TrainPokemon(5);
	cout << "\n" << PokeGym1.GetNumTrainingUnitsRemaining();
	PokeGym1.TrainPokemon(5);
	PokeGym1.Update();
	PokeGym1.Update();
	if (PokeGym1.IsBeaten() == 1)
		{cout << "\nIs Working";}





}