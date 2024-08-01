#include<iostream>
#include<string>

using namespace std;
    int a=1;
	int b=1;
    int z=1;
    int d=1;
    int e=1;
    int f=1;
    int g=1;
    bool GameOver=false;

struct connect4{

    connect4(string Names[]){
        re_init(Names);
    }
    connect4(){
        string N[2] = {"P1", "P2"};
        re_init(N);
    }
    
    void Playersname()
    {
    	cout<<"\nEnter name of Player one: ";
		cin>>PlayerNames[0];
		cout<<"\nEnter name of Player two : ";
		cin>>PlayerNames[1];
	}
    

    void re_init(string Names[]){
        for(int i = 0; i< 7; i++){
            ColumnMoves[i] = 6;
            for(int j = 0; j< 6; j++)
                Data[j][i] = 32; // 32 is code of space character
        }
        Result = 0;
        GameOver = 0;
        PlayerNames[0] = Names[0];
        PlayerNames[1] = Names[1];
        PlayerChar[0] = 'o';
        PlayerChar[1] = 'x';
        PlayerWinningChar[0] = 'O';
        PlayerWinningChar[1] = 'X';
    }
    
	
    int MakeMove(int Column, int i){
    	
    	WhosTurn(i);    	
    	
    		if(TurningPlayer==0)
    		{
    			
    			if(Column==7)
    			{
    				Data[6-a][Column-1]=PlayerChar[0];
    				int r=6-a;
    				int c=Column-1;
    				CheckIfGameOver(r,c,TurningPlayer);
    			    a++;
				}
				
    			if(Column==6)
    			{
    				Data[6-b][Column-1]=PlayerChar[0];
    				int r=6-b;
    				int c=Column-1;
    				CheckIfGameOver(r,c,TurningPlayer);
    			    b++;
				}
				
    			if(Column==5)
    			{
    				Data[6-z][Column-1]=PlayerChar[0];
    				int r=6-z;
    				int c=Column-1;
    				CheckIfGameOver(r,c,TurningPlayer);
    			    z++;
				}
				
    			if(Column==4)
    			{
    				Data[6-d][Column-1]=PlayerChar[0];
    			    int r=6-d;
    				int c=Column-1;
    				CheckIfGameOver(r,c,TurningPlayer);
    			    d++;
				}
				
    			if(Column==3)
    			{
    				Data[6-e][Column-1]=PlayerChar[0];
    			    int r=6-e;
    				int c=Column-1;
    				CheckIfGameOver(r,c,TurningPlayer);
    			    e++;
				}
				
    			if(Column==2)
    			{
    				Data[6-f][Column-1]=PlayerChar[0];
    			    int r=6-f;
    				int c=Column-1;
    			    CheckIfGameOver(r,c,TurningPlayer);
    				f++;
				}
    	
    			if(Column==1)
    			{
    				Data[6-g][Column-1]=PlayerChar[0];
    			    int r=6-g;
    				int c=Column-1;
    				CheckIfGameOver(r,c,TurningPlayer);
    			    g++;
				}
			}
			else
			{
				if(Column==7)
    			{
    				Data[6-a][Column-1]=PlayerChar[1];
    			    int r=6-a;
    				int c=Column-1;
    				CheckIfGameOver(r,c,TurningPlayer);
    			    a++;
				}
				
    			if(Column==6)
    			{
    				Data[6-b][Column-1]=PlayerChar[1];
    			    int r=6-b;
    				int c=Column-1;
    				CheckIfGameOver(r,c,TurningPlayer);
    			    b++;
				}
				
    			if(Column==5)
    			{
    				Data[6-z][Column-1]=PlayerChar[1];
    			    int r=6-z;
    				int c=Column-1;
    				CheckIfGameOver(r,c,TurningPlayer);
    			    z++;
				}
				
    			if(Column==4)
    			{
    				Data[6-d][Column-1]=PlayerChar[1];
    			    int r=6-d;
    				int c=Column-1;
    				CheckIfGameOver(r,c,TurningPlayer);
    			    d++;
				}
				
    			if(Column==3)
    			{
    				Data[6-e][Column-1]=PlayerChar[1];
    		        int r=6-e;
    				int c=Column-1;
    				CheckIfGameOver(r,c,TurningPlayer);
    			    e++;
				}
				
    			if(Column==2)
    			{
    				Data[6-f][Column-1]=PlayerChar[1];
    			    int r=6-f;
    				int c=Column-1;
    				CheckIfGameOver(r,c,TurningPlayer);
    			    f++;
				}
    	
    			if(Column==1)
    			{
    				Data[6-g][Column-1]=PlayerChar[1];
    			    int r=6-g;
    				int c=Column-1;
    				CheckIfGameOver(r,c,TurningPlayer);
    			    g++;
			    }
			}

    }
    
    void ShowGame(){
    
    	for(int i=0; i<6; i++)
    	{
    		cout<<"|";
    		for(int j=0; j<7; j++)
    		{
    			cout<<Data[i][j]<<"|";
			}
			cout<<endl;
		}
    /*
        Function to display the game status on screen;
    */
    }

    bool isGameOver(){
        return GameOver;
    }

    int WhosTurn(int i){
    	if(i%2==0)
    	{
    		TurningPlayer=0;
		}
		else
		{
			TurningPlayer=1;
		}
        return TurningPlayer;
    }

    string getPlayerName(int id){
        if(id< 0 || id > 1 )
            return "";
        return PlayerNames[id];
    }
private:
    void CheckIfGameOver(int r, int c, int i){
    	int y;
    
    //CONDITIONS FOR CHECK DOWN
    if(Data[r][c]==Data[r+1][c] && Data[r][c]==Data[r+2][c] && Data[r][c]==Data[r+3][c] )
    {
    	GameOver=true;
    	y=i;
    	finalresult(y);
    	
    }
	
	//CONDITIONS FOR CHECK SIDES
	else if(Data[r][c]==Data[r][c+1] && Data[r][c]==Data[r][c+2] && Data[r][c]==Data[r][c+3])
	{
		GameOver=true;
		y=i;
		finalresult(y);
	}
	
	else if(Data[r][c]==Data[r][c-1] && Data[r][c]==Data[r][c-2] && Data[r][c]==Data[r][c-3]  )
	{
		GameOver=true;
		y=i;
		finalresult(y);
	}
    
    else if(Data[r][c]==Data[r][c-1] && Data[r][c]==Data[r][c+1] && Data[r][c]==Data[r][c+2])
	{
		GameOver=true;
		y=i;
		finalresult(y);
	}
	
	else if(Data[r][c]==Data[r][c+1] && Data[r][c]==Data[r][c-1] && Data[r][c]==Data[r][c-2])
	{
		GameOver=true;
		y=i;
		finalresult(y);
	}
	
	//CONDITIONS FOR RIGHT DIOGNAL
	else if(Data[r][c]==Data[r-1][c+1] && Data[r][c]==Data[r-2][c+2] && Data[r][c]==Data[r-3][c+3])
	{
		GameOver=true;
		y=i;
		finalresult(y);
	}
	else if(Data[r][c]==Data[r+1][c-1] && Data[r][c]==Data[r+2][c-2] && Data[r][c]==Data[r+3][c-3])
	{
		GameOver=true;
		y=i;
		finalresult(y);
	}
	
	else if(Data[r][c]==Data[r+1][c-1] && Data[r][c]==Data[r+2][c-2] && Data[r][c]==Data[r-1][c+1])
	{
		GameOver=true;
		y=i;
		finalresult(y);
	}
	
	else if(Data[r][c]==Data[r-1][c+1] && Data[r][c]==Data[r-2][c+2] && Data[r][c]==Data[r+1][c-1])
	{
		GameOver=true;
		y=i;
		finalresult(y);
	}
	//CONDITIONS FOR LEFT DIOGNAL
	
	else if(Data[r][c]==Data[r-1][c-1] && Data[r][c]==Data[r-2][c-2] && Data[r][c]==Data[r-3][c-3])
	{
		GameOver=true;
		y=i;
		finalresult(y);
	}
	
	else if(Data[r][c]==Data[r+1][c+1] && Data[r][c]==Data[r+2][c+2] && Data[r][c]==Data[r+3][c+3])
	{
		GameOver=true;
		y=i;
		finalresult(y);
	}
	else if(Data[r][c]==Data[r+1][c+1] && Data[r][c]==Data[r+2][c+2] && Data[r][c]==Data[r-1][c-1])
	{
		GameOver=true;
		y=i;
		finalresult(y);
	}
	
	else if(Data[r][c]==Data[r-1][c-1] && Data[r][c]==Data[r-2][c-2] && Data[r][c]==Data[r+1][c+1])
	{
		GameOver=true;
		y=i;
		finalresult(y);
	}
	
    /*
        This function will check if the game is finished and set the values
        of variables GameOver and Result
        The parameters r and c specify the position of last move last

        This
    */

    }
    void finalresult(int y){
		if(y == 0)
		cout<<"\nCONGRATS "<<PlayerNames[0]<<" WINS ";
		if(y == 1)
		cout<<"\nCONGRATS "<<PlayerNames[1]<<" WINS ";
		cout<<endl;
	}

    string PlayerNames[2]; // To Hold Name of Players Who are playing
    int TurningPlayer; // To save the players ID who is making a move; 0: First Player, 1: Second Player
    char PlayerChar[2]; // Characters to be shown for move
    char PlayerWinningChar[2]; // Character to be shown if player wins.
    int  ColumnMoves[7]; // An array to keep record of first empty cell in a column
    char Data[6][7]; // Array to hold game data.
     // If true it means the game is over.
    int Result;// Variable to hold result of game {0: Drawn, -1: First Player Lost, 1: First Player Won}
};


int main(){
    /*
        This function use a single variable of type connect4
        and use it's functions to play the game
    */
    int Column;
    int i=0; 
    
    string N[2] = {"P1", "P2"};
    connect4 Game(N);
    Game.re_init(N);
    Game.Playersname();
    while(GameOver!=true){ 
	      	
        cout<<"Column number: ";
    	cin>>Column;
    	cout<<endl;
    	if(i%2==0)
    	   cout<<"P1";
    	if(i%2!=0)
    	   cout<<"P2";
		cout<<endl;
		cout<<" 1 2 3 4 5 6 7";
		cout<<endl;      
    	Game.MakeMove(Column, i);
    	Game.ShowGame();
    	cout<<endl;
    	i++;
		
    	
	}
	cout<<endl;
    if(i==42)
    {
    	cout<<"DRAW GAME";
	}

    return 0;
}
 
