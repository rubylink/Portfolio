1)
Name: Ruby Link
Assignment: Not So Super Mario Bros

2) Assignment:
   
The game simulation is carried out in a world that consists of a fixed number of levels. Mario must navigate the levels, encountering enemies and power ups, and collecting coins, before engaging a boss to move onto the next level.

Program takes in a command line input (spec.txt) that has the following format:
Line # 1 is the number of levels, L (a positive integer)
Line # 2 is the dimension of the grid, N (a positive integer)
Line # 3 is the number of initial lives, V (a positive integer)
Line # 4 is the approximate percentage of the positions in each level with coins (a positive integer)
Line # 5 is the approximate percentage of the positions in each level with nothing (a positive integer)
Line # 6 is the approximate percentage of the positions in each level with Goombas (a positive integer)
Line # 7 is the approximate percentage of the positions in each level with Koopas (a positive integer)
Line # 8 is the approximate percentage of the positions in each level with mushrooms (a positive integer)

Mario is placed at a random position in the first level with PL0 and the simulation begins until the game is won or lost.

As Mario moves about the game, he interacts with each tile. Once he has interacted with the current location, he moves on to the next location by moving up, down, left, or right. The direction is chosen randomly with uniform probability (25% each). 

If the position contains nothing, Mario moves on.
If the position contains a coin, Mario adds the coin to his wallet, and then the position contains nothing. Mario moves on.
If the position contains a mushroom, Mario’s power level increases by 1, or stays at PL2 if he’s already in PL2. Once the mushroom is consumed, the position contains nothing, and Mario moves on.
If the position contains a Goomba or Koopa, Mario has a set probability of beating them. If he loses, power level decreases and if power level falls to zero, the game is over.
If the position contains the level boss, Mario engages per the rules of a boss. Mario defeats the enemy with a 50% probability.
If Mario encounters the warp pipe, he will immediately jump to a random position in the next level without having to beat the current level boss.

The output of the game is a plain text file that represents a log of every move Mario has made. The name of the log is provided as a command line argument (log.txt).

3)To run:

docker start compsci
docker attach compsci
g++ *.cpp -o e.exe
./e.exe spec.txt log.txt
