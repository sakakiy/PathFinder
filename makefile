all: generateMaze pathFind

generateMaze: generateMaze.cpp
	c++ -o generateMaze generateMaze.cpp

pathFind: pathFind.cpp
	c++ -o pathFind pathFind.cpp

clean:
	rm -f *.o generateMaze
	rm -f *.o pathFind

