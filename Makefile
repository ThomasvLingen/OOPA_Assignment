EXEC = OOPA_CircuitSim
TEST = OOPA_test

all:
	mkdir -p build
	cd build; cmake ..
	cd build; make
	cd build; mv $(EXEC) ../
	cd build/test; mv $(TEST) ../..

clean:
	rm -rf build
	rm -rf $(EXEC)
	rm -rf $(TEST)
