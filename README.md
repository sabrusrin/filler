# filler
#### my 42 nickname - chermist  
>Code written in norminette code style(github.com/sabrusrin/norme)

### • How the game works  
  ◦ At each turn, the filler will send the updated map and a new token to the player concerned.  
  ◦ The player concerned will write on the standard output his or her piece’s coordinates to place it on the board.  
  ◦ The filler will send the map and a new piece to the other player.
  
##### I used wave algorithm to find the best position to put my token so it will cut an escape route for enemy.  
##### For visualisation I used a minilibx(ecole42 graphic library) that gives a functions to create/destroy/clear window, to put a pixel to the window I created and to work with keyboard/mouse events.
Use make to build project on macos.
#### If you want to build project on linux machine, follow these steps:
```
1) Update/upgrade your system:
  apt-get update
  apt-get upgrade

2) Install the following packages:
  apt-get install libx11-dev
  apt-get install libxext-dev

3) ./configure
4) Use make command: make linux
Hope it will work :)
```

### To run a game:
```
./filler_vm -f maps/map01 -p2 players/chermist.filler -p1 players/superjeannot.filler
```
### To run a game with visualisation:
```
./filler_vm -f maps/map01 -p2 players/chermist.filler -p1 players/superjeannot.filler | ./visu
```
![map01](https://raw.githubusercontent.com/sabrusrin/filler/master/images/map01.png)
![map02](https://raw.githubusercontent.com/sabrusrin/filler/master/images/map02.png)

### FillerVM Usage:  
```
./filler_vm -f path [-i | -p1 path | -p2 path] [-s | -q | -t time]  

   -t  --time		set timeout in second  
   -q  --quiet		quiet mode  
   -i  --interactive	interactive mode(default)  
   -p1 --player1	use filler binary as a first player  
   -p2 --player2	use filler binary as a second player  
   -f  --file		use a map file (required)  
   -s  --seed		use the seed number (initialization random) (man srand)  
```
