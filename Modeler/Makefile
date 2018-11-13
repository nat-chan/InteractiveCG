

WORKDIR = `pwd`

CC = gcc
CXX = g++
AR = ar
LD = g++
WINDRES = windres

INC = -I/home/N/dev/fltk-1.3.3/include -I/usr/include 
CFLAGS = `/home/N/dev/fltk-1.3.3/fltk-config --cxxflags` 
RESINC = 
LIBDIR = -L/home/N/dev/fltk-1.3.3/lib -L/usr/lib64
LIB =\
/home/N/dev/fltk-1.3.3/lib/libfltk_images.a  \
/home/N/dev/fltk-1.3.3/lib/libfltk_gl.a      \
/home/N/dev/fltk-1.3.3/lib/libfltk_forms.a   \
/home/N/dev/fltk-1.3.3/lib/libfltk.a         \
/usr/lib/x86_64-linux-gnu/libpng12.so.0      \
/usr/lib/x86_64-linux-gnu/mesa/libGL.so.1    \
/usr/lib/x86_64-linux-gnu/libGLU.so.1        \
/usr/lib/x86_64-linux-gnu/libjpeg.so.62      \
/usr/lib/x86_64-linux-gnu/libjpeg.so.8       \

LDFLAGS = `/home/N/dev/fltk-1.3.3/fltk-config --ldstaticflags`

INC_DEBUG = $(INC)
CFLAGS_DEBUG = $(CFLAGS) -g
RESINC_DEBUG = $(RESINC)
RCFLAGS_DEBUG = $(RCFLAGS)
LIBDIR_DEBUG = $(LIBDIR)
LIB_DEBUG = $(LIB)
LDFLAGS_DEBUG = $(LDFLAGS)
OBJDIR_DEBUG = obj/Debug
DEP_DEBUG = 
OUT_DEBUG = bin/Debug/Modeler

INC_RELEASE = $(INC)
CFLAGS_RELEASE = $(CFLAGS) -O2 -s
RESINC_RELEASE = $(RESINC)
RCFLAGS_RELEASE = $(RCFLAGS)
LIBDIR_RELEASE = $(LIBDIR)
LIB_RELEASE = $(LIB)
LDFLAGS_RELEASE = $(LDFLAGS)
OBJDIR_RELEASE = obj/Release
DEP_RELEASE = 
OUT_RELEASE = bin/Release/Modeler

OBJ_DEBUG = $(OBJDIR_DEBUG)/modelerview.o $(OBJDIR_DEBUG)/linearcurveevaluator.o $(OBJDIR_DEBUG)/main.o $(OBJDIR_DEBUG)/modelerapp.o $(OBJDIR_DEBUG)/modelerdraw.o $(OBJDIR_DEBUG)/modelerui.o $(OBJDIR_DEBUG)/particleSystem.o $(OBJDIR_DEBUG)/point.o $(OBJDIR_DEBUG)/rect.o $(OBJDIR_DEBUG)/rulerwindow.o $(OBJDIR_DEBUG)/animatoruiwindows.o $(OBJDIR_DEBUG)/camera.o $(OBJDIR_DEBUG)/color.o $(OBJDIR_DEBUG)/curve.o $(OBJDIR_DEBUG)/curveevaluator.o $(OBJDIR_DEBUG)/graphwidget.o $(OBJDIR_DEBUG)/imageio.o $(OBJDIR_DEBUG)/indicatorwindow.o

OBJ_RELEASE = $(OBJDIR_RELEASE)/modelerview.o $(OBJDIR_RELEASE)/linearcurveevaluator.o $(OBJDIR_RELEASE)/main.o $(OBJDIR_RELEASE)/modelerapp.o $(OBJDIR_RELEASE)/modelerdraw.o $(OBJDIR_RELEASE)/modelerui.o $(OBJDIR_RELEASE)/particleSystem.o $(OBJDIR_RELEASE)/point.o $(OBJDIR_RELEASE)/rect.o $(OBJDIR_RELEASE)/rulerwindow.o $(OBJDIR_RELEASE)/animatoruiwindows.o $(OBJDIR_RELEASE)/camera.o $(OBJDIR_RELEASE)/color.o $(OBJDIR_RELEASE)/curve.o $(OBJDIR_RELEASE)/curveevaluator.o $(OBJDIR_RELEASE)/graphwidget.o $(OBJDIR_RELEASE)/imageio.o $(OBJDIR_RELEASE)/indicatorwindow.o

all: debug release

clean: clean_debug clean_release

before_debug: 
	test -d bin/Debug || mkdir -p bin/Debug
	test -d $(OBJDIR_DEBUG) || mkdir -p $(OBJDIR_DEBUG)

after_debug: 

debug: before_debug out_debug after_debug

out_debug: before_debug $(OBJ_DEBUG) $(DEP_DEBUG)
	$(LD) $(LIBDIR_DEBUG) -o $(OUT_DEBUG) $(OBJ_DEBUG)  $(LDFLAGS_DEBUG) $(LIB_DEBUG)

$(OBJDIR_DEBUG)/modelerview.o: modelerview.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c modelerview.cpp -o $(OBJDIR_DEBUG)/modelerview.o

$(OBJDIR_DEBUG)/linearcurveevaluator.o: linearcurveevaluator.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c linearcurveevaluator.cpp -o $(OBJDIR_DEBUG)/linearcurveevaluator.o

$(OBJDIR_DEBUG)/main.o: main.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c main.cpp -o $(OBJDIR_DEBUG)/main.o

$(OBJDIR_DEBUG)/modelerapp.o: modelerapp.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c modelerapp.cpp -o $(OBJDIR_DEBUG)/modelerapp.o

$(OBJDIR_DEBUG)/modelerdraw.o: modelerdraw.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c modelerdraw.cpp -o $(OBJDIR_DEBUG)/modelerdraw.o

$(OBJDIR_DEBUG)/modelerui.o: modelerui.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c modelerui.cpp -o $(OBJDIR_DEBUG)/modelerui.o

$(OBJDIR_DEBUG)/particleSystem.o: particleSystem.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c particleSystem.cpp -o $(OBJDIR_DEBUG)/particleSystem.o

$(OBJDIR_DEBUG)/point.o: point.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c point.cpp -o $(OBJDIR_DEBUG)/point.o

$(OBJDIR_DEBUG)/rect.o: rect.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c rect.cpp -o $(OBJDIR_DEBUG)/rect.o

$(OBJDIR_DEBUG)/rulerwindow.o: rulerwindow.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c rulerwindow.cpp -o $(OBJDIR_DEBUG)/rulerwindow.o

$(OBJDIR_DEBUG)/animatoruiwindows.o: animatoruiwindows.cxx
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c animatoruiwindows.cxx -o $(OBJDIR_DEBUG)/animatoruiwindows.o

$(OBJDIR_DEBUG)/camera.o: camera.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c camera.cpp -o $(OBJDIR_DEBUG)/camera.o

$(OBJDIR_DEBUG)/color.o: color.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c color.cpp -o $(OBJDIR_DEBUG)/color.o

$(OBJDIR_DEBUG)/curve.o: curve.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c curve.cpp -o $(OBJDIR_DEBUG)/curve.o

$(OBJDIR_DEBUG)/curveevaluator.o: curveevaluator.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c curveevaluator.cpp -o $(OBJDIR_DEBUG)/curveevaluator.o

$(OBJDIR_DEBUG)/graphwidget.o: graphwidget.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c graphwidget.cpp -o $(OBJDIR_DEBUG)/graphwidget.o

$(OBJDIR_DEBUG)/imageio.o: imageio.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c imageio.cpp -o $(OBJDIR_DEBUG)/imageio.o

$(OBJDIR_DEBUG)/indicatorwindow.o: indicatorwindow.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c indicatorwindow.cpp -o $(OBJDIR_DEBUG)/indicatorwindow.o

clean_debug: 
	rm -f $(OBJ_DEBUG) $(OUT_DEBUG)
	rm -rf bin/Debug
	rm -rf $(OBJDIR_DEBUG)

before_release: 
	test -d bin/Release || mkdir -p bin/Release
	test -d $(OBJDIR_RELEASE) || mkdir -p $(OBJDIR_RELEASE)

after_release: 

release: before_release out_release after_release

out_release: before_release $(OBJ_RELEASE) $(DEP_RELEASE)
	$(LD) $(LIBDIR_RELEASE) -o $(OUT_RELEASE) $(OBJ_RELEASE)  $(LDFLAGS_RELEASE) $(LIB_RELEASE)

$(OBJDIR_RELEASE)/modelerview.o: modelerview.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c modelerview.cpp -o $(OBJDIR_RELEASE)/modelerview.o

$(OBJDIR_RELEASE)/linearcurveevaluator.o: linearcurveevaluator.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c linearcurveevaluator.cpp -o $(OBJDIR_RELEASE)/linearcurveevaluator.o

$(OBJDIR_RELEASE)/main.o: main.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c main.cpp -o $(OBJDIR_RELEASE)/main.o

$(OBJDIR_RELEASE)/modelerapp.o: modelerapp.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c modelerapp.cpp -o $(OBJDIR_RELEASE)/modelerapp.o

$(OBJDIR_RELEASE)/modelerdraw.o: modelerdraw.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c modelerdraw.cpp -o $(OBJDIR_RELEASE)/modelerdraw.o

$(OBJDIR_RELEASE)/modelerui.o: modelerui.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c modelerui.cpp -o $(OBJDIR_RELEASE)/modelerui.o

$(OBJDIR_RELEASE)/particleSystem.o: particleSystem.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c particleSystem.cpp -o $(OBJDIR_RELEASE)/particleSystem.o

$(OBJDIR_RELEASE)/point.o: point.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c point.cpp -o $(OBJDIR_RELEASE)/point.o

$(OBJDIR_RELEASE)/rect.o: rect.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c rect.cpp -o $(OBJDIR_RELEASE)/rect.o

$(OBJDIR_RELEASE)/rulerwindow.o: rulerwindow.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c rulerwindow.cpp -o $(OBJDIR_RELEASE)/rulerwindow.o

$(OBJDIR_RELEASE)/animatoruiwindows.o: animatoruiwindows.cxx
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c animatoruiwindows.cxx -o $(OBJDIR_RELEASE)/animatoruiwindows.o

$(OBJDIR_RELEASE)/camera.o: camera.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c camera.cpp -o $(OBJDIR_RELEASE)/camera.o

$(OBJDIR_RELEASE)/color.o: color.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c color.cpp -o $(OBJDIR_RELEASE)/color.o

$(OBJDIR_RELEASE)/curve.o: curve.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c curve.cpp -o $(OBJDIR_RELEASE)/curve.o

$(OBJDIR_RELEASE)/curveevaluator.o: curveevaluator.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c curveevaluator.cpp -o $(OBJDIR_RELEASE)/curveevaluator.o

$(OBJDIR_RELEASE)/graphwidget.o: graphwidget.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c graphwidget.cpp -o $(OBJDIR_RELEASE)/graphwidget.o

$(OBJDIR_RELEASE)/imageio.o: imageio.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c imageio.cpp -o $(OBJDIR_RELEASE)/imageio.o

$(OBJDIR_RELEASE)/indicatorwindow.o: indicatorwindow.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c indicatorwindow.cpp -o $(OBJDIR_RELEASE)/indicatorwindow.o

clean_release: 
	rm -f $(OBJ_RELEASE) $(OUT_RELEASE)
	rm -rf bin/Release
	rm -rf $(OBJDIR_RELEASE)

.PHONY: before_debug after_debug clean_debug before_release after_release clean_release

