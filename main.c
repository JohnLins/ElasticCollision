#include "raylib.h"
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>




typedef struct Object {
    float mass;
    float initialVelocity;
    float finalVelocity;
    Vector2 dem;
    Vector2 position;
} Object;

struct Scene {
    Object obj1;
    Object obj2;
} scene;


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
int main(void)
{
    const int screenWidth = 1000;
    const int screenHeight = 700;
    
    //&scene.obj1.mass;
  
    Object mine;
    mine.dem = (Vector2){100, 100};
    mine.position = (Vector2){6.0, screenHeight - 200 - mine.dem.y};
    mine.mass = 10;
    mine.initialVelocity = 6;
    
    
   
    InitWindow(screenWidth, screenHeight, "Conservation of Momentum");

    
    
   
    

	
    SetTargetFPS(60);  
    while (!WindowShouldClose())    
    {  
        BeginDrawing();

            ClearBackground(RAYWHITE);
            
              DrawLine(0, screenHeight-200, screenWidth, screenHeight-200, BLACK);
              DrawRectangle(0, screenHeight - 200, screenWidth, 200, RED);
                
              DrawRectangle(mine.position.x, mine.position.y, mine.dem.x,mine.dem.y , BLUE);
              DrawRectangleLines(mine.position.x, mine.position.y, mine.dem.x,mine.dem.y, BLACK);
              
              
              mine.position.x++;
              
        EndDrawing();
    }
    
    CloseWindow();       

    return 0;
}

