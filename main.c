#include "raylib.h"
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define screenHeight 700
#define screenWidth 1000



typedef struct Object {
    float mass;
    float initialVelocity;
    float finalVelocity;
    Vector2 dem;
    Vector2 position;
    Color color;
} Object;


void draw(){
    
}

/*
bool update(Weight *weights, bool first)
{  
    char *new;
    if(first == false){
         new = "new ";
    } else {new = "";}
    
    for(int i = 0; i < 3; i++){
        char term;
        
        printf("Mass of %sweight #%d (Grams): ", new, i+1);
        if(scanf("%f%c", &weights[i].mass, &term) != 2 || term != '\n'){
            printf("invalid\n");
            return false;
        }
        
        printf("Angle of %sweight #%d (Degrees) : ", new, i+1);
        if(scanf("%f%c", &weights[i].theta, &term) != 2 || term != '\n'){
            printf("invalid\n");
            return false;
        }
        
        weights[i].theta *= (-PI/180);
    }
    return true;
}
//Function to compute the 4th weight values
void calculateFourth(Weight *weights){
  
}
*/

void add(Object *obj, Vector2 d, float p, int m, int v, Color c){
    obj->dem = d;
    obj->position = (Vector2){p, screenHeight - 200 - obj->dem.y};
    obj->mass = m;
    obj->initialVelocity = v;
    obj->color = c;
}

void drawObj(Object *obj){
    DrawRectangle(obj->position.x, obj->position.y, obj->dem.x, obj->dem.y, BLUE);
    DrawRectangleLines(obj->position.x, obj->position.y, obj->dem.x, obj->dem.y, BLACK);
    
    
}

int main(void)
{
    //const int screenWidth = 1000;
    //const int screenHeight = 700;
    
    //&scene.obj1.mass;
  
    Object obj1; 
    add(&obj1, (Vector2){100, 100}, 6, 10, 6, RED);
    
    Object obj2; 
    add(&obj2, (Vector2){100, 100}, 540, 10, .3, BLUE);
    
    
    
   /* Object obj1;
    obj1.dem = (Vector2){100, 100};
    obj1.position = (Vector2){6.0, screenHeight - 200 - obj1.dem.y};
    obj1.mass = 10;
    obj1.initialVelocity = 6;*/
    
   
    InitWindow(screenWidth, screenHeight, "Conservation of Momentum");

    
    
   
    

	
    SetTargetFPS(60);  
    while (!WindowShouldClose())    
    {  
        BeginDrawing();

            ClearBackground(RAYWHITE);
            
              DrawLine(0, screenHeight-200, screenWidth, screenHeight-200, BLACK);
              DrawRectangle(0, screenHeight - 200, screenWidth, 200, RED);
                
              
              drawObj(&obj1);
              drawObj(&obj2);
              
              obj1.position.x++;
              
              
        EndDrawing();
    }
    
    CloseWindow();       

    return 0;
}

