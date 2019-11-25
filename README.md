# filler
#### my 42 nickname - chermist
Use make to build project.

### • How the game works  
  ◦ At each turn, the filler will send the updated map and a new token to the player concerned.  
  ◦ The player concerned will write on the standard output his or her piece’s coordinates to place it on the board.  
  ◦ The filler will send the map and a new piece to the other player.
  
##### I used wave algorithm to find the best position to put my token so it will cut an escape route for enemy.  
##### For visualisation I used a minilibx(ecole42 graphic library) that gives a functions to create/destroy/clear window, to put a pixel to the window I created and to work with keyboard/mouse events.

### To run a game:
```
./filler_vm -f maps/map01 -p2 players/chermist.filler -p1 players/superjeannot.filler
```
### To run a game with visualisation(currently works on MacOs only):
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
