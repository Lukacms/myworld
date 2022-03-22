# myworld - B2-MUL-Luka-Louis

# Description
Our own terraformer programm. <br>
The goal is io display a map and be able to edit it at runtime:
* altering the ground
* see the map under differents angles
* save the map, and load one

# Goals
* display the map and change it
* master isometric 2d
* save and load maps

# Usage
```
./my_world
```
or, to display help:
```
./my_world -h
```

# Returns
* 0 if everything goes well
* 84 in case of any errors (not being able to init correctly, not a good environnement, ...)

# How to use to project
A Makefile is used to compile the code, and it use the following rules:

| Command          | Result                                          |
| ---------------- | ----------------------------------------------- |
| `make`           | Builds a ```my_world``` executable.          |
| `make clean`     | Cleans build dumps, keeping the executable.     |
| `make fclean`    | Removes all of the files created by the build.  |
| `make re`        | Calls `make fclean` and then `make`.            |
