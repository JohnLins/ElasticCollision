#include "raylib.h"
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define screenHeight 700
#define screenWidth 1500
#define PLATFORMHEIGHT 200



typedef struct Object {
    float mass;
    float velocity;
    float finalVelocity;
    Vector2 dim;
    Vector2 position;
    Color color;
} Object;


void update(Object *obj, char* num, Color color)
{  
    printf("%s | mass: ", num);
    scanf("%f", &obj->mass);
    
    obj->dim = (Vector2){obj->mass * 5, obj->mass * 5};
    float xpos;
    printf("%s | x Position: ", num);
    scanf("%f", &xpos);
    obj->position = (Vector2){xpos, screenHeight - PLATFORMHEIGHT - obj->dim.y};
    
   
    
    printf("%s | V_i: ", num);
    scanf("%f", &obj->velocity);
    
    obj->color = color;  
   
}




void add(Object *obj, float p, int m, int v, Color c){
    obj->dim = (Vector2){m*5, m*5};
    obj->position = (Vector2){p, screenHeight - PLATFORMHEIGHT - obj->dim.y};
    obj->mass = m;
    obj->velocity = v;
    obj->color = c;
}

void drawObj(Object *obj){
    DrawRectangle(obj->position.x, obj->position.y, obj->dim.x, obj->dim.y, obj->color);
    DrawRectangleLines(obj->position.x, obj->position.y, obj->dim.x, obj->dim.y, BLACK);
    
    obj->position.x += obj->velocity;
    
}

void calulate(Object *obj1, Object *obj2){
    float cons = ( (obj1->velocity * obj1->mass) + (obj2->velocity * obj2->mass) ) / obj2->mass;
    float v1fco = ((obj1->mass)) / obj2->mass;
    //make negative to be elastic float v1fco = (-(obj1->mass)) / obj2->mass;
    //v_2_f = ((v_1_i*m_1)+(v_2_i*m_2))/m_2 - (m_1 / m_2)v_1_f
    
    
    
    obj1->finalVelocity = (cons + obj2->velocity - obj1->velocity) / (1 + v1fco);
    obj2->finalVelocity = cons - (v1fco * obj1->finalVelocity);
}


int main(void)
{ 
    Object obj1; 
    //add(&obj1, 6, 25, 5, PURPLE);
    
    Object obj2; 
    //add(&obj2, 450, 10, 3, BLUE);
    
    update(&obj1, "1", PURPLE);
    update(&obj2, "2", BLUE);


    Object backups[2] = {obj1, obj2};
    
    
    
    
   
    InitWindow(screenWidth, screenHeight, "Elastic Collision - Conservation of Momentum");

    
    InitAudioDevice();
    Sound collisionSound = LoadSound("collisonSound.wav");
    SetSoundVolume(collisionSound, 0.6f);
    SetSoundPitch(collisionSound, 0.01f);
   
   
        
    Color background = RAYWHITE;
	
    SetTargetFPS(60);  
    while (!WindowShouldClose())    
    {  
        BeginDrawing();

            ClearBackground(background);
            //GetColor(15793919)
            
              DrawLine(0, screenHeight-PLATFORMHEIGHT, screenWidth, screenHeight-PLATFORMHEIGHT, BLACK);
              DrawRectangle(0, screenHeight - PLATFORMHEIGHT, screenWidth, PLATFORMHEIGHT, RED);
                


                if(IsKeyDown(KEY_DOWN)){
                    obj1 = backups[0];
                    obj2 = backups[1];
                    background = RAYWHITE;
                }
               
               
                  DrawText(FormatText("v_1: %f", obj1.velocity), 10, 10, 30, BLACK);
                  DrawText(FormatText("v_2: %f", obj2.velocity), 400, 10, 30, BLACK);
                  DrawText(FormatText("x_1: %f", obj1.position.x), 10, 70, 30, BLACK);
                  DrawText(FormatText("x_2: %f", obj2.position.x), 400, 70, 30, BLACK);
                  
                  DrawText("Down Arrow to Reset", 10, screenHeight - 50, 15, RAYWHITE);
                  
               
              
              
              drawObj(&obj1);
              drawObj(&obj2);
              
              if( ((obj1.position.x + obj1.dim.x) >= (obj2.position.x))  ){
                  calulate(&obj1, &obj2);
                  printf("X");
                  background = LIGHTGRAY;
            
                  PlaySoundMulti(collisionSound);
                  obj1.velocity = obj1.finalVelocity;
                  obj2.velocity = obj2.finalVelocity;
              }
              
              
        EndDrawing();
    }
    
    CloseWindow();       

    return 0;
}

