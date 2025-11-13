#include <raylib.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct {
  Vector2* arr;
  size_t size;
} vector2_data;


vector2_data* val_cos(float steps, float start) {
  
    size_t size = (int)(2*M_PI/steps*2)+1;
    Vector2* arr = (Vector2*) malloc(sizeof(Vector2) * size);

    int c = 0;
    for (float x = (-2*M_PI); x <= 2*M_PI; x += steps) {
      float y = cosf(x + start);
      Vector2 point = { x, y };
      arr[c] = point;
      c++;
    }

    vector2_data* data = (vector2_data*) malloc(sizeof(vector2_data));
    data->arr = arr;
    data->size = size;

    return data;
}

vector2_data* val_sin(float steps, float start) {
  
    size_t size = (int)(2*M_PI/steps*2)+1;
    Vector2* arr = (Vector2*) malloc(sizeof(Vector2) * size);

    int c = 0;
    for (float x = (-2*M_PI); x <= 2*M_PI; x += steps) {
      float y = sinf(x + start);
      Vector2 point = { x, y };
      arr[c] = point;
      c++;
    }

    vector2_data* data = (vector2_data*) malloc(sizeof(vector2_data));
    data->arr = arr;
    data->size = size;

    return data;
}


void draw_vector2_data(vector2_data* v, float radius, Color color, int screenWidth, int screenHeight, int scalar) {
  
  for (int i = 0; i < v->size; i++) {

    float x = screenWidth/2 + (v->arr[i].x * scalar);
    float y = screenHeight/2 + (v->arr[i].y * scalar);

    DrawCircle(x, y, radius, color);
  }

}


int main() {

      // Initialization:
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1080;
    const int screenHeight = 720;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - input keys");

    Vector2 ballPosition = { (float)screenWidth/2, (float)screenHeight/2 };

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second


    //--------------------------------------------------------------------------------------
  
    int size = 50;
    int cycle = 1;
    float start = 0.1;

    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
      ClearBackground(BLACK);
        
        DrawLine(50, screenHeight / 2, screenWidth - 50, screenHeight / 2, WHITE); 
        DrawLine(screenWidth / 2, 50, screenWidth / 2, screenHeight - 50, WHITE); 
        draw_vector2_data(val_cos(0.001, start), 5, RED, screenWidth, screenHeight, 75);
        draw_vector2_data(val_sin(0.001, start), 5, BLUE, screenWidth, screenHeight, 75);
        start += 0.1;
      EndDrawing();
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------



  printf("Hello world!");
  return 0;
}
