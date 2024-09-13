#include <iostream>
#include <string>
#include <vector> //basically an array
#include <time.h>
#include <cstdlib> //for random number generation

using namespace std; //this is so we don't have to type std:: before every cout, cin, etc.

void start(char& level){ //this function is for the user to choose the level of difficulty

    cout << "Welcome to Connect 4!" << endl;
    cout << "Please choose a level of difficulty by entering the letter representing the level of difficulty: " << endl;
    cout << "E: Easy" << endl;
    cout << "H: Hard" << endl;
    cin >> level;
}

void display_board(){
    for (int w = 0; w < 10; ++h){
        for (int h = 0; h < 9; ++ v){
            cout << board[w][h] << " "; 
            //cout is the standard output stream
            //<< sends the value on the right to the standard output stream
            //basically read from left to right?, << is like +   
        }
    }
}

void computer_move(vector <vector <char>>& board, int inputCol, int& row){
    //& means that the argument is being passed reference rather than by value
    board[row][inputCol] = 'C';
    --row; //decrement the row to check whether column is full
    display_board(board);  
}

//check if seed value is valid or not (aka if column chosen is valid /not full)
void computer_fun_call(int& entry, int& row_1, int& row_2, int& row_3, int& row_4, int& row_5, int& row_6, int& row_7, vector <vector<char>>& board){
    int flag = 0; 

    while(flag == 0){
        if (entry == 1){  //this is the COLUMN NUMBER chosen
            if (row_1 <= 2){ //row is full, take random again
                srand(time(NULL));
                entry = rand() % 7 + 1;
                continue;
            }else{//if the row is NOT full, it calls function which prints onto the board
                computer_move(board, entry, row_1);
                flag = 1;
            }
        }
        else if (entry == 2){
            if (row_2 <= 2){
                srand(time(NULL));
                entry = rand() % 7 + 1;
                continue;
            }else{  
                computer_move(board, entry, row_2);
                flag = 1;
            }
        }
        else if (entry == 3){
            if (row_3 <= 2){
                srand(time(NULL));
                entry = rand() % 7 + 1;
                continue;
            }else{
                computer_move(board, entry, row_3);
                flag = 1;
            }
        }
        else if (entry == 4){
            if (row_4 <= 2){
                srand(time(NULL));
                entry = rand() % 7 + 1;
                continue;
            }else{
                computer_move(board, entry, row_4);
                flag = 1;
            }
        }
        else if (entry == 5){
            if (row_5 <= 2){
                srand(time(NULL));
                entry = rand() % 7 + 1;
                continue;
            }else{
                computer_move(board, entry, row_5);
                flag = 1;
            }
        }
        else if (entry == 6){
            if (row_6 <= 2){
                srand(time(NULL));
                entry = rand() % 7 + 1;
                continue;
            }else{
                computer_move(board, entry, row_6);
                flag = 1;
            }
        }
        else if (entry == 7){
            if (row_7 <= 2){
                srand(time(NULL));
                entry = rand() % 7 + 1;
                continue;
            }else{
                computer_move(board, entry, row_7);
                flag = 1;
            }
            
        }
    }
    
}

//clears board should the user decide to play again
void restart_game(int& flag, int& user_entry, int& entry, int& row_1, int& row_2, int& row_3, int& row_4, int& row_5, int& row_6, int& row_7, int& counter){
    char user_reponse = '';
    cout << "Would you like to play again? (Y/N)";
    cin >> user_response;
    if (user_response == 'Y' || user_response == 'y'){
        flag = 1;
        user_entry = 0;
        entry = 0;
        row_1 = 5;
        row_2 = 5;
        row_3 = 5;
        row_4 = 5;
        row_5 = 5;
        row_6 = 5;
        row_7 = 5;
        counter = 0;
    }
    else{
       cout << "Thank you for playing Connect 4!";
    }
}u

//checks if the user has won
void check_win(const vector<vector<char>>& board, int& win, int& check, char token){
    for (int i = 8; i > 2; --i){
        //checks if user won in a horizontal row
        //ensure that the i is the same so we are looking at columns in the SAME row
        if((board[i][1] == token && board[i][2] == token && board[i][3] == token && board[i][4] == token )|| (board[i][2] == token && board[i][3] == token && board[i][4] == token && board[i][5] == token) || (board[i][3] == token && board[i][4] == token && board[i][5] == token && board[i][6] == token) || (board[i][4] == token && board[i][5] == token && board[i][6] == token && board[i][7] == token)){ 
            win = 1;
            check = 0;
            break;
        }

        //vertical row check
        if ((board[i][1] == token && board[i-1][1] == token && board[i-2][1] == token && board[i-3][1] == token) || (board[i][2] == token && board[i-1][2] == token && board[i-2][2] == token && board[i-3][2] == token) || (board[i][3] == token && board[i-1][3] == token && board[i-2][3] == token && board[i-3][3] == token) || (board[i][4] == token && board[i-1][4] == token && board[i-2][4] == token && board[i-3][4] == token) || (board[i][5] == token && board[i-1][5] == token && board[i-2][5] == token && board[i-3][5] == token) || (board[i][6] == token && board[i-1][6] == token && board[i-2][6] == token && board[i-3][6] == token) || (board[i][7] == token && board[i-1][7] == token && board[i-2][7] == token && board[i-3][7] == token)){
            win = 1;
            check = 0;
            break;
        }
        //diagonal right check
        if ((board[i][1] == token && board[i-1][2] == token && board[i-2][3] == token && board[i-3][4] == token) || (board[i][2] == token && board[i-1][3] == token && board[i-2][4] == token && board[i-3][5] == token) || (board[i][3] == token && board[i-1][4] == token && board[i-2][5] == token && board[i-3][6] == token) || (board[i][4] == token && board[i-1][5] == token && board[i-2][6] == token && board[i-3][7] == token)){
            win = 1;
            check = 0;
            break;
        }
    }

    //diagonal left check
    for (int i = 3; i < 9; ++i){
        if ((board[i][1] == token && board[i+1][2] == token && board[i+2][3] == token && board[i+3][4] == token) || (board[i][2] == token && board[i+1][3] == token && board[i+2][4] == token && board[i+3][5] == token) || (board[i][3] == token && board[i+1][4] == token && board[i+2][5] == token && board[i+3][6] == token) || (board[i][4] == token && board[i+1][5] == token && board[i+2][6] == token && board[i+3][7] == token)){
            win = 1;
            check = 0;
            break;
        }
    }
}

void win_message(int win, int& flag, int& user_entry, int& cmpt_entry, int& row_1, int& row_2, int& row_3, int& row_4, int& row_5, int& row_6, int& row_7,int& counter){
    if (win == 1){
        cout << "Congratulations! You have won Connect 4!";
        restart_game(flag, user_entry, cmpt_entry, row_1, row_2, row_3, row_4, row_5, row_6, row_7, counter);
    }
    else if (win == 2){
        cout << "The computer has won Connect 4!";
        restart_game(flag, user_entry, cmpt_entry, row_1, row_2, row_3, row_4, row_5, row_6, row_7, counter);
    }
    else if (win == 3){
        cout << "The game is a draw!";
        restart_game(flag, user_entry, cmpt_entry, row_1, row_2, row_3, row_4, row_5, row_6, row_7, counter);
    }
}

//main connect four program
int main(){
    char level;
    int rows[7] = {row_1, row_2, row_3, row_4, row_5, row_6, row_7};
    int user_choice = 0, computer_choice = 0;
    int flag = 1;
    int counter = 0;

    while (flag == 1){ //while loop flag is one
        welcome(level)

        vector <vector <char>> board = { // MAKE EMPTY PLAYING BOARD
			{'+', '-', '-', '-', '-', '-', '-', '-', '+'},		
			{'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
			{'|', '=', '=', '=', '=', '=', '=', '=', '|'},
			{'|', '0', '0', '0', '0', '0', '0', '0', '|'},
			{'|', '0', '0', '0', '0', '0', '0', '0', '|'},
			{'|', '0', '0', '0', '0', '0', '0', '0', '|'},
			{'|', '0', '0', '0', '0', '0', '0', '0', '|'},
			{'|', '0', '0', '0', '0', '0', '0', '0', '|'},
			{'|', '0', '0', '0', '0', '0', '0', '0', '|'},
			{'+', '-', '-', '-', '-', '-', '-', '-', '+'}	
		};; 

        //if on easy level 
        if (level == 'E' || level == 'e'){
            flag = 0
            display_board(board);
            int win = 0;

            while (win == 0) { 
                cout << end1;

                int user_valid = 1

                while (user_valid == 1){
                    cout << "Please enter a column number (1-7) to place your token: ";
                    cin >> user_choice;
                    if (user_choice >= 1 && user_choice <= 7) { // Ensure valid column
                        if (row[user_choice] <= 2) { // Check if column is full
                            cout << "|| Column " << user_choice << " is full. Please try a different column! ||\n";
                            user_valid = 1; 
                            continue;
                        } else {
                            int currRow = row[user_choice]
                            board[row[currRow]][user_choice] = 'U';
                            counter++; 
                            row[user_choice]--; 
                            user_valid = 0; 
                            break;
                        }
                    } else {
                        cout << "|| Invalid column! Please try a different column! ||\n";
                        user_valid = 1; 
                        break;
                    }
                                        
                }

            }
            display_board(board);
            check_win(board, win, user_choice, 'U');

            if(win != 1){
                if (user_entry == 1){
                    computer_choice = user_choice + 6;
                } else if (user_entry == 7){
                    computer_choice = user_choice - 1;
                } else {
                    computer_choice = user_choice - 1;
                }

                computer_fun_call(computer_choice, row_1, row_2, row_3, row_4, row_5, row_6, row_7, board);
                cout << "\nThe computer has chosen to fill column" << computer_choice << ".\n\n";
                counter++;

                if (counter == 42){
                    win = 3;
                    user_chedck = 0;
                }
            }
            check_win(board, win, computer_choice, 'C');
        }

        win_message(win, flag, user_choice, computer_choice, row_1, row_2, row_3, row_4, row_5, row_6, row_7, counter);
    } else if (level == 'H' || level == 'h'){
        flag = 0;
        display_board(board);
        int win = 0;

        while (win == 0){
            cout << endl;
            int user_valid = 1;

            while (user_valid == 1){
                cout << "Please enter a column number (1-7) to place your token: ";
                cin >> user_choice;
                if (user_choice >= 1 && user_choice <= 7){
                    if (row[user_choice] <= 2){
                        cout << "|| Column " << user_choice << " is full. Please try a different column! ||\n";
                        user_valid = 1;
                        continue;
                    } else {
                        int currRow = row[user_choice];
                        board[row[currRow]][user_choice] = 'U';
                        counter++;
                        row[user_choice]--;
                        user_valid = 0;
                        break;
                    }
                } else {
                    cout << "|| Invalid column! Please try a different column! ||\n";
                    user_valid = 1;
                    break;
                }
            }
            display_board(board);
            check_win(board, win, user_choice, 'U');

            if (win != 1){
                srand(time(NULL));
                computer_choice = rand() % 7 + 1;
                computer_fun_call(computer_choice, row_1, row_2, row_3, row_4, row_5, row_6, row_7, board);
                cout << "\nThe computer has chosen to fill column " << computer_choice << ".\n\n";
                counter++;

                if (counter == 42){
                    win = 3;
                    user_check = 0;
                }
            }
            check_win(board, win, computer_choice, 'C');
        }
        win_message(win, flag, user_choice, computer_choice, row_1, row_2, row_3, row_4, row_5, row_6, row_7, counter);
    }
   
}







