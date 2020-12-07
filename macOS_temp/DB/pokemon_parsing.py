import requests
import json
'''
searchPokemon()

@Parameters:
    -pokemon name (string)
=>
    name : 포켓몬 이름(str)
    moves : 포켓몬 기술(list)
    movesLength : 기술 수
    power : 힘? (int)
    pp: ?? (int)
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
        movesLength = len(moves)
        # 기술 수치 찾기
        move_response = requests.get(moves[0]['url'])
        move_data = json.loads(move_response.text)
        power = move_data['power']
        pp = move_data['pp']
        #json 예쁘게 출력
        print(json.dumps(moves, indent = 4, sort_keys = True))


searchPokemon("pikachu")
