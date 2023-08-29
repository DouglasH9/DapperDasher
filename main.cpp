#include <iostream>
#include "raylib.h"

int main() {

    const int winHeight {900};
    const int winWidth {1300};

    InitWindow(winWidth, winHeight, "Dapper Dasher");

    //acceleration due to gravity (pixels/frame)/frame
    const int gravity {1};

    //rectangle dims
    const int recWidth {50};
    const int recHeight {80};

    int posY {winHeight - recHeight};
    int velocity {0};

    bool isInAir {false};

    const int jumpVelocity {-22};

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(WHITE);
        isInAir = false;

        if (posY >= winHeight - recHeight) {
            velocity = 0;
        } else {
            velocity += gravity;
            isInAir = true;
        }

        if (IsKeyPressed(KEY_SPACE) && !isInAir) {
            velocity += jumpVelocity;
        }

        posY += velocity;

        DrawRectangle(winWidth/2, posY, recWidth, recHeight, BLUE);

        EndDrawing();
    }
    CloseWindow();
    return 0;
}
