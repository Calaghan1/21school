import random

from load_map import Map
from load_data import Enemy, Protagonist, NPC


class Game:
    def __init__(self, player_name: str):
        self.map = Map()
        self.player = Protagonist(player_name)

    def available_directions(self):
        paths = {}
        for path in self.map.locations[self.player.whereami()].paths:
            paths[path] = self.map.locations[path].description
        return paths

    def available_npcs(self):
        npcs = {}
        for npc in self.map.locations[self.player.whereami()].npcs:
            npcs[npc] = self.map.locations[self.player.whereami()].npcs[npc].name
        return npcs

    def available_enemies(self):
        enemies = {}
        for enemy in self.map.locations[self.player.whereami()].enemies:
            enemies[enemy] = self.map.locations[self.player.whereami()].enemies[enemy].name
        return enemies

    def fight(self, enemy_id: str):
        if enemy_id in self.available_enemies():
            first_hit = random.randint(1, 2)
            if first_hit:
                pass
            else:
                pass

    def get_players_inventory(self):
        return self.player.inventory

    def get_stats(self):
        return {'HP': self.player.hp, 'Strength': self.player.strength, 'Craft': self.player.craft}

    def get_location(self):
        return

    def move(self, location: int):
        if location in self.available_directions():
            self.player.go(location)
            return f'{self.player.name} перешел в'
        else:
            return 'Локация не доступна'


if __name__ == '__main__':
    game = Game('Putnik')
    print(game.available_directions())
    print(game.available_npcs())
    print(game.available_enemies())


