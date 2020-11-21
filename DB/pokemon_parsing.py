import requests
import json

'''
    name : 포켓몬 이름(str)
    moves : 포켓몬 기술(list)

'''
def searchPokemon(name):
    try:
        response = requests.get("https://pokeapi.co/api/v2/pokemon/" + name)
        pokemon = json.loads(response.text)
    except:
        print("There is no such pokemon in the database")
    else:
        name = pokemon['name']
        moves = list(i['move'] for i in pokemon['moves'])
        #출력
        print(json.dumps(moves, indent = 4, sort_keys = True))



searchPokemon("pikachu")
