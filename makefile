rem: hello.o chat.o auto.o main.o
	g++ -o rem hello.o chat.o auto.o main.o
hello.o: hello.cpp hello.h
	g++ -c hello.cpp
chat.o: chat.cpp chat.h
	g++ -c chat.cpp
auto.o: auto.cpp auto.h
	g++ -c auto.cpp
main.o: main.cpp
	g++ -c main.cpp