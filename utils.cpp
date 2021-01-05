#include "utils.h"

void print_highest_score() //func for printing highest score(i meant lowest)
{
    ifstream ifile("best_score.txt");
    int score;
    ifile >> score;
    if (score == 1000000) score = 0; //if no game is played || quits at the first try

    cout << "Your Highest Score was : " << score << endl;
}

void file_default_value() // func for setting the default value to the file
{
    ofstream ofile("best_score.txt");
    int bscore;
    bscore = 1000000;
    ofile << bscore << endl;
}

void print_to_file(int vector_size) //inputting best score to a txt file
{
    ifstream ifile("best_score.txt"); //read input from file
    if(!ifile.is_open()) // checking if file opened correctly
        cout << "Unable to open"<< endl;

    int bscore;
    ifile >> bscore;


    ofstream ofile("best_score.txt"); //write output to file
    if(!ofile.is_open()) // checking if file opened correctly
        cout << "Unable to open"<< endl;

    if(vector_size<bscore) // if the guess count is lower than the file value, it prints to the file
        ofile << vector_size;
    else 
        ofile << bscore;
}

void print_vector(vector<int> v) //func for all guesses collection
{
    cout << "Here are your guesses: ";
    for (int i = 0;i<v.size();i++) //printing all the guesses
        cout << v[i] << " ";
    cout << endl;
}


void play_game() //func for the actual game
{
    

    int random_num = rand()%1001; // random generated number between 1000
    int guess;  // guess number, guesses(vector that stores all the guesses)
    vector<int> guesses;

    while(true) //only breaks out of loop after guessing correctly
    {
        cout << "Guess The Random Number (between 1-1000) : ";
        cin >> guess;
        guesses.push_back(guess); // adding guesses to vector
        if (guess > 1000) continue;
        if (guess == random_num)
        {    
            cout << "------------------------------------------------"<<endl;
            cout << "Your guess "<< guess <<" is correct"<< endl;
            cout << "Total guess count: "<< guesses.size() << endl;
            print_to_file(guesses.size()); // func call to write to a file
            print_vector(guesses); //func call for printing all the guesses
            break;
        }
        else if(guess > random_num) 
            cout << "Your guess is too high"<<endl;
        else 
            cout << "your guess is too low"<< endl;
        
        
    }

}

/*
//using array
void print_array(int array[],int array_size) //func for all guesses collection using c style array
{
    cout << "Here are your guesses: ";
    for (int i = 0;i<array_size;i++) //printing all the guesses
        cout << array[i] << " ";
    cout << endl;
}
*/