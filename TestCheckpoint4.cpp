#include "Point2D.h"
#include "Vector2D.h"
#include "GameObject.h"
#include "Building.h"
#include "PokemonCenter.h"
#include "PokemonGym.h"
#include "Pokemon.h"
#include "Model.h"
#include "View.h"
#include "GameCommand.h"

#include <iostream>
#include "string.h"
#include "math.h"
#include "stdlib.h"


int main()
{
    srand(time(NULL));
    
    Model model = Model();
    View view = View();

    //view.Clear();
    //view.Draw();

    model.Display(view);

    DoMoveCommand(model, 3, Point2D(7,13));
    DoMoveCommand(model, 1, Point2D(7, 1));
    DoMoveCommand(model, 2, Point2D(13,3));

    //DoGoCommand(model, view);
    DoRunCommand(model, view);
    //model.ShowStatus();

    DoTrainInGymCommand(model, 1, 2);
    DoMoveToGymCommand(model, 2, 2);

    DoRunCommand(model, view);
    DoRunCommand(model, view);

    DoTrainInGymCommand(model, 2, 1);

    DoRunCommand(model, view);

    DoMoveToCenterCommand(model, 2, 1);

    DoRunCommand(model, view);
    DoRunCommand(model, view);

    DoMoveToCenterCommand(model, 1, 1);

    DoRunCommand(model, view);
    DoRunCommand(model, view);

    DoTrainInGymCommand(model, 1, 2);
    DoRecoverInCenterCommand(model, 1, 7);

    DoRunCommand(model, view);
    


 /*   DoMoveCommand(model, 1, Point2D(18,24));
    DoMoveCommand(model, 1, Point2D(18,24));
    DoMoveCommand(model, 1, Point2D(18,24));
    DoMoveCommand(model, 1, Point2D(18,24));
    DoMoveCommand(model, 1, Point2D(18,24));
    DoMoveCommand(model, 1, Point2D(18,24));
    DoMoveCommand(model, 1, Point2D(18,24));

    DoRunCommand(model, view);
*/
}

