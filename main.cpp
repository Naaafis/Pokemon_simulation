#include "Point2D.h"
#include "View.h"
#include "Model.h"
#include "GameCommand.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <ctime>
#include <fstream>

using namespace std;

//Function prototypes
bool IsNumber(string s);
bool IsWhiteSpace(string s);

const string POKEMON_BANNER = "                                  ,'\\\n"
                              "    _.----.        ____         ,'  _\\   ___    ___     ____\n"
                              "_,-'       `.     |    |  /`.   \\,-'    |   \\  /   |   |    \\  |`.\n"
                              "\\      __    \\    '-.  | /   `.  ___    |    \\/    |   '-.   \\ |  |\n"
                              " \\.    \\ \\   |  __  |  |/    ,','_  `.  |          | __  |    \\|  |\n"
                              "   \\    \\/   /,' _`.|      ,' / / / /   |          ,' _`.|     |  |\n"
                              "    \\     ,-'/  /   \\    ,'   | \\/ / ,`.|         /  /   \\  |     |\n"
                              "     \\    \\ |   \\_/  |   `-.  \\    `'  /|  |    ||   \\_/  | |\\    |\n"
                              "      \\    \\ \\      /       `-.`.___,-' |  |\\  /| \\      /  | |   |\n"
                              "       \\    \\ `.__,'|  |`-._    `|      |__| \\/ |  `.__,'|  | |   |\n"
                              "        \\_.-'       |__|    `-._ |              '-.|     '-.| |   |\n"
                              "                                `'                            '-._|";
// TODO: Add help menu
int main(int argc, char** argv) {
    // Welcome Message
    cout << "EC327: Introduction to Software Engineering" << endl;
    cout << "Fall 2019" << endl;
    cout << "Programming Assignment 3" << endl;
    cout << POKEMON_BANNER << endl;
    //constructing the game model
    Model game_model;
    View game_view;

    bool game_is_running = true;
    game_model.ShowStatus();
    game_model.Display(game_view);

    /*bool read_from_file = false;
    game_model.ShowStatus();
    game_model.Display(game_view);
    ifstream input_file;
    if (argc == 2) {
        input_file.open(argv[1], ios_base::in);
        if (!input_file.is_open()) {
            cout << "Failed to open input file " << argv[1] << endl;
            exit(EXIT_FAILURE);
        }
        read_from_file = true;
        srand(0);
    } else
    */
        
    srand(time(NULL));

    while (game_is_running) 
    {
        cout << "Enter command: ";
        char command = 'a';
        int id = 0;
        int id1 = 0;
        int id2 = 0;
        bool error = false;
        string input = "'";
        char type = ' ';
        double x = 0;
        double y = 0;
        unsigned int stamina_amount = 0;
        unsigned int training_unit_amount = 0;
        try
        {
        /*
        if (read_from_file) {
            getline(input_file, input);
        } else
            getline(cin, input);
        if (input.length() > 0 and !IsWhiteSpace(input)) {
            istringstream iss(input);
            vector<string> tokens;
            copy(istream_iterator<string>(iss),
                 istream_iterator<string>(),
                 back_inserter<vector<string> >(tokens));
            if (tokens[0].length() == 1)
                command = tokens[0][0];
            else
                error = true; */
            getline(cin, input);

            if (input.length() > 0 && !IsWhiteSpace(input))
            {

                istringstream iss(input);
                vector<string> tokens;
                copy(istream_iterator<string>(iss),
                    istream_iterator<string>(),
                    back_inserter<vector<string>>(tokens));
                if (tokens[0].length() == 1)
                    {
                        command = tokens[0][0];
                    }
                else
                    throw Invalid_Input("Please enter a valid command!");

                switch (command) 
                {
                //moving a Pikachu to a locationsw
                case 'm':
                    if (tokens.size() == 4) 
                    {
                        id = atoi(tokens[1].c_str());
                        x = atof(tokens[2].c_str());
                        y = atof(tokens[3].c_str());
                        Point2D moveTo = Point2D(x, y);
                        DoMoveCommand(game_model, id, moveTo);
                        game_model.Display(game_view);
                    }
                    else 
                    {
                        throw Invalid_Input("Not an integer or double");
                    }
                    break;
                case 'c':
                    if (tokens.size() == 3) 
                    {
                        id = atoi(tokens[1].c_str());
                        id2 = atoi(tokens[2].c_str());
                        DoMoveToCenterCommand(game_model, id, id2);
                        game_model.Display(game_view);
                    }
                    else 
                    {
                        throw Invalid_Input("Not an integer or double");
                    }
                    break;
                case 'g':
                    if (tokens.size() == 3) 
                    {
                        id = atoi(tokens[1].c_str());
                        id2 = atoi(tokens[2].c_str());
                        DoMoveToGymCommand(game_model, id, id2);
                        game_model.Display(game_view);
                    }
                    else 
                    {
                        throw Invalid_Input("Not an integer input or invalid amount of inputs");
                    }
                    break;
                case 'a':
                    if (tokens.size() == 3)
                    {
                        id = atoi(tokens[1].c_str());
                        id2 = atoi(tokens[2].c_str());
                        DoMoveToArenaCommand(game_model, id, id2);
                        game_model.Display(game_view);
                    }
                    else
                    {
                        throw Invalid_Input("Not an integer input or invalid amounts of input");
                    }
                    break;
                case 'r':
                    if (tokens.size() == 3)
                    {
                        id = atoi(tokens[1].c_str());
                        stamina_amount = atoi(tokens[2].c_str());
                        DoRecoverInCenterCommand(game_model, id, stamina_amount);
                        game_model.Display(game_view);
                    }
                    else
                    {
                        throw Invalid_Input("Not an integer input or invalid amounts of input");
                    }
                    break;
                case 't':
                    if (tokens.size() == 3) 
                    {
                        id = atoi(tokens[1].c_str());
                        training_unit_amount = atoi(tokens[2].c_str());
                        DoTrainInGymCommand(game_model, id, training_unit_amount);
                        game_model.Display(game_view);
                    }
                    else 
                    {
                        throw Invalid_Input("Not an integer input or not enough inputs");
                    }
                    break;
                case 's':
                    if (tokens.size() == 2) 
                    {
                        id = atoi(tokens[1].c_str());
                        DoStopCommand(game_model, id);
                        game_model.Display(game_view);
                    }
                    else 
                    {
                        throw Invalid_Input("Not an integer input or too many inputs");
                    }
                    break;
                //advance one tick
                case 'v':
                    if (tokens.size() == 1) {
                        DoGoCommand(game_model, game_view);
                    }
                    else 
                    {
                        throw Invalid_Input("Not an integer input or too many inputs");
                    }
                    break;
                //advance 5 time ticks or until next event
                case 'x':
                    if (tokens.size() == 1) {
                        DoRunCommand(game_model, game_view);
                    }
                    else 
                    {
                        throw Invalid_Input("Too many inputs or not a GameModel or GameView input");
                    }
                    break;
                //battle
                case 'b':
                    if (tokens.size() == 3)
                    {
                        id = atoi(tokens[1].c_str());
                        id2 = atoi(tokens[2].c_str());
                        DoBattleCommand(game_model, id, id2);
                        game_model.Display(game_view);
                    }
                    else
                    {
                        throw Invalid_Input("Inputs are incorrect or not enough inputs");
                    }
                    break;
                //create new objects 
                case 'n':
                    if (tokens.size() == 5)
                    {
                        type = *tokens[1].c_str();
                        id = atoi(tokens[2].c_str());
                        x = atof(tokens[3].c_str());
                        y = atof(tokens[4].c_str());
                        Point2D location = Point2D(x, y);
                        game_model.NewCommand(game_model, type, id, location);
                        
                        game_model.Display(game_view);
                    }
                    else
                    {
                        throw Invalid_Input("Inputs are incorrect or not enough inputs");
                    }
                    break;
                //quit the program
                case 'q':
                    if (tokens.size() == 1) 
                    {
                        cout << "Terminating program." << endl;
                        game_is_running = false;
                    }
                    else 
                    {
                        throw Invalid_Input("ERROR: Please enter a valid command!");
                    }
                    break;
                default:
                    throw Invalid_Input("ERROR: Please enter a valid command!");
                    break;
                }
            }
        }

        catch (Invalid_Input &except)
        {
            cout << "Invalid input -> " << except.msg_ptr << endl;
        }
    }
    return 0;
}

bool IsNumber(string s)
{
    for(int i = 0; i < s.length(); i++) 
    {
        if(!(s[i] >= '0' && s[i] <= '9')) 
        {
            return false;
        }
    }
    return true;
}

bool IsWhiteSpace(string s) 
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != ' ' && s[i] != '\t') 
        {
            return false;
        }
    }
    return true;
}

