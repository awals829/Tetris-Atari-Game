# TETRIS
## General Game Overview

   The primary goal of Tetris is to maneuver falling Tetromino pieces - each composed of four blocks in various configurations - one at a time to form complete horizontal lines. Completing lines awards points, clears space, and prolongs gameplay. The game increases in speed and complexity as it progresses, demanding quicker strategic thinking and reflexes from the player. Failure occurs when accumulated blocks reach the top of the play area, marking the end of the game. The ultimate aim is to achieve the highest possible score before this happens. The game is set in a digital grid divided into distinct blocks. This grid forms the central stage of the game, with a clear division between the active play area (where blocks accumulate) and the passive play area (space for maneuvering falling blocks). The play area is framed by side, top, and bottom edges, creating a visually clear and contained environment for gameplay. There are seven unique Tetromino shapes, each with a distinct block configuration. The block configurations consist of I-shape, O-shape, T-Shape, S-Shape, Z-Shape, L-Shape, and J-Shape. These shapes are randomly selected, ensuring varied gameplay. Shapes continuously descend from the top center of the play area. Players can move shapes horizontally, rotate them in 90-degree increments, and adjust their falling speed. Movement is restricted to within the grid, and rotations are bound by the play area's spatial constraints. Once a piece collides with the bottom or another placed piece, it locks in place, and a new piece spawns.

# Game Play Details for Core 1-Player Version

## Objectives and Rules

   ### Objective:
  Players must shift and/or rotate Tetromino pieces to strategically position them in order to complete lines and score points.
  Completing a horizontal line, that is a line with no empty spaces, clears it and scores points for the player.
  Achieve the highest score possible before the game is over.
  There is no win condition, the game continues to run until the player either quits, or the game over condition is triggered.
  
   ### Game Over Condition:
  If any placed Tetromino reaches the top of the gameplay area, the game ends for the player.
  
   ### Tetromino Shapes:
  Tetromino pieces consist of four blocks, forming various shapes.
  There are a total of 7 different Tetromino shapes.
  
   ### Movement and Rotation:
  Tetromino pieces can shift left or right horizontally
  Pieces can also rotate in 90-degree increments.
  Movement and rotation are allowed ONLY while the piece is still in play and not placed.
  Rotations will not occur if the Tetromino cannot rotate to that position due to screen bounds or placed pieces interfering with the final rotation shape.
  Movement is discrete in the sense that it is not fluid pixel by pixel, instead it is block by block increments.
  
   ### Spawning and Placement:
  The game starts with a Tetromino piece spawning at the top center of the play area.
  Pieces fall from the top in block-sized increments until placed, after which a new random piece spawns at the same location (For example, if a block is 16x16 pixels, then the falling       increment is 16 pixels).
  A piece is placed when it collides with either the bottom of the gameplay, or another piece that is already placed.
  
   ### Scoring and Levels:
  Starting level is 1, max level is 10.
  Base points for clearing a line are 40.
  Levels increment every 10 cleared lines. These 10 lines do not have to be cleared all at once and are cumulative.
  Levels are scoring multipliers for cleared lines (40 points multiplied by the current level value).
  The rate at which the Tetromino piece falls increases when the level increases.
  Progressing to the next level does not interrupt gameplay, rather, this change is seamless and all pieces currently in play remain in play.
  
   ### Gameplay Mechanics:
  The gameplay area is 10 blocks wide and 20 blocks tall.
  Basic movement is limited to left and right motions, while rotations occur in 90-degree increments.
  The player can implement a ‘soft drop’ which increases the speed the Tetromino piece falls while a specified button is pressed.
  Players can clear multiple lines simultaneously.


## Block Movement and Placement 

  There are seven different Tetronimos, all bound by the same movement and placement rules. Each Tetronimo consists of 4 “blocks”, each measuring about 16x16 pixels. Blocks, forming Tetromino shapes, are generated randomly at the top center of the play area. This randomness ensures a varied and unpredictable gameplay experience. Tetronimos move two dimensionally on the screen, falling continuously downwards until acted upon by the player. The game features a singular drop speed setting, represented by an integer value. This speed dictates the rate at which Tetrominoes descend. Players can accelerate the descent but cannot modify the base speed, maintaining consistent gameplay dynamics. Actions that can be taken by a player consist of a left shift, a right shift, a clockwise rotation, a counterclockwise rotation and an accelerated drop. A left shift will move the block a distance of 16 pixels, or one “segment”, to the left and a right shift will move the block 16 pixels to the right. A clockwise rotation will rotate the block by 90 degrees about its centermost point to the right, and a counterclockwise rotation will rotate the block by 90 degrees about its centermost point to the left. A soft drop will accelerate the speed at which the block falls naturally by 2 times the current level drop rate while the respective key is pressed. The velocity of these actions is measured in pixels per clock tick. Falling Tetronimos will always appear at the top center of the passive play area and can be acted upon as soon as they are visible on screen. The player may take action on a block until it collides with any top portion of the active play area, at which point it is permanently placed. In some versions of the game, one final move of the Tetromino is permitted after it collides with the upper boundary, however this feature will be omitted for simplicity’s sake. Following the placement of a Tetromino, a new shape is immediately generated at the top center of the grid. This continuous cycle of generation and placement drives the game forward, challenging players to adapt to new shapes and maintain control of the play area.


## Play Area

  The play area consists of two main components, the “active” play area and the “passive” play area. The active play area contains actively placed pieces, and the  passive play area awaits player input on the currently running piece. This play area is confined by two side edges (Left and Right), a top edge and a bottom edge. The entire gameplay area measures 10 blocks wide and 20 blocks high (160 x 320 in pixels), but the size of the active and passive areas is determined by the actions of the player via the currently placed Tetromino stack height. The left, right and bottom edges serve no functional purpose other than to contain the play area, however the top edge marks the limit to the active play area. The passive play area represents the space available to the player to shift and adjust a falling block, whereas the active play area represents the area taken by previously placed blocks. The size of the active play area is the width of the total play area (160 pixels) times the distance in pixels between the bottom edge and the index of the topmost block of the highest placed Tetromino. The size of the passive play area is the width of the total play area (160 pixels) times the height of the total play area (320 pixels) minus the height of the active play area.
A collision of a block with the top edge of the active play area can result in two different outcomes; either 1 or more rows are completed and “cleared”, increasing the score by 40 points (level modifier dependent) per row cleared and decreasing the height of the active play area by 16 pixels per row cleared, or no rows are completed and the active play area is increased by the height in pixels of the collided block. In the event of a collision of the active play area and the top edge of the play area, the game is lost and will terminate. When the game ends, a message indicating the players final score and the lifetime top score will be displayed.


## Hypothetical Game Session

  The game starts off with a splash screen, and the options 1-Player, 2-Player, and Quit are displayed. A selection is made on ‘1-Player’ and the game Tetris loads to the screen for a 1-Player game. Level 1 begins, the top score loads the last top score achieved (let’s say 5000), and background music starts to play. The first block, an ‘O-Piece' spawns into view at the top-centre of the passive gameplay area screen, then the block begins to slowly descend downwards in block by block increments every 2 seconds. The player presses the ‘Left Arrow Key’ multiple times, prompting a block interaction ‘beep’ sound to play with each click; Additionally, this shifts the ‘O-Piece' in 1 block increments to the left with each key press to the left-most edge of the play area screen. The player then presses and holds the ‘Soft Drop Key’ until the piece makes contact with the bottom of the screen with a ‘thud’ sound, placing the piece in that position at the bottom left corner of the play area. 

  The next block generates at the same spawn location as the first ‘O-Piece’, but instead it is now the ‘L-Piece’. The player then rotates the piece clockwise multiple times with each ‘X Key’ press so that the longest side of the Tetromino shape is on the bottom. They then shift this piece closer to the now actively placed ‘O-Piece’ and place the ‘L-Piece’ next to it. Since the ‘Game Over’ condition has not been met, gameplay continues with further single-block spawns and player placements until the player places a piece in such a way that a horizontal line is filled in the active play area. A ‘chime’ sound plays, and the single line the player completed is cleared, the player is awarded 40 points (for the level 1 gameplay modifier). 
Any “floating” rows or pieces that may have been seated on the now cleared row line fall down towards the newly made space. The player, via shifting piece movement and rotations, clears a total of 10 lines cumulatively and the level increments by one. All currently placed pieces remain the same however, and the newly spawned Tetromino blocks begin to descend at a slightly faster pace. Gameplay continues the same as the level before, with Tetromino pieces generating at the top-centre spawn area again. The player now successfully lines up 2 rows that can potentially be completed with one piece placement if given a piece that fits. An ‘I-Piece’ spawns and the player places their piece to complete 2 horizontal lines at once. Both lines are cleared, respective points are awarded, and any “floating” rows fall. 

  The game continues for the player until one of their actively placed pieces touch the top of the play area screen. This occurs for our player on level 6, with a score of 6960, the top score is updated to this value. The game returns to the main menu, and the player can choose to play again or quit the game, they choose the ‘Quit’ option and the game closes.


