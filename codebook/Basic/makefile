CPP = g++ -std=c++11 -O2

name = $(basename $(file))
type = $(suffix $(file))
exe = $(name).out

$(exe): $(file)
ifeq ($(type),.cpp)
	$(CPP) -D AC -o $(exe) $(name).cpp
endif

clean:
	rm *.out
