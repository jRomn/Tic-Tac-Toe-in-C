#include <iostream>
#include "Function_Declarations.hpp"

using namespace std;

/* Global Variable Defenition */
int Player = 1;
char board[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
int position = 0;
bool Winner = false; 
bool Full = false;


/*---Function Definition to provide the necessary details to Start the Game---*/
void Introduction( ) {
        
    cout << "\n";

    cout << "===========\n";
    cout << "Tic-Tac-Toe\n";
    cout << "===========\n\n";
    
    cout << "Player 1) 'X'\n";
    cout << "Player 2) 'O'\n\n";

    cout << "     |     |      \n";

    cout << "  " << 1 << "  |  " << 2 << "  |  " << 3 << "\n";

    cout << "_____|_____|_____ \n";
    cout << "     |     |      \n";

    cout << "  " << 4 << "  |  " << 5 << "  |  " << 6 << "\n";

    cout << "_____|_____|_____ \n";
    cout << "     |     |      \n";

    cout << "  " << 7 << "  |  " << 8 << "  |  " << 9 << "\n";
    cout << "     |     |      \n";

    cout << "\n";    
    
    cout << "\nThe game board is a 3x3 grid represented by numbers (1-9) or symbols (e.g., X and O).\n\n";
    cout << "- Two players take turns marking their symbols (X and O) on empty cells by selecting a number (1-9).\n\n";
    cout << "- The first player to get three consecutive marks in a row, column, or diagonal wins.\n\n";
    cout << "- A tie occurs if all cells are filled and no player has three consecutive marks.\n\n";
    cout << "\n\nLet's get Started (Press [Enter]).\n\n";

    cin.get();                                      // Wait for User to press a Key

}

void Set_Position () {
    
    /* --- Set the Position --- */
    // Prompt the User for a number between 1 - 9. 
    cout << "Player " << Player << "'s Turn (Enter 1-9): ";     

    // Check user input is a valid number between 1-9. 
    while (!(cin >> position)) { 
        cout << "Player " << Player << ", please enter a valid number between 1 and 9: ";
        cin.clear(); 
        cin.ignore();
    }

    // Check the position is available . 
    while (board[position-1] != ' ') {
        cout << "Oops, please try again. That position is already filled out.\n";
        cin >> position; 
        cin.clear();
        cin.ignore();
    }
    
}

void Update_Board() {
    
    /* Update the Board */
    /* Another Function */
    // If it's Player 1 ---> Update the board w/ 'X'
    if (Player == 1) {
        board[position - 1] = 'X';
    } 
    else if (Player == 2) {
        board[position -1] = 'O';
    }
    
}

/*---Function Definition to display the 3x3 Grid---*/
void draw() {
    cout << "\n";

    cout << "     |     |      \n";

    cout << "  " << board[0] << "  |  " << board[1] << "  |  " << board[2] << "\n";

    cout << "_____|_____|_____ \n";
    cout << "     |     |      \n";

    cout << "  " << board[3] << "  |  " << board[4] << "  |  " << board[5] << "\n";

    cout << "_____|_____|_____ \n";
    cout << "     |     |      \n";

    cout << "  " << board[6] << "  |  " << board[7] << "  |  " << board[8] << "\n";
    cout << "     |     |      \n";

    cout << "\n";
}

void Change_Player() {

    if (Player % 2 == 1) {
        Player++;
    }
    else if (Player % 2 == 0){
        Player--;
    }
}


bool is_winner() { 

    // Player 1
    if (
        (board[0] == 'X' && board[1] == 'X' && board[2] == 'X') ||
        (board[3] == 'X' && board[4] == 'X' && board[5] == 'X') ||
        (board[6] == 'X' && board[7] == 'X' && board[8] == 'X') ||
        (board[0] == 'X' && board[3] == 'X' && board[6] == 'X') ||
        (board[1] == 'X' && board[4] == 'X' && board[7] == 'X') ||
        (board[2] == 'X' && board[5] == 'X' && board[8] == 'X') ||
        (board[0] == 'X' && board[4] == 'X' && board[8] == 'X') ||
        (board[2] == 'X' && board[4] == 'X' && board[6] == 'X')
        ) {

            Winner = true; 
            
        }

    // Player 2
    else if (
        (board[0] == 'O' && board[1] == 'O' && board[2] == 'O') ||
        (board[3] == 'O' && board[4] == 'O' && board[5] == 'O') ||
        (board[6] == 'O' && board[7] == 'O' && board[8] == 'O') ||
        (board[0] == 'O' && board[3] == 'O' && board[6] == 'O') ||
        (board[1] == 'O' && board[4] == 'O' && board[7] == 'O') ||
        (board[2] == 'O' && board[5] == 'O' && board[8] == 'O') ||
        (board[0] == 'O' && board[4] == 'O' && board[8] == 'O') ||
        (board[2] == 'O' && board[4] == 'O' && board[6] == 'O')
        ) {

            Winner = true; 
            
        }

    else {
        Winner = false;
    }

    return Winner;

}

bool is_filled() {
    
    
        if(
        board[0] == ' ' || board[1] == ' ' || board[2] == ' ' ||
        board[3] == ' ' || board[4] == ' ' || board[5] == ' ' ||
        board[6] == ' ' || board[7] == ' ' || board[8] == ' '
        ) {
            Full = false;
        }
        else {
            Full = true;
        }

    
    return Full; 

}

/*  */
void Start_Playing( ) {

    while ( !is_winner() && !is_filled() ) {
        /* --- Set the Position --- */
        // Prompt the User for a number between 1 - 9. 
        Set_Position();

        /* --- Update the Board --- */
        Update_Board();

        /* --- Print the Board --- */
        draw();    
    
        /* --- Change Player --- */
        Change_Player();
    }

}

void end_game() {

    cout << "The Game has End.\n";
    
    if(is_winner() == true) {
        if(Player % 2 == 1) { 
            cout << "Player 2 Won!\n";
        }
        else {
            cout << "Player 1 Won!\n";
        }
    }

    else {
        cout << "There was a tie.\n";
    }

}


