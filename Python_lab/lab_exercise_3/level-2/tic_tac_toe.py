board = [
    ['O', 'O', 'X'],
    ['O', 'X', 'O'],
    ['O', 'X', 'X']
]
def check_TicTacToe(board):
    for i in range(0,3):
        if board[i][0] == board[i][1] == board[i][2]:
            return (f"{board[i][0]} player wins")
        elif board[0][i] == board[1][i] == board[2][i]:
            return (f"{board[0][i]} player wins")
        elif board[0][0] == board[1][1] == board[2][2]:
            return (f"{board[0][0]} player wins")
        elif board[0][2] == board[1][1] == board[2][0]:
            return (f"{board[0][2]} player wins")
        else:
            return 'draw'
for row in board:
    print(row)
print('result of the match' , check_TicTacToe(board))