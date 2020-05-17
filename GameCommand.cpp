#include "GameCommand.h"
#include <iostream>

void DoMoveCommand(Model& model, int pokemon_id, Point2D p1) {
    if (model.GetPokemonPtr(pokemon_id) != 0) 
    {
        cout << "Moving " << model.GetPokemonPtr(pokemon_id)->GetName()
             << " to " << p1 << endl;
        model.GetPokemonPtr(pokemon_id)->StartMoving(p1);
    } else
        cout << "ERROR: Please enter a valid command!" << endl;
}

void DoMoveToCenterCommand(Model& model, int pokemon_id, int center_id) {
    if (model.GetPokemonPtr(pokemon_id) != 0 && model.GetPokemonCenterPtr(center_id) != 0) {
        cout << "Moving " << model.GetPokemonPtr(pokemon_id)->GetName()
             << " to center " << center_id << endl;
        model.GetPokemonPtr(pokemon_id)->StartMovingToCenter(model.GetPokemonCenterPtr(center_id));
    } else
        cout << "ERROR: Please enter a valid command!" << endl;
}

void DoMoveToGymCommand(Model& model, int pokemon_id, int gym_id) {
    if (model.GetPokemonPtr(pokemon_id) != 0 && model.GetPokemonGymPtr(gym_id) != 0) {
        cout << "Moving " << model.GetPokemonPtr(pokemon_id)->GetName()
             << " to gym " << gym_id << endl;
        model.GetPokemonPtr(pokemon_id)->StartMovingToGym(model.GetPokemonGymPtr(gym_id));
    } else
        cout << "ERROR: Please enter a valid command!" << endl;
}

void DoMoveToArenaCommand(Model &model, int pokemon_id, int arena_id)
{
    if (model.GetPokemonPtr(pokemon_id) != 0)
    {
        cout << "Moving " << model.GetPokemonPtr(pokemon_id)->GetName() << " to Battle Arena " << arena_id << endl;
        model.GetPokemonPtr(pokemon_id)->StartMovingToArena(model.GetBattleArenaPtr(arena_id));
    }
    else
        cout << "ERROR: Please enter a valid command!" << endl;
}

void DoStopCommand(Model& model, int pokemon_id) {
    if (model.GetPokemonPtr(pokemon_id) != 0) {
        cout << "Stopping " << model.GetPokemonPtr(pokemon_id)->GetName() << endl;
        model.GetPokemonPtr(pokemon_id)->Stop();
    } else
        cout << "ERROR: Please enter a valid command!" << endl;
}

void DoTrainInGymCommand(Model& model, int pokemon_id, unsigned int training_units) {
    if (model.GetPokemonPtr(pokemon_id) != 0) {
        cout << "Training " << model.GetPokemonPtr(pokemon_id)->GetName() << endl;
        model.GetPokemonPtr(pokemon_id)->StartTraining(training_units);
    } else
        cout << "ERROR: Please enter a valid command!" << endl;
}

void DoRecoverInCenterCommand(Model& model, int pokemon_id, unsigned int stamina_points) {
    if (model.GetPokemonPtr(pokemon_id) != 0) {
        cout << "Recovering " << model.GetPokemonPtr(pokemon_id)->GetName() << "'s stamina" << endl;
        model.GetPokemonPtr(pokemon_id)->StartRecoveringStamina(stamina_points);
    } else
        cout << "ERROR: Please enter a valid command!" << endl;
}

void DoBattleCommand(Model &model, int pokemon_id, int rival_id)
{
    if (model.GetPokemonPtr(pokemon_id) != 0 && model.GetRivalPtr(rival_id) != 0 && model.GetPokemonPtr(pokemon_id)->GetState() == IN_ARENA)
    {
        cout << model.GetPokemonPtr(pokemon_id)->GetId() << "Getting ready for the battle" << endl;
        model.GetPokemonPtr(pokemon_id)->ReadyBattle(model.GetRivalPtr(rival_id));
    }
    else
        cout << "ERROR: Please enter a valid command!" << endl;
}


void DoGoCommand(Model& model, View& view) {
    cout << "Advancing one tick." << endl;
    model.Update();
    model.ShowStatus();
    model.Display(view);
}

void DoRunCommand(Model& model, View& view) {
    cout << "Advancing to next event." << endl;
    int count = 0;
    bool event = false;
    while (count < 5 && !event) {
        event = model.Update();
        count++;
    }
    model.ShowStatus();
    model.Display(view);
}



