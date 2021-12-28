all: compile link

compile:
	g++ -I src/include -c Graphique.cxx
link:
	g++ Graphique.o -o Jeux -L src/lib -l sfml-graphics -l sfml-window -l sfml-system