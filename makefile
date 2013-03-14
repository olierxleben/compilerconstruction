# compile and "link" Tiger programs
# adapted M. Weinhardt, 05.03.13

# path to Tiger compiler binary
#TIGER = c:/gnu/bin/tiger 
TIGER = ./bin/tiger.exe

# path to Tiger runtime library (runtime.s)
#RUNTIME = c:/gnu/tiger/runtime.s 
RUNTIME =./runtime.s

# take input file, compile with tiger, 
# cat with tiger runtime and 
%.s : %.tig
	$(TIGER) $<
	cat $(RUNTIME) $<.s > $@
	
#	@$(TIGER) $<	
#	@type ./runtime.s $<.s > $@