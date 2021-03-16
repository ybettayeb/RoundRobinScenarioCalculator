OBJS	= main.o MatchTreeRecursive.o standings.o team.o
SOURCE	= main.cpp MatchTreeRecursive.cpp standings.cpp team.cpp
HEADER	= matchTreeRecursive.h standings.h team.h
OUT	= a.out
CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp 

MatchTreeRecursive.o: MatchTreeRecursive.cpp
	$(CC) $(FLAGS) MatchTreeRecursive.cpp 

standings.o: standings.cpp
	$(CC) $(FLAGS) standings.cpp 

team.o: team.cpp
	$(CC) $(FLAGS) team.cpp 

clean:
	rm -f $(OBJS) $(OUT)