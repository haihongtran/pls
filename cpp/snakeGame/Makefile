CPPFLAGS = -Wall -g -std=c++11
RESULT = SnakeGame
OBJECT = common.o food.o gamePlay.o snake.o wall.o main.o

all: $(RESULT)

$(RESULT): $(OBJECT)
	g++ $(CPPFLAGS) *.o -o $@

%.o: %.cpp %.h
	g++ $(CPPFLAGS) -c $<

clean:
	rm *.o
	rm $(RESULT)
