LIBS=-lsfml-graphics -lsfml-window -lsfml-system

all: visualis

constants.o: constants.h constants.cpp
		g++ -c -fopenmp "constants.cpp" -o constants.o

bar.o: bar.h bar.cpp
		g++ -c -fopenmp "bar.cpp" -o bar.o

functions.o: functions.h functions.cpp
		g++ -c -fopenmp "functions.cpp" -o functions.o


visual.o: visual.cpp
		g++ -c -fopenmp "visual.cpp" -o visual.o



visualis: constants.o bar.o functions.o visual.o
		@echo "** Building the visualization"
		g++ -o visualis -fopenmp constants.o  bar.o functions.o visual.o $(LIBS)

clean:
		@echo "** Removing object files and executable..."
		rm -f visualis *.o

install:
		@echo '** Installing...'
		cp visualis /usr/bin

uninstall:
		@echo '** Uninstalling...'
		rm -f /usr/bin/visualis