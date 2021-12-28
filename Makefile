all: compile link

compile:
	g++ -I src/include -c main_copy.cxx Graphique.cxx
link:
	g++ main_copy.o -o main_copy Graphique -L src/lib -l sfml-graphics -l sfml-window -l sfml-system