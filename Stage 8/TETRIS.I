# 1 "tetris.c" 1
# 1 "C:/c68/include/stdlib.h" 1
# 1 "C:/c68/include/compiler.h" 1
# 9 "C:/c68/include/stdlib.h" 2
# 18 "C:/c68/include/stdlib.h"
typedef unsigned long  size_t;




typedef char  wchar_t;
# 44 "C:/c68/include/stdlib.h"
typedef struct {
    int		quot;
    int		rem;
} div_t;

typedef struct {
    long	quot;
    long	rem;
} ldiv_t;

 double atof (const char *s) ;
 int atoi (const char *str) ;
 long atol (const char *str) ;
 long int strtol (const char *nptr, char **endptr, int base) ;
 unsigned long int strtoul (const char *nptr, char **endptr, int base) ;
 double strtod (const char *s, char **endptr) ;

 void srand (unsigned int seed) ;
 int rand (void) ;

 void *malloc (size_t n) ;
 void free (void *param) ;
 void *realloc (void *_r, size_t n) ;
 void *calloc (size_t n, size_t sz) ;





 void *alloca (size_t) ;
# 89 "C:/c68/include/stdlib.h"
 void  abort (void) ;


 int atexit (void (*)(void)) ;

 void  exit (int) ;

 char *getenv (const char *tag) ;
 int system (const char *s) ;

 void *bsearch (const void *key, const void *base, size_t num, size_t size, int (*cmp )(const void *, const void *)) ;
 void qsort (void *base, size_t total_elems, size_t size, int (*cmp )(const void *, const void *)) ;

 int abs (int x) ;
 long labs (long x) ;

 div_t div (int num, int denom) ;
 ldiv_t ldiv (long num, long denom) ;

 int mblen (const char *, size_t) ;
 size_t mbstowcs (wchar_t *, const char *, size_t) ;
 int mbtowc (wchar_t *, const char *, size_t) ;
 size_t wcstombs (char *, const wchar_t *, size_t) ;
 int wctomb (char *, wchar_t) ;

 wchar_t *wcscat (wchar_t *, const wchar_t *) ;
 int wcscmp (const wchar_t *, const wchar_t *) ;
 wchar_t *wcscpy (wchar_t *, const wchar_t *) ;
 size_t wcslen (const wchar_t *) ;
 wchar_t *wcsncat (wchar_t *, const wchar_t *, size_t) ;
 int wcsncmp (const wchar_t *, const wchar_t *, size_t) ;
 wchar_t *wcsncpy (wchar_t *, const wchar_t *, size_t) ;
# 1 "tetris.c" 2
# 1 "C:/c68/include/stdio.h" 1
# 69 "C:/c68/include/stdio.h"
typedef	struct
	{
	long		_cnt;
	unsigned char	*_ptr;
	unsigned char	*_base;
	unsigned int	_flag;
	int		_file;
	long		_bsiz;
	unsigned char	_ch;
	}
	FILE;


typedef unsigned long fpos_t;
# 92 "C:/c68/include/stdio.h"
extern	FILE	_iob[];
# 108 "C:/c68/include/stdio.h"
 char *	ctermid	(char *) ;




 int	remove	(const char *) ;
 int	rename	(const char *, const char *) ;
 char *	tmpnam	(char *) ;
 FILE *	tmpfile	(void) ;

 int	fclose	(FILE *) ;
 int	fflush	(FILE *) ;

 FILE *	fopen	(const char *, const char *) ;
 FILE *	freopen	(const char *, const char *, FILE *) ;

 void	setbuf	(FILE *, char *) ;
 int	setvbuf	(FILE *, char *, int, size_t) ;
# 132 "C:/c68/include/stdio.h"
 int  fscanf  (FILE *, const char *, ...) ;
 int  scanf   (const char *, ...) ;
 int  sscanf  (const char *, const char *, ...) ;


 int	fprintf	(FILE *, const char *, ...) ;
 int	printf	(const char *, ...) ;
 int	sprintf	(char *, const char *, ...) ;

 int 	vfprintf (FILE *, const char *, char * ) ;
 int 	vprintf	 (const char *, char * ) ;
 int 	vsprintf (char *, const char *, char * ) ;

 int	vscanf  (const char *, char * ) ;
 int	vfscanf (FILE *, const char *, char * ) ;
 int	vsscanf	(const char *, const char *, char * ) ;


 int	fgetc	(FILE *) ;
 char	*fgets	(char *, int, FILE *) ;
 char	*gets	(char *) ;
 int	fputc	(int c, FILE *) ;
 int	fputs	(const char *, FILE *) ;
 int	puts	(const char *) ;

 size_t	fread	(void *, size_t, size_t, FILE *) ;
 size_t	fwrite	(const void *, size_t, size_t, FILE *) ;

 int	fgetpos	(FILE *, fpos_t *) ;
 int	fsetpos	(FILE *, fpos_t *) ;

 int	fseek	(FILE *, long, int) ;
 long	ftell	(FILE *) ;
 void	rewind	(FILE *) ;

 void	perror	(const char *) ;


 FILE	*fdopen	(int, const char *) ;


 FILE *	fopenp	(const char *, const char *) ;
 int 	fungetc	(int, FILE *) ;
 int	pclose	(FILE *) ;
 FILE *	popen	(const char *, const char *) ;
 void	setlinebuf	(FILE *) ;

 void	_binmode	(int) ;
 long 	getl	(FILE *) ;
 long 	putl	(long, FILE *) ;
 short 	getw	(FILE *) ;
 short 	putw	(short, FILE *) ;
 void	_getbuf	(FILE *fp) ;
# 192 "C:/c68/include/stdio.h"
 int	_filbuf	(FILE *) ;
# 2 "tetris.c" 2
# 1 "C:/c68/include/osbind.h" 1
# 1 "C:/c68/include/ostruct.h" 1
# 22 "C:/c68/include/ostruct.h"
typedef struct {
    long b_free;
    long b_total;
    long b_secsiz;
    long b_clsiz;
} _DISKINFO;


typedef struct {
  short time;
  short date;
} _DOSTIME;


typedef struct
{
        unsigned char maxlen;
        unsigned char actuallen;
        char    buffer[255];
} _CCONLINE;
# 48 "C:/c68/include/ostruct.h"
typedef struct _dta {
    char 	    dta_buf[21];
    char            dta_attribute;
    unsigned short  dta_time;
    unsigned short  dta_date;
    long            dta_size;
    char            dta_name[14];
} _DTA;
# 98 "C:/c68/include/ostruct.h"
typedef struct {
  short recsiz;
  short clsiz;
  short clsizb;
  short rdlen;
  short fsiz;
  short fatrec;
  short datrec;
  short numcl;
  short bflags;
} _BPB;




typedef struct _md {
    struct _md	*md_next;
    long	 md_start;
    long	 md_length;
    long	 md_owner;
} _MD;


typedef struct {
    _MD *mp_free;
    _MD *mp_used;
    _MD *mp_rover;
} _MPB;
# 141 "C:/c68/include/ostruct.h"
typedef struct {
    char    *ibuf;
    short   ibufsiz;
    volatile short   ibufhd;
    volatile short   ibuftl;
    short   ibuflow;
    short   ibufhi;
} _IOREC;


typedef struct {
	char	topmode;
	char	buttons;
	char	xparam;
	char	yparam;
	short	xmax;
	short	ymax;
	short	xstart;
	short	ystart;
} _PARAM;


typedef struct {
    void    (*midivec)	(void) ;
    void    (*vkbderr)	(void) ;
    void    (*vmiderr)	(void) ;
    void    (*statvec)	(void *) ;
    void    (*mousevec)	(void *) ;
    void    (*clockvec)	(void *) ;
    void    (*joyvec)	(void *) ;
    long    (*midisys)	(void) ;
    long    (*ikbdsys)	(void) ;
    char    kbstate;
} _KBDVECS;


typedef struct {
    void *unshift;
    void *shift;
    void *caps;
} _KEYTAB;


typedef struct
{
        void    *pb_scrptr;
        int     pb_offset;
        int     pb_width;
        int     pb_height;
        int     pb_left;
        int     pb_right;
        int     pb_screz;
        int     pb_prrez;
        void    *pb_colptr;
        int     pb_prtype;
        int     pb_prport;
        void    *pb_mask;
} _PBDEF;
# 17 "C:/c68/include/osbind.h" 2
# 33 "C:/c68/include/osbind.h"
 long _trap_1_w		(short) ;
 long _trap_1_ww	(short,short) ;
 long _trap_1_wl	(short,long) ;
 long _trap_1_wlw	(short,long,short) ;
 long _trap_1_wwll	(short,short,long,long) ;
 long _trap_1_wlww	(short,long,short,short) ;
 long _trap_1_www	(short,short,short) ;
 long _trap_1_wll	(short,long,long) ;
 long _trap_1_wwlll	(short,short,long,long,long) ;
 long _trap_1_wwwll	(short,short,short,long,long) ;
 long _trap_13_wl	(short,long) ;
 long _trap_13_w	(short) ;
 long _trap_13_ww	(short,short) ;
 long _trap_13_www	(short,short,short) ;
 long _trap_13_wwlwww	(short,short,long,short,short,short) ;
 long _trap_13_wwl	(short,short,long) ;
 long _trap_14_wwl	(short,short,long) ;
 long _trap_14_wwll	(short,short,long,long) ;
 long _trap_14_ww	(short,short) ;
 long _trap_14_w	(short) ;
 long _trap_14_wllw	(short,long,long,short) ;
 long _trap_14_wl	(short,long) ;
 long _trap_14_www	(short,short,short) ;
 long _trap_14_wllwwwww (short,long,long,short,short,short,short,short) ;
 long _trap_14_wllwwwwlw (short,long,long,short,short,short,short,long,short) ;
 long _trap_14_wllwwwwwlw (short,long,long,short,short,short,short,short,long,short) ;
 long _trap_14_wwwwwww	(short,short,short,short,short,short,short) ;
 long _trap_14_wlll	(short,long,long,long) ;
 long _trap_14_wllww	(short,long,long,short,short) ;
 long _trap_14_wwwwl	(short,short,short,short,long) ;
 long _trap_14_wwwl	(short,short,short,long) ;
 long _trap_14_wlwlw	(short,long,short,long,short) ;
# 103 "C:/c68/include/osbind.h"
 long _trap_1_ 	(short,...) ;
 long _trap_14_ 	(short,...) ;
 long _trap_13_ 	(short,...) ;
# 3 "tetris.c" 2
# 1 "./tetris.h" 1
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
# 4 "./tetris.h" 2


unsigned long get_time();
long time_difference();
void alignMemory(unsigned char **memory);
# 4 "tetris.c" 2
# 1 "./model.h" 1
# 5 "tetris.c" 2
# 1 "./raster.h" 1
# 1 "./types.h" 1
# 57 "./types.h"
typedef unsigned char UINT8;
typedef unsigned int  UINT16;
typedef unsigned long UINT32;
# 14 "./raster.h" 2


extern  void set_vid_base(UINT16 *);
# 33 "./raster.h"
void plot_pixel8_RShift(UINT8 *base, int x, int y);
# 51 "./raster.h"
void plot_pixel8_LShift(UINT8 *base, int x, int y);
# 80 "./raster.h"
void plot_bitmap8(UINT8 *base,
                    int x, int y,
                    const UINT8 *bitmap);
# 108 "./raster.h"
void clear_bitmap8(UINT8 *base,
                    int x, int y,
                    const UINT8 *bitmap);
# 133 "./raster.h"
void clear_region8(UINT8 *base,
                    int x, int y);
# 160 "./raster.h"
void plot_bitmap16(UINT16 *base,
                    int x, int y,
                    const UINT16 *bitmap);
# 188 "./raster.h"
void clear_bitmap16(UINT16 *base,
                    int x, int y,
                    const UINT16 *bitmap);
# 213 "./raster.h"
void clear_region16(UINT16 *base,
                    int x, int y);
# 239 "./raster.h"
void plot_vline(UINT8 *base, int x, int y1, int y2);
# 264 "./raster.h"
void plot_hline(UINT8 *base, int x1, int x2, int y);
# 287 "./raster.h"
void plot_square(UINT8 *base, int x, int y, int size);
# 311 "./raster.h"
void plot_rectangle(UINT8 *base, int x, int y, int width, int height);
# 320 "./raster.h"
UINT16* getVideoBase();

void setVideoBase(UINT16 * base);
# 6 "tetris.c" 2
# 1 "./render.h" 1
# 1 "./model.h" 1
# 14 "./render.h" 2
# 1 "./raster.h" 1
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
# 7 "tetris.c" 2
# 1 "./font.h" 1



extern const unsigned char font[];
# 8 "tetris.c" 2
# 1 "./assets.h" 1
# 9 "tetris.c" 2
# 1 "./events.h" 1
# 1 "./model.h" 1
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
# 10 "tetris.c" 2
# 1 "./input.h" 1



int isKeyPressed();
char getKey();
# 11 "tetris.c" 2


unsigned long *timer = (long *)0x462, timeNow, timeThen, timeDifference;

extern void clear_screen(UINT8 *);
# 24 "tetris.c"
UINT8 bufferAlloc[32256];

int main() {
    int i;
    char input;
    void *base = (void *)getVideoBase();
    UINT8 *buffer = bufferAlloc;
    UINT8 *currentScreen = base;
    Game_Model model;

    srand((unsigned int) buffer);
    alignMemory(&buffer);

    initializeAllEvent(&model);
    spawnTetrominoEvent(&model);
    updateModelEvent(&model);
    renderAllObjects(&model, currentScreen);

    timeThen = get_time();

    while(model.isGameOver == 0 ) {




        if(isKeyPressed()) {


            input = getKey();

            if(input == 0x1B ) {
                model.isGameOver = 1 ;
            }
            else if(input == 0x61 ) {
                model.horizontalShift = -1;
            }
            else if(input == 0x64 ) {
                model.horizontalShift = 1;
            }
            else if(input == 0x73 ) {
                model.verticalShift = 1;
            }
            else if(input == 0x78 ) {
                model.rotate = 1;
            }
            else if(input == 0x7A ) {
                model.rotate = -1;
            }
        }

        timeNow = get_time();




        if(time_difference() > 0) {

            if(currentScreen == base)
                currentScreen = buffer;
            else
                currentScreen = base;

            updateModelEvent(&model);
            clear_screen(currentScreen);
            renderAllObjects(&model, currentScreen);
            setVideoBase((UINT16 *)currentScreen);


            timeThen = get_time();
        }
    }

    (void)_trap_14_wllw((short)0x5,(long)(-1),(long)base,(short)(-1)) ;
    printf("*** GAME OVER ***\n");
    return 0;
}


unsigned long get_time() {
    unsigned long time, old_ssp;
    old_ssp = _trap_1_wl((short)0x20,(long)(0)) ;
    time = *timer;
    _trap_1_wl((short)0x20,(long)(old_ssp)) ;
    return time;
}


long time_difference() {
    return (timeNow - timeThen);
}


void alignMemory(UINT8 **memory) {
    if(((UINT8)(*memory) & 0xFF) !=0) {
        *memory += (UINT8)(256 - ((UINT8)(*memory) & 0xFF));
    }
}
