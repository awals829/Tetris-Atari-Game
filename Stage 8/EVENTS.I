# 1 "events.c" 1
# 1 "./events.h" 1
# 1 "./model.h" 1
# 209 "./model.h"
typedef struct block{

    int arenaX, arenaY;

    int screenX, screenY;

    int is_occupied, is_tetromino_piece;

} Block;
# 225 "./model.h"
typedef struct tetromino {

    unsigned char tetromino_type;
# 235 "./model.h"
    Block blocks[4 ];

} Tetromino;
# 246 "./model.h"
typedef struct play_area {

    int screenX, screenY;

    int width, height;


    int gravity;

    char is_full;

    Block arena[10 ][20 ];

} Play_area;
# 268 "./model.h"
typedef struct score_display {

    int screenX, screenY;

    int width, height;

    unsigned long top_score;

    unsigned long current_score;

    int level;

} Score_display;
# 289 "./model.h"
typedef struct next_tetrom_display {

    int screenX, screenY;

    int width, height;

    char next_label_string[5];

    Block grid[8][5];

} Next_tetrom_display;
# 307 "./model.h"
typedef struct top_score_label {

    int screenX, screenY;

    char top_score_label_string[10];

    int string_length;

} Top_score_label;
# 323 "./model.h"
typedef struct top_score_string {

    int screenX, screenY;

    char top_score_num_string[7];

    int string_length;

} Top_score_string;
# 339 "./model.h"
typedef struct current_score_label {

    int screenX, screenY;

    char current_score_label_string[6];

    int string_length;

} Current_score_label;
# 355 "./model.h"
typedef struct current_score_string {

    int screenX, screenY;

    char current_score_num_string[7];

    int string_length;

} Current_score_string;
# 371 "./model.h"
typedef struct level_label {

    int screenX, screenY;

    char level_label_string[6];

    int string_length;

} Level_label;
# 387 "./model.h"
typedef struct level_string {

    int screenX, screenY;




    char level_num_string[3];

    int string_length;

} Level_string;
# 405 "./model.h"
typedef struct game_model {
    Tetromino t;
    Tetromino next;
    Tetromino temp;
    Play_area p;
    Score_display sd;
    Top_score_label tsl;
    Top_score_string tss;
    Current_score_label csl;
    Current_score_string css;
    Level_label lvlL;
    Level_string lvlS;
    Next_tetrom_display ntd;
    int totalClearedLinesCounter;
    int scoreIncrementCounter;
    int isGameOver;
    int horizontalShift;
    int verticalShift;
    int rotate;
    int gameTime;

} Game_Model;
# 441 "./model.h"
void copyTetromino(Tetromino *from, Tetromino *to);

void initModelValues(Game_Model *model);
# 451 "./model.h"
int arenaX_to_screenX(Block b);


int arenaY_to_screenY(Block b);


int screenX_to_arenaX(Block b);


int screenY_to_arenaY(Block b);
# 468 "./model.h"
void initBlock(Block *b, int arenaX, int arenaY);


int isArenaXViable(int arenaX);


int isArenaYViable(int arenaY);


int isPositionOccupied(Play_area *play_area, int arenaX, int arenaY);


int isPositionTetromino(Play_area *play_area, int arenaX, int arenaY);
# 489 "./model.h"
char randomize(Tetromino *t);


void clearTetrominoValues(Tetromino *t);


void copyTetrominotoToPlayArea(Tetromino *t, Play_area *p);


void clearTetrominoFromPlayArea(Tetromino *t, Play_area *p);


void placeTetromino(Tetromino *t, Play_area *p);


int shiftTetrominoDown(Tetromino *t, Play_area *p);


int shiftTetrominoLeft(Tetromino *t, Play_area *p);


int shiftTetrominoRight(Tetromino *t, Play_area *p);


int rotateTetrominoCWise(Tetromino *t, Play_area *p);


int rotateTetrominoCCWise(Tetromino *t, Play_area *p);


void shift(Tetromino *t, int nextX, int nextY, int i);


void initializeAllTetrominoSpawn(Tetromino *t, char type);


void initializeTetrominoTshape(Tetromino *t);


void initializeTetrominoLshape(Tetromino *t);


void initializeTetrominoJshape(Tetromino *t);


void initializeTetrominoSshape(Tetromino *t);


void initializeTetrominoZshape(Tetromino *t);


void initializeTetrominoIshape(Tetromino *t);


void initializeTetrominoOshape(Tetromino *t);


int movementValidityChecker(Play_area *p, int arenaX, int arenaY);
# 555 "./model.h"
void initPlayArea(Game_Model *model);


int isRowFull(Game_Model *model, int yRow);


void clearRow(Game_Model *model, int yRow);
# 569 "./model.h"
void initScoreDisplay(Game_Model *model);


void initTopScoreLabel(Game_Model *model);


void initCurrentScoreLabel(Game_Model *model);


void initLevelLabel(Game_Model *model);


void initTopScoreString(Game_Model *model);


void initCurrentScoreString(Game_Model *model);


void initLevelString(Game_Model *model);





void setScoresAndLevel(Game_Model *model);
# 600 "./model.h"
void incrementScore(Game_Model *model);


void setTopScore(Game_Model *model, unsigned long top_score);


void incrementLevel(Game_Model *model);


void updateTopScore(Game_Model *model);


void scoreToString(unsigned long score, char score_string[]);


void levelToString(unsigned long level, char level_string[]);
# 623 "./model.h"
void initNextTetromDisplay(Game_Model *model);
# 16 "./events.h" 2
# 29 "./events.h"
void initializeAllEvent(Game_Model *model);
# 40 "./events.h"
int quit();
# 57 "./events.h"
int spawnTetrominoEvent(Game_Model *model);


void setNewTetrominoEvent(Game_Model *model);


void setNextTetrominoEvent(Game_Model *model);


void placeTetrominoEvent(Game_Model *model);
# 79 "./events.h"
int shiftTetrominoDownEvent(Game_Model *model);
# 91 "./events.h"
int shiftTetrominoLeftEvent(Game_Model *model);
# 103 "./events.h"
int shiftTetrominoRightEvent(Game_Model *model);
# 119 "./events.h"
int rotateTetrominoCWiseEvent(Game_Model *model);
# 135 "./events.h"
int rotateTetrominoCCWiseEvent(Game_Model *model);
# 142 "./events.h"
void clearLinesEvent(Game_Model *model);

void dropLinesEvent(Game_Model *model, int row);

void speedIncreaseEvent(Game_Model *model);
# 153 "./events.h"
void incrementScoreEvent(Game_Model *model);


void incrementLevelEvent(Game_Model *model);
# 163 "./events.h"
void updateModelEvent(Game_Model *model);
# 13 "events.c" 2
# 34 "events.c"
void initializeAllEvent(Game_Model *model) {
    initModelValues(model);
    setNextTetrominoEvent(model);
    setNewTetrominoEvent(model);
    initPlayArea(model);
    initScoreDisplay(model);
    initNextTetromDisplay(model);
    initTopScoreLabel(model);
    initCurrentScoreLabel(model);
    initTopScoreString(model);
    initCurrentScoreString(model);
    initLevelLabel(model);
    initLevelString(model);
    setScoresAndLevel(model);
}
# 66 "events.c"
int spawnTetrominoEvent(Game_Model *model) {
    int spawned = 1 ;
    int i;
    for(i = 0; i < 4 ; i++) {
        if(!movementValidityChecker(&model->p, model->t.blocks[i].arenaX, model->t.blocks[i].arenaY)) {
            spawned = 0 ;
            break;
        }
    }
    if(spawned) {
        copyTetrominotoToPlayArea(&model->t, &model->p);
    }
    return spawned;
}
# 91 "events.c"
void setNewTetrominoEvent(Game_Model *model) {
    copyTetromino(&model->next, &model->temp);
    setNextTetrominoEvent(model);
    copyTetromino(&model->temp, &model->t);
    initializeAllTetrominoSpawn(&model->t, model->t.tetromino_type);
}


void setNextTetrominoEvent(Game_Model *model) {
    model->next.tetromino_type = randomize(&model->t);
    initializeAllTetrominoSpawn(&model->next, model->next.tetromino_type);
}


void placeTetrominoEvent(Game_Model *model) {
    placeTetromino(&model->t, &model->p);
}
# 123 "events.c"
int shiftTetrominoDownEvent(Game_Model *model) {
    int isShifted;
    clearTetrominoFromPlayArea(&model->t, &model->p);
    isShifted = shiftTetrominoDown(&model->t, &model->p);
    copyTetrominotoToPlayArea(&model->t, &model->p);
    return isShifted;
}
# 143 "events.c"
int shiftTetrominoLeftEvent(Game_Model *model) {
    int isShifted;
    clearTetrominoFromPlayArea(&model->t, &model->p);
    isShifted = shiftTetrominoLeft(&model->t, &model->p);
    copyTetrominotoToPlayArea(&model->t, &model->p);
    return isShifted;
}
# 163 "events.c"
int shiftTetrominoRightEvent(Game_Model *model) {
    int isShifted;
    clearTetrominoFromPlayArea(&model->t, &model->p);
    isShifted = shiftTetrominoRight(&model->t, &model->p);
    copyTetrominotoToPlayArea(&model->t, &model->p);
    return isShifted;
}
# 184 "events.c"
int rotateTetrominoCWiseEvent(Game_Model *model) {
    int rotatedEvent;
    if(model->t.tetromino_type != 'O') {
        clearTetrominoFromPlayArea(&model->t, &model->p);
        rotatedEvent = rotateTetrominoCWise(&model->t, &model->p);
        copyTetrominotoToPlayArea(&model->t, &model->p);
    }
    return rotatedEvent;
}
# 207 "events.c"
int rotateTetrominoCCWiseEvent(Game_Model *model) {
    int rotatedEvent;
    if(model->t.tetromino_type != 'O') {
        clearTetrominoFromPlayArea(&model->t, &model->p);
        rotatedEvent = rotateTetrominoCCWise(&model->t, &model->p);
        copyTetrominotoToPlayArea(&model->t, &model->p);
    }
    return rotatedEvent;
}
# 222 "events.c"
void clearLinesEvent(Game_Model *model) {
    int x, y, count = 0;
    for(y = (20  - 1) ; y >= 0 ; y--) {
        if(isRowFull(model, y)) {
            model->totalClearedLinesCounter++;
            clearRow(model, y);
            incrementScore(model);
            y++;
        }
    }
    updateTopScore(model);
    incrementLevelEvent(model);
    setScoresAndLevel(model);

}

void speedIncreaseEvent(Game_Model *model) {
    if(model->p.gravity > (14  - 10)) {
        model->p.gravity--;
    }
}
# 249 "events.c"
void incrementLevelEvent(Game_Model *model) {
    if(model->totalClearedLinesCounter >= 1 ) {

        model->totalClearedLinesCounter = 0;
        incrementLevel(model);
        speedIncreaseEvent(model);
    }
}
# 263 "events.c"
void updateModelEvent(Game_Model *model) {
    int spawned;
    model->gameTime++;

    if(model->verticalShift == 1) {
        if(!shiftTetrominoDownEvent(model)) {
            placeTetrominoEvent(model);
            setNewTetrominoEvent(model);
            clearLinesEvent(model);
            spawned = spawnTetrominoEvent(model);
        }
        model->verticalShift = 0;
        model->gameTime = 0;
    } else if(model->horizontalShift == -1) {
        shiftTetrominoLeftEvent(model);
        model->horizontalShift = 0;
    } else if(model->horizontalShift == 1) {
        shiftTetrominoRightEvent(model);
        model->horizontalShift = 0;
    } else if(model->rotate == -1) {
        rotateTetrominoCCWiseEvent(model);
        model->rotate = 0;
    } else if(model->rotate == 1) {
        rotateTetrominoCWiseEvent(model);
        model->rotate = 0;
    }


    if(model->gameTime >= model->p.gravity) {
        if(!shiftTetrominoDownEvent(model)) {
            placeTetrominoEvent(model);
            setNewTetrominoEvent(model);
            clearLinesEvent(model);
            spawned = spawnTetrominoEvent(model);
        }
        model->verticalShift = 0;
        model->gameTime = 0;
    }
    if(!spawned) {
        model->isGameOver = 1 ;
    }
}
