all:project2.o
  g++ -g project2.o -o Tullo_p2
project2.o: project2.cpp
  g++ -c project2.cpp -project2.o
clean: rm -rf *.o Tullo_p2
