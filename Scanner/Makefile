# scanner: main.c scan.c 
# 				cc -o scanner -g main.c scan.c

scanner: main.cpp Scanner.cpp Scanner.h
			g++ -g -o scanner main.cpp Scanner.cpp Scanner.h
clean: 
		rm -rf scanner *.o
