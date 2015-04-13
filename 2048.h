#ifndef __2048__
#define __2048__

struct Tile;

class G2048 {
    private:
        /*
            This data member represents the 4x4 board.
        */
        int board[4][4];
        /*
            This data member represents the current score for the game.
        */
        int score;
        /*
            This data member stores the name of the file to which the game is/will be saved.
        */
        char* filename;
        /*
            This function randomly adds a tile of value 2 or 4 to the board after each valid turn.
        */
        void addTile();
        /*
            This function prompts for an input character from the player, then returns the value.
            The input represents the direction to take, or the player's desire to quit.
        */
        char getInput();
        /*
            This function moves the tiles in the specified direction,
            computes and updates the score. It returns true if the state of the board has changed (move is valid).
        */
        bool move(char direction);
        /*
            This function prints in the terminal the current state of the board.
        */
        void drawBoard();
        /*
            This function checks if the game is already won.
        */
        bool hasReached2048();
        /*
            This function checks if there is still a possible move.
        */
        bool hasMove();
        /*
            This function tries to load a 2048 game from the specified file.
        */
        void loadGame();
        /*
            This function saves the instance of this class to the specified file. 
            If the argument is NULL, prompt for a valid filename.
        */
        void saveGame();
        /*********************************************
        PLACE ANY ADDITIONAL MEMBER DECLARATIONS HERE
        **********************************************/
        Tile randomAvailableTile();
        bool hasAvailableTile;
    public:
        /*
            This initializes a game of 2048 - the board, score, and filename.            
            When the filename given is valid, check for the existence of the file,
             and load the values contained in it accordingly.
            Use the same file to save the game upon quitting.
        */
        G2048(char* filename);
        /*  
            This function starts/resumes a game of 2048.
        */
        void startGame();
};

#endif
