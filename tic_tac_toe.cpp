#include <iostream>
#include <ctime>

using namespace std;

void drawBoard(char *place);
int main(){
    char place[9] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char player = 'X';
    char computer = 'O';

    drawBoard(place);
    return 0;
}

void drawBoard(char *place){
    cout << "     |     |     " << '\n';
    cout << "  " << place[0] << "  |  "<< place[1] <<"  |  " << place[2] << "  " << '\n';
    cout << "_____|_____|_____" << '\n';
    cout << "     |     |     " << '\n';
    cout << "  " << place[3] << "  |  "<< place[4] <<"  |  " << place[5] << "  " << '\n';
    cout << "_____|_____|_____" << '\n';
    cout << "     |     |     " << '\n';
    cout << "  " << place[6] << "  |  "<< place[7] <<"  |  " << place[8] << "  " << '\n';
    cout << "     |     |     " << '\n';
}