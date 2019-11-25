# filler

Use make to build project.

To run a game:

./filler_vm -f maps/map01 -p2 players/chermist.filler -p1 players/superjeannot.filler

To run a game with visualisation(currently works on MacOs only):

./filler_vm -f maps/map01 -p2 players/chermist.filler -p1 players/superjeannot.filler | ./visu

![map01](https://raw.githubusercontent.com/sabrusrin/filler/master/images/map01.png)
![map02](https://raw.githubusercontent.com/sabrusrin/filler/master/images/map02.png)

FillerVM Usage:
Usage: ./filler_vm -f path [-i | -p1 path | -p2 path] [-s | -q | -t time]

   -t  --time		set timeout in second
   -q  --quiet		quiet mode
   -i  --interactive	interactive mode(default)
   -p1 --player1	use filler binary as a first player
   -p2 --player2	use filler binary as a second player
   -f  --file		use a map file (required)
   -s  --seed		use the seed number (initialization random) (man srand)
