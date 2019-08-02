/***************************************************************************************
 ** Program name: mainProject1.cpp file for [Week 1, Project 1] CS_162_400_S2019
 ** Author: Ryan Wells Farran
 ** Date: 04/14/2019 | Sunday, April 14th 2019
 ** Description: This program uses langtonAnt.hpp/.cpp, langtonBoard.hpp/.cpp, menu.hpp/.cpp,
 ** and inputVal.hpp/.cpp and simulates the Langton's Ant procedure using the console input/output.
 ** Basically, the user will create a grid (Langton's Board) of a certain size they choose,
 ** and then an "ant" (*) will go around and if it hits a white square it will turn right and go forward,
 ** and alternatively if it hits a black square it will turn left and then go forward, but in each scenario,
 ** before moving forward the Langton Ant will "swap" the color of the square it is about to exit.
 ** This may sound boring, but play around with the software and notice how the larger the screen
 ** and number of iterations set by the suer, the more interesting the final output becomes.
 ** Notice too how when the ant reaches the edge of the screen it "wraps around" to the otherside,
 ** and in fact, the pattern even continues. This is showed in a bit more detail in the refletion piece of
 ** this assignment. Earlier I was having trouble with deleting my memory; I was calling the destructor
 ** using board.~LangtonBoard(); but it was throwing an error when I tried to restart my program.
 ** I simply commented out the line and so now I beleive that my program is working properly and
 ** automatically calling my destructor function becuase I was able to run very large simulations back to back
 ** without any complaints from the compiler in XCode and Flip. All in all, this was by far the most
 ** exciting thing I have ever made so far in programming! I found watching the simulations
 ** run to be very beautiful! Thanks to who ever is reading this and have a great day!
 ***************************************************************************************/
#include <iostream> //needed for console input and output
#include <string>
#include "menu.hpp"
#include "inputVal.hpp"
#include "langtonBoard.hpp"
#include "langtonAnt.hpp"

//Using statments for console input/output commands
using std::cout; //all other files use the "::" scope operator instead of "using"
using std::cin;
using std::endl;
using std::string;

int main()
{
    string aestheticLine = "*******************************************"; //used to visually seperate certain areas of code
    
    //code used for Menu
    int userChoice; //Stores whatever option user chooses from Menu class
    bool restart = true; //Used for first menu start/quit prompt
    bool restart2 = true; //Used for second program restart/quit prompt
    
    //Code used to store grid size, number of steps, and starting location of Langton Ant
    int numOfRows;
    int numOfCols;
    int numOfSteps;
    int antRowStart;
    int antColStart;
    
    Menu menu = Menu("the Langton’s Ant simulation"); //Call the function witht he name of
                                                    //the project so it can be reused for other assignments
    while (restart == true)
    {
        userChoice = menu.startMenu(); //Begins Start/Quit prompt
        if (userChoice == 1)
        {
            //run program...(user chose '1')
            cout << aestheticLine << endl; //used to distinguish program start from Menu
            inputVal dummyInputVal; //used to call dummyInputVal.getPosInt() instead of using cin
            cout << "Before running, we must prepare our simulation." << endl; //Instructions/explanation
            
            //Set dimensions of Board
            cout << "How many ROWS tall will your BOARD be?" << endl;
            numOfRows = dummyInputVal.getPosInt();
            cout << "How many COLUMNS wide will your BOARD be?" << endl;
            numOfCols = dummyInputVal.getPosInt();;
            
            //Set number of steps ant will take
            cout << "How many iterations will you observe?" << endl;
            numOfSteps = dummyInputVal.getPosInt();;
            
            //Set the Ant's starting coordinates
            cout << "Which ROW of the BOARD will your ANT begin at?" << endl;
            antRowStart = dummyInputVal.getPosInt();
            cout << "Which COLUMN of the BOARD will your ANT begin at?" << endl;
            antColStart = dummyInputVal.getPosInt();
            
            //Dynamically allocate array by calling constructor
            LangtonBoard board = LangtonBoard(numOfRows, numOfCols);
            
            //Instantiate an Ant object pointing to a location on the board
            LangtonAnt userAnt(&board, antRowStart, antColStart);
            
            board.printBoard(); //shows starting position of Ant
            
            //Run program for as many iterations (numOfSteps) set by user earlier in program
            for (int count = 0; count < numOfSteps; ++count)
            {
                userAnt.moveAnt();
                board.printBoard();
            }
            
            //Calls destructor to free up dynamically allocated memory.
            //board.~LangtonBoard();
            
            //Ask user if they would like to run the program again or quit
            while (restart2 == true)
            {
                userChoice = menu.endMenu();
                if (userChoice == 1)
                {
                    restart = true;  //Will remain in outer loop upon exit of nested loop...
                    restart2 = false; //set this to flase to exit nested loop, but remain in outer
                }
                else if (userChoice == 2)
                {
                    restart = false; //sets both restart flags to false to exit program
                    restart2 = false;
                }
                else //final else statement used for formality, though this code should ideally never run
                {
                    cout << "You didn't select 1 or 2. Try again..." << endl;
                }
            }
        }
        else if (userChoice == 2)
        {
            restart = false;
        }
        else //final else statement used for formality, though this code should ideally never run
        {
            cout << "You didn't select 1 or 2. Try again..." << endl;
        }
    }

    return 0; //exits program by returning 0 to main function
}
