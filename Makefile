all: compile link

compile:
	g++ -I src/include -c lui.cxx
link:
	g++ lui.o -o lui -L src/lib -l sfml-graphics -l sfml-window -l sfml-system