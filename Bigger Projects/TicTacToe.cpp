#include <iostream>
#include <cstring>
#define N 3
using namespace std;

class tictactoe
{
    public:
        tictactoe();
        ~tictactoe();
        bool play(int ,int );
        char check_win();
        void print();
        
        
        void next_player();
        char get_player() const;
    private:
        char **board;
        char player;
};


int main(void)
{
    tictactoe game;
    int player_line,player_row,turns=1;
    char winner;
    
    while(true)
    {
        cout << "Board" << endl;
        cout << "-----" << endl;
        game.print();
        cout << endl << "|-------------|" << endl;
        cout << "|" << game.get_player() << " Player Turn|" << endl;
        cout << "|-------------|" << endl;
        cout << "Give Line:";
        cin >> player_line;
        cout << "Give Row:";
        cin >> player_row;
        if(!game.play(player_line-1,player_row-1))
        {
            cout << "Lathos kinisi" << endl;
            continue;
        } 
        winner = game.check_win();
        if(winner == 'X')
        {
            cout << "|-------------|" << endl;
            cout << "|Winner Is X! |" << endl;
            cout << "|-------------|" << endl;
            break;
        }
        else if(winner == 'O')
        {   cout << "|------------|" << endl;
            cout << "|Winner Is O!|" << endl;
            cout << "|------------|" << endl;
            break;
        }
        turns++;
        if(turns == 10)
        {
            cout << "Tie!" << endl;
            break;
        }
        game.next_player();
    }
    game.print();
    return 0;
}

char tictactoe::get_player() const
{
    return player;
}


void tictactoe::next_player()
{
     if(player =='X')
        {
            player = 'O';
        }
        else
        {
            player = 'X';
        }
}


tictactoe::tictactoe()
{
    board = new char* [N];
    for(int i=0;i<N;i++)
    {
        board[i] = new char [N];
    }
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            board[i][j] = '-';
        }
    }
    player = 'X';
}

tictactoe::~tictactoe()
{
    for(int i=0;i<N;i++)
    {
        delete [] board[i];
    }
    delete [] board;
}

bool tictactoe::play(int in_x,int in_y)
{
    if(board[in_x][in_y] == '-')
    {
        board[in_x][in_y] = player;
        return true;
    }
    else
    {
        return false;
    }
}

char tictactoe::check_win()
{
    
    /* lines*/
    int count_X_lines;
    int count_O_lines;
    bool lines_X = false;
    bool lines_O = false;
    
    for(int i=0;i<N;i++)
    {
        count_X_lines = 0;
        count_O_lines = 0;
        for(int j=0;j<N;j++)
        {
            if(board[i][j] == 'X')
            {
                count_X_lines += 1;
            }
            else if(board[i][j] == 'O')
            {
                count_O_lines += 1;
            }
        }
        if(count_X_lines == 3)
        {
            lines_X = true;
            break;
        }
        if(count_O_lines == 3)
        {
            lines_O = true;
            break;
        }
        
    }
    if(lines_X == true)
    {
        return 'X';
    }
    else if(lines_O == true)
    {
        return 'O';
    }
 

    
    /*rows*/

    int count_X_rows;
    int count_O_rows;
    bool rows_X = false;
    bool rows_O = false;


    for(int j=0;j<N;j++)
    {
        count_X_rows = 0;
        count_O_rows = 0;
        for(int i=0;i<N;i++)
        {
            if(board[i][j] == 'X')
            {
                count_X_rows += 1;
               
            }
            else if(board[i][j] == 'O')
            {
                count_O_rows += 1;
               
            }
        }
        
        if(count_X_rows == 3)
        {
            rows_X = true;
            break;
        }
         if(count_O_rows == 3)
        {
            rows_O = true;
            break;
        }
    }
    if(rows_X == true)
    {
        return 'X';
    }
    else if(rows_O == true)
    {
        return 'O';
    }
   

    
    /*Main Diagonal*/

    int count_X_Main_Diagonal = 0;
    int count_O_Main_Diagonal = 0;
    bool Main_X_Diagonal = false;
    bool Main_O_Diagonal = false;
    
    
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(i == j && board[i][j] == 'X')
            {
                count_X_Main_Diagonal += 1;
            }
            else if(i == j && board[i][j] == 'O')
            {
                count_O_Main_Diagonal += 1;
            }
        }
        if(count_X_Main_Diagonal == 3)
        {
            Main_X_Diagonal = true;
            break;
        }
         if(count_O_Main_Diagonal == 3)
        {
            Main_O_Diagonal = true;
            break;
        }
    }

    if(Main_X_Diagonal == true)
    {
        return 'X';
    }
    else if(Main_O_Diagonal == true)
    {
        return 'O';
    }
  

   

    /*Secondary Diagonal*/

    int count_X_Secondary_Diagonal = 0;
    int count_O_Secondary_Diagonal = 0; 
    bool Secondary_Diagonal_X = false;
    bool Secondary_Diagonal_O = false;


    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
                if(i == N-(j+1) && board[i][j] == 'X')
                {
                    count_X_Secondary_Diagonal += 1;
                }
                else if(i == N-(j+1) && board[i][j] == 'O')
                {
                    count_O_Secondary_Diagonal += 1;
                }
        }
        if(count_X_Secondary_Diagonal == 3)
        {
            Secondary_Diagonal_X = true;
            break;
        }
        if(count_O_Secondary_Diagonal == 3)
        {
            Secondary_Diagonal_O = true;
            break;
        }
    }
    
    if(Secondary_Diagonal_X == true)
    {
        return 'X';
    }
    else if(Secondary_Diagonal_O == true)
    {
        return 'O';
    }
    


    if(lines_X == false && lines_O == false && rows_X == false && rows_O == false && Main_X_Diagonal == false && Main_O_Diagonal == false && Secondary_Diagonal_X == false && Secondary_Diagonal_O == false)
    {
        return '-';    
    }    
}   
    
void tictactoe::print()
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(j !=2 )
            {
                cout << board[i][j] << "|";
            }
            else
            {
                cout << board[i][j];
            }
        }
        cout << endl;
    }
}