CXX=g++
CFLAGS= -c -Wall -Werror
LIBPWG = obj/src/libpwgen
PWG = obj/src/pwgen
SPWG = src/pwgen
SLIBPWG = src/libpwgen
OBJECTS = pwgen.exe pwgen.o pwgen.d reg.o reg.d Odn.o Odn.d Spec.o Spec.d num.o num.d generate.o generate.d copy.o copy.d isint.o isint.d

all: bin/pwgen.exe

bin/pwgen.exe: $(PWG)/pwgen.o $(LIBPWG)/libpwgen.a
	$(CXX) -I src -Wall -Werror -o bin/pwgen.exe $(PWG)/pwgen.o $(LIBPWG)/libpwgen.a

$(LIBPWG)/libpwgen.a: $(LIBPWG)/reg.o $(LIBPWG)/Odn.o $(LIBPWG)/Spec.o $(LIBPWG)/num.o $(LIBPWG)/generate.o $(LIBPWG)/copy.o $(LIBPWG)/isint.o
	ar rcs $@ $^

$(LIBPWG)/Odn.o: $(SLIBPWG)/Odn.cpp
	$(CXX) -I src $(CFLAGS) -MMD -o $(LIBPWG)/Odn.o $(SLIBPWG)/Odn.cpp

$(LIBPWG)/num.o: $(SLIBPWG)/num.cpp
	$(CXX) -I src $(CFLAGS) -MMD -o $(LIBPWG)/num.o $(SLIBPWG)/num.cpp

$(LIBPWG)/reg.o: $(SLIBPWG)/reg.cpp
	$(CXX) -I src $(CFLAGS) -MMD -o $(LIBPWG)/reg.o $(SLIBPWG)/reg.cpp

$(LIBPWG)/Spec.o: $(SLIBPWG)/Spec.cpp
	$(CXX) -I src $(CFLAGS) -MMD -o $(LIBPWG)/Spec.o $(SLIBPWG)/Spec.cpp

$(LIBPWG)/isint.o: $(SLIBPWG)/isint.cpp
	$(CXX) -I src $(CFLAGS) -MMD -o $(LIBPWG)/isint.o $(SLIBPWG)/isint.cpp

$(LIBPWG)/copy.o: $(SLIBPWG)/copy.cpp
	$(CXX) -I src $(CFLAGS) -MMD -o $(LIBPWG)/copy.o $(SLIBPWG)/copy.cpp

$(LIBPWG)/generate.o: $(SLIBPWG)/generate.cpp
	$(CXX) -I src $(CFLAGS) -MMD -o $(LIBPWG)/generate.o $(SLIBPWG)/generate.cpp

$(PWG)/pwgen.o: src/pwgen/main.cpp
	$(CXX) -I src $(CFLAGS) -MMD -o $(PWG)/pwgen.o $(SPWG)/main.cpp

-include pwgen.d reg.d Odn.d Spec.d num.d generate.d copy.d isint.d

test: bin/test.exe

bin/test.exe: obj/test/test.o $(LIBPWG)/libpwgen.a
	$(CXX) -I src -Wall -Werror -o bin/test obj/test/test.o $(LIBPWG)/libpwgen.a

obj/test/test.o: test/test.cpp
	$(CXX) -I src -I thirdparty $(CFLAGS) -MMD -o obj/test/test.o test/test.cpp

.PHONY: clean
clean: 
	rm -rf $(PWG)/*.o $(PWG)/*.d $(LIBPWG)/*.o $(LIBPWG)/*.d bin/*.exe