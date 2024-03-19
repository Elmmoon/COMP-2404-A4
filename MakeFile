OPT = -Wall

a4: main.o Escape.o Hero.o PartArray.o Participant.o Pit.o Position.o Snorc.o random.o
	g++ $(OPT) -o a4 main.o Escape.o Hero.o PartArray.o Participant.o Pit.o Position.o Snorc.o random.o

main.o: main.cc Escape.h
	g++ $(OPT) -c main.cc 

Escape.o: Escape.cc Escape.h Participant.h PartArray.h Hero.h Snorc.h Pit.h defs.h
	g++ $(OPT) -c Escape.cc 

Hero.o: Hero.cc Hero.h Pit.h Participant.h defs.h
	g++ $(OPT) -c Hero.cc 

Participant.o: Participant.cc Participant.h Pit.h Position.h defs.h
	g++ $(OPT) -c Participant.cc 

PartArray.o: PartArray.cc PartArray.h Participant.h defs.h
	g++ $(OPT) -c PartArray.cc 

Pit.o: Pit.cc Pit.h defs.h Position.h PartArray.h Hero.h
	g++ $(OPT) -c Pit.cc 

Position.o: Position.cc Position.h
	g++ $(OPT) -c Position.cc 

Snorc.o: Snorc.cc Snorc.h Participant.h Pit.h
	g++ $(OPT) -c Snorc.cc 

random.o: random.cc
	g++ $(OPT) -c random.cc 

clean:
	rm -f *.o a4