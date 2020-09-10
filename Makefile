PROJ = output.out
CXX = g++
CXXFLAGS = -g -Wall -std=c++11
OBJS = Proj3CensusTest.o

$(PROJ): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

Proj3CensusTest.o: Proj3CensusTest.cpp
	$(CXX) $(CXXFLAGS) -c $<

# -f removes any error messages if the file is not present
.PHONY: clean run valgrind finish
clean:
	rm -rf $(OBJS)
	rm -f $(PROJ)
	rm -f *~ *.h.gch *#
run: $(PROJ)
	./$(PROJ) $(PARAM)
valgrind: $(PROJ)
	valgrind ./$(PROJ)
finish:clean
	rm –rf -f proj3.zip
	zip proj3.zip ./*