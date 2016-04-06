EXEC = OOPA_CircuitSim

all:
	mkdir -p build
	cd build; cmake ..
	cd build; make
	cd build; mv $(EXEC) ../

clean:
	rm -rf build
	rm -rf $(EXEC)
