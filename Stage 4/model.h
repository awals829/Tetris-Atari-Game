/*
 * File: model.h
 * Author: Marusia Luciuk, Andrew Walsh
 * Team Members: Marusia Luciuk, Andrew Walsh
 *
 * This header file for the main structures and 
 * constants used in the Tetris game, including 
 * Tetrominoes, Blocks, and the Play Area.
 */

#ifndef MODEL_H
#define MODEL_H

/*****************************************
 *            CONSTANTS
 *****************************************/
/**
 * Definitions of game specific constants.
 */

/* Conditional Results For Readability */
#define TRUE 1
#define FALSE 0

/* Number of Blocks (columns) in the play area */
#define PLAY_AREA_WIDTH_GRID 10
/* Number of Blocks (rows) in the play area */
#define PLAY_AREA_HEIGHT_GRID 20

/* Standard Tetromino Block Count */
#define TETROMINO_SIZE 4

/* Play Area Grid Min Arena Array X-Coordinate Play_area[X][Y] */
#define PLAY_AREA_MIN_X 0
/* Play Area Grid Min Arena Array Y-Coordinate Play_area[X][Y] */
#define PLAY_AREA_MIN_Y 0
/* Play Area Grid Max Arena Array X-Coordinate Play_area[X][Y] */
#define PLAY_AREA_MAX_X (PLAY_AREA_WIDTH_GRID - 1)
/* Play Area Grid Max Arena Array Y-Coordinate Play_area[X][Y] */
#define PLAY_AREA_MAX_Y (PLAY_AREA_HEIGHT_GRID - 1)


/* Top Left Starting Coordinates For Play Area & 
    Horizontal & Verical Pixel Sizing For Play Area */
#define PLAY_AREA_START_SCREENX 127
#define PLAY_AREA_START_SCREENY 39
#define PLAY_AREA_WIDTH_SCREEN (PLAY_AREA_WIDTH_GRID << 4) + 1
#define PLAY_AREA_HEIGHT_SCREEN (PLAY_AREA_HEIGHT_GRID << 4) + 1


/* Offset Coordinates For The Tetromino Blocks 
    In The Arena For Ease Of Visualization. */

/* Blocks In Play Area Screen X-Coordinates Start */
#define BLOCK_PLAY_START_SCREENX (PLAY_AREA_START_SCREENX + 1)
/* Blocks In Play Area Screen Y-Coordinates Start */
#define BLOCK_PLAY_START_SCREENY (PLAY_AREA_START_SCREENY + 1)


/* Score Display Box Coordinates & Sizing 
    Always placed at a set distance
    away from the play area (to the right by 5 blocks) */

/* Score Display Screen X-Coordinates */
#define SCORE_DISPLAY_SCREENX (PLAY_AREA_START_SCREENX + PLAY_AREA_WIDTH_SCREEN) + (5 << 4)
/* Score Display Screen Y-Coordinates */
#define SCORE_DISPLAY_SCREENY (PLAY_AREA_START_SCREENY)
/* Score Display Width In Pixels */
#define SCORE_DISPLAY_WIDTH_PX (11 << 3)
/* Score Display Height In Pixels */
#define SCORE_DISPLAY_HEIGHT_PX (12 << 3)

/* Next Tetromino Display Screen X-Coordinates*/
#define NEXT_TETROM_DISPLAY_SCREENX SCORE_DISPLAY_SCREENX/* Same X displacement as score display */
/* Next Tetromino Display Screen Y-Coordinates */
#define NEXT_TETROM_DISPLAY_SCREENY (16 << 4)
/* Next Tetromino Display Width In Pixels */
#define NEXT_TETROM_DISPLAY_WIDTH_PX (8 << 4) + 1
/* Next Tetromino Height In Pixels */
#define NEXT_TETROM_DISPLAY_HEIGHT_PX (6 << 4) + 1

/* Offset Coordinates For The Next Tetromino Blocks 
   Display In The Arena For Ease Of Visualization. */

/* Blocks Offset For Next Tetromino Display Screen X-Coordinates Start */
#define NEXT_BLOCK_START_SCREENX (NEXT_TETROM_DISPLAY_SCREENX + 1)
/* Blocks Offset For Next Tetromino Display Screen Y-Coordinates Start */
#define NEXT_BLOCK_START_SCREENY (NEXT_TETROM_DISPLAY_SCREENY + 1)


/* Top Score Label Screen X-Coordinates */
#define TOP_SCORE_LABEL_SCREENX (SCORE_DISPLAY_SCREENX + 8)
/* Top Score Label Screen Y-Coordinates */
#define TOP_SCORE_LABEL_SCREENY (SCORE_DISPLAY_SCREENY + 4)

/* Top Score Numeric String Screen X-Coordinates */
#define TOP_SCORE_STRING_SCREENX (SCORE_DISPLAY_SCREENX + 8)
/* Top Score Numeric String Screen Y-Coordinates */
#define TOP_SCORE_STRING_SCREENY (TOP_SCORE_LABEL_SCREENY + 16)

/* Current Score Label Screen X-Coordinates */
#define CURRENT_SCORE_LABEL_SCREENX (SCORE_DISPLAY_SCREENX + 8)
/* Current Score Label Screen Y-Coordinates */
#define CURRENT_SCORE_LABEL_SCREENY (TOP_SCORE_STRING_SCREENY + 16)

/* Current Score Numeric String Screen X-Coordinates */
#define CURRENT_SCORE_STRING_SCREENX (SCORE_DISPLAY_SCREENX + 8)
/* Current Score Numeric String Screen Y-Coordinates */
#define CURRENT_SCORE_STRING_SCREENY (CURRENT_SCORE_LABEL_SCREENY + 16)

/* Current Level Label Coordinates Screen X-Coordinates */
#define CURRENT_LEVEL_LABEL_SCREENX (SCORE_DISPLAY_SCREENX + 8)
/* Current Level Label Coordinates Screen Y-Coordinates */
#define CURRENT_LEVEL_LABEL_SCREENY (CURRENT_SCORE_STRING_SCREENY + 16)

/* Current Level Numeric String Screen X-Coordinates */
#define CURRENT_LEVEL_STRING_SCREENX (SCORE_DISPLAY_SCREENX + 8)
/* Current Level Numeric String Screen Y-Coordinates */
#define CURRENT_LEVEL_STRING_SCREENY (CURRENT_LEVEL_LABEL_SCREENY + 16)


/* Level 1 Num To Convert To String For Display */
#define L1 1
/* Level 2 Num To Convert To String For Display  */
#define L2 2
/* Level 3 Num To Convert To String For Display  */
#define L3 3
/* Level 4 Num To Convert To String For Display  */
#define L4 4
/* Level 5 Num To Convert To String For Display  */
#define L5 5
/* Level 6 Num To Convert To String For Display  */
#define L6 6
/* Level 7 Num To Convert To String For Display  */
#define L7 7
/* Level 8 Num To Convert To String For Display  */
#define L8 8
/* Level 9 Num To Convert To String For Display  */
#define L9 9
/* Level 10 Num To Convert To String For Display  */
#define L10 10

/* Level 1 (Default) Value To Increment Score Per Cleared Line */
#define SCORE_INCREMENT_L1 40
/* Level 2 Value To Increment Score Per Cleared Line */
#define SCORE_INCREMENT_L2 (SCORE_INCREMENT_L1 + SCORE_INCREMENT_L1)
/* Level 3 Value To Increment Score Per Cleared Line */
#define SCORE_INCREMENT_L3 (SCORE_INCREMENT_L2 + SCORE_INCREMENT_L1)
/* Level 4 Value To Increment Score Per Cleared Line */
#define SCORE_INCREMENT_L4 (SCORE_INCREMENT_L3 + SCORE_INCREMENT_L1)
/* Level 5 Value To Increment Score Per Cleared Line */
#define SCORE_INCREMENT_L5 (SCORE_INCREMENT_L4 + SCORE_INCREMENT_L1)
/* Level 6 Value To Increment Score Per Cleared Line */
#define SCORE_INCREMENT_L6 (SCORE_INCREMENT_L5 + SCORE_INCREMENT_L1)
/* Level 7 Value To Increment Score Per Cleared Line */
#define SCORE_INCREMENT_L7 (SCORE_INCREMENT_L6 + SCORE_INCREMENT_L1)
/* Level 8 Value To Increment Score Per Cleared Line */
#define SCORE_INCREMENT_L8 (SCORE_INCREMENT_L7 + SCORE_INCREMENT_L1)
/* Level 9 Value To Increment Score Per Cleared Line */
#define SCORE_INCREMENT_L9 (SCORE_INCREMENT_L8 + SCORE_INCREMENT_L1)
/* Level 10 Value To Increment Score Per Cleared Line */
#define SCORE_INCREMENT_L10 (SCORE_INCREMENT_L9 + SCORE_INCREMENT_L1)


/*****************************************
 *            OBJECTS
 *****************************************/
/**
 * Definitions of key game objects:
 * 
 * - Block
 * - Tetromino
 * - Play_area
 * - Score_display
 * - Top_score_label
 * - Top_score_string
 * - Current_score_label
 * - Current_score_string
 * - Level_label
 * - Level_string
 */

/********** Block Object **********
 * 
 * Represents a single block, either part of a Tetromino
 * or a stationary block in the play area.
 */
typedef struct block{
    /* Play area arena[10][20] block coordinates */
    int arenaX, arenaY;
    /* Screen coordinates of block for plotting */
    int screenX, screenY;
    /* Condition checks for collisions etc. */
    unsigned char is_occupied, is_tetromino_piece;

} Block;


/********** Tetromino Object **********
 * 
 * Represents a Tetromino, composed of 4 Blocks, 
 * which is the primary game piece.
 */
typedef struct tetromino {
    /* Block type of tetromino -> [ T , L , J , S , Z , I , or O ] */
    unsigned char tetromino_type;
    /* 
        4 Blocks That Make Up The Tetromino
        blocks[0] -> Origin Block (Rotates around this)
        blocks[1] -> Block 1
        blocks[2] -> Block 2 
        blocks[3] -> Block 3
    */
    Block blocks[TETROMINO_SIZE];

} Tetromino;


/********** Play Area Object **********
 * 
 * Represents the primary gameplay area 
 * where Tetrominoes are spawned, placed,
 * moved, and lines are cleared.
 */
typedef struct play_area {
    /* Top left coordinates for start of play area */
    int screenX, screenY;
    /* Play area width and height */
    int width, height;
    /* Indicates vertical displacement per clock tick 
    of playable tetromino */
    int gravity;
    /* Indicates if arena matrix is full */
    char is_full; 
    /* Play area for tetris game made up of block objects */
    Block arena[PLAY_AREA_WIDTH_GRID][PLAY_AREA_HEIGHT_GRID];

} Play_area;


/********** Score Display Object **********
 * 
 * Primary score box on the top right section
 * of the screen. Used for "containing" the 
 * labels and numeric game progress strings.
 */
typedef struct score_display {
    /* Screen position coordinates */
    int screenX, screenY;
    /* General sizing of score display box */
    int width, height;
    /* Int indicating top score */
    unsigned long top_score;
    /* Int indicating current score */
    unsigned long current_score;
    /* Current level for game modifiers */
    unsigned int level;

} Score_display;

/********** Score Display Object **********
 * 
 * Primary score box on the top right section
 * of the screen. Used for "containing" the 
 * labels and numeric game progress strings.
 */
typedef struct next_tetrom_display {
    /* Screen position coordinates */
    int screenX, screenY;
    /* General sizing of score display box */
    int width, height;
    
    char next_label_string[5];

    Block grid[8][5];

} Next_tetrom_display;


/********** Top Score Label Object **********
 * 
 * The label for the top score that will
 * appear in score display screen.
 */
typedef struct top_score_label {
    /* Screen position coordinates */
    int screenX, screenY;
    /* Char array indicating the top score label for font printing */
    char top_score_label_string[10];
    /* Length of char string array */
    int string_length;

} Top_score_label;


/********** Top Score String Object **********
 * 
 * String of characters that represent the respective
 * in-game highest top score converted to a string.
 */
typedef struct top_score_string {
    /* Screen position coordinates */
    int screenX, screenY; 
     /* Int indicating top score (Used to check if Score display value is different).
        This is helpful to avoid repeated unecessary prints when updating all
        score display values at at once. */
    unsigned long top_score;
    /* Char array indicating the top score string for font printing */
    char top_score_num_string[7];
    /* Length of char string array */
    int string_length;

} Top_score_string;


/********** Current Score Label Object **********
 * 
 * The label for the current score that will
 * appear in score display screen.
 */
typedef struct current_score_label {
    /* Screen position coordinates */
    int screenX, screenY;
    /* Char array indicating the current score label for font printing */
    char current_score_label_string[6];
    /* Length of char string array */
    int string_length;

} Current_score_label;


/********** Current Score String Object **********
 * 
 * String of characters that represent the respective
 * in-game current score converted to a string.
 */
typedef struct current_score_string {
    /* Screen Position coordinates */
    int screenX, screenY; 
    /* Int indicating current score (Used to check if Score display value is different).
        This is helpful to avoid repeated unecessary prints when updating all
        score display values at at once. */
    unsigned long current_score;
    /* Char array indicating the current score string for font printing */
    char current_score_num_string[7];
    /* Length of char string array */
    int string_length;

} Current_score_string;


/********** Level Label Object **********
 * 
 * The label for the level that will
 * appear in score display screen.
 */
typedef struct level_label {
    /* Screen position coordinates */
    int screenX, screenY;
    /* Char array indicating the level label for font printing */
    char level_label_string[6];
    /* Length of char string array */
    int string_length;

} Level_label;


/********** Level String Object **********
 * 
 * String of characters that represent the respective
 * level number converted to a string.
 */
typedef struct level_string {
    /* Screen position coordinates */
    int screenX, screenY;
    /* Int indicating the current level (Used to check if Score display value is different).
        This is helpful to avoid repeated unecessary prints when updating all
        score display values at at once. */
    unsigned int level;
    /* Char array indicating the level string for font printing */
    char level_num_string[3];
    /* Length of char string array */
    int string_length;

} Level_string;



/*****************************************
 *           FUNCTION PROTOTYPES
 *****************************************/
/**
 * Function prototypes for initializing game objects, handling game logic,
 * updating game state, rendering, and other utility functions.
 */

/********** GRID COORD & SCREEN COORD CONVERSION FUNCTIONS **********/

/* Converts arena x-coordinate to screen x-coordinate for a block */
int arenaX_to_screenX(Block b); /*Tested: Yes */

/* Converts arena y-coordinate to screen y-coordinate for a block */
int arenaY_to_screenY(Block b); /*Tested: Yes */

/* Converts screen x-coordinate to arena x-coordinate for a block */
int screenX_to_arenaX(Block b); /*Tested: Yes */

/* Converts screen y-coordinate to arena y-coordinate for a block */
int screenY_to_arenaY(Block b); /*Tested: Yes */


/********** BLOCK FUNCTIONS **********/

/* Initializes a block with given arena coordinates */
void initBlock(Block *b, int arenaX, int arenaY); /*Tested: Yes */

/* Checks if the x-arena of the arena is a viable location returns TRUE / FALSE */
int isArenaXViable(int arenaX); /*Tested: Yes */

/* Checks if the y-arena of the arena is a viable location returns TRUE / FALSE */
int isArenaYViable(int arenaY); /*Tested: Yes */

/* Checks if the x-arena / y-arena of the arena is occupied returns TRUE / FALSE */
int isPositionOccupied(Play_area *play_area, int arenaX, int arenaY); /*Tested: Yes */

/* Checks if the x-arena / y-arena of the arena is a tetromino piece returns TRUE / FALSE */
int isPositionTetromino(Play_area *play_area, int arenaX, int arenaY); /*Tested: Yes */


/********** TETROMINO FUNCTIONS **********/

/* Selects a random tetromino piece based on the 
    block 1 and block 3 coordinates of the input tetromino */
void randomize(Tetromino *t); /*Tested: Yes */

/* Copies the tetromino blocks to their respective coordinates to the play area */
void copyTetrominotoArena(Tetromino *t, Play_area *p); /*Tested: Yes */

/* Clears the tetromino blocks at their respective coordinates to the play area */
void clearTetrominoArena(Tetromino *t, Play_area *p); /*Tested: Yes */

/* Sets the tetromino coordinates as occupied and no longer tetromino pieces.
    This does not clear the internal tetromino coordinates */
void placeTetromino(Tetromino *t, Play_area *p); /*Tested: Yes */

/* Clears the current tetromino location, shifts down if valid, then copies back to the arena */
int shiftTetrominoDown(Tetromino *t, Play_area *p);

/* Clears the current tetromino location, shifts left if valid, then copies back to the arena */
int shiftTetrominoLeft(Tetromino *t, Play_area *p);

/* Clears the current tetromino location, shifts right if valid, then copies back to the arena */
int shiftTetrominoRight(Tetromino *t, Play_area *p);

/* Initializes the spawn coordinates for tetromino passed in to the char type */
void initializeTetrominoSpawn(Tetromino *t, char type); /*Tested: Yes */

/* Sets up the spawn coordinates of a T-shape tetromino */
void initializeTetrominoTshape(Tetromino *t); /*Tested: Yes */

/* Sets up the spawn coordinates of a L-shape tetromino */
void initializeTetrominoLshape(Tetromino *t); /*Tested: Yes */

/* Sets up the spawn coordinates of a J-shape tetromino */
void initializeTetrominoJshape(Tetromino *t); /*Tested: Yes */

/* Sets up the spawn coordinates of a S-shape tetromino */
void initializeTetrominoSshape(Tetromino *t); /*Tested: Yes */

/* Sets up the spawn coordinates of a Z-shape tetromino */
void initializeTetrominoZshape(Tetromino *t); /*Tested: Yes */

/* Sets up the spawn coordinates of a I-shape tetromino */
void initializeTetrominoIshape(Tetromino *t); /*Tested: Yes */

/* Sets up the spawn coordinates of a O-shape tetromino */
void initializeTetrominoOshape(Tetromino *t); /*Tested: Yes */

/* Checks if the coordinates entered are occupied by a placed piece or empty */
int movementValidityChecker(Play_area *p, int arenaX, int arenaY); /*Tested: Yes */

/* Rotates a tetromino on it's origin point clockwise 
90 degrees if the desination coordinates are valid */
int rotateTetrominoCWise(Tetromino *t, Play_area *p); /*Tested: Yes */

/* Rotates a tetromino on it's origin point counterclockwise 
90 degrees if the desination coordinates are valid */
int rotateTetrominoCCWise(Tetromino *t, Play_area *p); /*Tested: Yes */


/********** PLAY AREA FUNCTIONS **********/

/* Initializes each block in the arena with matrix coords, 
screen coords, default empty block values, and it's sizing */
void initPlayArea(Play_area *p); /*Tested: Yes */


/********** SCORE FUNCTIONS **********/

/* Initializes the score display to the default screen coordinates with default values */
void initScoreDisplay(Score_display *sd); /*Tested: Yes */

/* Initializes the top score label to the default screen coordinates with default value "TOP SCORE" */
void initTopScoreLabel(Top_score_label *tsl); /*Tested: Yes */

/* Initializes the current score label to the default screen coordinates with default value "SCORE" */
void initCurrentScoreLabel(Current_score_label *csl); /*Tested: Yes */

/* Initializes the level label to the default screen coordinates with default value "LEVEL" */
void initLevelLabel(Level_label *lvlL); /*Tested: Yes */

/* Initializes the top score string value to the screen coordinates and starting value "000000" */
void initTopScoreString(Top_score_string *tss); /*Tested: Yes */

/* Initializes the current score string value to the screen coordinates and starting value "000000" */
void initCurrentScoreString(Current_score_string *css); /*Tested: Yes */

/* Initializes the current score string value to the screen coordinates and starting value "00" */
void initLevelString(Level_string *lvlN); /*Tested: Yes */

/* Sets the char string value to be the same value as the integer value */
void scoreToString(unsigned long score, char score_string[]); /*Tested: Yes */

/* Sets the char string value to be the same value as the integer value */
void levelToString(unsigned long level, char level_string[]); /*Tested: Yes */

/* Sets all score display numeric string values to their current value in the Score display object */
void updateAllScoreDisplayNum(Score_display *sd, Top_score_string *tss, Current_score_string *css, Level_string *lvlS);


/********** NEXT TETROMINO DISPLAY FUNCTIONS **********/
/* Initializes the next tetromino display coordinates and block offset values */
void initNextTetromDisplay(Next_tetrom_display *ntd);


#endif
