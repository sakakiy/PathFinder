all: gMaze pathFind generateMaze/mainStack

####################
# 迷路生成プログラムをビルド
gMaze: generateMaze/generateMaze.cpp
	c++ -o gMaze generateMaze/generateMaze.cpp

####################
# 経路探索プログラムをビルド
pathFind: pathFind.cpp
	c++ -o pathFind pathFind.cpp

####################
# スタックのテストプログラムをビルド
generateMaze/mainStack: generateMaze/main.cpp generateMaze/stack/stack.o
	c++ -o generateMaze/mainStack generateMaze/main.cpp generateMaze/stack/stack.o

generateMaze/stack/stack.o: generateMaze/stack/stack.cpp
	c++ -o generateMaze/stack/stack.o -c generateMaze/stack/stack.cpp

####################
# クリーン
clean:
	rm -f *.o gMaze
	rm -f *.o pathFind
	rm -f generateMaze/stack/stack.o generateMaze/mainStack

