#include <iostream>
#include "GameObject.h"
#include "Vector2D.h"
#include "Point2D.h"
#include "Building.h"
#include "PokemonCenter.h"
#include "PokemonGym.h"
#include "Pokemon.h"
#include "time.h"
#include "stdlib.h"

using namespace std;

int main()
{

srand(time(NULL));

//Testing PokemonCenter class

    PokemonCenter Center1 = PokemonCenter(1, 5, 15, Point2D(0, 0.3));

    //Test PokemonCenter visibility
    cout << "Is Center 1 visible? " << Center1.ShouldBeVisible() << endl;

    //Shows status of Center
    Center1.ShowStatus();
    cout << endl;

    //Tells whether Center was updated
    Center1.Update(); 
    cout << endl;
  
//Testing PokemonGym
    
    PokemonGym gym1 = PokemonGym(25, 5, 1, 5, 1, Point2D(8, 7.3));    

    cout << "Is Gym 1 visible? " << gym1.ShouldBeVisible() << endl;

    gym1.ShowStatus();
    cout << endl;
    gym1.Update();
    cout << endl;
    

//Testing Pokemon
    //string in_name, int in_id, char in_code, unsigned int in_speed, Point2D in_loc
    
    Pokemon pikachu = Pokemon("Pikachu", 1, 'P', 3, Point2D(0,0));
    Pokemon p2 = Pokemon();
    Pokemon p3 = Pokemon('P');

    
    pikachu.StartMoving(Point2D(12,13));
    pikachu.Update();
    cout << endl;
    pikachu.ShowStatus();
    cout << endl;
    

    while (pikachu.GetState() == 1)
    {
        pikachu.StartMoving(Point2D(12,13));
        cout << endl;
        pikachu.Update();
        cout << endl;
        pikachu.ShowStatus();
        cout << endl;
    }

    pikachu.StartMoving(Point2D(12,13));
    cout << endl;
    
    pikachu.StartMovingToGym(&gym1);
    cout << endl;
    pikachu.Update();
    cout << endl;
    pikachu.ShowStatus();
    cout << endl;
    
    /*while (pikachu.GetState() == 5)
    {
        pikachu.StartMovingToGym(&gym1);
        cout << endl;
        pikachu.Update();
        cout << endl;
        pikachu.ShowStatus();
        cout << endl;
        
    } */

    /*pikachu.StartMovingToGym(&gym1);
    cout << endl;
    pikachu.Update();
    cout << endl;
    pikachu.ShowStatus();
    cout << endl;*/
    
    if (pikachu.IsExhausted())
    {
        cout << "Is exhausted" << endl;
        cout << endl;
    }
    else
    {
        cout << "Is not exhausted" << endl;
        cout << endl;
    }

    pikachu.StartRecoveringStamina(4);
    cout << endl;
    pikachu.StartTraining(4);
    cout << endl;
    pikachu.StartTraining(2);
    cout << endl;

    pikachu.Update();
    cout << endl;
    pikachu.ShowStatus();
    cout << endl;

    pikachu.StartRecoveringStamina(1);
    cout << endl;

    cout << "_________________________________________" << endl;
    cout << "Checking to see status of Pokemon Center" << endl;    
    Center1.ShowStatus();
    cout << endl;
    Center1.Update();
    cout << endl;
    cout << "_________________________________________" << endl;

    pikachu.StartMovingToCenter(&Center1);
    cout << endl;
    pikachu.Update();
    cout << endl;
    pikachu.ShowStatus();
    cout << endl;

    cout << "_________________________________________" << endl;
    cout << "Checking to see if gym is now empty" << endl;
    gym1.Update();
    cout << endl;
    gym1.ShowStatus();
    cout << endl;
    cout << "______________________________________" << endl;


    while (pikachu.GetState() == 6)
    {
        pikachu.StartMovingToCenter(&Center1);
        cout << endl;
        pikachu.Update();
        cout << endl;
        pikachu.ShowStatus();
        cout << endl;
    }

    pikachu.StartMovingToCenter(&Center1);
    cout << endl;
    pikachu.Update();
    cout << endl;
    pikachu.ShowStatus();
    cout << endl;

    cout << "Should Pikachu be visible? " << pikachu.ShouldBeVisible() << endl;
    cout << "Is Pikachu exhausted? " << pikachu.IsExhausted() << endl;

    pikachu.StartTraining(2);
    cout << endl;

    pikachu.StartRecoveringStamina(1);
    cout << endl;
    pikachu.Update();
    cout << endl;
    pikachu.ShowStatus();
    cout << endl;

    while (pikachu.Update() == false)
    {
        pikachu.StartMovingToGym(&gym1);
        cout << endl;
        //pikachu.Update();
        //cout << endl;
        pikachu.ShowStatus();
        cout << endl;
    }

    pikachu.StartMovingToGym(&gym1);
    cout << endl;
    pikachu.Update();
    cout << endl;
    pikachu.ShowStatus();
    cout << endl;

    
    cout << "_________________________________________" << endl;
    cout << "Checking to see if center is now empty" << endl;
    Center1.Update();
    cout << endl;
    Center1.ShowStatus();
    cout << endl;
    cout << "______________________________________" << endl;
    
    cout << "_________________________________________" << endl;
    cout << "Checking to see if gym is now empty" << endl;
    gym1.Update();
    cout << endl;
    gym1.ShowStatus();
    cout << endl;
    cout << "______________________________________" << endl;







    return 0;
}