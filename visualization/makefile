LIBS=-lsfml-graphics -lsfml-window -lsfml-system

all: visualis

constants.o: constants.cpp
		g++ -c -fopenmp "constants.cpp" -o constants.o

functions.o: functions.cpp
		g++ -c -fopenmp "functions.cpp" -o functions.o

visual.o: visual.cpp
		g++ -c -fopenmp "visual.cpp" -o visual.o

bar.o: bar.cpp
		g++ -c -fopenmp "bar.cpp" -o bar.o


visualis: constants.o visual.o functions.o bar.o
		@echo "** Building the visualization"
		g++ -o visualis -fopenmp  constants.o functions.o visual.o bar.o $(LIBS)

clean:
		@echo "** Removing object files and executable..."
		rm -f visualis *.o

install:
		@echo '** Installing...'
		cp visualis /usr/bin

uninstall:
		@echo '** Uninstalling...'
		rm -f /usr/bin/visualis