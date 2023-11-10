OBJS = printer.o multifile.o 

out: $(OBJS)
	$(CXX) $(OBJS) -o $@

%.o: %.cxx
	$(CXX) -c $< -o $@ $(CXXFLAGS) -l ./