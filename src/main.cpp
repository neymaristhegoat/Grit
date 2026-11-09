#include <iostream>
#include <raylib.h>

int main(void) {
    const int screenWidth = 800;
    const int screenHeight = 450;
    bool DebugMode = false;
    bool DebugPrint = true;

    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(screenWidth, screenHeight, "Grit InDev");

    SetTargetFPS(60);

    std::cout << "[DEBUG] Window Created\n";

    while (!WindowShouldClose()) {
        if (IsKeyPressed(KEY_F11)) ToggleFullscreen();
        if (IsKeyPressed(KEY_F2)) {
            if (!DebugMode) {
                DebugMode = true;
                DebugPrint = true;
            }
            else {
                DebugMode = false;
            }

        }

        if (DebugMode) {
            if (DebugPrint) {
                std::cout << "[DEBUG] DebugMode on\n";
                DebugPrint = false;
            }
        }


        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Grit InDev Test", 7, 7, 15, LIGHTGRAY);
        EndDrawing();
    }
    CloseWindow();
    return 0;

}