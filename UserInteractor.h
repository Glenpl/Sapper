#ifndef USERINTERACTOR_H
#define USERINTERACTOR_H

#include "Translator.h"
#include "Board.h"
#include "BoardPrinter.h"

struct validated_input
{
    validated_input(std::string action, int row, int col);
    validated_input(std::string action, std::string row, std::string col);
    std::string action;
    int row;
    int col;
};

typedef unsigned int UI;

class UserInteractor
{
private:
    Translator translator;
    BoardPrinter board_printer;
    bool to_int(int& val, std::string str_val);
    validated_input validate_input(std::string action_u, std::string row_u, std::string col_u);
public:
    UserInteractor();
    UI specify_board_size();
    UI specify_bombs_amount(const UI board_size);
    bool specify_zeros_shown();
    void specify_UI_language();
    void print_board(Board* board);
    validated_input take_command(UI, UI);
    void game_saved_message();
    void game_finished_message(bool lose);
    void no_saved_progress_error_message();
    void print_menu();
    UI menu_selection_question();
    void about_game();
    void press_any_button_message();
};

#endif // USERINTERACTOR_H
