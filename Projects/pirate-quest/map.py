import pygame
import pytmx
from pytmx.util_pygame import load_pygame
import pyscroll

class MapManager:

    def __init__(self, screen_size):
        self.tmx_data = load_pygame('assets/map/map.tmx')
        self.map_layer = pyscroll.BufferedRenderer(
            pyscroll.data.TiledMapData(self.tmx_data),
            screen_size
        )
        self.map_layer.zoom = 2

        # calque utilisé pour savoir où le joueur peut marcher (île = sol, sinon = eau)
        self.island_layer = self.tmx_data.get_layer_by_name('Island')
        self.tile_width = self.tmx_data.tilewidth
        self.tile_height = self.tmx_data.tileheight
        self.map_width = self.tmx_data.width * self.tile_width
        self.map_height = self.tmx_data.height * self.tile_height

    def render(self, surface, center):
        self.map_layer.center(center)
        rect = surface.get_rect()
        self.map_layer.draw(surface, rect)

    def world_to_screen(self, world_pos):
        # convertit une position dans le monde (le tmx) en position à l'écran
        # en tenant compte de la caméra et du zoom
        view_rect = self.map_layer.view_rect
        zoom = self.map_layer.zoom
        screen_x = (world_pos[0] - view_rect.left) * zoom
        screen_y = (world_pos[1] - view_rect.top) * zoom
        return screen_x, screen_y

    def is_walkable(self, x, y):
        # une case est marchable si elle contient une tuile sur le calque Island
        tile_x = int(x // self.tile_width)
        tile_y = int(y // self.tile_height)

        if tile_x < 0 or tile_y < 0 or tile_x >= self.tmx_data.width or tile_y >= self.tmx_data.height:
            return False

        return self.island_layer.data[tile_y][tile_x] != 0

    def is_in_bounds(self, x, y):
        # utilisé par le bateau : il peut naviguer partout tant qu'on reste sur la carte
        return 0 <= x < self.map_width and 0 <= y < self.map_height

    def get_player_spawn(self):
        spawn = self.tmx_data.get_object_by_name('PlayerSpawn')
        return spawn.x, spawn.y

    def get_chest_positions(self):
        # récupère la position (centre en pixels) de chaque coffre placé sur la carte
        positions = []
        chest_layer = self.tmx_data.get_layer_by_name('Chest')
        for x, y, surface in chest_layer.tiles():
            positions.append((
                x * self.tile_width + self.tile_width // 2,
                y * self.tile_height + self.tile_height // 2
            ))
        return positions
