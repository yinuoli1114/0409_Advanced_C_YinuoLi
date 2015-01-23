
GCC = gcc
CFLAGS = -g -Wall -Wshadow
LIBS =
SOURCES = answer06.c pa06.c
TARGET = pa06
TESTN := $(shell seq 0 14)
VALGRIND = valgrind --tool=memcheck --leak-check=full --show-reachable=yes --verbose

# -------------------------------------------------------------

TESTS := $(addprefix test,${TESTN})

.PHONY : all build clean environment help testall $(TESTS)
.DEFAULT_GOAL := build

OBJF = obj
OBJS = $(patsubst %.c,$(OBJF)/%.o,$(SOURCES))

-include $(SOURCES:%=$(OBJF)/%.P)


all: | build testall

testall: | $(TESTS)

test1: pa06
	$(VALGRIND) --log-file=outputs/memoutput01 ./pa06 images/01-unnormalized-smile.ee264 outputs/output01.ppm
	diff -w outputs/output01.ppm expected/01-smile.ppm
test2: pa06
	$(VALGRIND) --log-file=outputs/memoutput02 ./pa06 images/02-unnormalized-cat-chess.ee264 outputs/output02.ppm
	diff -w outputs/output02.ppm expected/02-cat-chess.ppm
test3: pa06
	$(VALGRIND) --log-file=outputs/memoutput03 ./pa06 images/03-unnormalized-hawkes-bay-NZ.ee264 outputs/output03.ppm
	diff -w outputs/output03.ppm expected/03-hawkes-bay-NZ.ppm
test4: pa06
	$(VALGRIND) --log-file=outputs/memoutput04 ./pa06 images/04-unnormalized-nelsonmandela.ee264 outputs/output04.ppm
	diff -w outputs/output04.ppm expected/04-nelsonmandela.ppm
test5: pa06
	$(VALGRIND) --log-file=outputs/memoutput05 ./pa06 images/05-unnormalized-sagan-stamp.ee264 outputs/output05.ppm
	diff -w outputs/output05.ppm expected/05-sagan-stamp.ppm
test6: pa06
	! $(VALGRIND) --log-file=outputs/memoutput06 ./pa06 images/corrupt-testcases/bad-comment-len.ee264 outputs/corrupt_output06.ppm
test7: pa06
	! $(VALGRIND) --log-file=outputs/memoutput07 ./pa06 images/corrupt-testcases/big-width-height.ee264 outputs/corrupt_output07.ppm
test8: pa06
	! $(VALGRIND) --log-file=outputs/memoutput08 ./pa06 images/corrupt-testcases/check-magic-bits.ee264 outputs/corrupt_output08.ppm
test9: pa06
	! $(VALGRIND) --log-file=outputs/memoutput09 ./pa06 images/corrupt-testcases/comment-has-no-null-byte.ee264 outputs/corrupt_output09.ppm
test10: pa06
	! $(VALGRIND) --log-file=outputs/memoutput10 ./pa06 images/corrupt-testcases/height0.ee264 outputs/corrupt_output10.ppm
test11: pa06
	! $(VALGRIND) --log-file=outputs/memoutput11 ./pa06 images/corrupt-testcases/height-wrong.ee264 outputs/corrupt_output11.ppm
test12: pa06
	! $(VALGRIND) --log-file=outputs/memoutput12 ./pa06 images/corrupt-testcases/incomplete-header.ee264 outputs/corrupt_output12.ppm
test13: pa06
	! $(VALGRIND) --log-file=outputs/memoutput13 ./pa06 images/corrupt-testcases/incomplete-image.ee264 outputs/corrupt_output13.ppm
test14: pa06
	! $(VALGRIND) --log-file=outputs/memoutput14 ./pa06 images/corrupt-testcases/width0.ee264 outputs/corrupt_output14.ppm






build: $(TARGET)

clean:
	@cd $(CURDIR)
	rm -rf $(TARGET) $(OBJF) outputs

environment:
	@cd $(CURDIR)
	@mkdir -p outputs
	@mkdir -p $(OBJF)

help:
	@echo
	@echo "   You do NOT need to use make to run your program. (See below.)"
	@echo
	@echo "   make            Build $(TARGET)"
	@echo "   make testall    Run /all/ testcases"
	@echo "   make clean      Remove all temporary files"
	@echo "   make help       Print this message"
	@echo
	@echo "   There are 13 testcases. (i.e., 0 through 109.) You can run an "
	@echo "   individual testcase as follows:"
	@echo
	@echo "   make test0      Run the zeroeth testcase"
	@echo "   make test1      Run the first testcase"
	@echo "   ...             etc."
	@echo

$(TARGET): $(OBJS) | environment
	$(GCC) $(CFLAGS) $(OBJS) $(LIBS) -o $@

$(OBJF)/%.o: %.c | environment
	@$(GCC) -MM $(CFLAGS) $< | sed 's,^\([^ ]\),$(OBJF)\/\1,g' | sed '$$ s,$$, \\,' > $(OBJF)/$<.P
	$(GCC) $(CFLAGS) -c -o $@ $<

#${TESTS}: test%: $(TARGET) | environment
#	@./bin/test.sh "$(TARGET)" inputs/input$* outputs/output$* expected/expected$* outputs/valgrind-log$*


