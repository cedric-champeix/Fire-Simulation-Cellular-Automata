#
# Cédric Champeix
#

import pygame
import map
import time

CELL_SIZE = 4


def run_iteration(i, my_map, screen):
    if i < map.NB_MAP:
        screen.fill((0, 0, 0))  # Clear the screen
        grid = my_map.update(i)

        # Draw the board
        for row in range(my_map.map_size):
            for col in range(my_map.map_size):
                match grid[row][col]:
                    case 0:
                        color = (255, 255, 0)
                    case 1:
                        color = (0, 255, 0)
                    case 2:
                        color = (105, 105, 105)
                    case 3:
                        color = (255, 0, 0)
                pygame.draw.rect(screen, color, (col * CELL_SIZE, row * CELL_SIZE, CELL_SIZE, CELL_SIZE))

        pygame.display.update()
        i += 1


def main():
    my_map = map.Map()

    pygame.init()
    display_size = (CELL_SIZE * my_map.map_size, CELL_SIZE * my_map.map_size)
    screen = pygame.display.set_mode(display_size)
    pygame.display.set_caption("Fire evolution")

    i = 0
    running = True
    while running:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False

        keys=pygame.key.get_pressed()
        if keys[pygame.K_LEFT] and i > 0:
            i -= 1
            run_iteration(i, my_map, screen)
        elif keys[pygame.K_RIGHT] and i < map.NB_MAP:
            i += 1
            run_iteration(i, my_map, screen)


        time.sleep(0.1)

    # Quit pygame
    pygame.quit()


if __name__ == '__main__':
    main()
