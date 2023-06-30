import uuid
from collections import defaultdict
import random
from random import choice
import json
import os


class NPC:
    def __init__(self, id: str):
        with open('npcs.json', 'r') as file:
            npc_dict = json.load(file)[id]
            self.id = id
            self.name = npc_dict['name']
            self.item = npc_dict['item']
            self.dialog = npc_dict['dialog']
            self.status = npc_dict['status']

    def upgrade_status(self):
        self.status += 1
        npc_dict = {}
        with open('npcs.json', 'r') as file:
            npc_dict = json.load(file)
            npc_dict[self.id]['status'] = self.status
        with open('npcs.json', 'w', encoding='utf8') as file:
            json.dump(npc_dict, file)


class Enemy:
    def __init__(self):
        with open('enemies.json', 'r') as file:
            enemy_dict = json.load(file)
            key = list(enemy_dict.keys())
            print(key)
            id = choice(key)
            print(id)
            self.id = id
            enemy_dict = enemy_dict[id]
            self.name = enemy_dict['name']
            self.hp = enemy_dict['hp']
            self.drop = enemy_dict['drop']
            self.damage = enemy_dict['damage']
            self.status = enemy_dict['status']



    def attack(self):
        return self.damage

    def take_hit(self, damage: int):
        self.hp -= damage
        return self.hp


class Protagonist:
    def __init__(self, name: str):
        if os.path.isfile('player.json'):
            self.load()
        else:
            self.id = str(uuid.uuid4())
            self.name: str = name
            self.hp: int = 10
            self.strength: int = 1
            self.craft: int = 1
            self.inventory = defaultdict(int)
            self.inventory["Heal_water"] = 1
            self.location = (0, 0)
            self.save()
    def save(self):
        with open('player.json', 'w') as file:
            player_dict = {'id': self.id, 'name': self.name, 'hp': self.hp, 'strength': self.strength,
                           'craft': self.craft,
                           'inventory': self.inventory, 'location': str(self.location)}
            json.dump(player_dict, file)

    def load(self):
        with open('player.json', 'r') as file:
            player_dict = json.load(file)
            self.id = player_dict['id']
            self.name = player_dict['name']
            self.hp = player_dict['hp']
            self.craft = player_dict['craft']
            self.strength = player_dict['strength']
            self.inventory = player_dict['inventory']
            self.location = (int(player_dict['location'][1]), int(player_dict['location'][4]))
            
    def new_location(self, n_loc):
        self.location = n_loc

    def get_lication(self):
        return self.location

    def talk_to(self, npc):
        if npc.status == 0:
            npc.upgrade_status()
            return npc.dialog[0]
        elif npc.status == 1:
            npc.upgrade_status()
            # self.take(npc.item)
            return npc.dialog[1]
        else:
            return f'Вы уже поговорили с {npc.name}'

    def get_location(self, location: str):
        self.location = location

    def attack(self):
        return self.strength + random.randint(1, self.craft)

    def take_hit(self, value: int):
        self.hp -= value
        if self.hp <= 0:
            raise Exception('Вы умерли!')

    def heal(self, value: int):
        self.hp += value * self.craft

    def advance_strength(self, value: int = 1):
        self.strength += value

    def advance_craft(self, value: int = 1):
        self.craft += value

    def go(self, location: str):
        self.location = location

    def whereami(self):
        return self.location

    def take(self, item: str):
        if not self.inventory.get(item):
            self.inventory[item] = 1
        else:
            self.inventory[item] += 1
        return f'{item} получен!'

    def give(self, npc, item: str):
        if self.inventory.get(item):
            self.inventory[item] -= 1
        if self.inventory[item] == 0:
            del self.inventory[item]
        # npc.receive(item)



