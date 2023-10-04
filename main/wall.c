#include "wall.h"

void wallSetPosition(struct Wall * wall, int x, int y, int width, int height) {
    wall->x = x;
    wall->y = y;
    wall->width = width;
    wall->height = height;
}

void wallUpdate(SDL_Renderer * renderer, struct Wall * wall){
    SDL_Rect rect = {wall->x, wall->y, wall->width, wall->height};
    SDL_SetRenderDrawColor(renderer, 149, 62, 19, 255);
    SDL_Rect red;
    SDL_Rect black;
    if (wall->height >= wall->width){
    	for (int i = 0; i < wall->height; i+=10){
    		SDL_SetRenderDrawColor(renderer, 149, 62, 19, 255);
    		red.x = wall->x;
    		red.y = wall->y+i;
    		red.w = wall->width;
    		red.h = 8;
    		//SDL_Rect red = {wall->x, (wall->y)+i, wall->width, 8};
    		SDL_RenderFillRect(renderer, &red);
    		SDL_RenderDrawRect(renderer, &red);
    		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    		black.x = wall->x;
    		black.y = wall->y+i+8;
    		black.w = wall->width;
    		black.h = 2;
    		//SDL_Rect black = {wall->x, (wall->y)+i+8, wall->width, 2};
    		SDL_RenderFillRect(renderer, &black);
    		SDL_RenderDrawRect(renderer, &black);
    	}
    } else{
    	for (int i = 0; i < wall->width; i+=10){
    		SDL_SetRenderDrawColor(renderer, 149, 62, 19, 255);
    		red.x = wall->x+i;
    		red.y = wall->y;
    		red.w = 8;
    		red.h = wall->height;
    		//SDL_Rect red = {(wall->x)+i, wall->y, 8, wall->height};
    		SDL_RenderFillRect(renderer, &red);
    		SDL_RenderDrawRect(renderer, &red);
    		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    		black.x = wall->x+i+8;
    		black.y = wall->y;
    		black.w = 2;
    		black.h = wall->height;
    		//SDL_Rect black = {(wall->x)+i+8, wall->y, 2, wall->height};
    		SDL_RenderFillRect(renderer, &black);
    		SDL_RenderDrawRect(renderer, &black);
    	}
    }
    //SDL_RenderFillRect(renderer, &rect);
    //SDL_RenderDrawRect(renderer, &rect);
}

//insert link at the first location
void insertFirstWall(struct Wall_collection ** head, int key, struct Wall * wall) {
   //create a link
   struct Wall_collection *link = (struct Wall_collection*) malloc(sizeof(struct Wall_collection));

   link->key = key;
   link->wall = *wall;

   //point it to old first node
   link->next = *head;

   //point first to new first node
   *head = link;
}

void insertAndSetFirstWall(struct Wall_collection ** head, int key, int x, int y, int width, int height){
   //create a link
   struct Wall *wall = (struct Wall*) malloc(sizeof(struct Wall));
   wallSetPosition(wall, x, y, width, height);
   insertFirstWall(head, key, wall);

}

void updateAllWalls(struct Wall_collection * head, SDL_Renderer * renderer) {
   struct Wall_collection *ptr = head;

   //start from the beginning
   while(ptr != NULL) {
      //printf("(%d)",ptr->key);
      wallUpdate(renderer, &ptr->wall);
      ptr = ptr->next;
   }

}
