CPP = g++ -std=c++11 -O2

name = $(basename $(file))
type = $(suffix $(file))

$(name).out: $(file)
ifeq ($(type),.cpp)
	$(CPP) -o $(name).out $(name).cpp
endif
