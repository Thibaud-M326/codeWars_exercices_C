#include <stdio.h>

enum game_state { NOT_FINISHED = -1, DRAW = 0, X_WON = 1, O_WON = 2 };
enum square { EMPTY = 0, X = 1, O = 2 };

void ft_print_nice_board(const enum square board[3][3])
{
  int i;
  int j;
  
  i = 0;
  j = 0;
  printf("+---+---+---+\n");
  while(i < 3)
  {
    printf("| ");
    while(j < 3)
    {
      printf("%d | ", board[i][j]);
      j++; 
    }
    printf("\n");
    printf("+---+---+---+\n");
    j = 0;
    i++;
  }
}

int ft_test_line(const enum square board[3][3], int player_num)
{
  int i;
  int j;
  
  i = 0;
  j = 0;
  while(i < 3)
  {
    while(j < 3 && board[i][j] == player_num)
    {
      if(j == 2)
      {
        return player_num; 
      }
      j++;
    }
    j = 0;
    i++;
  }
  return 0;
}

int ft_init_test_line(const enum square board[3][3])
{
  int winner;
  int player_num;
  int i;
  
  player_num = 0;
  i = 0;
  winner = 0;
  while(i < 3)
  {
    if(board[i][0] != 0)
    {
      player_num = board[i][0]; 
      winner = ft_test_line(board, player_num);
      if(winner != 0)
      {
        return winner;
      }
    }
    i++;
  }
  return winner;
}

int ft_test_column(const enum square board[3][3], int player_num)
{
  int i;
  int j;
  
  i = 0;
  j = 0;
  while(i < 3)
  {
    while(j < 3 && board[j][i] == player_num)
    {
      if(j == 2)
      {
        return player_num; 
      }
      j++;
    }
    j = 0;
    i++;
  }
  return 0;
}

int ft_init_test_column(const enum square board[3][3])
{
  int winner;
  int player_num;
  int i;
  
  player_num = 0;
  i = 0;
  winner = 0;
  while(i < 3)
  {
    if(board[0][i] != 0)
    {
      player_num = board[0][i];
      winner = ft_test_column(board, player_num);
      if(winner != 0)
      {
        return winner;
      }
    }
    i++;
  }
  return winner;
}

int ft_test_diagonal_top(const enum square board[3][3], int player_num)
{
  if(board[0][0] == player_num
  && board[1][1] == player_num
  && board[2][2] == player_num)
  {
    return player_num;
  }
  return 0;
}

int ft_init_diagonal_top(const enum square board[3][3])
{
  int winner;
  int player_num;
  
  winner = 0;
  player_num = 0;
  if(board[0][0] != 0)
  {
    player_num = board[0][0];
    winner = ft_test_diagonal_top(board, player_num);
  }
  return winner;
}

int ft_test_diagonal_bottom(const enum square board[3][3], int player_num)
{
  if(board[2][0] == player_num
  && board[1][1] == player_num
  && board[0][2] == player_num)
  {
    return player_num;
  }
  return 0;
}

int ft_init_diagonal_bottom(const enum square board[3][3])
{
  int winner;
  int player_num;
  
  winner = 0;
  player_num = 0;
  if(board[2][0] != 0)
  {
    player_num = board[2][0];
    winner = ft_test_diagonal_bottom(board, player_num);
  }
  return winner;
    
}
  
enum game_state check_game_state (const enum square board[3][3])
{
  int i;
  int j;
  int winner;
  
  winner = 0;
  i = 0;
  j = 0;
  ft_print_nice_board(board);
  winner = ft_init_test_line(board);
  if(winner != 0)
  {
    return winner;
  }
  winner = ft_init_test_column(board);
  if(winner != 0)
  {
    return winner;
  }
  winner = ft_init_diagonal_top(board);
  if(winner != 0)
  {
    return winner;
  }
  winner = ft_init_diagonal_bottom(board);
  if(winner != 0)
  {
    return winner;
  }
  while(i < 3)
  {
    while(j < 3)
    {
      if(board[i][j] == 0)
      {
        return NOT_FINISHED;
      }
      j++; 
    }
    j = 0;
    i++;
  }
  return DRAW;
}