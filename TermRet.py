import os
import subprocess

P_ISRunning = True

games = ["snake"]

def clear_screen():
    if os.name == 'nt':  # For Windows
        os.system('cls')
    else:  # For Linux and Mac
        os.system('clear')

def print_game_list():
    print("LIST OF GAMES AVAILABLE RN.\n")
    for i, game in enumerate(games):
        print(f"{i+1} - {game}")
    print()

def run_game(game_name):
    try:
        subprocess.run(["build/" + game_name + ".exe"])
        return True
    except FileNotFoundError:
        print(f"Failed to run: {game_name}")
        return False

clear_screen()
print("======================================")
print_game_list()

while P_ISRunning:
    game_name = input("Which game do you want to play: ")

    if run_game(game_name):
        P_ISRunning = False

