from collections import defaultdict
import random
import json
import atexit

def load_locations(num):
    num = str(num)
    print(num)
    with open('location.json', 'r', encoding='utf-8') as f:
        d = json.load(f)
    return d.get(num)




class Protagonist:  # you may decide to add some parent class here, e.g. ORM Model
    def __init__(self, name: str, id: str):  # add more parameters if you need
        self.id = id  # a unique identifier of a current player
        self.name: str = name
        self.hp: int = 10
        # replace with self.level = 1  if you decide to use just level
        self.strength: int = 1
        self.craft: int = 1
        # name and count, modify starting inventory at your wish
        self.inventory = defaultdict(int)
        self.inventory["pocket dust"] += 1  # modify starting inventory as you see fit
        self.location = (0,0)
    def talk_to(self, npc):
        if (npc.dealog_dic):
            return npc.dealog_dic.pop(0)
            
          # you'll need to implement this

    def new_location(self, n_loc):
        self.location = n_loc


    def get_lication(self):
        return self.location
    
    def attack(self):
        return self.strength + random.randrange(1, 6)

    def take_hit(self, value=1):
        self.hp -= value
        if self.hp <= 0:
            # you'll need to catch this exception in your code and handle this endgame 
            # situation properly, e.g. giving player a meaningful message of what 
            # happened and reset the save so he or she can start again  
            raise Exception("You died")
    
    def heal(self, value=1):
        self.strength: int = 1 
        self.craft: int = 1  # starting values may differ
        self.hp += 1

    # can be 'advance_level()' instead. Also, are there any situations in your game
    # where a skill is increased by more than one or even decreased?
    def advance_strength(self, value: int = 1):
        self.strength += value

    def advance_craft(self, value: int = 1):
        self.craft += value

    def go(self, direction):
        pass  # you'll need to implement this in other exercise

    def whereami(self):
        return  location[-1] # returns description of the current location

    def take(self, item: str):
        self.inventory[item] += 1

    def give(self, npc, item: str):
        self.inventory[item] -= 1
        if self.inventory[item] == 0:
            del self.inventory[item]
        npc.receive(item)

class NPC:
    def __init__(self, name, items, dealog_dic):
        self.name = name
        self.inventory = defaultdict
        self.hp: int = 10
        self.dealog_dic = dealog_dic

    def give(self, item: str):
        self.inventory[item] -= 1
        if self.inventory[item] == 0:
            del self.inventory[item]
        return item

class Enemy:
    def __init__(self, name, items, strength: int, craft: int):
        self.name = name
        self.inventory = defaultdict
        self.hp: int = 10
        self.strength = strength
        self.craft = craft

    def attack(self):
        return self.strength + random.randrange(1, 6)

    def take_hit(self):
        self.hp -= 1
        if self.hp <= 0:
            raise Exception("Dead")

def main():
    print(load_locations('0'))
    # # with open('npc.json', 'r', encoding='utf-8') as f:
    # #     d = json.load(f)
    # # print(d['1']['name'])
    # # npc = NPC(d['1']['name'],d['1']["items"], d['1']["dealog_dic"])
    # luke =  Protagonist("luke", '1')
    # print(luke.talk_to(npc))
    # print(luke.talk_to(npc))
    # ne_luke = Enemy('Gandon', 'Палка', 4, 3)
    # js = open('test.json', 'w')
    # try:
    # while True:
    #     if luke.attack() < ne_luke.attack():
    #         luke.take_hit()
    #     else:
    #         ne_luke.take_hit()
    # except:
    #     print(luke.hp)
    #     print(ne_luke.hp)
    
if __name__ == '__main__':
    main()
    

