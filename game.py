board=["-","-","-",
      "-","-","-",
      "-","-","-"]

game_is_still_running=True
current_player="X"
winner=None

#display the board
def display_board():
  print(board[0]+ " | "+ board[1] +" | "+ board[2])
  print(board[3]+ " | "+ board[4]+ " | "+ board[5])
  print(board[6]+ " | "+ board[7]+ " | "+ board[8])

#play game
def play_game():
  display_board()
  
  while game_is_still_running:
    handle_turn(current_player)
    check_if_game_over()
    flip_player()
    
#if the game is Over
  if(winner=="X" or winner=="O"):
    print(winner + " won")
  elif winner==None:
    print("tie")


#take the turn
def handle_turn(player):
  print(player+" 's turn")
  
  turn=(input("choose a position among 1-9: "))
  valid=False
  while not valid:
    
    while turn not in ['1','2','3','4','5','6','7','8','9']:
      turn=(input("choose a position among 1-9: "))
    turn=int(turn) -1
    if board[turn] =="-":
      valid=True
    else:
      print("Not possible,try again!")
      
      
  board[turn]=player
  display_board()


#decide if the game is over or not
def check_if_game_over():
  check_if_win()
  check_if_tie()
  return

def check_if_win():
  global winner
  row_winner=check_row()
  coloumn_winner=check_coloumn()
  diagonal_winner=check_diagonal()

  if row_winner:
    winner=row_winner
  elif coloumn_winner:
    winner=coloumn_winner
  elif diagonal_winner:
    winner=diagonal_winner
  else:
    winner=None
  return



# total row part
def check_row():
  #global variable setup
  global game_is_still_running
  
  #checking the match for row
  row_1 = board[0]==board[1]==board[2]!="-"
  row_2 = board[3]==board[4]==board[5]!="-"
  row_3 = board[6]==board[7]==board[8]!="-"
  
  #eventually make the game_is_still_running variable false which end the game.
  if row_1 or row_2 or row_3:
    game_is_still_running=False
  
  #give value to check_if_win function
  if row_1:
    return board[0]
  elif row_2:
    return board[3]
  elif row_3:
    return board[6]
  return


#total coloumn part
def check_coloumn():
  #global variable setup
  global game_is_still_running

  #checking the match for coloumn
  coloumn_1 = board[0]==board[3]==board[6]!="-"
  coloumn_2 = board[1]==board[4]==board[7]!="-"
  coloumn_3 = board[2]==board[5]==board[8]!="-"
  
  #eventually make the game_is_still_running variable false which end the game.
  if (coloumn_1 or coloumn_2 or coloumn_3):
    game_is_still_running=False
  
  #give value to check_if_win function
  if coloumn_1:
    return board[0]
  elif coloumn_2:
    return board[1]
  elif coloumn_3:
    return board[2]
  return
  

#total diagonal part
def check_diagonal():

  #global variable setup
  global game_is_still_running

  #checking the match for diagonal
  diagonal_1 = board[0]==board[4]==board[8]!="-"
  diagonal_2 = board[2]==board[4]==board[6]!="-"
  
  
  #eventually make the game_is_still_running variable false which end the game.
  if (diagonal_1 or diagonal_2 ):
    game_is_still_running=False
  
  #give value to check_if_win function
  if diagonal_1:
    return board[0]
  elif diagonal_2:
    return board[2]
  
  return

def flip_player():
  #if the current player is X flip to O
  global current_player
  if current_player=="X":
    current_player="O"
  elif(current_player=="O"):
    current_player="X"
  return

def check_if_tie():
  global game_is_still_running
  global winner
  if "-" not in board:
    game_is_still_running=False
    winner=None
  return


play_game()