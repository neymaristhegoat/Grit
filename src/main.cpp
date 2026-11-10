#include <iostream>
#include <raylib.h>

int main(void) {
    const int screenWidth = 800;
    const int screenHeight = 450;
    const char *FpsText = 0;
    const char *FtText = 0;
    bool DebugMode = false;
    bool DebugPrint = true;
    float deltaTime = GetFrameTime();

    Vector2 playerPosition = { (float)screenWidth/2, (float)screenHeight/2};

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

        if (IsKeyDown(KEY_D)) playerPosition.x += 2.0f;
        if (IsKeyDown(KEY_A)) playerPosition.x -= 2.0f;
        if (IsKeyDown(KEY_W)) playerPosition.y -= 2.0f;
        if (IsKeyDown(KEY_S)) playerPosition.y += 2.0f;
        if (IsKeyDown(KEY_RIGHT)) playerPosition.x += 2.0f;
        if (IsKeyDown(KEY_LEFT)) playerPosition.x -= 2.0f;
        if (IsKeyDown(KEY_UP)) playerPosition.y -= 2.0f;
        if (IsKeyDown(KEY_DOWN)) playerPosition.y += 2.0f;

        BeginDrawing();

        ClearBackground(RAYWHITE);
        DrawText("Grit InDev Test", 7, 7, 15, LIGHTGRAY);


        if (DebugMode) {
            if (DebugPrint) {
                std::cout << "[DEBUG] DebugMode on\n";
                DebugPrint = false;
            }
            FpsText = TextFormat("FPS: %i", GetFPS());
            FtText = TextFormat("Frame Time: %i", GetFrameTime());
            DrawText(FpsText, 7, 19, 15, LIGHTGRAY);
            DrawText(FtText, 7, 31, 15, LIGHTGRAY);
            
        }

        DrawCircleV(playerPosition, 20, BLUE);


        EndDrawing();
    }
    CloseWindow();
    return 0;

}