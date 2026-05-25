# 1 "render.c" 1
# 1 "./render.h" 1
# 1 "./model.h" 1
# 195 "./model.h"
typedef struct block{

    int arenaX, arenaY;

    int screenX, screenY;

    unsigned char is_occupied, is_tetromino_piece;

} Block;
# 211 "./model.h"
typedef struct tetromino {

    unsigned char tetromino_type;
# 221 "./model.h"
    Block blocks[4 ];

} Tetromino;
# 232 "./model.h"
typedef struct play_area {

    int screenX, screenY;

    int width, height;


    int gravity;

    char is_full;

    Block arena[10 ][20 ];

} Play_area;
# 254 "./model.h"
typedef struct score_display {

    int screenX, screenY;

    int width, height;

    unsigned long top_score;

    unsigned long current_score;

    int level;

} Score_display;
# 274 "./model.h"
typedef struct next_tetrom_display {

    int screenX, screenY;

    int width, height;

    char next_label_string[5];

    Block grid[8][5];

} Next_tetrom_display;
# 292 "./model.h"
typedef struct top_score_label {

    int screenX, screenY;

    char top_score_label_string[10];

    int string_length;

} Top_score_label;
# 308 "./model.h"
typedef struct top_score_string {

    int screenX, screenY;

    char top_score_num_string[7];

    int string_length;

} Top_score_string;
# 324 "./model.h"
typedef struct current_score_label {

    int screenX, screenY;

    char current_score_label_string[6];

    int string_length;

} Current_score_label;
# 340 "./model.h"
typedef struct current_score_string {

    int screenX, screenY;

    char current_score_num_string[7];

    int string_length;

} Current_score_string;
# 356 "./model.h"
typedef struct level_label {

    int screenX, screenY;

    char level_label_string[6];

    int string_length;

} Level_label;
# 372 "./model.h"
typedef struct level_string {

    int screenX, screenY;




    char level_num_string[3];

    int string_length;

} Level_string;
# 390 "./model.h"
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
# 425 "./model.h"
void copyTetromino(Tetromino *from, Tetromino *to);

void initModelValues(Game_Model *model, int seed);
# 435 "./model.h"
int arenaX_to_screenX(Block b);


int arenaY_to_screenY(Block b);


int screenX_to_arenaX(Block b);


int screenY_to_arenaY(Block b);
# 452 "./model.h"
void initBlock(Block *b, int arenaX, int arenaY);


int isArenaXViable(int arenaX);


int isArenaYViable(int arenaY);


int isPositionOccupied(Play_area *play_area, int arenaX, int arenaY);


int isPositionTetromino(Play_area *play_area, int arenaX, int arenaY);
# 473 "./model.h"
char randomize(Tetromino *t, int seed);


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
# 539 "./model.h"
void initPlayArea(Game_Model *model);


int isRowFull(Game_Model *model, int yRow);


void clearRow(Game_Model *model, int yRow);
# 553 "./model.h"
void initScoreDisplay(Game_Model *model);


void initTopScoreLabel(Game_Model *model);


void initCurrentScoreLabel(Game_Model *model);


void initLevelLabel(Game_Model *model);


void initTopScoreString(Game_Model *model);


void initCurrentScoreString(Game_Model *model);


void initLevelString(Game_Model *model);





void setScoresAndLevel(Game_Model *model);
# 584 "./model.h"
void incrementScore(Game_Model *model);

void setTopScore(Game_Model *model, unsigned long top_score);


void incrementLevel(Game_Model *model);


void updateTopScore(Game_Model *model);



void scoreToString(unsigned long score, char score_string[]);


void levelToString(unsigned long level, char level_string[]);
# 607 "./model.h"
void initNextTetromDisplay(Game_Model *model);
# 14 "./render.h" 2
# 1 "./raster.h" 1
# 1 "./types.h" 1
# 57 "./types.h"
typedef unsigned char UINT8;
typedef unsigned int  UINT16;
typedef unsigned long UINT32;
# 14 "./raster.h" 2
# 31 "./raster.h"
void plot_pixel8_RShift(UINT8 *base, int x, int y);
# 49 "./raster.h"
void plot_pixel8_LShift(UINT8 *base, int x, int y);
# 78 "./raster.h"
void plot_bitmap8(UINT8 *base,
                    int x, int y,
                    const UINT8 *bitmap);
# 106 "./raster.h"
void clear_bitmap8(UINT8 *base,
                    int x, int y,
                    const UINT8 *bitmap);
# 131 "./raster.h"
void clear_region8(UINT8 *base,
                    int x, int y);
# 158 "./raster.h"
void plot_bitmap16(UINT16 *base,
                    int x, int y,
                    const UINT16 *bitmap);
# 186 "./raster.h"
void clear_bitmap16(UINT16 *base,
                    int x, int y,
                    const UINT16 *bitmap);
# 211 "./raster.h"
void clear_region16(UINT16 *base,
                    int x, int y);
# 237 "./raster.h"
void plot_vline(UINT8 *base, int x, int y1, int y2);
# 262 "./raster.h"
void plot_hline(UINT8 *base, int x1, int x2, int y);
# 285 "./raster.h"
void plot_square(UINT8 *base, int x, int y, int size);
# 309 "./raster.h"
void plot_rectangle(UINT8 *base, int x, int y, int width, int height);
# 15 "./render.h" 2
# 1 "./assets.h" 1




extern unsigned int block_bitmap[];
# 16 "./render.h" 2
# 30 "./render.h"
void renderAllObjects(const Game_Model *model, void *base);
# 43 "./render.h"
void renderTetromino(const Tetromino *t, Play_area *p, UINT16 *base);
# 56 "./render.h"
void clearTetrominoRender(const Tetromino *t, Play_area *p, UINT16 *base);
# 69 "./render.h"
void renderPlayArea(const Game_Model *model, UINT8 *base);
# 82 "./render.h"
void renderNextTetrominoArea(const Game_Model *model, UINT8 *base);
# 96 "./render.h"
void renderBlocks(const Game_Model *model, UINT16 *base);
# 109 "./render.h"
void renderScoreDisplay(const Game_Model *model, UINT8 *base);
# 122 "./render.h"
void renderTopScoreLabel(const Game_Model *model,  UINT8 *base);
# 135 "./render.h"
void renderTopScoreNumString(const Game_Model *model,  UINT8 *base);
# 148 "./render.h"
void renderCurrentScoreLabel(const Game_Model *model,  UINT8 *base);
# 161 "./render.h"
void renderCurrentScoreNumString(const Game_Model *model,  UINT8 *base);
# 174 "./render.h"
void renderLevelLabel(const Game_Model *model,  UINT8 *base);
# 187 "./render.h"
void renderLevelNumString(const Game_Model *model,  UINT8* base);
# 201 "./render.h"
void renderScoreDisplayValues(const Game_Model *model, UINT8 *base);
# 214 "./render.h"
void renderAllObjects(const Game_Model *model, void *base);
# 11 "render.c" 2
# 1 "./assets.h" 1
# 12 "render.c" 2
# 1 "./model.h" 1
# 13 "render.c" 2
# 1 "./raster.h" 1
# 14 "render.c" 2
# 1 "./font.h" 1



extern const unsigned char font[];
# 15 "render.c" 2
# 33 "render.c"
void renderAllObjects(const Game_Model *model, void *base) {
    renderPlayArea(model, (UINT8 *) base);
    renderScoreDisplay(model, (UINT8 *) base);
    renderScoreDisplayValues(model, (UINT8 *) base);
    renderNextTetrominoArea(model, (UINT8 *) base);
    renderBlocks(model, (UINT16 *) base);
}
# 55 "render.c"
void renderTetromino(const Tetromino *t, Play_area *p, UINT16 *base) {
    int i;
    for(i = 0; i < 4 ; i++) {
        plot_bitmap16(base, p->arena[t->blocks[i].arenaX]->screenX, p->arena[t->blocks[i].arenaY]->screenY, block_bitmap);
    }
}
# 72 "render.c"
void clearTetrominoRender(const Tetromino *t, Play_area *p, UINT16 *base) {
    int i;
    for(i = 0; i < 4 ; i++) {
        clear_region16(base, p->arena[t->blocks[i].arenaX]->screenX, p->arena[t->blocks[i].arenaY]->screenY);
    }
}
# 93 "render.c"
void renderPlayArea(const Game_Model *model, UINT8 *base) {
    plot_rectangle(base, model->p.screenX, model->p.screenY, model->p.width, model->p.height);
}
# 113 "render.c"
void renderNextTetrominoArea(const Game_Model *model, UINT8 *base) {
    plot_rectangle(base, model->ntd.screenX, model->ntd.screenY, model->ntd.width, model->ntd.height);
}
# 126 "render.c"
void renderBlocks(const Game_Model *model, UINT16 *base) {
    int x, y, isOccupied, isTetromino;
    for(y = 0; y <= (20  - 1) ; y++) {
        for(x = 0; x <= (10  - 1) ; x++) {
            isOccupied = isPositionOccupied(&model->p, x, y);
            isTetromino = isPositionTetromino(&model->p, x, y);
            if (isOccupied || isTetromino) {
                plot_bitmap16(base, model->p.arena[x][y].screenX, model->p.arena[x][y].screenY, block_bitmap);
            } else if (!isOccupied) {
                clear_region16(base, model->p.arena[x][y].screenX, model->p.arena[x][y].screenY);
            }
        }
    }
}
# 155 "render.c"
void renderScoreDisplay(const Game_Model *model, UINT8 *base) {
    plot_rectangle(base, model->sd.screenX, model->sd.screenY, model->sd.width, model->sd.height);
}
# 168 "render.c"
void renderTopScoreLabel(const Game_Model *model,  UINT8 *base) {
    int i, x;
    for(x = model->tsl.screenX, i = 0; model->tsl.top_score_label_string[i] != '\0'; x += 8, i++) {
        clear_region8(base, x, model->tsl.screenY);
        plot_bitmap8(base, x, model->tsl.screenY, (font + (((model->tsl.top_score_label_string[i]) - ' ') << 3)) );
    }
}
# 185 "render.c"
void renderTopScoreNumString(const Game_Model *model,  UINT8 *base) {
    int i, x;
    for(x = model->tss.screenX, i = 0; model->tss.top_score_num_string[i] != '\0'; x += 8, i++) {
        clear_region8(base, x, model->tss.screenY);
        plot_bitmap8(base, x, model->tss.screenY, (font + (((model->tss.top_score_num_string[i]) - ' ') << 3)) );
    }
}
# 202 "render.c"
void renderCurrentScoreLabel(const Game_Model *model,  UINT8 *base) {
    int i, x;
    for(x = model->csl.screenX, i = 0; model->csl.current_score_label_string[i] != '\0'; x += 8, i++) {
        clear_region8(base, x, model->csl.screenY);
        plot_bitmap8(base, x, model->csl.screenY, (font + (((model->csl.current_score_label_string[i]) - ' ') << 3)) );
    }
}
# 219 "render.c"
void renderCurrentScoreNumString(const Game_Model *model,  UINT8 *base) {
    int i, x;
    for(x = model->css.screenX, i = 0; model->css.current_score_num_string[i] != '\0'; x += 8, i++) {
        clear_region8(base, x, model->css.screenY);
        plot_bitmap8(base, x, model->css.screenY, (font + (((model->css.current_score_num_string[i]) - ' ') << 3)) );
    }
}
# 236 "render.c"
void renderLevelLabel(const Game_Model *model,  UINT8 *base) {
    int i, x;
    for(x = model->lvlL.screenX, i = 0; model->lvlL.level_label_string[i] != '\0'; x += 8, i++) {
        clear_region8(base, x, model->lvlL.screenY);
        plot_bitmap8(base, x, model->lvlL.screenY, (font + (((model->lvlL.level_label_string[i]) - ' ') << 3)) );
    }
}
# 253 "render.c"
void renderLevelNumString(const Game_Model *model,  UINT8 *base) {
    int i, x;
    for(x = model->lvlS.screenX, i = 0; model->lvlS.level_num_string[i] != '\0'; x += 8, i++) {
        clear_region8(base, x, model->lvlS.screenY);
        plot_bitmap8(base, x, model->lvlS.screenY, (font + (((model->lvlS.level_num_string[i]) - ' ') << 3)) );
    }
}
# 273 "render.c"
void renderScoreDisplayValues(const Game_Model *model, UINT8 *base) {
    int i, x;
    renderTopScoreLabel(model, base);
    renderTopScoreNumString(model, base);
    renderCurrentScoreLabel(model, base);
    renderCurrentScoreNumString(model, base);
    renderLevelLabel(model, base);
    renderLevelNumString(model, base);
}
