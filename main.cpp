/* 
***Guess The Number Game 
*/

#include "utils.h"

//main function
int main ()
{   
    srand(time(NULL));
    int choice; // menu choice
    file_default_value(); // setting the file default value before the game starts
    do
    {
        // game menu
        cout << "GAME MENU" << endl;
        cout << "Enter 1 to Play The Game" << endl << "Enter 2 to Quit The Game" << endl;
        cin >> choice; // for choosing to play game or quit

        switch(choice) // determines action after choice
        {
            case 1: // playing the game
                play_game();
                break;

            case 2: // quiting the game
                cout << "Quiting the game..." << endl;
                print_highest_score(); // func call for printing highest score after quiting the game
                break;

            default: // to choose only 1 & 2
                cout << "Choose between 1 & 2" << endl;
                break;
        }
    }while(choice !=2);

  return 0;  
}
