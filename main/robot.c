#include "robot.h"

// void setup_robot(struct Robot *robot)
// {
//     robot->x = OVERALL_WINDOW_WIDTH / 2 - 50;
//     robot->y = OVERALL_WINDOW_HEIGHT - 50;
//     robot->true_x = OVERALL_WINDOW_WIDTH / 2 - 50;
//     robot->true_y = OVERALL_WINDOW_HEIGHT - 50;
//     robot->width = ROBOT_WIDTH;
//     robot->height = ROBOT_HEIGHT;
//     robot->direction = 0;
//     robot->angle = 0;
//     robot->currentSpeed = 0;
//     robot->crashed = 0;
//     robot->auto_mode = 0;

//     printf("Press arrow keys to move manually, or enter to move automatically\n\n");
// }

// David's deadend map
void setup_robot(struct Robot *robot)
{
    robot->x = OVERALL_WINDOW_WIDTH / 6 + 15;
    robot->y = OVERALL_WINDOW_HEIGHT - 50;
    robot->true_x = OVERALL_WINDOW_WIDTH / 6 + 15;
    robot->true_y = OVERALL_WINDOW_HEIGHT - 50;
    robot->width = ROBOT_WIDTH;
    robot->height = ROBOT_HEIGHT;
    robot->direction = 0;
    robot->angle = 0;
    robot->currentSpeed = 0;
    robot->crashed = 0;
    robot->auto_mode = 0;

    printf("Press arrow keys to move manually, or enter to move automatically\n\n");
}

// DEMO SIMPLE MAZE 1
// void setup_robot(struct Robot *robot)
// {
//     robot->x = 270;
//     robot->y = 460;
//     robot->true_x = 270;
//     robot->true_y = 460;
//     robot->width = ROBOT_WIDTH;
//     robot->height = ROBOT_HEIGHT;
//     robot->direction = 0;
//     robot->angle = 0;
//     robot->currentSpeed = 0;
//     robot->crashed = 0;
//     robot->auto_mode = 0;

//     printf("Press arrow keys to move manually, or enter to move automatically\n\n");
// }

// DEMO SIMPLE MAZE 2
// void setup_robot(struct Robot *robot)
// {
//     robot->x = 620;
//     robot->y = 380;
//     robot->true_x = 620;
//     robot->true_y = 380;
//     robot->width = ROBOT_WIDTH;
//     robot->height = ROBOT_HEIGHT;
//     robot->direction = 0;
//     robot->angle = 270;
//     robot->currentSpeed = 0;
//     robot->crashed = 0;
//     robot->auto_mode = 0;

//     printf("Press arrow keys to move manually, or enter to move automatically\n\n");
// }

// DEMO SIMPLE MAZE 3
// void setup_robot(struct Robot *robot)
// {
//     robot->x = 640 - 10 - 270;
//     robot->y = 460;
//     robot->true_x = 640 - 10 - 270;
//     robot->true_y = 460;
//     robot->width = ROBOT_WIDTH;
//     robot->height = ROBOT_HEIGHT;
//     robot->direction = 0;
//     robot->angle = 0;
//     robot->currentSpeed = 0;
//     robot->crashed = 0;
//     robot->auto_mode = 0;

//     printf("Press arrow keys to move manually, or enter to move automatically\n\n");
// }

// DEMO SIMPLE MAZE 4
// void setup_robot(struct Robot *robot)
// {
//     robot->x = 0;
//     robot->y = 380;
//     robot->true_x = 0;
//     robot->true_y = 380;
//     robot->width = ROBOT_WIDTH;
//     robot->height = ROBOT_HEIGHT;
//     robot->direction = 0;
//     robot->angle = 90;
//     robot->currentSpeed = 0;
//     robot->crashed = 0;
//     robot->auto_mode = 0;

//     printf("Press arrow keys to move manually, or enter to move automatically\n\n");
// }

// DEMO COMPLEX MAZE 5
// void setup_robot(struct Robot *robot)
// {
//     robot->x = 170;
//     robot->y = 460;
//     robot->true_x = 170;
//     robot->true_y = 460;
//     robot->width = ROBOT_WIDTH;
//     robot->height = ROBOT_HEIGHT;
//     robot->direction = 0;
//     robot->angle = 0;
//     robot->currentSpeed = 0;
//     robot->crashed = 0;
//     robot->auto_mode = 0;

//     printf("Press arrow keys to move manually, or enter to move automatically\n\n");
// }

// DEMO COMPLEX MAZE 6
// void setup_robot(struct Robot *robot)
// {
//     robot->x = 620;
//     robot->y = 40;
//     robot->true_x = 620;
//     robot->true_y = 40;
//     robot->width = ROBOT_WIDTH;
//     robot->height = ROBOT_HEIGHT;
//     robot->direction = 0;
//     robot->angle = 270;
//     robot->currentSpeed = 0;
//     robot->crashed = 0;
//     robot->auto_mode = 0;

//     printf("Press arrow keys to move manually, or enter to move automatically\n\n");
// }

// DEMO COMPLEX MAZE 7
// void setup_robot(struct Robot *robot)
// {
//     robot->x = 640 - 10 - 170;
//     robot->y = 460;
//     robot->true_x = 640 - 10 - 170;
//     robot->true_y = 460;
//     robot->width = ROBOT_WIDTH;
//     robot->height = ROBOT_HEIGHT;
//     robot->direction = 0;
//     robot->angle = 0;
//     robot->currentSpeed = 0;
//     robot->crashed = 0;
//     robot->auto_mode = 0;

//     printf("Press arrow keys to move manually, or enter to move automatically\n\n");
// }

// DEMO COMPLEX MAZE 8
// void setup_robot(struct Robot *robot)
// {
//     robot->x = 0;
//     robot->y = 40;
//     robot->true_x = 0;
//     robot->true_y = 40;
//     robot->width = ROBOT_WIDTH;
//     robot->height = ROBOT_HEIGHT;
//     robot->direction = 0;
//     robot->angle = 90;
//     robot->currentSpeed = 0;
//     robot->crashed = 0;
//     robot->auto_mode = 0;

//     printf("Press arrow keys to move manually, or enter to move automatically\n\n");
// }

int robot_off_screen(struct Robot *robot)
{
    if (robot->x < 0 || robot->y < 0)
    {
        return 0;
    }
    if (robot->x > OVERALL_WINDOW_WIDTH || robot->y > OVERALL_WINDOW_HEIGHT)
    {
        return 0;
    }
    return 1;
}

int checkRobotHitWall(struct Robot *robot, struct Wall *wall)
{

    int overlap = checkOverlap(robot->x, robot->width, robot->y, robot->height,
                               wall->x, wall->width, wall->y, wall->height);

    return overlap;
}

int checkRobotHitWalls(struct Robot *robot, struct Wall_collection *head)
{
    struct Wall_collection *ptr = head;
    int hit = 0;

    while (ptr != NULL)
    {
        hit = (hit || checkRobotHitWall(robot, &ptr->wall));
        ptr = ptr->next;
    }
    return hit;
}

int checkRobotReachedEnd(struct Robot *robot, int x, int y, int width, int height)
{

    int overlap = checkOverlap(robot->x, robot->width, robot->y, robot->height,
                               x, width, y, height);

    return overlap;
}

void robotCrash(struct Robot *robot)
{
    robot->currentSpeed = 0;
    if (!robot->crashed)
        printf("Ouchies!!!!!\n\nPress space to start again\n");
    robot->crashed = 1;
}

void robotSuccess(struct Robot *robot, unsigned long msec)
{
    robot->currentSpeed = 0;
    if (!robot->crashed)
    {
        printf("Success!!!!!\n\n");
        printf("Time taken %lu seconds %lu milliseconds \n", msec / 1000, msec % 1000);
        printf("Press space to start again\n");
    }
    robot->crashed = 1;
}

int checkRobotSensor(int x, int y, int sensorSensitivityLength, struct Wall *wall)
{
    // viewing_region of sensor is a square of 2 pixels * chosen length of sensitivity
    int overlap = checkOverlap(x, 2, y, sensorSensitivityLength,
                               wall->x, wall->width, wall->y, wall->height);

    return overlap;
}

int checkRobotSensorFrontRightAllWalls(struct Robot *robot, struct Wall_collection *head)
{
    struct Wall_collection *ptr, *head_store;
    int i;
    double xDir, yDir;
    int robotCentreX, robotCentreY, xTL, yTL;
    int score, hit;

    int sensorSensitivityLength = floor(SENSOR_VISION / 5);

    head_store = head;
    robotCentreX = robot->x + ROBOT_WIDTH / 2;
    robotCentreY = robot->y + ROBOT_HEIGHT / 2;
    score = 0;

    for (i = 0; i < 5; i++)
    {
        ptr = head_store;
        xDir = round(robotCentreX + (ROBOT_WIDTH / 2 - 2) * cos((robot->angle) * PI / 180) - (-ROBOT_HEIGHT / 2 - SENSOR_VISION + sensorSensitivityLength * i) * sin((robot->angle) * PI / 180));
        yDir = round(robotCentreY + (ROBOT_WIDTH / 2 - 2) * sin((robot->angle) * PI / 180) + (-ROBOT_HEIGHT / 2 - SENSOR_VISION + sensorSensitivityLength * i) * cos((robot->angle) * PI / 180));
        xTL = (int)xDir;
        yTL = (int)yDir;
        hit = 0;

        while (ptr != NULL)
        {
            hit = (hit || checkRobotSensor(xTL, yTL, sensorSensitivityLength, &ptr->wall));
            ptr = ptr->next;
        }
        if (hit)
            score = i;
    }
    return score;
}

int checkRobotSensorFrontLeftAllWalls(struct Robot *robot, struct Wall_collection *head)
{
    struct Wall_collection *ptr, *head_store;
    int i;
    double xDir, yDir;
    int robotCentreX, robotCentreY, xTL, yTL;
    int score, hit;
    int sensorSensitivityLength;

    head_store = head;
    robotCentreX = robot->x + ROBOT_WIDTH / 2;
    robotCentreY = robot->y + ROBOT_HEIGHT / 2;
    score = 0;
    sensorSensitivityLength = floor(SENSOR_VISION / 5);

    for (i = 0; i < 5; i++)
    {
        ptr = head_store;
        xDir = round(robotCentreX + (-ROBOT_WIDTH / 2) * cos((robot->angle) * PI / 180) - (-ROBOT_HEIGHT / 2 - SENSOR_VISION + sensorSensitivityLength * i) * sin((robot->angle) * PI / 180));
        yDir = round(robotCentreY + (-ROBOT_WIDTH / 2) * sin((robot->angle) * PI / 180) + (-ROBOT_HEIGHT / 2 - SENSOR_VISION + sensorSensitivityLength * i) * cos((robot->angle) * PI / 180));
        xTL = (int)xDir;
        yTL = (int)yDir;
        hit = 0;

        while (ptr != NULL)
        {
            hit = (hit || checkRobotSensor(xTL, yTL, sensorSensitivityLength, &ptr->wall));
            ptr = ptr->next;
        }
        if (hit)
            score = i;
    }
    return score;
}

int checkRobotSensorLeftAllWalls(struct Robot *robot, struct Wall_collection *head)
{
    struct Wall_collection *ptr, *head_store;
    int i;
    double xDir, yDir;
    int robotCentreX, robotCentreY, xTL, yTL;
    int score, hit;
    int sensorSensitivityLength;

    head_store = head;
    robotCentreX = robot->x + ROBOT_WIDTH / 2;
    robotCentreY = robot->y + ROBOT_HEIGHT / 2;
    score = 0;
    sensorSensitivityLength = floor(SENSOR_VISION / 5);

    for (i = 0; i < 5; i++)
    {
        ptr = head_store;
        double x1 = (-ROBOT_WIDTH / 2 - SENSOR_VISION + sensorSensitivityLength * i);
        double y1 = 0;
        xDir = round((robotCentreX + x1 * cos(robot->angle * PI / 180)) - y1 * sin(robot->angle * PI / 180));
        yDir = round((robotCentreY + x1 * sin(robot->angle * PI / 180)) + y1 * cos(robot->angle * PI / 180));
        xTL = (int)xDir;
        yTL = (int)yDir;
        hit = 0;

        while (ptr != NULL)
        {
            hit = (hit || checkRobotSensor(xTL, yTL, sensorSensitivityLength, &ptr->wall));
            ptr = ptr->next;
        }
        if (hit)
            score = i;
    }
    return score;
}

int checkRobotSensorRightAllWalls(struct Robot *robot, struct Wall_collection *head)
{
    struct Wall_collection *ptr, *head_store;
    int i;
    double xDir, yDir;
    int robotCentreX, robotCentreY, xTL, yTL;
    int score, hit;
    int sensorSensitivityLength;

    head_store = head;
    robotCentreX = robot->x + ROBOT_WIDTH / 2;
    robotCentreY = robot->y + ROBOT_HEIGHT / 2;
    score = 0;
    sensorSensitivityLength = floor(SENSOR_VISION / 5);

    for (i = 0; i < 5; i++)
    {
        ptr = head_store;
        double x1 = (ROBOT_WIDTH / 2 + SENSOR_VISION - sensorSensitivityLength * i);
        double y1 = 0;
        xDir = round((robotCentreX + x1 * cos(robot->angle * PI / 180)) - y1 * sin(robot->angle * PI / 180));
        yDir = round((robotCentreY + x1 * sin(robot->angle * PI / 180)) + y1 * cos(robot->angle * PI / 180));
        xTL = (int)xDir;
        yTL = (int)yDir;
        hit = 0;

        while (ptr != NULL)
        {
            hit = (hit || checkRobotSensor(xTL, yTL, sensorSensitivityLength, &ptr->wall));
            ptr = ptr->next;
        }
        if (hit)
            score = i;
    }
    return score;
}

void robotUpdate(struct SDL_Renderer *renderer, struct Robot *robot, int fl, int fr, int l, int r)
{
    double xDir, yDir;

    int robotCentreX, robotCentreY, xTR, yTR, xTL, yTL, xBR, yBR, xBL, yBL;
    SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255);

    /*
    //Other Display options:
    // The actual square which the robot is tested against (not so nice visually with turns, but easier
    // to test overlap
    SDL_Rect rect = {robot->x, robot->y, robot->height, robot->width};
    SDL_SetRenderDrawColor(renderer, 80, 80, 80, 255);
    SDL_RenderDrawRect(renderer, &rect);
    SDL_RenderFillRect(renderer, &rect);
    */
    /*
    //Center Line of Robot. Line shows the direction robot is facing
    xDir = -30 * sin(-robot->angle*PI/180);
    yDir = -30 * cos(-robot->angle*PI/180);
    xDirInt = robot->x+ROBOT_WIDTH/2+ (int) xDir;
    yDirInt = robot->y+ROBOT_HEIGHT/2+ (int) yDir;
    SDL_RenderDrawLine(renderer,robot->x+ROBOT_WIDTH/2, robot->y+ROBOT_HEIGHT/2, xDirInt, yDirInt);
    */

    // Rotating Square
    // Vector rotation to work out corners x2 = x1cos(angle)-y1sin(angle), y2 = x1sin(angle)+y1cos(angle)
    robotCentreX = robot->x + ROBOT_WIDTH / 2;
    robotCentreY = robot->y + ROBOT_HEIGHT / 2;

    xDir = round(robotCentreX + (ROBOT_WIDTH / 2) * cos((robot->angle) * PI / 180) - (-ROBOT_HEIGHT / 2) * sin((robot->angle) * PI / 180));
    yDir = round(robotCentreY + (ROBOT_WIDTH / 2) * sin((robot->angle) * PI / 180) + (-ROBOT_HEIGHT / 2) * cos((robot->angle) * PI / 180));
    xTR = (int)xDir;
    yTR = (int)yDir;

    xDir = round(robotCentreX + (ROBOT_WIDTH / 2) * cos((robot->angle) * PI / 180) - (ROBOT_HEIGHT / 2) * sin((robot->angle) * PI / 180));
    yDir = round(robotCentreY + (ROBOT_WIDTH / 2) * sin((robot->angle) * PI / 180) + (ROBOT_HEIGHT / 2) * cos((robot->angle) * PI / 180));
    xBR = (int)xDir;
    yBR = (int)yDir;

    xDir = round(robotCentreX + (-ROBOT_WIDTH / 2) * cos((robot->angle) * PI / 180) - (ROBOT_HEIGHT / 2) * sin((robot->angle) * PI / 180));
    yDir = round(robotCentreY + (-ROBOT_WIDTH / 2) * sin((robot->angle) * PI / 180) + (ROBOT_HEIGHT / 2) * cos((robot->angle) * PI / 180));
    xBL = (int)xDir;
    yBL = (int)yDir;

    xDir = round(robotCentreX + (-ROBOT_WIDTH / 2) * cos((robot->angle) * PI / 180) - (-ROBOT_HEIGHT / 2) * sin((robot->angle) * PI / 180));
    yDir = round(robotCentreY + (-ROBOT_WIDTH / 2) * sin((robot->angle) * PI / 180) + (-ROBOT_HEIGHT / 2) * cos((robot->angle) * PI / 180));
    xTL = (int)xDir;
    yTL = (int)yDir;

    SDL_RenderDrawLine(renderer, xTR, yTR, xBR, yBR);
    SDL_RenderDrawLine(renderer, xBR, yBR, xBL, yBL);
    SDL_RenderDrawLine(renderer, xBL, yBL, xTL, yTL);
    SDL_RenderDrawLine(renderer, xTL, yTL, xTR, yTR);

    // Front Right Sensor
    int sensor_sensitivity = floor(SENSOR_VISION / 5);
    int i;
    for (i = 0; i < 5; i++)
    {
        xDir = round(robotCentreX + (ROBOT_WIDTH / 2 - 2) * cos((robot->angle) * PI / 180) - (-ROBOT_HEIGHT / 2 - SENSOR_VISION + sensor_sensitivity * i) * sin((robot->angle) * PI / 180));
        yDir = round(robotCentreY + (ROBOT_WIDTH / 2 - 2) * sin((robot->angle) * PI / 180) + (-ROBOT_HEIGHT / 2 - SENSOR_VISION + sensor_sensitivity * i) * cos((robot->angle) * PI / 180));
        xTL = (int)xDir;
        yTL = (int)yDir;

        SDL_Rect rect = {xTL, yTL, 2, sensor_sensitivity};
        if (fr > 3)
        {
            SDL_SetRenderDrawColor(renderer, 220 + (20 * (5 - i)), 0 + (20 * (5 - i)), (20 * (5 - i)), 255);
        }
        else if (fr == 3)
        {
            SDL_SetRenderDrawColor(renderer, 200 + (20 * (5 - i)), 50 + (20 * (5 - i)), 10 + (20 * (5 - i)), 255);
        }
        else if (fr == 2)
        {
            SDL_SetRenderDrawColor(renderer, 170 + (20 * (5 - i)), 100 + (20 * (5 - i)), 50 + (20 * (5 - i)), 255);
        }
        else
        {
            SDL_SetRenderDrawColor(renderer, 150 + (20 * (5 - i)), 150 + (20 * (5 - i)), 80 + (20 * (5 - i)), 255);
        }
        SDL_RenderDrawRect(renderer, &rect);
        SDL_RenderFillRect(renderer, &rect);
    }

    // Front Left Sensor
    for (i = 0; i < 5; i++)
    {
        xDir = round(robotCentreX + (-ROBOT_WIDTH / 2) * cos((robot->angle) * PI / 180) - (-ROBOT_HEIGHT / 2 - SENSOR_VISION + sensor_sensitivity * i) * sin((robot->angle) * PI / 180));
        yDir = round(robotCentreY + (-ROBOT_WIDTH / 2) * sin((robot->angle) * PI / 180) + (-ROBOT_HEIGHT / 2 - SENSOR_VISION + sensor_sensitivity * i) * cos((robot->angle) * PI / 180));
        xTL = (int)xDir;
        yTL = (int)yDir;

        SDL_Rect rect = {xTL, yTL, 2, sensor_sensitivity};
        if (fl > 3)
        {
            SDL_SetRenderDrawColor(renderer, 220 + (20 * (5 - i)), 0 + (20 * (5 - i)), (20 * (5 - i)), 255);
        }
        else if (fl == 3)
        {
            SDL_SetRenderDrawColor(renderer, 200 + (20 * (5 - i)), 50 + (20 * (5 - i)), 10 + (20 * (5 - i)), 255);
        }
        else if (fl == 2)
        {
            SDL_SetRenderDrawColor(renderer, 170 + (20 * (5 - i)), 100 + (20 * (5 - i)), 50 + (20 * (5 - i)), 255);
        }
        else
        {
            SDL_SetRenderDrawColor(renderer, 150 + (20 * (5 - i)), 150 + (20 * (5 - i)), 80 + (20 * (5 - i)), 255);
        }
        SDL_RenderDrawRect(renderer, &rect);
        SDL_RenderFillRect(renderer, &rect);
    }

    // Left Sensor
    for (i = 0; i < 5; i++)
    {
        double x1 = (-ROBOT_WIDTH / 2 - SENSOR_VISION + sensor_sensitivity * i);
        double y1 = 0;
        xDir = round((robotCentreX + x1 * cos(robot->angle * PI / 180)) - y1 * sin(robot->angle * PI / 180));
        yDir = round((robotCentreY + x1 * sin(robot->angle * PI / 180)) + y1 * cos(robot->angle * PI / 180));
        xTL = (int)xDir;
        yTL = (int)yDir;
        SDL_Rect rect = {xTL, yTL, sensor_sensitivity, 2};
        if (l > 3)
        {
            SDL_SetRenderDrawColor(renderer, 220 + (20 * (5 - i)), 0 + (20 * (5 - i)), (20 * (5 - i)), 255);
        }
        else if (l == 3)
        {
            SDL_SetRenderDrawColor(renderer, 200 + (20 * (5 - i)), 50 + (20 * (5 - i)), 10 + (20 * (5 - i)), 255);
        }
        else if (l == 2)
        {
            SDL_SetRenderDrawColor(renderer, 170 + (20 * (5 - i)), 100 + (20 * (5 - i)), 50 + (20 * (5 - i)), 255);
        }
        else
        {
            SDL_SetRenderDrawColor(renderer, 150 + (20 * (5 - i)), 150 + (20 * (5 - i)), 80 + (20 * (5 - i)), 255);
        }
        SDL_RenderDrawRect(renderer, &rect);
        SDL_RenderFillRect(renderer, &rect);
    }
    // printf("left: %d %d\n", xTL, robotCentreX);

    // Right Sensor
    for (i = 0; i < 5; i++)
    {
        double x1 = (ROBOT_WIDTH / 2 + SENSOR_VISION - sensor_sensitivity * i);
        double y1 = 0;
        xDir = round((robotCentreX + x1 * cos(robot->angle * PI / 180)) - y1 * sin(robot->angle * PI / 180));
        yDir = round((robotCentreY + x1 * sin(robot->angle * PI / 180)) + y1 * cos(robot->angle * PI / 180));
        xTL = (int)xDir;
        yTL = (int)yDir;
        SDL_Rect rect = {xTL, yTL, sensor_sensitivity, 2};
        if (r > 3)
        {
            SDL_SetRenderDrawColor(renderer, 220 + (20 * (5 - i)), 0 + (20 * (5 - i)), (20 * (5 - i)), 255);
        }
        else if (r == 3)
        {
            SDL_SetRenderDrawColor(renderer, 200 + (20 * (5 - i)), 50 + (20 * (5 - i)), 10 + (20 * (5 - i)), 255);
        }
        else if (r == 2)
        {
            SDL_SetRenderDrawColor(renderer, 170 + (20 * (5 - i)), 100 + (20 * (5 - i)), 50 + (20 * (5 - i)), 255);
        }
        else
        {
            SDL_SetRenderDrawColor(renderer, 150 + (20 * (5 - i)), 150 + (20 * (5 - i)), 80 + (20 * (5 - i)), 255);
        }
        SDL_RenderDrawRect(renderer, &rect);
        SDL_RenderFillRect(renderer, &rect);
    }
    // printf("right: %d %d\n\n", xTL, robotCentreX);
}

void robotMotorMove(struct Robot *robot)
{
    double x_offset, y_offset;
    switch (robot->direction)
    {
    case UP:
        robot->currentSpeed += DEFAULT_SPEED_CHANGE;
        if (robot->currentSpeed > MAX_ROBOT_SPEED)
            robot->currentSpeed = MAX_ROBOT_SPEED;
        break;
    case DOWN:
        robot->currentSpeed -= DEFAULT_SPEED_CHANGE;
        if (robot->currentSpeed < -MAX_ROBOT_SPEED)
            robot->currentSpeed = -MAX_ROBOT_SPEED;
        break;
    case LEFT:
        robot->angle = (robot->angle + 360 - DEFAULT_ANGLE_CHANGE) % 360;
        break;
    case RIGHT:
        robot->angle = (robot->angle + DEFAULT_ANGLE_CHANGE) % 360;
        break;
    }
    robot->direction = 0;
    x_offset = (-robot->currentSpeed * sin(-robot->angle * PI / 180));
    y_offset = (-robot->currentSpeed * cos(-robot->angle * PI / 180));

    robot->true_x += x_offset;
    robot->true_y += y_offset;

    x_offset = round(robot->true_x);
    y_offset = round(robot->true_y);

    robot->x = (int)x_offset;
    robot->y = (int)y_offset;
}

void robotAutoMotorMove(struct Robot *robot, int front_left_sensor, int front_right_sensor, int left_sensor, int right_sensor, int *adjusted, int *atDeadEnd, int *searchingLeft)
{
    if (left_sensor < 1 && front_left_sensor == 0 && front_right_sensor == 0 && *adjusted % 2 == 0 && *searchingLeft < 24) // If we are not close to any wall, turn left every 5 loop
    {
        *searchingLeft += 1;
        robot->direction = LEFT;
    }
    else if (left_sensor > 3 && right_sensor > 3)
    {
        if (robot->currentSpeed < 2)
            robot->direction = UP;
    }
    else if (front_left_sensor == 0 && front_right_sensor == 0 && left_sensor <= 3) // If we do not have anything in front of us, move forward
    {
        if (left_sensor < 1 || right_sensor < 1)
        {
            if (robot->currentSpeed < 4)
                robot->direction = UP;
        }
        else
        {
            if (robot->currentSpeed < 3)
                robot->direction = UP;
        }
    }
    else if (front_left_sensor >= 1 || left_sensor > 1) // If we are too close to the left, turn right
    {
        printf("TOO CLOSE TO THE LEFT!!!! TURNING RIGHT!!!!\n");
        if (right_sensor < 3)
        {
            robot->direction = RIGHT;
        }
        else
        {
            if (robot->currentSpeed < 2)
                robot->direction = UP;
        }
    }
    else if (robot->currentSpeed > 0 && (front_left_sensor > 0 || front_right_sensor > 0)) // If we are moving and we are moving straight int a wall
    {
        robot->direction = DOWN;
    }
    else if (front_left_sensor == 1 && left_sensor == 1) // Close to ideal position, move forward
    {
        robot->direction = UP;
    }
    else if (front_right_sensor > 1 || right_sensor > 1) // If we are to close to the right, turn left
    {
        if (left_sensor < 3)
        {
            robot->direction = LEFT;
        }
        else
        {
            if (robot->currentSpeed < 2)
                robot->direction = UP;
        }
    }
    else
    {
        robot->direction = UP;
    }
    int frontSensitivity = 2;
    if (robot->currentSpeed > 2)
    {
        frontSensitivity = 1;
    }
    if (front_right_sensor > frontSensitivity && front_left_sensor > frontSensitivity)
    {
        if (robot->currentSpeed > -2)
            robot->direction = DOWN;
    }

    if (front_left_sensor > 0 || front_right_sensor > 0 || left_sensor > 0 || right_sensor > 0) // Reset searching for walls at the left
    {
        *searchingLeft = 0;
    }

    if ((front_left_sensor >= 1 && front_right_sensor >= 1 && left_sensor >= 1 && right_sensor >= 1) || *atDeadEnd == 1)
    {
        printf("AT DEADEND... REVERSING\n");
        *atDeadEnd = 1;
        if (robot->currentSpeed > -4)
        {
            printf("SLOWING DOWN... %d\n", robot->currentSpeed);
            robot->direction = DOWN;
        }
        else
        {
            robot->direction = UP;
        }

        if (left_sensor <= 0 || right_sensor <= 0)
        {
            if (robot->currentSpeed < 0)
            {
                robot->direction = UP;
            }
            else
            {
                if (left_sensor <= 0)
                {
                    *atDeadEnd = 2;
                }
                else if (right_sensor <= 0)
                {
                    *atDeadEnd = 3;
                }
                *adjusted = 0;
            }
        }
    }
    if (*atDeadEnd > 1)
    {
        if (*atDeadEnd == 2 && *adjusted < 6)
        {
            robot->direction = LEFT;
            printf("ADJUSTED %d, TURNING LEFT BECAUSE OF DEADEND\n", *adjusted);
        }
        else if (*atDeadEnd == 3 && *adjusted < 6)
        {
            robot->direction = RIGHT;
            printf("ADJUSTED %d, TURNING RIGHT BECAUSE OF DEADEND\n", *adjusted);
        }
        else if (*adjusted < 8)
        {
            robot->direction = UP;
        }
        else
        {
            *atDeadEnd = 0;
        }
    }
    *adjusted += 1;

    // printf("LEFT IS %d\n", left_sensor);
}
