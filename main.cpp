#include "raylib.h"

int main() {

    const int winHeight {550};
    const int winWidth {900};

    InitWindow(winWidth, winHeight, "Dapper Dasher");

    //acceleration due to gravity (pixels/sec)/sec
    const float gravity {1'500.00};

    //Scarfy sprite variables
    Texture2D scarfy;
    scarfy = LoadTexture("../textures/scarfy.png");
    Rectangle scarfyRec;
    scarfyRec.width = scarfy.width/6;
    scarfyRec.height = scarfy.height;
    scarfyRec.x = 0;
    scarfyRec.y = 0;
    Vector2 scarfyPosition;
    scarfyPosition.x = winWidth/2 - scarfyRec.width/2;
    scarfyPosition.y = winHeight - scarfyRec.height;
    int scarfyFrame {};

    //nebula sprite vars
    Texture2D nebula = LoadTexture("../textures/12_nebula_spritesheet.png");
    Rectangle nebRec;
    nebRec.width = nebula.width/8;
    nebRec.height = nebula.height/8;
    nebRec.x = 0;
    nebRec.y = 0;
    Vector2 nebPosition;
    nebPosition.x = winWidth - nebRec.width;
    nebPosition.y = winHeight - nebRec.height;


    //amount of time before updating animation frame
    const float updateTime {1.0 / 12.0};
    float runningTime {};

    float velocity {0.00};

    bool isInAir {false};

    //pixels per second
    const float jumpVelocity {-600.00};

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        //delta time (time since last frame)
        const float dT {GetFrameTime()};

        BeginDrawing();
        ClearBackground(WHITE);
        isInAir = false;


        if (scarfyPosition.y >= winHeight - scarfyRec.height) {
            velocity = 0;
        } else {
            velocity += gravity * dT;
            isInAir = true;
        }

        if (IsKeyPressed(KEY_SPACE) && !isInAir) {
            velocity += jumpVelocity;
        }

        scarfyPosition.y += velocity * dT;

        //update running time
        runningTime += dT;
        if (runningTime >= updateTime) {
            runningTime = 0;
            //update animation frame
            scarfyRec.x = scarfyFrame * scarfyRec.width;
            scarfyFrame++;
            if (scarfyFrame > 5)
                scarfyFrame = 0;
        }

        DrawTextureRec(scarfy, scarfyRec, scarfyPosition, WHITE);
        DrawTextureRec(nebula, nebRec, nebPosition, WHITE);

        EndDrawing();
    }
    UnloadTexture(nebula);
    UnloadTexture(scarfy);
    CloseWindow();
    return 0;
}
