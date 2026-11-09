#include <iostream>
#include <raylib.h>

int main(void) {
    const int screenWidth = 800;
    const int screenHeight = 450;

    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(screenWidth, screenHeight, "Grit InDev");

    SetTargetFPS(60);

    std::cout << "[DEBUG] Window Created";

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Grit InDev Test", 7, 7, 15, LIGHTGRAY);
        EndDrawing();
    }
    CloseWindow();
    return 0;

}