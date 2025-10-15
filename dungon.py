import pygame
import random
import asyncio
import platform

# Initialize Pygame
pygame.init()
FPS = 60

# Screen settings
SCREEN_WIDTH = 800
SCREEN_HEIGHT = 600
TILE_SIZE = 32
screen = pygame.display.set_mode((SCREEN_WIDTH, SCREEN_HEIGHT))
pygame.display.set_caption("Dungeon RPG")

# Colors
WHITE = (255, 255, 255)
BLACK = (0, 0, 0)
RED = (255, 0, 0)
GREEN = (0, 255, 0)

# Dungeon map (0: floor, 1: wall)
dungeon_map = [
    [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1],
    [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1],
    [1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1],
    [1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1],
    [1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 0, 1],
    [1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 1],
    [1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 1],
    [1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1],
    [1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 0, 1],
    [1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1],
    [1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1],
    [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1],
    [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1]
]

# Player settings
player = {
    "x": 2 * TILE_SIZE,
    "y": 2 * TILE_SIZE,
    "health": 100,
    "attack": 10
}

# Enemy settings
enemies = [
    {"x": 10 * TILE_SIZE, "y": 5 * TILE_SIZE, "health": 50, "attack": 5},
    {"x": 15 * TILE_SIZE, "y": 8 * TILE_SIZE, "health": 50, "attack": 5}
]

# Clock for frame rate
clock = pygame.time.Clock()

def draw_map():
    for y, row in enumerate(dungeon_map):
        for x, tile in enumerate(row):
            if tile == 1:
                pygame.draw.rect(screen, WHITE, (x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, TILE_SIZE))
            else:
                pygame.draw.rect(screen, BLACK, (x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, TILE_SIZE))

def draw_player():
    pygame.draw.rect(screen, GREEN, (player["x"], player["y"], TILE_SIZE, TILE_SIZE))

def draw_enemies():
    for enemy in enemies:
        if enemy["health"] > 0:
            pygame.draw.rect(screen, RED, (enemy["x"], enemy["y"], TILE_SIZE, TILE_SIZE))

def move_player(dx, dy):
    new_x = player["x"] + dx * TILE_SIZE
    new_y = player["y"] + dy * TILE_SIZE
    map_x = new_x // TILE_SIZE
    map_y = new_y // TILE_SIZE
    if 0 <= map_x < len(dungeon_map[0]) and 0 <= map_y < len(dungeon_map) and dungeon_map[map_y][map_x] == 0:
        player["x"] = new_x
        player["y"] = new_y

def check_collision():
    for enemy in enemies:
        if enemy["health"] > 0 and player["x"] == enemy["x"] and player["y"] == enemy["y"]:
            player["health"] -= enemy["attack"]
            enemy["health"] -= player["attack"]
            if player["health"] <= 0:
                return False
    return True

async def main():
    running = True
    while running:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False
        keys = pygame.key.get_pressed()
        if keys[pygame.K_LEFT]:
            move_player(-1, 0)
        if keys[pygame.K_RIGHT]:
            move_player(1, 0)
        if keys[pygame.K_UP]:
            move_player(0, -1)
        if keys[pygame.K_DOWN]:
            move_player(0, 1)
        
        if not check_collision():
            running = False

        screen.fill(BLACK)
        draw_map()
        draw_enemies()
        draw_player()
        pygame.display.flip()
        clock.tick(FPS)
        await asyncio.sleep(1.0 / FPS)

    pygame.quit()

if platform.system() == "Emscripten":
    asyncio.ensure_future(main())
else:
    if __name__ == "__main__":
        asyncio.run(main())
