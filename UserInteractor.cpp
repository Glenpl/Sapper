#include <iostream>
#include "conio.h"
#include "UserInteractor.h"

using namespace std;

void UserInteractor::no_saved_progress_error_message()
{
    cout << translator.loc("\nError! No saved progress available. [Press any botton to close game]");
    getch();
}

void UserInteractor::end_game_message()
{
    cout << translator.loc("Ok, goodbye! :) [press any button]");
    getch();
}

void UserInteractor::continue_game_message()
{
    cout << translator.loc("Here we go! [press any button]");
    getch();
}

void UserInteractor::play_once_again_question_message()
{
    cout<< translator.loc("Would you like to play once again? [yes/no]\n");
}

void UserInteractor::set_language()
{
    translator.set_language(ask_about_prefered_language());
}

void UserInteractor::game_saved_message()
{
    cout << translator.loc("\n\nSaved. [Press any button]");
    getch();
}

string UserInteractor::continue_or_end_game_answer()
{
    string answer;
    while(answer != "yes" && answer != "no")
    {
        cout<<">";
        cin>>answer;
        answer = translator.to_en(answer);
    }
    return answer;
}

void UserInteractor::game_finished_messages(bool lose)
{
    if(lose)
        cout << translator.loc("\n\nWhat a pity! You stepped on a bomb!\n");
    else
        cout << translator.loc("\n\nCongratulations! You marked all bombs correctly and saved many human beings!\n");
}

string UserInteractor::ask_about_prefered_language()
{
    string selected;
    while(selected != "en" && selected != "EN" && selected != "PL" && selected != "pl" &&
            selected != "1" && selected != "2")
    {
        cout<<"Select language:\n1.EN [English]\n2.PL [Polski]\n>";
        cin>>selected;
    }
    if(selected == "1" || selected == "EN" || selected == "en")
        return "EN";
    if(selected == "2" || selected == "PL" || selected == "pl")
        return "PL";
    return "EN";
}

UI UserInteractor::specify_board_size()
{
    int input_int = 0;
    while(input_int > 99 || input_int < 1)
    {
        cout << translator.loc("\nSpecify the size of the board (1 to 99)\n>");
        string input;
        cin>>input;
        if(to_int(input_int, input) == false || (input_int > 99 || input_int < 1))
            cout << translator.loc("\nInvalid value!");
    }
    return static_cast<UI>(input_int);
}

UI UserInteractor::specify_bombs_amount()
{
    int input_int = 0;
    int max_b = board_->get_board_size()*board_->get_board_size();
    while(input_int > max_b || input_int < 1)
    {
        cout << translator.loc("\nSpecify how many bombs will be set on the board (1 to the square od board size)\n>");
        string input;
        cin>>input;
        if(to_int(input_int, input) == false || (input_int > 99 || input_int < 1))
            cout << translator.loc("\nInvalid value!");
    }
    return static_cast<UI>(input_int);
}

bool UserInteractor::specify_zeroes_shown()
{
    string input;
    while(input != "true" && input != "false")
    {
        cout << translator.loc("\nSpecify if the zeroes will be shown since the game begin: [true/false]\n>");
        cin>>input;
        input = translator.to_en(input);
        if(input != "true" && input != "false")
            cout << translator.loc("\nInvalid value!");
    }
    return ( (input == "true") ? (true) : (false) );
}

string UserInteractor::select_game_mode_question()
{
    string game_mode = "";
    while(game_mode != "1" && game_mode != "2")
    {
        cout << translator.loc("\nSelect game mode:\n1.Start new game\n2.Continue saved game\n>");
        cin>>game_mode;
    }
    return (game_mode == "1" ? "new_game" : "saved_progress");
}

void UserInteractor::print_board_upper_body()
{
    printf("\n\n");
    printf("                    ");
    for(UI i = 0; i < board_->get_board_size(); i++)
    {
        string col = "%i  ";
        col += [](int x)->string {return ((x>8)?(""):(" "));}(i);
        printf(col.c_str(), i+1);
    }
    printf("\n                   ");
    for(UI i = 0; i < board_->get_board_size()*4-1; i++)
        printf("_");
    printf("\n");
}

string UserInteractor::string_of_x_spaces(UI x)
{
    string spaces;
    for(UI i = 0; i < x; i++)
        spaces += ' ';
    return spaces;
}

void UserInteractor::print_line_separating_rows()
{
    printf("|");
    for(UI j = 0; j < board_->get_board_size()-1; j++)
        printf("---+");
    printf("---|\n");
}

void UserInteractor::print_row(UI row)
{
    printf(" | ");
    for(UI col = 0; col < board_->get_board_size(); col++)
        cout << board_->board[row][col] << " | ";
    printf("%i\n", row+1);
}

void UserInteractor::print_board_main_body()
{
    for(UI row = 0; row < board_->get_board_size(); row++)
    {
        string spaces = [](UI row_num)->string {return ((row_num>8)?(""):(" "));}(row);
        spaces += "               %i";
        printf(spaces.c_str(), row+1);
        print_row(row);
        spaces = string_of_x_spaces(spaces.length());
        spaces += [](UI row_num)->string {return ((row_num>8)?(" "):(""));}(row);
        printf(spaces.c_str());
        if(row < board_->get_board_size()-1)
            print_line_separating_rows();
    }
}

void UserInteractor::print_board_lower_body()
{
    printf(" ");
    for(UI i = 0; i < board_->get_board_size()*4-1; i++)
        printf("-");
    printf("\n                    ");
    for(UI i = 0; i < board_->get_board_size(); i++)
    {
        string col = "%i  ";
        col += [](int x)->string {return ((x<=8)?(" "):(""));}(i);
        printf(col.c_str(), i+1);
    }
    printf("\n\n");
}

void UserInteractor::print_board()
{
    system("CLS");
    print_board_upper_body();
    print_board_main_body();
    print_board_lower_body();
}

val_input UserInteractor::take_command(UI bombs_amount, UI flags)
{
    unverified_input ui;
    cout << translator.loc("Flags left: ") << bombs_amount - flags << "\n";
    cout << translator.loc("Tell me what to do! (action[show/mark/save_game], row[1-9] , col[1-9]):\n>");
    cin>>ui.action>>ui.row>>ui.col;
    return validate_input(ui);
}

val_input UserInteractor::validate_input(unverified_input unverified)
{
    val_input validated;
    int rown = board_->get_board_size() + 1, coln = board_->get_board_size() +1;
    unverified.action = translator.to_en(unverified.action);
    try
    {
        rown = stoi(unverified.row) - 1, coln = stoi(unverified.col) - 1;
    }
    catch(...)
    {
        // error when converting invalid value from
        // string to int with stoi(), ignore
    }
    validated.action = ((unverified.action == "show" || unverified.action == "mark" || unverified.action == "save_game")?(unverified.action):("invalid"));
    validated.row = ((board_->is_coord_inside_board(rown))?(rown):(board_->get_board_size()+1));
    validated.col = ((board_->is_coord_inside_board(coln))?(coln):(board_->get_board_size()+1));
    return validated;
}

bool UserInteractor::to_int(int& val, string str_val)
{
    try
    {
        val = stoi(str_val);
    }
    catch(...)
    {
        val = 0;
        return false;
    }
    return true;
}