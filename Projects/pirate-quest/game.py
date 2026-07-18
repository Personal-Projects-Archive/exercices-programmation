import pygame
pygame.init()
from map import MapManager
from player import Player
from chest import Chest
from boat import Boat

# position de départ du bateau : juste au large de la plage la plus proche des autres îles
BOAT_DOCK = (336, 272)

class Game:

    def __init__(self):
        self.screen_size = (800, 600)
        self.screen = pygame.display.set_mode(self.screen_size)
        pygame.display.set_caption("PirateQuest")
        self.clock = pygame.time.Clock()
        self.font = pygame.font.SysFont(None, 28)
        self.small_font = pygame.font.SysFont(None, 20)

        self.map_manager = MapManager(self.screen_size)

        spawn_x, spawn_y = self.map_manager.get_player_spawn()
        self.player = Player(spawn_x, spawn_y)

        chest_spritesheet = pygame.image.load('assets/spritesheets/chest.png').convert_alpha()
        self.chests = [
            Chest(x, y, chest_spritesheet)
            for x, y in self.map_manager.get_chest_positions()
        ]
        self.treasure_count = 0

        boat_spritesheet = pygame.image.load('assets/spritesheets/boats.png').convert_alpha()
        self.boat = Boat(BOAT_DOCK[0], BOAT_DOCK[1], boat_spritesheet)

        self.running = True

    def run(self):
        while self.running:
            dt = self.clock.tick(60) / 1000  # temps écoulé depuis la dernière image, en secondes

            self.handle_events()
            self.update(dt)
            self.draw()

        pygame.quit()

    def handle_events(self):
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                self.running = False
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_ESCAPE:
                    self.running = False
                if event.key == pygame.K_e:
                    self.try_board_boat()

    def try_board_boat(self):
        if self.player.mode == 'foot' and not self.boat.occupied and self.boat.is_near(self.player.get_position()):
            self.player.board_boat(self.boat.x, self.boat.y)
            self.boat.occupied = True

    def update(self, dt):
        keys = pygame.key.get_pressed()
        dx, dy = self.player.handle_input(keys)

        was_on_boat = self.player.mode == 'boat'
        self.player.update(dt, dx, dy, self.map_manager)

        if was_on_boat and self.player.mode == 'foot':
            # débarquement : le bateau reste ancré dans l'eau, juste au large de la plage
            self.boat.x, self.boat.y = self.player.last_water_position
            self.boat.occupied = False

        player_pos = self.player.get_position()
        for chest in self.chests:
            chest.update(dt, player_pos)
            if chest.just_opened():
                self.treasure_count += 1

    def draw(self):
        self.screen.fill((0, 0, 0))
        self.map_manager.render(self.screen, self.player.get_position())

        for chest in self.chests:
            chest.draw(self.screen, self.map_manager.world_to_screen((chest.x, chest.y)))

        if not self.boat.occupied:
            self.boat.draw(self.screen, self.map_manager.world_to_screen((self.boat.x, self.boat.y)))

        player_screen_pos = self.map_manager.world_to_screen(self.player.get_position())
        if self.player.mode == 'boat':
            self.boat.draw(self.screen, player_screen_pos, facing_left=(self.player.direction == 'left'))
        else:
            self.player.draw(self.screen, player_screen_pos)

        self.draw_hud()

        pygame.display.flip()

    def draw_hud(self):
        total = len(self.chests)
        text = f"Trésors : {self.treasure_count}/{total}"
        surface = self.font.render(text, True, (255, 255, 255))
        self.screen.blit(surface, (10, 10))

        controls = self.small_font.render(
            "Flèches/ZQSD : bouger   E : bateau (les autres coffres sont sur d'autres îles)",
            True, (255, 255, 255)
        )
        self.screen.blit(controls, (10, 40))

        if self.player.mode == 'foot' and not self.boat.occupied and self.boat.is_near(self.player.get_position()):
            hint = self.font.render("Appuie sur E pour embarquer", True, (255, 255, 255))
            rect = hint.get_rect(center=(self.screen_size[0] // 2, self.screen_size[1] - 30))
            self.screen.blit(hint, rect)

        if self.treasure_count == total:
            win_text = self.font.render("Tous les trésors ont été trouvés !", True, (255, 215, 0))
            rect = win_text.get_rect(center=(self.screen_size[0] // 2, 40))
            self.screen.blit(win_text, rect)

game = Game()
game.run()
