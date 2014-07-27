all: generateMaze pathFind mainStack

####################
# 迷路生成プログラムをビルド
generateMaze: generateMaze.cpp
	c++ -o generateMaze generateMaze.cpp

####################
# 経路探索プログラムをビルド
pathFind: pathFind.cpp
	c++ -o pathFind pathFind.cpp

####################
# スタックのテストプログラムをビルド
mainStack: main.cpp stack/stack.o
	c++ -o mainStack main.cpp stack/stack.o

stack/stack.o: stack/stack.cpp
	c++ -o stack/stack.o -c stack/stack.cpp

####################
# クリーン
clean:
	rm -f *.o generateMaze
	rm -f *.o pathFind
	rm -f stack/stack.o mainStack

