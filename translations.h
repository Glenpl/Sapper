#ifndef TRANSLATIONS_H
#define TRANSLATIONS_H

class Translator
{
private:
    std::string language;
    std::string PL(std::string message);
    std::string EN(std::string message);
public:
    std::string get_language();
    void set_language(std::string lang);
    std::string loc(std::string message);
    std::string to_en(std::string message);
    std::string translate(std::string message);
};

std::string Translator::get_language()
{
    return this->language;
}

void Translator::set_language(std::string lang)
{
    this->language = lang;
}

std::string Translator::loc(std::string message)
{
    return translate(message);
}

std::string Translator::to_en(std::string message)
{
    if(message == "tak")
        return "yes";
    if(message == "nie")
        return "no";
    if(message == "prawda")
        return "true";
    if(message == "falsz")
        return "false";
    if(message == "pokaz")
        return "show";
    if(message == "oznacz")
        return "mark";
    if(message == "zapisz_gre")
        return "save_game";
    // default
    return message;
}

std::string Translator::translate(std::string message)
{
    if(this->language == "PL")
        return PL(message);
    if(this->language == "EN")
        return EN(message);
    return message;
}

std::string Translator::PL(std::string message)
{
    if(message == "Here we go! [press any button]")
        return "Zaczynajmy! [nacisnij dowolny przycisk]";
    if(message == "Flags left: ")
        return "Pozostale flagi: ";
    if(message == "Tell me what to do! (action[show/mark/save_game], row[1-9] , col[1-9]):\n>")
        return "Powiedz mi co mam zrobic! (akcja[pokaz/oznacz/zapisz_gre], rzad[1-9], kolumna[1-9])\n>";
    if(message == "\n\nWhat a pity! You stepped on a bomb!\n")
        return "\n\nNiestety! Wszedles na bombe!\n";
    if(message == "\n\nCongratulations! You marked all bombs correctly and saved many human beings!\n")
        return "\n\nGratulacje! Poprawnie zaznaczyles wszystkie bomby i uratowales wielu ludzi!\n";
    if(message == "Would you like to play once again? [yes/no]\n")
        return "Czy chcesz zagrac jeszcze raz? [tak/nie]\n";
    if(message == "Ok, goodbye! :) [press any button]")
        return "Do nastepnego razu! :) [nacisnij dowolny przycisk]";
    if(message == "\n\nSaved. [Press any button]")
        return "\n\nZapisano. [Nacisnij dowolny przycisk]";
    if(message == "\nSelect game mode:\n1.Start new game\n2.Continue saved game\n>")
        return "\nWybierz sposob gry:\n1.Zacznij nowa gre\n2.Kontynuuj zapisana gre\n>";
    if(message == "\nSpecify the size of the board (1 to 99)\n>")
        return "\nPodaj rozmiar planszy (od 1 do 99)\n>";
    if(message == "\nError! No saved progress available. [Press any botton to close game]")
        return "\nBlad! Brak zapisanego postepu gry. [Nacisnij dowolny przycisk aby zakonczyc gre]";
    if(message == "\nSpecify how many bombs will be set on the board (1 to the square od board size)\n>")
        return "\nPodaj ilosc bomb rozmieszonych na planszy (od 1 do kwadratu wielkosci planszy)\n>";
    if(message == "\nSpecify if the zeroes will be shown since the game begin: [true/false]\n>")
        return "\nOkresl czy zera maja byc pokazane od poczatku rozgrywki [prawda/falsz]\n>";
    if(message == "\nInvalid value!")
        return "\nNiepoprawna wartosc!";
    // default
    return message;
}

std::string Translator::EN(std::string message)
{
    return message;
}

#endif // TRANSLATIONS
