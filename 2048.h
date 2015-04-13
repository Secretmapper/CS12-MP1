#ifndef __2048__
#define __2048__

/** Tile Datastructure
 */
struct Tile;

class G2048 {
    private:
        /** Board Datastructure. 
         * Represents the 4x4 board
         */
        int board[4][4];

        /** Current Score for the Game
         */
        int score;

        /** Filename where the game will be saved. 
         */
        char* filename;

        /** Adds random tile to the board after every turn. 
         *  Adds tile of value 2 or 4 to the board every turn.
         */
        void addTile();

        /** Prompts input character from the player then returns the value. 
         *  Input represents the direction to take or quit.
         *  @return Input character
         */
        char getInput();

        /** Moves the tiles in the specified direction. 
         *  Computes and updates the score. 
         *  @return Boolean on wheter the board has changed (move is valid).
         */
        bool move(char direction);

        /** Prints in the terminal the current state of the board. 
         */
        void drawBoard();
        
        /** Checks if the game is already won.
         *  @return Is there a 2048 in the board?
         */
        bool hasReached2048();

        /** Checks if there is still a possible move.
         *  There is a possible move when there is still an empty tile.
         *  Or if it is still possible to combine tiles.
         */
        bool hasMove();
        
        /** Loads the game.
         *  Loads the game from the filename specified. 
         */
        void loadGame();
         
        /** Saves the game.
         *  Saves the game to the filename specified.
         *  Prompts user if filename is NULL.
         */
        void saveGame();

        /*********************************************
        PLACE ANY ADDITIONAL MEMBER DECLARATIONS HERE
        **********************************************/

        /** Wheter there is still an available tile. 
         *  Value set every game loop .
         *  @see randomAvailableTile
         *  Checked to see if there is an available tile.
         */
        bool hasAvailableTile;

        /** Get Random Available Tile.
         *  Sets hasAvailableTile.
         *  @see hasAvailableTile
         *  @return Random Tile from the board.
         */
        Tile randomAvailableTile();

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
