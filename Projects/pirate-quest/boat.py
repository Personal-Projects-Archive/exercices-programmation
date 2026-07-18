import pygame
import math

class Boat:

    BOARD_DISTANCE = 40  # distance (en pixels) à laquelle le joueur peut embarquer

    def __init__(self, x, y, spritesheet):
        frame = spritesheet.subsurface(pygame.Rect(0, 0, 32, 32))
        self.frame = pygame.transform.scale(frame, (48, 48))
        self.frame_flipped = pygame.transform.flip(self.frame, True, False)
        self.x = x
        self.y = y
        self.occupied = False  # True quand le joueur est actuellement à son bord

    def is_near(self, position):
        distance = math.hypot(position[0] - self.x, position[1] - self.y)
        return distance < self.BOARD_DISTANCE

    def draw(self, surface, screen_pos, facing_left=False):
        frame = self.frame_flipped if facing_left else self.frame
        pos = (screen_pos[0] - frame.get_width() // 2, screen_pos[1] - frame.get_height() // 2)
        surface.blit(frame, pos)
