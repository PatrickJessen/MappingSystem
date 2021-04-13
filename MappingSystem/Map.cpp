#include "Map.h"
#include <iostream>
Map::Map(Window* window, const char* path)
{
    this->window = window;

    std::ifstream fs(path, std::ifstream::in);
    for (int r = 0; r < kRow; r++) {
        for (int c = 0; c < kCol; c++) {
            fs >> level[r][c];
            /*std::cout << r << " " << c << "\n";*/
        }
    }
}

Map::~Map()
{
}


void Map::LoadMap(Window* window, Sprite* sprite)
{
    for (int i = 0; i < kRow; ++i) {
        for (int j = 0; j < kCol; ++j) {
            // Min tile position
            dstRect = { j * tileSize, i * tileSize, tileSize, tileSize };
            // tilenummer fra txt filen
            srcRect = { level[i][j] * tileSize, 0, tileSize, tileSize };
            if (level[i][j] == 1)
            {
                SDL_RenderCopy(window->GetRender(), sprite->tex, &srcRect, &dstRect);
            }
        }
    }
}

SDL_Texture* Map::loadTexture(SDL_Renderer* renderer, const char* filePath)
{
    SDL_Surface* surface(SDL_LoadBMP(filePath));
    if (surface) {
        SDL_Texture* texture(SDL_CreateTextureFromSurface(renderer, surface));
        if (texture) {
            printf("Texture loaded successfully: %s\n", filePath);
            return texture;
        }
        printf("Failed to create texture: %s\n", filePath);
        return nullptr;
    }
    printf("Cannot find texture file: %s\n", filePath);
    return nullptr;
}