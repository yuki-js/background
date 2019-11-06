OBJS=ai.o displaylist.o draw.o
OUTS=ai.out
CXX := clang++
CPPFLAGS+=
LDFLAGS+=-framework GLUT -framework OpenGL -framework CoreFoundation -framework AudioToolbox  -Wno-deprecated 

$(OUTS): $(OBJS)
	$(CXX) $(LDFLAGS) $^ -o $@

all: $(OUTS)

.PHONY: clean
clean:
	$(RM) $(OBJS)
	$(RM) $(OUTS)
