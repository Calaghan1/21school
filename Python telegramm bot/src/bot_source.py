# @Spice_and_Wolf_bot
import telebot
from telebot import types
import urllib.request 
from random import choice
import random
from telebot.util import quick_markup
import load_data
import load_map
from telebot.types import InlineKeyboardMarkup, InlineKeyboardButton
global markdown_stek
markdown_stek = []
token="5922115315:AAGc3rXIZJzxNYjKfin-uX6D4KUtJg7sU18"

def make_map(x, y):
    result = ''
    for i in range(0, 3):
        for j in range(0, 5):   
            if (i == 1 and j == 3):
                result += '🛖'
            elif (i == 2 and j == 2):
                result += '👩‍⚕️'
            elif (i == 2 and j == 4):
                result += '💀'
            elif (i == 0 and j == 2):
                result += '💀'
            elif (i == x and y == j):
                result += '😛'
            else:
                result += '▪️'
        result += '\n'
    return result


global player
global enemy
global npc
player = load_data.Protagonist("player")

bot=telebot.TeleBot(token)

# def fight(call,enemy):

    # try:
    #     while True:
    #         if player.attack() < enemy.attack():
    #             player.take_hit()
    #         else:
    #             enemy.take_hit()
    # except:
    #     print(player.hp)
    #     print(enemy.hp)




@bot.message_handler(commands=['start'])
def start_message(message):
    # bot.send_message(message.chat.id,"Привет ✌️ ")
    user_markup = telebot.types.ReplyKeyboardMarkup(True, False)
    user_markup.row('/start', '/stop')
    user_markup.row('/Текущая_локация', '/Что вокруг')
    bot.send_message(message.from_user.id, "Привет ✌️ ", reply_markup = user_markup)

    markdown_stek.append(user_markup)


@bot.callback_query_handler(func=lambda call: call.data == "right")
def callHandler1(call):
    loc = player.get_lication()
    if not loc[1] + 1 > 4:
        player.new_location((loc[0], loc[1] + 1))
        map = (make_map(loc[0],loc[1] + 1))
        markup = quick_markup({
        '➡' : {'callback_data': 'right'},
        '⬆': {'callback_data': 'up'},
        '⬇': {'callback_data': 'down'}
        ,'⬅': {'callback_data': 'left'}}, row_width=4)
        small_key = types.InlineKeyboardButton(text='Inventory', callback_data = 'Inventory')
        markup.add(small_key)
        try:
            bot.edit_message_text(map, call.message.chat.id, call.message.id, reply_markup = markup)
        except Exception as e:
            print(e)
        event_manager(call)



@bot.callback_query_handler(func=lambda call: call.data == "Inventory")
def callHandler_Inventory(call):
    user_markup = telebot.types.ReplyKeyboardMarkup(True, False)
    keys = list(player.inventory.keys())
    for k in keys:
        bot.edit_message_text('/' + k, call.message.chat.id, call.message.id)
        





@bot.callback_query_handler(func=lambda call: call.data == "up")
def callHandler2(call):
    loc = player.get_lication()
    if not loc[0] - 1 < 0:
        player.new_location((loc[0] - 1, loc[1]))
        map = (make_map(loc[0] - 1,loc[1]))
        markup = quick_markup({
        '➡' : {'callback_data': 'right'},
        '⬆': {'callback_data': 'up'},
        '⬇': {'callback_data': 'down'}
        ,'⬅': {'callback_data': 'left'}}, row_width=4)
        small_key = types.InlineKeyboardButton(text='Inventory', callback_data = 'Inventory')
        markup.add(small_key)
        try:
            bot.edit_message_text(map, call.message.chat.id, call.message.id, reply_markup = markup)
        except Exception as e:
            print(e)
        event_manager(call)

@bot.callback_query_handler(func=lambda call: call.data == "down")
def callHandler3(call):
    loc = player.get_lication()
    if not(loc[0] + 1 > 2):
        player.new_location((loc[0] + 1, loc[1]))
        map = (make_map(loc[0] +  1,loc[1]))
        
        markup = quick_markup({
        '➡' : {'callback_data': 'right'},
        '⬆': {'callback_data': 'up'},
        '⬇': {'callback_data': 'down'}
        ,'⬅': {'callback_data': 'left'}}, row_width=4)
        small_key = types.InlineKeyboardButton(text='Inventory', callback_data = 'Inventory')
        markup.add(small_key)
        try:
            bot.edit_message_text(map, call.message.chat.id, call.message.id, reply_markup = markup)
        except Exception as e:
            print(e)
        event_manager(call)


@bot.callback_query_handler(func=lambda call: call.data == "left")
def callHandler4(call):
    loc = player.get_lication()
    if not loc[1] - 1 < 0:
        player.new_location((loc[0], loc[1] - 1))
        map = (make_map(loc[0],loc[1] - 1))
        markup = quick_markup({
        '➡' : {'callback_data': 'right'},
        '⬆': {'callback_data': 'up'},
        '⬇': {'callback_data': 'down'}
        ,'⬅': {'callback_data': 'left'}}, row_width=4)
        small_key = types.InlineKeyboardButton(text='Inventory', callback_data = 'Inventory')
        markup.add(small_key)
        try:
            bot.edit_message_text(map, call.message.chat.id, call.message.id, reply_markup = markup)
        except Exception as e:
            print(e)
        event_manager(call)

    

@bot.message_handler(commands=['stop'])
def start_message(massage):
    hide_markup = telebot.types.ReplyKeyboardRemove(True)
    bot.send_message(massage.from_user.id, '...', reply_markup = hide_markup)



def walk_map(massage):
    loc = player.get_lication()
    map = (make_map(loc[0],loc[1]))
    markup = quick_markup({
    '➡' : {'callback_data': 'right'},
    '⬆': {'callback_data': 'up'},
    '⬇': {'callback_data': 'down'}
    ,'⬅': {'callback_data': 'left'}}, row_width=4)
    small_key = types.InlineKeyboardButton(text='Inventory', callback_data = 'Inventory')
    markup.add(small_key)
    bot.send_message(massage.from_user.id, map, reply_markup = markup)

@bot.message_handler(commands=['Текущая_локация'])
def where_am_i(massage):
    loc = player.get_lication()
    loc_disc = load_map.load_locations(loc)
    if loc_disc:
        mess = loc_disc.get("description")
        print("mess")
    else:
        mess = 'Ничего особенного но держи ухо в остро'
    bot.send_message(massage.from_user.id, mess)
    walk_map(massage)


@bot.message_handler(commands=['<--'])
def go_back(massage):
    markdown_stek.pop()
    bot.send_message(massage.from_user.id, 'Закрыл', reply_markup = markdown_stek[-1])
    
# @bot.callback_query_handler(func=lambda call: call.data == "event")
def event_manager(call):
    loc = player.get_lication()
    # if (random.randrange(0, 10) < 2):
    #     enemy = get_random_enemy()
    #     fight(enemy)
    if (loc[0] == 2 and loc[1] == 4) or (loc[0] == 0 and loc[1] == 2):
        global enemy 
        enemy = load_data.Enemy()
        fight_markup = telebot.types.ReplyKeyboardMarkup(True, False)
        fight_markup.row('/Сражаться!','/Бежать!')
        fight_markup.row('/Идти_дальше', '/Остаться')
        bot.send_message(call.message.chat.id,'Вас атакует ' + enemy.name + ' ! Бежать или сражаться?', reply_markup = fight_markup)
    event_markup = telebot.types.ReplyKeyboardMarkup(True, False)
    event_markup.row('/start', '/stop')
    event_markup.row('/Идти_дальше', '/Остаться')
    if loc[0] == 1 and loc[1] == 3:
        event_markup.row('/Попробовать странный элексир у бармена')
        bot.send_message(call.message.chat.id,'В', reply_markup = event_markup)
    if loc[0] == 2 and loc[1] == 2:
        event_markup.row('/Погорить_с_врачом')
        global npc
        npc = load_data.NPC("id_2")
        bot.send_message(call.message.chat.id,'Ты у врача ваше здоровье восстановлено', reply_markup = event_markup)
        player.hp += 5
    
@bot.message_handler(commands=['Heal_water'])
def doc_talk(massage):
    if player.inventory["Heal_water"] > 0:
        player.hp += 2
        bot.send_message(massage.chat.id,'Здоровье игрока -' + str(player.hp))
        player.inventory["Heal_water"] -= 1
    else:
        bot.send_message(massage.chat.id,'Данных предметов не осталось. Здоровье игрока -' + str(player.hp))

@bot.message_handler(commands=['Погорить_с_врачом'])
def doc_talk(massage):
    print("SDd")
    bot.send_message(massage.chat.id, player.talk_to(npc))
    if npc.status == 2:
        bot.send_message(massage.chat.id, "Врач дал вам 1 Heal_water")
        player.take(npc.item)

@bot.message_handler(commands=['Сражаться!'])
def fight(massage):
    try:
        if enemy.hp > 0:
            bot.send_message(massage.chat.id,'Ты наносишь удар')
            enemy.take_hit(player.attack())
            player.take_hit(enemy.attack())
            bot.send_message(massage.chat.id,'Здоровье игрока -' + str(player.hp))
            bot.send_message(massage.chat.id,'Здоровье врага -' + str(enemy.hp))
        else:
            bot.send_message(massage.chat.id,'Ты одержал вверх')
            player.advance_strength()
            player.advance_craft()
            bot.send_message(massage.chat.id,'Сила + 1 Крафт + 1')
            if player.strength > 5:
                finish(massage)
    except:
        user_markup = telebot.types.ReplyKeyboardMarkup(True, False)
        user_markup.row('/start', '/stop')
        user_markup.row('/Текущая_локация', '/Что вокруг')
        bot.send_message(massage.from_user.id, "Вы мертвы ", reply_markup = user_markup)

def finish(massage):
    finish_markup = telebot.types.ReplyKeyboardMarkup(True, False)
    finish_markup.row('/start')
    bot.send_message(massage.chat.id,'Поздравляю! Вы победили. Конец игры!', reply_markup = finish_markup)
   
    



@bot.message_handler(commands=['Идти_дальше'])
def go_back(massage):
    walk_map(massage)

bot.infinity_polling()


