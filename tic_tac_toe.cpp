#include <iostream>
#include <ctime>

using namespace std;

char const player = 'X';
char const computer = 'O';

void drawBoard(char *place);
void playerMove(char *place);
void computerMove(char *place);
bool checkWin(char *place);
void playGame(char *place);

int main(){
    char place[9] = { '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    playGame(place);
    return 0;
}

bool checkWin(char *place){  // Return true if still playing, return false if someone won

    if(place[0] == place[1] && place[1] == place[2]){
        if(place[1] == player){
            cout << '\n' << "You won!" << '\n';
            return false;
        }
        else{
            cout << '\n' << "You lost!" << '\n';
            return false;
        }
    }
    if(place[3] == place[4] && place[4] == place[5]){
        if(place[4] == player){
            cout << '\n' << "You won!" << '\n';
            return false;
        }
        else{
            cout << '\n' << "You lost!" << '\n';
            return false;
        }
    }
    if(place[6] == place[7] && place[7] == place[8]){
        if(place[7] == player){
            cout << '\n' << "You won!" << '\n';
            return false;
        }
        else{
            cout << '\n' << "You lost!" << '\n';
            return false;
        }
    }



    if(place[0] == place[3] && place[3] == place[6]){
        if(place[3] == player){
            cout << '\n' << "You won!" << '\n';
            return false;
        }
        else{
            cout << '\n' << "You lost!" << '\n';
            return false;
        }
    }
    if(place[1] == place[4] && place[4] == place[7]){
        if(place[4] == player){
            cout << '\n' << "You won!" << '\n';
            return false;
        }
        else{
            cout << '\n' << "You lost!" << '\n';
            return false;
        }
    }
    if(place[2] == place[5] && place[5] == place[8]){
        if(place[7] == player){
            cout << '\n' << "You won!" << '\n';
            return false;
        }
        else{
            cout << '\n' << "You lost!" << '\n';
            return false;
        }
    }

    if(place[0] == place[4] && place[4] == place[8]){
        if(place[4] == player){
            cout << '\n' << "You won!" << '\n';
            return false;
        }
        else{
            cout << '\n' << "You lost!" << '\n';
            return false;
        }
    }
    if(place[2] == place[4] && place[4] == place[6]){
        if(place[4] == player){
            cout << '\n' << "You won!" << '\n';
            return false;
        }
        else{
            cout << '\n' << "You lost!" << '\n';
            return false;
        }
    }

    
    
}
void drawBoard(char *place){
    std::cout << '\n' << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << "  " << place[0] << "  |  "<< place[1] <<"  |  " << place[2] << "  " << '\n';
    std::cout << "_____|_____|_____" << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << "  " << place[3] << "  |  "<< place[4] <<"  |  " << place[5] << "  " << '\n';
    std::cout << "_____|_____|_____" << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << "  " << place[6] << "  |  "<< place[7] <<"  |  " << place[8] << "  " << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << '\n' << '\n';
}
void playerMove(char *place){

    int localisation = 0;
    
    std::cout << "Avaible places at numbers: ";
    for(int i = 0; i < 9; i++){
        if(!(place[i] == computer || place[i] == player)){
            std::cout << i + 1<< " ";
        }
    }
    std::cout << '\n';

do{
    std::cout << "Please select your localisation to place the 'X': ";
    std::cin >> localisation;
    }while(!(localisation >= 1 && localisation <= 9) || (place[localisation - 1] == 'X' || place[localisation - 1] == 'O'));    // 0 or more and 9 or less and 

    place[localisation-1] = player;


}
void computerMove(char *place){
    int localisation = 0;
    srand(time(NULL));
    do{
        localisation = rand() % 9 + 1;
    }while(!(localisation >= 1 && localisation <= 9) || (place[localisation - 1] == 'X' || place[localisation - 1] == 'O'));

    place[localisation-1] = computer;


}
void playGame(char *place){
    system("cls");
    cout << '\n' << '\n' << "You're X, and your enemy is an O" << '\n' << '\n';
    int counter = 9;
    while(counter != 0 || checkWin(place) == true){
        drawBoard(place);

        cout << '\n' << "Player choose now!" << '\n';
        playerMove(place);
        if(checkWin(place) == false){
            drawBoard(place);
            break;
        }
        else{
            drawBoard(place);
        }

        _sleep(5000);
        system("cls");
        computerMove(place);
        if(checkWin(place) == false){
            drawBoard(place);
            break;
        }

        if(counter == 0 && checkWin(place) == true){
            cout << '\n' << "Draw!" << '\n';
        }
    }
}