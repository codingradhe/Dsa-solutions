#include <bits/stdc++.h>
using namespace std;

char cheakWinner(char board[3][3]){
  char winner =' ';

  for(int i=0;i<3;i++){
    if(board[i][0]!=' ' &&
       board[i][0]==board[i][1] &&
       board[i][1]==board[i][2]){
      winner = board[i][0];
      return winner;
    }
  }

  for(int i=0;i<3;i++){
    if(board[0][i]!=' ' &&
       board[0][i]==board[1][i] &&
       board[1][i]==board[2][i]){
      winner = board[0][i];
      return winner;
    }
  }

  if(board[0][0]!=' ' &&
     board[0][0]==board[1][1] &&
     board[1][1]==board[2][2]){
    winner = board[0][0];
    return winner;
  }

  if(board[0][2]!=' ' &&
     board[0][2]==board[1][1] &&
     board[1][1]==board[2][0]){
    winner = board[0][2];
    return winner;
  }

  return winner;
}

int main() {

  char board[3][3]={
    {' ',' ',' '},
    {' ',' ',' '},
    {' ',' ',' '},
  };

  const char playerX='X';
  const char playerO='O';

  char currentPlayer = playerX;

  int r=-1,c=-1;

  for(int i=0;i<9;i++){

    // print board
    cout<<"  |  |  "<<endl;
    cout<<" "<<board[0][0]<<"| "<<board[0][1]<<"| "<<board[0][2]<<endl;
    cout<<"__|__|__"<<endl;
    cout<<"  |  |  "<<endl;
    cout<<" "<<board[1][0]<<"| "<<board[1][1]<<"| "<<board[1][2]<<endl;
    cout<<"__|__|__"<<endl;
    cout<<"  |  |  "<<endl;
    cout<<" "<<board[2][0]<<"| "<<board[2][1]<<"| "<<board[2][2]<<endl;
    cout<<"  |  |  "<<endl;

    // get player input
    cout<<"current Player is "<<currentPlayer<<endl;

    while(true){

      cout<<"Enter r c form 0-2 for row and coloumn: ";

      cin>>r>>c;

      if(r<0||r>2||c>2||c<0){
        cout<<"Invalid input,try again"<<endl;
      }
      else if(board[r][c]!=' '){
        cout<<"Tile is full ,try again"<<endl;
      }
      else{
        break;
      }

      r=-1;
      c=-1;

      cin.clear();
      cin.ignore(1000,'\n');
    }

    board[r][c]=currentPlayer;

    char winner = cheakWinner(board);

    if(winner!=' '){
      cout<<"Player "<<winner<<" is winner"<<endl;
      return 0;
    }

    currentPlayer = (currentPlayer==playerX) ? playerO : playerX;
  }

  cout<<"Tie"<<endl;

  return 0;
}
