#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <string>

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

using namespace std;

int main()
{
    cout << "EC327: Introduction to Software Engineering" << endl;
    cout << "Fall 2019" << endl;
    cout << "Programming Assignment 3" << endl;
    
    
    cout << "                                  ,'\\ " << endl;
    cout << "   _.----.        ____         ,'  _\\   ___    ___     ____ " << endl;
    cout << "_,-'       `.     |    |  /`.   \\,-'    |   \\  /   |   |    \\  |`. " << endl;
    cout << "\\      __    \\    '-.  | /   `.  ___    |    \\/    |   '-.   \\ |  | " << endl;
    cout << " \\.    \\ \\   |  __  |  |/    ,','_  `.  |          | __  |    \\|  | " << endl;
    cout << "   \\    \\/   /,' _`.|      ,' / / / /   |          ,' _ `.  |    |  | " << endl;
    cout << "    \\     ,-'/  /   \\    ,'   | \\/ / ,`.|         /  /   \\ |      | " << endl;
    cout << "     \\    \\ |   \\_/  |   `-.  \\    `'  /|  |    ||   \\_/ | |\\    | " << endl;
    cout << "      \\    \\ \\      /       `-.`.___,-' |  |\\  /| \\      / |  |  | " << endl;
    cout << "       \\    \\ `.__,'|  |`-._    `|      |__| \\/ |  `.__,'|  | |   | " << endl;
    cout << "        \\_.-'       |__|    `-._ |              '-.|     '-.| |   | " << endl;
    cout << "                                `'                            '-._| " << endl;

    
    
    
    char entryCode = 0;
    double x;
    double y;
    int id1;
    int id2;
    unsigned int stamina_amount;
    unsigned int unit_amount;

    srand(time(NULL));
    
    Model model = Model();
    View view = View();

    model.Display(view);


    while (entryCode != 'q')
    {
        cout << "Enter Command: ";
        cin >> entryCode;

        switch (entryCode)
        {
            case 'm':
            {    
                cin >> id1;
                cin >> x;
                cin >> y;
                DoMoveCommand(model, id1, Point2D(x,y));
                break;
            }

            case 'g':
            {
                cin >> id1;
                cin >> id2;
                DoMoveToGymCommand(model, id1, id2);
                break;
            }

            case 'c':
            {
                cin >> id1;
                cin >> id2;
                DoMoveToCenterCommand(model, id1, id2);
                break;
            }

            case 's':
            {
                cin >> id1;
                DoStopCommand(model, id1);
                break;
            }

            case 'r':
            {
                cin >> id1;
                cin >> stamina_amount;
                DoRecoverInCenterCommand(model, id1, stamina_amount);
                break;
            }

            case 't':
            {
                cin >> id1;
                cin >> unit_amount;
                DoTrainInGymCommand(model, id1, unit_amount);
                break;
            }

            case 'v':
            {
                DoGoCommand(model, view);
                break;
            }

            case 'x':
            {
                DoRunCommand(model, view);
                break;
            }

            case 'q':
            {
                break;
            }

            default:
            {
                cout << "Please enter a valid command" << endl;
                break;
            }
        }

    }

    return 0;
}


/*
cout << "                                  ,'\\ " << endl;
cout << "   _.----.        ____         ,'  _\\   ___    ___     ____ " << endl;
cout << "_,-'       `.     |    |  /`.   \\,-'    |   \\  /   |   |    \\  |`. " << endl;
cout << "\\      __    \\    '-.  | /   `.  ___    |    \\/    |   '-.   \\ |  | " << endl;
cout << " \\.    \\ \\   |  __  |  |/    ,','_  `.  |          | __  |    \\|  | " << endl;
cout << "   \\    \\/   /,' _`.|      ,' / / / /   |          ,' _`.|     |  | " << endl;
cout << "    \\     ,-'/  /   \\    ,'   | \\/ / ,`.|         /  /   \\  |     | " << endl;
cout << "     \\    \\ |   \\_/  |   `-.  \\    `'  /|  |    ||   \\_/  | |\\    | " << endl;
cout << "      \\    \\ \\      /       `-.`.___,-' |  |\\  /| \\      /  | |   | " << endl;
cout << "       \\    \\ `.__,'|  |`-._    `|      |__| \\/ |  `.__,'|  | |   | " << endl;
cout << "        \\_.-'       |__|    `-._ |              '-.|     '-.| |   | " << endl;
cout << "                                `'                            '-._| " << endl;
*/