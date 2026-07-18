import pygame
import math

class Chest:

    OPEN_DISTANCE = 26  # distance (en pixels) à laquelle le joueur déclenche l'ouverture

    def __init__(self, x, y, spritesheet):
        self.x = x
        self.y = y
        self.frames = self._load_frames(spritesheet)
        self.state = 'closed'  # closed -> opening -> open
        self.frame_index = 0
        self.timer = 0
        self.counted = False  # évite de compter le même coffre deux fois dans le score

    def _load_frames(self, spritesheet):
        frames = []
        for col in range(3):
            rect = pygame.Rect(col * 32, 0, 32, 32)
            frame = spritesheet.subsurface(rect)
            frame = pygame.transform.scale(frame, (48, 48))
            frames.append(frame)
        return frames

    def update(self, dt, player_pos):
        if self.state == 'open':
            return

        distance = math.hypot(player_pos[0] - self.x, player_pos[1] - self.y)
        if self.state == 'closed' and distance < self.OPEN_DISTANCE:
            self.state = 'opening'

        if self.state == 'opening':
            self.timer += dt
            if self.timer >= 0.15:
                self.timer = 0
                self.frame_index += 1
                if self.frame_index >= len(self.frames) - 1:
                    self.frame_index = len(self.frames) - 1
                    self.state = 'open'

    def just_opened(self):
        # renvoie True une seule fois, au moment où le coffre vient d'être ouvert
        if self.state == 'open' and not self.counted:
            self.counted = True
            return True
        return False

    def draw(self, surface, screen_pos):
        frame = self.frames[self.frame_index]
        pos = (screen_pos[0] - frame.get_width() // 2, screen_pos[1] - frame.get_height() // 2)
        surface.blit(frame, pos)
