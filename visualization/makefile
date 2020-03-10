LIBS=-lsfml-graphics -lsfml-window -lsfml-system

all: simulation

visual.o: visual.cpp
		g++ -c -fopenmp "visual.cpp" -o visual.o

bar.o: bar.cpp
		g++ -c -fopenmp "bar.cpp" -o bar.o

simulation: visual.o bar.o
		@echo "** Building the simulation"
		g++ -o simulation -fopenmp  visual.o bar.o $(LIBS)

clean:
		@echo "** Removing object files and executable..."
		rm -f simulation *.o

install:
		@echo '** Installing...'
		cp simulation /usr/bin

uninstall:
		@echo '** Uninstalling...'
		rm -f /usr/bin/simulation