OBJS = printer.o multifile.o 

out: $(OBJS)
	$(CC) $(OBJS) -o $@

%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS)