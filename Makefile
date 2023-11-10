all:
	./build.sh

clean:
	./clean.sh

%:
	./build.sh $@

.PHONY:	all clean