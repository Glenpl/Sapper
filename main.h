#ifndef MAIN_H
#define MAIN_H

using namespace std;

typedef unsigned int UI;

struct validated_input
{
    string action;
    int row;
    int col;
};

struct unverified_input
{
    string action;
    string row;
    string col;
};

typedef validated_input val_input;

// boards
const UI MAX_BOARD_SIZE = 100;
string board[MAX_BOARD_SIZE][MAX_BOARD_SIZE]; // board that will be displayed to user
UI board_int[MAX_BOARD_SIZE][MAX_BOARD_SIZE]; // board with actual fields' values
UI shown[MAX_BOARD_SIZE][MAX_BOARD_SIZE]; // board with values: marked, hidden, shown for each field

// function index
class UserInteractor
{
private:
    Translator translator;
    string string_of_x_spaces(UI x);
    void print_board_main_body();
    void print_row(UI row);
    void print_line_separating_rows();
    void print_board_upper_body();
    void print_board_lower_body();
public:
    UI BOARD_SIZE;
    UI specify_board_size();
    UI specify_bombs_amount();
    bool specify_zeroes_shown();
    string ask_about_prefered_language();
    void print_board();
    val_input takeCommand(UI, UI);
    val_input validate_input(unverified_input unverified);
    bool is_coord_inside_board(UI coord);
    void setLanguage();
    void gameSavedMessage();
    string continue_or_end_gameAnswer();
    void endGameMessage();
    void continueGameMessage();
    void gameFinishedMessages(bool lose);
    void playOnceAgainQuestionMessage();
    void noSavedProgressErrorMessage();
    string selectGameModeQuestion();
};

class Sapper
{
public:
    void run();
    Sapper();
private:
    UserInteractor user_interactor;
    void start_new_game_or_continue_saved_proggress();
    void update_board();
    void update_field(UI row, UI col);
    UI count_bombs_around_field(int row, int col);
    void init_game();
    void clear_boards();
    void clear_field(UI row, UI col);
    void set_bombs_on_board();
    void set_fields_values();
    void set_field_value(UI row, UI col);
    void do_action(string action, UI row, UI col);
    void mark_field(UI row, UI col);
    void finish_game(bool);
    void continue_or_end();
    bool is_coord_inside_board(UI coord);
    val_input validate_input(string act, string row, string col);
    void main_game();
    bool is_field_a_bomb(UI row, UI col);
    void specify_settings();
    bool continue_saved_game_from_file();
    void save_progress_to_file();

    static const UI FIELD_CLEAR = 0;
    static const UI FIELD_BOMB = 9;
    static const UI FIELD_MARKED = 10;
    static const UI FIELD_SHOWN = 11;
    static const UI FIELD_HIDDEN = 12;

    UI BOARD_SIZE; // board is a grid of x * x fields
    UI BOMBS_AMOUNT; // number of bombs set on the board
    bool SHOW_ZEROES; // show all zero-valued fields
    UI flags;
    bool lose;
    UI hidden_fields_amount;
};

bool to_int(int& val, string str_val);

#endif // MAIN
