import pygame

class Player:

    def __init__(self, x, y):
        self.frame_size = 32
        self.size = 64  # taille affichée à l'écran (sprite d'origine agrandi x2)

        self.spritesheet = pygame.image.load('assets/spritesheets/characters.png').convert_alpha()

        # la feuille de sprites ne contient qu'un cycle de marche vers le bas et un vers le haut,
        # donc gauche/droite réutilisent le cycle "bas" en le retournant (miroir horizontal)
        self.frames_down = self._load_frames(row=1, columns=3)
        self.frames_up = self._load_frames(row=2, columns=4)
        self.frames_left = [pygame.transform.flip(frame, True, False) for frame in self.frames_down]
        self.frames_right = self.frames_down

        self.animations = {
            'down': self.frames_down,
            'up': self.frames_up,
            'left': self.frames_left,
            'right': self.frames_right,
        }

        self.x = x
        self.y = y
        self.direction = 'down'
        self.moving = False
        self.mode = 'foot'  # 'foot' à pied, 'boat' en mer
        self.frame_index = 0
        self.animation_timer = 0
        self.animation_speed = 0.12  # secondes entre deux images du cycle de marche

        self.walk_speed = 140  # pixels par seconde, à pied
        self.boat_speed = 110  # pixels par seconde, en bateau
        self.last_water_position = (x, y)  # dernière position en mer avant d'accoster (pour laisser le bateau dans l'eau)

    def _load_frames(self, row, columns):
        frames = []
        for col in range(columns):
            rect = pygame.Rect(col * self.frame_size, row * self.frame_size, self.frame_size, self.frame_size)
            frame = self.spritesheet.subsurface(rect)
            frame = pygame.transform.scale(frame, (self.size, self.size))
            frames.append(frame)
        return frames

    def handle_input(self, keys):
        dx, dy = 0, 0

        if keys[pygame.K_UP] or keys[pygame.K_w]:
            dy -= 1
            self.direction = 'up'
        if keys[pygame.K_DOWN] or keys[pygame.K_s]:
            dy += 1
            self.direction = 'down'
        if keys[pygame.K_LEFT] or keys[pygame.K_a]:
            dx -= 1
            self.direction = 'left'
        if keys[pygame.K_RIGHT] or keys[pygame.K_d]:
            dx += 1
            self.direction = 'right'

        self.moving = dx != 0 or dy != 0
        return dx, dy

    def board_boat(self, boat_x, boat_y):
        self.mode = 'boat'
        self.x = boat_x
        self.y = boat_y

    def update(self, dt, dx, dy, map_manager):
        if dx != 0 and dy != 0:
            # normalise la diagonale pour ne pas se déplacer plus vite en biais
            dx *= 0.7071
            dy *= 0.7071

        speed = self.boat_speed if self.mode == 'boat' else self.walk_speed
        move_x = dx * speed * dt
        move_y = dy * speed * dt

        if self.mode == 'boat':
            # en mer il n'y a pas de collision avec l'île, seulement les limites de la carte
            before_x, before_y = self.x, self.y

            new_x = self.x + move_x
            if map_manager.is_in_bounds(new_x, self.y):
                self.x = new_x

            new_y = self.y + move_y
            if map_manager.is_in_bounds(self.x, new_y):
                self.y = new_y

            # on débarque automatiquement dès qu'on touche une île ; on garde en mémoire
            # la position juste avant, encore dans l'eau, pour que le bateau y reste ancré
            if map_manager.is_walkable(self.x, self.y):
                self.mode = 'foot'
                self.last_water_position = (before_x, before_y)
        else:
            # à pied, collision testée séparément sur x et y (avec la coordonnée actuelle de
            # l'autre axe, qui est déjà valide) pour pouvoir glisser le long de la côte
            new_x = self.x + move_x
            if map_manager.is_walkable(new_x, self.y):
                self.x = new_x

            new_y = self.y + move_y
            if map_manager.is_walkable(self.x, new_y):
                self.y = new_y

        self._animate(dt)

    def _animate(self, dt):
        if self.mode == 'boat' or not self.moving:
            self.frame_index = 0
            self.animation_timer = 0
            return

        self.animation_timer += dt
        if self.animation_timer >= self.animation_speed:
            self.animation_timer = 0
            frames = self.animations[self.direction]
            self.frame_index = (self.frame_index + 1) % len(frames)

    def get_position(self):
        return self.x, self.y

    def draw(self, surface, screen_pos):
        # utilisé seulement à pied : en bateau, c'est Boat qui se dessine
        frames = self.animations[self.direction]
        frame = frames[self.frame_index % len(frames)]
        pos = (screen_pos[0] - self.size // 2, screen_pos[1] - self.size // 2)
        surface.blit(frame, pos)
