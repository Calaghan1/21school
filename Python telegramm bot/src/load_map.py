import json
from load_data import NPC, Enemy


class Location:
    def __init__(self, npcs, enemies, description: str, id: str, paths):
        self.npcs = npcs
        self.enemies = enemies
        self.description = description
        self.id = id
        self.paths = paths

def load_locations(num):
    print(num)
    num = str(num)
    print(num)
    with open('locations.json', 'r', encoding='utf-8') as f:
        d = json.load(f)
    return d.get(num)

class Map:
    def __init__(self):
        with open('locations.json', 'r', encoding='utf-8') as f:
            locations_dict = json.load(f)
            self.locations = {}
            for location in locations_dict:
                npcs = {}
                enemies = {}
                for npc in locations_dict[location]['npcs_id']:
                    npcs[npc] = NPC(npc)
                for enemy in locations_dict[location]['enemies_id']:
                    enemies[enemy] = Enemy(enemy)
                self.locations[location] = Location(npcs, enemies, locations_dict[location]['description'], location,
                                                    locations_dict[location]['paths'])
