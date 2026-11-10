#include <iostream>
#include <raylib.h>

int main(void) {
    const int screenWidth = 800;
    const int screenHeight = 450;
    const char *FpsText = 0;
    const char *FtText = 0;
    const char *FpsTargetText = 0;
    const char speed = 15.0f;
    bool DebugMode = false;
    bool DebugPrint = true;
    int currentFps = 60;

    Vector2 playerPosition = { (float)screenWidth/2, (float)screenHeight/2};

    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(screenWidth, screenHeight, "Grit InDev");

    SetTargetFPS(currentFps);

    std::cout << "[DEBUG] Window Created\n";

    while (!WindowShouldClose()) {
        float mouseWheel = GetMouseWheelMove();

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

        if (IsKeyDown(KEY_D)) playerPosition.x += GetFrameTime()*6.0f*speed;
        if (IsKeyDown(KEY_A)) playerPosition.x -= GetFrameTime()*6.0f*speed;
        if (IsKeyDown(KEY_W)) playerPosition.y -= GetFrameTime()*6.0f*speed;
        if (IsKeyDown(KEY_S)) playerPosition.y += GetFrameTime()*6.0f*speed;
        if (IsKeyDown(KEY_RIGHT)) playerPosition.x += GetFrameTime()*6.0f*speed;
        if (IsKeyDown(KEY_LEFT)) playerPosition.x -= GetFrameTime()*6.0f*speed;
        if (IsKeyDown(KEY_UP)) playerPosition.y -= GetFrameTime()*6.0f*speed;
        if (IsKeyDown(KEY_DOWN)) playerPosition.y += GetFrameTime()*6.0f*speed;

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
            FpsTargetText = TextFormat("FPS Target: %i", currentFps);
            DrawText(FpsText, 7, 19, 15, LIGHTGRAY);
            DrawText(FtText, 7, 31, 15, LIGHTGRAY);
            DrawText(FpsTargetText, 7, 43, 15, LIGHTGRAY);

            if (mouseWheel != 0) {
                currentFps += (int)mouseWheel;
                if (currentFps < 0) currentFps = 0;
                SetTargetFPS(currentFps);
            }

            
        }

        DrawCircleV(playerPosition, 20, BLUE);


        EndDrawing();
    }
    CloseWindow();
    return 0;

}