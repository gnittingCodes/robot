#include "stdio.h"
#include "stdlib.h"
#include "SDL.h"
#include "SDL2_gfxPrimitives.h"
#include <sys/time.h>
#include "math.h"
#include "formulas.h"
#include "wall.h"
#include "robot.h"

int done = 0;

int main(int argc, char *argv[])
{
    SDL_Window *window;
    SDL_Renderer *renderer;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        return 1;
    }

    window = SDL_CreateWindow("Robot Maze", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, OVERALL_WINDOW_WIDTH, OVERALL_WINDOW_HEIGHT, SDL_WINDOW_OPENGL);
    renderer = SDL_CreateRenderer(window, -1, 0);

    struct Robot robot;
    struct Wall_collection *head = NULL;
    int front_left_sensor, front_right_sensor, left_sensor, right_sensor = 0;
    struct timeval start_time, end_time;

    gettimeofday(&start_time, 0);

    unsigned long msec;

    // first maze

    // insertAndSetFirstWall(&head, 1, OVERALL_WINDOW_WIDTH / 2, OVERALL_WINDOW_HEIGHT / 2, 10, OVERALL_WINDOW_HEIGHT / 2);
    // insertAndSetFirstWall(&head, 2, OVERALL_WINDOW_WIDTH / 2 - 100, OVERALL_WINDOW_HEIGHT / 2 + 100, 10, OVERALL_WINDOW_HEIGHT / 2 - 100);
    // insertAndSetFirstWall(&head, 3, OVERALL_WINDOW_WIDTH / 2 - 250, OVERALL_WINDOW_HEIGHT / 2 + 100, 150, 10);
    // insertAndSetFirstWall(&head, 4, OVERALL_WINDOW_WIDTH / 2 - 150, OVERALL_WINDOW_HEIGHT / 2, 150, 10);
    // insertAndSetFirstWall(&head, 5, OVERALL_WINDOW_WIDTH / 2 - 250, OVERALL_WINDOW_HEIGHT / 2 - 200, 10, 300);
    // insertAndSetFirstWall(&head, 6, OVERALL_WINDOW_WIDTH / 2 - 150, OVERALL_WINDOW_HEIGHT / 2 - 100, 10, 100);
    // insertAndSetFirstWall(&head, 7, OVERALL_WINDOW_WIDTH / 2 - 250, OVERALL_WINDOW_HEIGHT / 2 - 200, 450, 10);
    // insertAndSetFirstWall(&head, 8, OVERALL_WINDOW_WIDTH / 2 - 150, OVERALL_WINDOW_HEIGHT / 2 - 100, 250, 10);
    // insertAndSetFirstWall(&head, 9, OVERALL_WINDOW_WIDTH / 2 + 200, OVERALL_WINDOW_HEIGHT / 2 - 200, 10, 300);
    // insertAndSetFirstWall(&head, 10, OVERALL_WINDOW_WIDTH / 2 + 100, OVERALL_WINDOW_HEIGHT / 2 - 100, 10, 300);
    // insertAndSetFirstWall(&head, 11, OVERALL_WINDOW_WIDTH / 2 + 100, OVERALL_WINDOW_HEIGHT / 2 + 200, OVERALL_WINDOW_WIDTH / 2 - 100, 10);
    // insertAndSetFirstWall(&head, 12, OVERALL_WINDOW_WIDTH / 2 + 200, OVERALL_WINDOW_HEIGHT / 2 + 100, OVERALL_WINDOW_WIDTH / 2 - 100, 10);

    // second maze
    /*insertAndSetFirstWall(&head, 1, OVERALL_WINDOW_WIDTH/2, OVERALL_WINDOW_HEIGHT/2, 10, OVERALL_WINDOW_HEIGHT/2);
    insertAndSetFirstWall(&head, 2, OVERALL_WINDOW_WIDTH/2 + 100, OVERALL_WINDOW_HEIGHT/2 - 100, 10, OVERALL_WINDOW_HEIGHT/2 + 100);
    insertAndSetFirstWall(&head, 3, OVERALL_WINDOW_WIDTH/2 - 100, OVERALL_WINDOW_HEIGHT/2 - 100, 10, OVERALL_WINDOW_HEIGHT/2 + 100);
    insertAndSetFirstWall(&head, 4, OVERALL_WINDOW_WIDTH/2 - 100, OVERALL_WINDOW_HEIGHT/2 - 100, 200, 10);*/

    // third maze
    // insertAndSetFirstWall(&head, 1, 0, 0, 10, OVERALL_WINDOW_HEIGHT);
    // insertAndSetFirstWall(&head, 2, 10, OVERALL_WINDOW_HEIGHT - 10, OVERALL_WINDOW_WIDTH - 10, 10);
    // insertAndSetFirstWall(&head, 3, OVERALL_WINDOW_WIDTH - 10, 0, 10, OVERALL_WINDOW_HEIGHT - 10);
    // insertAndSetFirstWall(&head, 4, 10, 0, OVERALL_WINDOW_WIDTH - 110, 10);
    // insertAndSetFirstWall(&head, 5, 110, OVERALL_WINDOW_HEIGHT - 110, OVERALL_WINDOW_WIDTH - 220, 10);
    // insertAndSetFirstWall(&head, 6, 10, OVERALL_WINDOW_HEIGHT - 220, OVERALL_WINDOW_WIDTH - 110, 10);

    // fourth maze

    /*insertAndSetFirstWall(&head, 1, OVERALL_WINDOW_WIDTH/2 - 10, 0, 10, OVERALL_WINDOW_HEIGHT);
    insertAndSetFirstWall(&head, 2, OVERALL_WINDOW_WIDTH/2 - 70, 0, 10, OVERALL_WINDOW_HEIGHT);*/

    // fifth maze

    // insertAndSetFirstWall(&head, 1, OVERALL_WINDOW_WIDTH / 2, OVERALL_WINDOW_HEIGHT - 200, 10, 200);
    // insertAndSetFirstWall(&head, 2, OVERALL_WINDOW_WIDTH / 2 - 80, OVERALL_WINDOW_HEIGHT - 100, 10, 100);
    // insertAndSetFirstWall(&head, 3, OVERALL_WINDOW_WIDTH / 2 - 240, OVERALL_WINDOW_HEIGHT - 200, 400, 10);
    // insertAndSetFirstWall(&head, 4, OVERALL_WINDOW_WIDTH / 2 - 320, OVERALL_WINDOW_HEIGHT - 100, 240, 10);
    // insertAndSetFirstWall(&head, 5, 0, 190, 10, 200);
    // insertAndSetFirstWall(&head, 6, OVERALL_WINDOW_WIDTH / 2 + 80, OVERALL_WINDOW_HEIGHT - 100, 240, 10);
    // insertAndSetFirstWall(&head, 7, OVERALL_WINDOW_WIDTH / 2 + 80, OVERALL_WINDOW_HEIGHT - 100, 10, 100);
    // insertAndSetFirstWall(&head, 8, OVERALL_WINDOW_WIDTH - 10, 0, 10, OVERALL_WINDOW_HEIGHT - 100);
    // insertAndSetFirstWall(&head, 9, 0, 190, OVERALL_WINDOW_WIDTH / 2, 10);
    // insertAndSetFirstWall(&head, 10, OVERALL_WINDOW_WIDTH - 160, OVERALL_WINDOW_HEIGHT - 150, 50, 10);
    // insertAndSetFirstWall(&head, 11, OVERALL_WINDOW_WIDTH / 2, 0, 10, 200);
    // insertAndSetFirstWall(&head, 12, OVERALL_WINDOW_WIDTH / 2, 0, OVERALL_WINDOW_WIDTH / 2, 10);

    // sixth maze
    // insertAndSetFirstWall(&head, 1, 0, OVERALL_WINDOW_HEIGHT - 10, OVERALL_WINDOW_WIDTH, 10);
    // insertAndSetFirstWall(&head, 2, 0, 0, 10, OVERALL_WINDOW_HEIGHT - 10);
    // insertAndSetFirstWall(&head, 3, OVERALL_WINDOW_WIDTH - 10, 0, 10, OVERALL_WINDOW_HEIGHT - 10);
    // insertAndSetFirstWall(&head, 4, 10, OVERALL_WINDOW_HEIGHT - 80, OVERALL_WINDOW_WIDTH - 100, 10);
    // insertAndSetFirstWall(&head, 5, 100, OVERALL_WINDOW_HEIGHT - 160, OVERALL_WINDOW_WIDTH - 10, 10);
    // insertAndSetFirstWall(&head, 6, 10, OVERALL_WINDOW_HEIGHT - 240, OVERALL_WINDOW_WIDTH - 100, 10);
    // insertAndSetFirstWall(&head, 7, 100, OVERALL_WINDOW_HEIGHT - 320, OVERALL_WINDOW_WIDTH - 10, 10);
    // insertAndSetFirstWall(&head, 8, 10, OVERALL_WINDOW_HEIGHT - 400, OVERALL_WINDOW_WIDTH - 100, 10);
    // insertAndSetFirstWall(&head, 9, 100, OVERALL_WINDOW_HEIGHT - 480, OVERALL_WINDOW_WIDTH - 10, 10);

    // seventh maze (super complex)
    // insertAndSetFirstWall(&head, 1, 0, OVERALL_WINDOW_HEIGHT - 10, OVERALL_WINDOW_WIDTH, 10);
    // insertAndSetFirstWall(&head, 2, 0, 0, 10, OVERALL_WINDOW_HEIGHT - 10);
    // insertAndSetFirstWall(&head, 3, OVERALL_WINDOW_WIDTH - 10, 0, 10, OVERALL_WINDOW_HEIGHT - 10);
    // insertAndSetFirstWall(&head, 4, 10, OVERALL_WINDOW_HEIGHT - 80, OVERALL_WINDOW_WIDTH - 100, 10);
    // insertAndSetFirstWall(&head, 5, 100, OVERALL_WINDOW_HEIGHT - 160, OVERALL_WINDOW_WIDTH - 10, 10);
    // insertAndSetFirstWall(&head, 6, 10, OVERALL_WINDOW_HEIGHT - 240, OVERALL_WINDOW_WIDTH - 100, 10);
    // insertAndSetFirstWall(&head, 7, 100, OVERALL_WINDOW_HEIGHT - 320, OVERALL_WINDOW_WIDTH - 10, 10);
    // insertAndSetFirstWall(&head, 8, 10, OVERALL_WINDOW_HEIGHT - 400, OVERALL_WINDOW_WIDTH - 100, 10);
    // insertAndSetFirstWall(&head, 9, 100, OVERALL_WINDOW_HEIGHT - 480, OVERALL_WINDOW_WIDTH - 10, 10);
    // insertAndSetFirstWall(&head, 10, 60, OVERALL_WINDOW_HEIGHT - 100, 10, 20);
    // insertAndSetFirstWall(&head, 11, 120, OVERALL_WINDOW_HEIGHT - 100, 10, 20);
    // insertAndSetFirstWall(&head, 12, 180, OVERALL_WINDOW_HEIGHT - 100, 10, 20);
    // insertAndSetFirstWall(&head, 13, 240, OVERALL_WINDOW_HEIGHT - 100, 10, 20);
    // insertAndSetFirstWall(&head, 14, 300, OVERALL_WINDOW_HEIGHT - 100, 10, 20);
    // insertAndSetFirstWall(&head, 15, 360, OVERALL_WINDOW_HEIGHT - 100, 10, 20);
    // insertAndSetFirstWall(&head, 16, 420, OVERALL_WINDOW_HEIGHT - 100, 10, 20);
    // insertAndSetFirstWall(&head, 17, 480, OVERALL_WINDOW_HEIGHT - 100, 10, 20);
    // insertAndSetFirstWall(&head, 18, 90, OVERALL_WINDOW_HEIGHT - 160, 10, 30);
    // insertAndSetFirstWall(&head, 19, 150, OVERALL_WINDOW_HEIGHT - 150, 10, 20);
    // insertAndSetFirstWall(&head, 20, 210, OVERALL_WINDOW_HEIGHT - 150, 10, 20);
    // insertAndSetFirstWall(&head, 21, 270, OVERALL_WINDOW_HEIGHT - 150, 10, 20);
    // insertAndSetFirstWall(&head, 22, 330, OVERALL_WINDOW_HEIGHT - 150, 10, 20);
    // insertAndSetFirstWall(&head, 23, 390, OVERALL_WINDOW_HEIGHT - 150, 10, 20);
    // insertAndSetFirstWall(&head, 24, 450, OVERALL_WINDOW_HEIGHT - 150, 10, 20);
    // insertAndSetFirstWall(&head, 25, 510, OVERALL_WINDOW_HEIGHT - 150, 10, 20);
    // insertAndSetFirstWall(&head, 26, 60, OVERALL_WINDOW_HEIGHT - 260, 10, 20);
    // insertAndSetFirstWall(&head, 27, 120, OVERALL_WINDOW_HEIGHT - 260, 10, 20);
    // insertAndSetFirstWall(&head, 28, 180, OVERALL_WINDOW_HEIGHT - 260, 10, 20);
    // insertAndSetFirstWall(&head, 29, 240, OVERALL_WINDOW_HEIGHT - 260, 10, 20);
    // insertAndSetFirstWall(&head, 30, 300, OVERALL_WINDOW_HEIGHT - 260, 10, 20);
    // insertAndSetFirstWall(&head, 31, 360, OVERALL_WINDOW_HEIGHT - 260, 10, 20);
    // insertAndSetFirstWall(&head, 32, 420, OVERALL_WINDOW_HEIGHT - 260, 10, 20);
    // insertAndSetFirstWall(&head, 33, 480, OVERALL_WINDOW_HEIGHT - 260, 10, 20);
    // insertAndSetFirstWall(&head, 34, 90, OVERALL_WINDOW_HEIGHT - 320, 10, 30);
    // insertAndSetFirstWall(&head, 35, 150, OVERALL_WINDOW_HEIGHT - 310, 10, 20);
    // insertAndSetFirstWall(&head, 36, 210, OVERALL_WINDOW_HEIGHT - 310, 10, 20);
    // insertAndSetFirstWall(&head, 37, 270, OVERALL_WINDOW_HEIGHT - 310, 10, 20);
    // insertAndSetFirstWall(&head, 38, 330, OVERALL_WINDOW_HEIGHT - 310, 10, 20);
    // insertAndSetFirstWall(&head, 39, 390, OVERALL_WINDOW_HEIGHT - 310, 10, 20);
    // insertAndSetFirstWall(&head, 40, 450, OVERALL_WINDOW_HEIGHT - 310, 10, 20);
    // insertAndSetFirstWall(&head, 41, 510, OVERALL_WINDOW_HEIGHT - 310, 10, 20);
    // insertAndSetFirstWall(&head, 42, 60, OVERALL_WINDOW_HEIGHT - 200, 10, 10);
    // insertAndSetFirstWall(&head, 43, 120, OVERALL_WINDOW_HEIGHT - 200, 10, 10);
    // insertAndSetFirstWall(&head, 44, 180, OVERALL_WINDOW_HEIGHT - 200, 10, 10);
    // insertAndSetFirstWall(&head, 45, 240, OVERALL_WINDOW_HEIGHT - 200, 10, 10);
    // insertAndSetFirstWall(&head, 46, 300, OVERALL_WINDOW_HEIGHT - 200, 10, 10);
    // insertAndSetFirstWall(&head, 47, 360, OVERALL_WINDOW_HEIGHT - 200, 10, 10);
    // insertAndSetFirstWall(&head, 48, 420, OVERALL_WINDOW_HEIGHT - 200, 10, 10);
    // insertAndSetFirstWall(&head, 49, 480, OVERALL_WINDOW_HEIGHT - 200, 10, 10);
    // insertAndSetFirstWall(&head, 50, 60, OVERALL_WINDOW_HEIGHT - 360, 10, 10);
    // insertAndSetFirstWall(&head, 51, 120, OVERALL_WINDOW_HEIGHT - 360, 10, 10);
    // insertAndSetFirstWall(&head, 52, 180, OVERALL_WINDOW_HEIGHT - 360, 10, 10);
    // insertAndSetFirstWall(&head, 53, 240, OVERALL_WINDOW_HEIGHT - 360, 10, 10);
    // insertAndSetFirstWall(&head, 54, 300, OVERALL_WINDOW_HEIGHT - 360, 10, 10);
    // insertAndSetFirstWall(&head, 55, 360, OVERALL_WINDOW_HEIGHT - 360, 10, 10);
    // insertAndSetFirstWall(&head, 56, 420, OVERALL_WINDOW_HEIGHT - 360, 10, 10);
    // insertAndSetFirstWall(&head, 57, 480, OVERALL_WINDOW_HEIGHT - 360, 10, 10);

    //  deadend map
    int gap_width = 60;
    insertAndSetFirstWall(&head, 1,
                          OVERALL_WINDOW_WIDTH / 2, OVERALL_WINDOW_HEIGHT / 6, // start x and y
                          WALL_WIDTH, gap_width);
    insertAndSetFirstWall(&head, 2,
                          OVERALL_WINDOW_WIDTH / 6, OVERALL_WINDOW_HEIGHT / 6,
                          OVERALL_WINDOW_WIDTH / 2 - OVERALL_WINDOW_WIDTH / 6, WALL_WIDTH);
    insertAndSetFirstWall(&head, 3,
                          OVERALL_WINDOW_WIDTH / 6 + gap_width, OVERALL_WINDOW_HEIGHT / 6 + gap_width,
                          OVERALL_WINDOW_WIDTH / 2 - OVERALL_WINDOW_WIDTH / 6 - gap_width + WALL_WIDTH, WALL_WIDTH);
    insertAndSetFirstWall(&head, 4,
                          OVERALL_WINDOW_WIDTH / 6 - WALL_WIDTH, OVERALL_WINDOW_HEIGHT / 6,
                          WALL_WIDTH, 5 * OVERALL_WINDOW_HEIGHT / 6 + WALL_WIDTH);
    insertAndSetFirstWall(&head, 5,
                          OVERALL_WINDOW_WIDTH / 6 + gap_width, OVERALL_WINDOW_HEIGHT / 6 + gap_width,
                          WALL_WIDTH, OVERALL_WINDOW_HEIGHT / 3 - gap_width / 2);
    insertAndSetFirstWall(&head, 6,
                          OVERALL_WINDOW_WIDTH / 6 + gap_width, OVERALL_WINDOW_HEIGHT / 2 + gap_width / 2 - WALL_WIDTH,
                          2 * OVERALL_WINDOW_WIDTH / 3, WALL_WIDTH);
    insertAndSetFirstWall(&head, 7,
                          OVERALL_WINDOW_WIDTH / 6 + gap_width, OVERALL_WINDOW_HEIGHT / 2 + 3 * gap_width / 2,
                          2 * OVERALL_WINDOW_WIDTH / 3, WALL_WIDTH);
    insertAndSetFirstWall(&head, 8,
                          OVERALL_WINDOW_WIDTH / 6 + gap_width, OVERALL_WINDOW_HEIGHT / 2 + 3 * gap_width / 2,
                          WALL_WIDTH, OVERALL_WINDOW_HEIGHT / 2 - gap_width / 2);

    // DEMO SIMPLE MAZE 1 & 2
    // insertAndSetFirstWall(&head, 2, 220, 400, 10, 80);
    // insertAndSetFirstWall(&head, 2, 20, 400, 200, 10);
    // insertAndSetFirstWall(&head, 2, 20, 50, 10, 350);
    // insertAndSetFirstWall(&head, 2, 20, 50, 280, 10);
    // insertAndSetFirstWall(&head, 2, 300, 50, 10, 100);
    // insertAndSetFirstWall(&head, 2, 300, 150, 110, 10);
    // insertAndSetFirstWall(&head, 2, 400, 50, 10, 100);
    // insertAndSetFirstWall(&head, 2, 400, 50, 220, 10);
    // insertAndSetFirstWall(&head, 2, 620, 50, 10, 290);
    // insertAndSetFirstWall(&head, 2, 620, 340, 20, 10);

    // insertAndSetFirstWall(&head, 1, 320, 300, 10, 180);
    // insertAndSetFirstWall(&head, 2, 120, 300, 200, 10);
    // insertAndSetFirstWall(&head, 2, 120, 150, 10, 150);
    // insertAndSetFirstWall(&head, 2, 120, 150, 80, 10);
    // insertAndSetFirstWall(&head, 2, 200, 150, 10, 100);
    // insertAndSetFirstWall(&head, 2, 200, 250, 310, 10);
    // insertAndSetFirstWall(&head, 2, 500, 150, 10, 100);
    // insertAndSetFirstWall(&head, 2, 500, 150, 10, 100);
    // insertAndSetFirstWall(&head, 2, 500, 150, 20, 10);
    // insertAndSetFirstWall(&head, 2, 520, 150, 10, 290);
    // insertAndSetFirstWall(&head, 2, 520, 440, 120, 10);

    // DEMO SIMPLE MAZE 3 & 4
    // insertAndSetFirstWall(&head, 2, 640 - 10 - 220, 400, 10, 80);
    // insertAndSetFirstWall(&head, 2, 640 - 200 - 20, 400, 200, 10);
    // insertAndSetFirstWall(&head, 2, 640 - 10 - 20, 50, 10, 350);
    // insertAndSetFirstWall(&head, 2, 640 - 280 - 20, 50, 280, 10);
    // insertAndSetFirstWall(&head, 2, 640 - 10 - 300, 50, 10, 100);
    // insertAndSetFirstWall(&head, 2, 640 - 110 - 300, 150, 110, 10);
    // insertAndSetFirstWall(&head, 2, 640 - 10 - 400, 50, 10, 100);
    // insertAndSetFirstWall(&head, 2, 640 - 400 - 220, 50, 220, 10);
    // insertAndSetFirstWall(&head, 2, 640 - 10 - 620, 50, 10, 290);
    // insertAndSetFirstWall(&head, 2, 640 - 620 - 20, 340, 20, 10);

    // insertAndSetFirstWall(&head, 1, 640 - 10 - 320, 300, 10, 180);
    // insertAndSetFirstWall(&head, 2, 640 - 200 - 120, 300, 200, 10);
    // insertAndSetFirstWall(&head, 2, 640 - 10 - 120, 150, 10, 150);
    // insertAndSetFirstWall(&head, 2, 640 - 80 - 120, 150, 80, 10);
    // insertAndSetFirstWall(&head, 2, 640 - 10 - 200, 150, 10, 100);
    // insertAndSetFirstWall(&head, 2, 640 - 310 - 200, 250, 310, 10);
    // insertAndSetFirstWall(&head, 2, 640 - 10 - 500, 150, 10, 100);
    // insertAndSetFirstWall(&head, 2, 640 - 20 - 500, 150, 20, 10);
    // insertAndSetFirstWall(&head, 2, 640 - 10 - 520, 150, 10, 290);
    // insertAndSetFirstWall(&head, 2, 640 - 120 - 520, 440, 120, 10);

    // DEMO COMPLEX MAZE 5 & 6
    // int i;
    // insertAndSetFirstWall(&head, 12, 120, 450, 10, 30);
    // insertAndSetFirstWall(&head, 12, 220, 450, 10, 30);
    // for (i = 0; i < 100; i++)
    // {
    //     insertAndSetFirstWall(&head, i, 20 + i, 350 + i, 10, 10);       // 1
    //     insertAndSetFirstWall(&head, i, 20 + 100 + i, 350 + i, 10, 10); // 1
    // }
    // insertAndSetFirstWall(&head, 12, 20, 280, 10, 70);
    // insertAndSetFirstWall(&head, 12, 120, 280, 10, 70);
    // for (i = 0; i < 180; i++)
    // {
    //     insertAndSetFirstWall(&head, i, 20 + 190 - i / 2, 100 + i, 10, 10); // 1
    // }
    // for (i = 0; i < 105; i++)
    // {
    //     insertAndSetFirstWall(&head, i, 20 + 105 / 2 - i / 2, 175 + i, 10, 10); // 1
    // }
    // insertAndSetFirstWall(&head, 2, 20, 175, 105 / 2, 10);
    // insertAndSetFirstWall(&head, 2, 20, 20, 10, 155);
    // insertAndSetFirstWall(&head, 2, 20, 20, 300, 10);
    // insertAndSetFirstWall(&head, 2, 320, 20, 10, 60);
    // insertAndSetFirstWall(&head, 2, 80, 100, 130, 10);
    // insertAndSetFirstWall(&head, 2, 80, 80, 10, 20);
    // insertAndSetFirstWall(&head, 2, 80, 80, 160, 10);
    // double j;
    // for (i = 0; i < 50; i++)
    // {
    //     j = i;
    //     insertAndSetFirstWall(&head, i + 1,
    //                           // the most important bit is below.
    //                           // increase the 20 for a tighter bend
    //                           // descrease for a more meandering flow
    //                           320 + 30 * sin(10 * j * M_PI / 180),
    //                           // increase the 5 for a spacier curve
    //                           (i * 5) + 80,
    //                           10, 10);
    // }
    // for (i = 0; i < 75; i++)
    // {
    //     j = i;
    //     insertAndSetFirstWall(&head, i + 1,
    //                           // the most important bit is below.
    //                           // increase the 20 for a tighter bend
    //                           // descrease for a more meandering flow
    //                           240 + 30 * sin(10 * j * M_PI / 180),
    //                           // increase the 5 for a spacier curve
    //                           (i * 5) + 80,
    //                           10, 10);
    // }
    // insertAndSetFirstWall(&head, 2, 345, 330, 105, 10);
    // insertAndSetFirstWall(&head, 2, 450, 190, 10, 150);
    // insertAndSetFirstWall(&head, 2, 380, 190, 70, 10);
    // insertAndSetFirstWall(&head, 2, 380, 20, 10, 170);
    // insertAndSetFirstWall(&head, 2, 380, 20, 260, 10);

    // insertAndSetFirstWall(&head, 2, 255, 455, 345, 10);
    // insertAndSetFirstWall(&head, 2, 600, 100, 10, 365);
    // insertAndSetFirstWall(&head, 2, 530, 100, 70, 10);
    // insertAndSetFirstWall(&head, 2, 530, 80, 10, 20);
    // insertAndSetFirstWall(&head, 2, 530, 80, 110, 10);

    // DEMO COMPLEX MAZE 7 & 8
    // int i;
    // insertAndSetFirstWall(&head, 12, 640 - 10 - 120, 450, 10, 30);
    // insertAndSetFirstWall(&head, 12, 640 - 10 - 220, 450, 10, 30);

    // for (i = 0; i < 100; i++)
    // {
    //     insertAndSetFirstWall(&head, i, 640 - 10 - (20 + i), 350 + i, 10, 10);       // 1
    //     insertAndSetFirstWall(&head, i, 640 - 10 - (20 + 100 + i), 350 + i, 10, 10); // 1
    // }
    // insertAndSetFirstWall(&head, 12, 640 - 10 - 20, 280, 10, 70);
    // insertAndSetFirstWall(&head, 12, 640 - 10 - 120, 280, 10, 70);

    // for (i = 0; i < 180; i++)
    // {
    //     insertAndSetFirstWall(&head, i, 640 - 10 - (20 + 190 - i / 2), 100 + i, 10, 10); // 1
    // }
    // for (i = 0; i < 105; i++)
    // {
    //     insertAndSetFirstWall(&head, i, 640 - 10 - (20 + 105 / 2 - i / 2), 175 + i, 10, 10); // 1
    // }

    // insertAndSetFirstWall(&head, 2, 640 - 105 / 2 - 20, 175, 105 / 2, 10);
    // insertAndSetFirstWall(&head, 2, 640 - 10 - 20, 20, 10, 155);
    // insertAndSetFirstWall(&head, 2, 640 - 300 - 20, 20, 300, 10);
    // insertAndSetFirstWall(&head, 2, 640 - 10 - 320, 20, 10, 60);
    // insertAndSetFirstWall(&head, 2, 640 - 130 - 80, 100, 130, 10);
    // insertAndSetFirstWall(&head, 2, 640 - 10 - 80, 80, 10, 20);
    // insertAndSetFirstWall(&head, 2, 640 - 160 - 80, 80, 160, 10);

    // double j;
    // for (i = 0; i < 50; i++)
    // {
    //     j = i;
    //     insertAndSetFirstWall(&head, i + 1,
    //                           // the most important bit is below.
    //                           // increase the 20 for a tighter bend
    //                           // descrease for a more meandering flow
    //                           640 - 10 - (320 + 30 * sin(10 * j * M_PI / 180)),
    //                           // increase the 5 for a spacier curve
    //                           (i * 5) + 80,
    //                           10, 10);
    // }
    // for (i = 0; i < 75; i++)
    // {
    //     j = i;
    //     insertAndSetFirstWall(&head, i + 1,
    //                           // the most important bit is below.
    //                           // increase the 20 for a tighter bend
    //                           // descrease for a more meandering flow
    //                           640 - 10 - (240 + 30 * sin(10 * j * M_PI / 180)),
    //                           // increase the 5 for a spacier curve
    //                           (i * 5) + 80,
    //                           10, 10);
    // }

    // insertAndSetFirstWall(&head, 2, 640 - 105 - 345, 330, 105, 10);
    // insertAndSetFirstWall(&head, 2, 640 - 10 - 450, 190, 10, 150);
    // insertAndSetFirstWall(&head, 2, 640 - 70 - 380, 190, 70, 10);
    // insertAndSetFirstWall(&head, 2, 640 - 10 - 380, 20, 10, 170);
    // insertAndSetFirstWall(&head, 2, 640 - 260 - 380, 20, 260, 10);

    // insertAndSetFirstWall(&head, 2, 640 - 345 - 255, 455, 345, 10);
    // insertAndSetFirstWall(&head, 2, 640 - 10 - 600, 100, 10, 365);
    // insertAndSetFirstWall(&head, 2, 640 - 70 - 530, 100, 70, 10);
    // insertAndSetFirstWall(&head, 2, 640 - 10 - 530, 80, 10, 20);
    // insertAndSetFirstWall(&head, 2, 640 - 110 - 530, 80, 110, 10);

    setup_robot(&robot);
    updateAllWalls(head, renderer);

    SDL_Event event;
    int adjusted = 0;
    int atDeadEnd = 0;
    int searchingLeft = 0;
    while (!done)
    {
        // Dark theme, using USYD's black colour
        SDL_SetRenderDrawColor(renderer, 0x37, 0x36, 0x36, 255);
        SDL_RenderClear(renderer);

        // Move robot based on user input commands/auto commands
        if (robot.auto_mode == 1)
            robotAutoMotorMove(&robot, front_left_sensor, front_right_sensor, left_sensor, right_sensor, &adjusted, &atDeadEnd, &searchingLeft);
        robotMotorMove(&robot);

        // Check if robot reaches endpoint. and check sensor values
        if (checkRobotReachedEnd(&robot, OVERALL_WINDOW_WIDTH - 10, OVERALL_WINDOW_HEIGHT / 2 + 100, 10, 100))

        // DEMO SIMPLE MAZE 1
        // if (checkRobotReachedEnd(&robot, 640, 340, 10, 100))

        // DEMO SIMPLE MAZE 2
        // if (checkRobotReachedEnd(&robot, 220, 480, 100, 10))

        // DEMO SIMPLE MAZE 3
        // if (checkRobotReachedEnd(&robot, 0, 340, 10, 100))

        // DEMO SIMPLE MAZE 4
        // if (checkRobotReachedEnd(&robot, 640 - 10 - 320, 480, 100, 10))

        // DEMO COMPLEX MAZE 5
        // if (checkRobotReachedEnd(&robot, 640, 20, 10, 60))

        // DEMO COMPLEX MAZE 6
        // if (checkRobotReachedEnd(&robot, 120, 480, 100, 10))

        // DEMO COMPLEX MAZE 7
        // if (checkRobotReachedEnd(&robot, 0, 20, 10, 60))

        // DEMO COMPLEX MAZE 8
        // if (checkRobotReachedEnd(&robot, 640 - 10 - 220, 480, 100, 10))
        {
            gettimeofday(&end_time, 0);
            msec = ((end_time.tv_sec - start_time.tv_sec) * 1000) + (end_time.tv_usec - start_time.tv_usec) / 1000;
            robotSuccess(&robot, msec);
            setup_robot(&robot);
        }
        else if (checkRobotHitWalls(&robot, head))
            robotCrash(&robot);
        // Otherwise compute sensor information
        else
        {
            front_left_sensor = checkRobotSensorFrontLeftAllWalls(&robot, head);
            if (front_left_sensor > 0)
                printf("Getting close on the front left. Score = %d\n", front_left_sensor);

            front_right_sensor = checkRobotSensorFrontRightAllWalls(&robot, head);
            if (front_right_sensor > 0)
                printf("Getting close on the front right. Score = %d\n", front_right_sensor);

            left_sensor = checkRobotSensorLeftAllWalls(&robot, head);
            if (left_sensor > 0)
                printf("Getting close on the left. Score = %d\n", left_sensor);

            right_sensor = checkRobotSensorRightAllWalls(&robot, head);
            if (right_sensor > 0)
                printf("Getting close on the right. Score = %d\n", right_sensor);
        }
        robotUpdate(renderer, &robot, checkRobotSensorFrontLeftAllWalls(&robot, head), checkRobotSensorFrontRightAllWalls(&robot, head), checkRobotSensorLeftAllWalls(&robot, head), checkRobotSensorRightAllWalls(&robot, head));
        updateAllWalls(head, renderer);

        // Check for user input
        SDL_RenderPresent(renderer);
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                done = 1;
            }
            const Uint8 *state = SDL_GetKeyboardState(NULL);
            if (state[SDL_SCANCODE_UP] && robot.direction != DOWN)
            {
                robot.direction = UP;
            }
            if (state[SDL_SCANCODE_DOWN] && robot.direction != UP)
            {
                robot.direction = DOWN;
            }
            if (state[SDL_SCANCODE_LEFT] && robot.direction != RIGHT)
            {
                robot.direction = LEFT;
            }
            if (state[SDL_SCANCODE_RIGHT] && robot.direction != LEFT)
            {
                robot.direction = RIGHT;
            }
            if (state[SDL_SCANCODE_SPACE])
            {
                gettimeofday(&start_time, 0);
                setup_robot(&robot);
            }
            if (state[SDL_SCANCODE_RETURN])
            {
                robot.auto_mode = 1;
                gettimeofday(&start_time, 0);
            }
        }

        SDL_Delay(120);
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    printf("DEAD\n");
}
