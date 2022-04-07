#pragma once

struct PlayerCoords {
    int x;
    int y;
} playerCoords;

void movePlayerToLeft() {
    playerCoords.x -= 10;
}

void movePlayerToRight() {
    playerCoords.x += 10;
}