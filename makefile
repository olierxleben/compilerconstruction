# compile and "link" Tiger programs
# adapted M. Weinhardt, 05.03.13

# path to Tiger compiler binary
#TIGER = c:/gnu/bin/tiger 
TIGER = ./bin/tiger.exe

# path to Tiger runtime library (runtime.s)
#RUNTIME = c:/gnu/tiger/runtime.s 
RUNTIME =./runtime.s

# path to output files
OUT = out/

%.s : %.tig
	$(TIGER) $<
	cat $(RUNTIME) $<.s > $(OUT)$@
	
#	@$(TIGER) $<	
#	@type ./runtime.s $<.s > $@