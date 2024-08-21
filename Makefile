CC = gcc
CFLAGS = `pkg-config --cflags gtk+-3.0`
LIBS = `pkg-config --libs gtk+-3.0`

all: TaskSchedulerSimulatorGUI

TaskSchedulerSimulatorGUI: main.o task.o
	$(CC) -o TaskSchedulerSimulatorGUI main.o task.o $(LIBS)

main.o: main.c task.h
	$(CC) -c main.c $(CFLAGS)

task.o: task.c task.h
	$(CC) -c task.c

clean:
	rm -f *.o TaskSchedulerSimulatorGUI
