

WORKDIR = `pwd`

CC = gcc
CXX = g++
AR = ar
LD = g++
WINDRES = windres

#ここ
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

#sudo apt-get install libjpeg62
#for CentOS
#/usr/lib64/libjpeg.so.62
#/usr/lib64/libpng12.so.0
#/usr/lib64/libGL.so.1
#/usr/lib64/libGLU.so.1 
LDFLAGS = `/home/N/dev/fltk-1.3.3/fltk-config --ldstaticflags`
#ここまで

INC_DEBUG = $(INC)
CFLAGS_DEBUG = $(CFLAGS) -g
RESINC_DEBUG = $(RESINC)
RCFLAGS_DEBUG = $(RCFLAGS)
LIBDIR_DEBUG = $(LIBDIR)
LIB_DEBUG = $(LIB)
LDFLAGS_DEBUG = $(LDFLAGS)
OBJDIR_DEBUG = obj/Debug
DEP_DEBUG = 
OUT_DEBUG = bin/Debug/RayTracer

INC_RELEASE = $(INC)
CFLAGS_RELEASE = $(CFLAGS) -O2 -s
RESINC_RELEASE = $(RESINC)
RCFLAGS_RELEASE = $(RCFLAGS)
LIBDIR_RELEASE = $(LIBDIR)
LIB_RELEASE = $(LIB)
LDFLAGS_RELEASE = $(LDFLAGS)
OBJDIR_RELEASE = obj/Release
DEP_RELEASE = 
OUT_RELEASE = bin/Release/RayTracer

OBJ_DEBUG = $(OBJDIR_DEBUG)/ui/GraphicalUI.o $(OBJDIR_DEBUG)/scene/camera.o $(OBJDIR_DEBUG)/scene/light.o $(OBJDIR_DEBUG)/scene/material.o $(OBJDIR_DEBUG)/scene/ray.o $(OBJDIR_DEBUG)/scene/scene.o $(OBJDIR_DEBUG)/ui/CommandLineUI.o $(OBJDIR_DEBUG)/parser/Tokenizer.o $(OBJDIR_DEBUG)/ui/ModelerCamera.o $(OBJDIR_DEBUG)/ui/TraceGLWindow.o $(OBJDIR_DEBUG)/ui/debuggingView.o $(OBJDIR_DEBUG)/ui/debuggingWindow.o $(OBJDIR_DEBUG)/ui/glObjects.o $(OBJDIR_DEBUG)/fileio/buffer.o $(OBJDIR_DEBUG)/SceneObjects/Box.o $(OBJDIR_DEBUG)/SceneObjects/Cone.o $(OBJDIR_DEBUG)/SceneObjects/Cylinder.o $(OBJDIR_DEBUG)/SceneObjects/Sphere.o $(OBJDIR_DEBUG)/SceneObjects/Square.o $(OBJDIR_DEBUG)/SceneObjects/trimesh.o $(OBJDIR_DEBUG)/RayTracer.o $(OBJDIR_DEBUG)/fileio/imageio.o $(OBJDIR_DEBUG)/getopt.o $(OBJDIR_DEBUG)/main.o $(OBJDIR_DEBUG)/parser/Parser.o $(OBJDIR_DEBUG)/parser/ParserException.o $(OBJDIR_DEBUG)/parser/Token.o

OBJ_RELEASE = $(OBJDIR_RELEASE)/ui/GraphicalUI.o $(OBJDIR_RELEASE)/scene/camera.o $(OBJDIR_RELEASE)/scene/light.o $(OBJDIR_RELEASE)/scene/material.o $(OBJDIR_RELEASE)/scene/ray.o $(OBJDIR_RELEASE)/scene/scene.o $(OBJDIR_RELEASE)/ui/CommandLineUI.o $(OBJDIR_RELEASE)/parser/Tokenizer.o $(OBJDIR_RELEASE)/ui/ModelerCamera.o $(OBJDIR_RELEASE)/ui/TraceGLWindow.o $(OBJDIR_RELEASE)/ui/debuggingView.o $(OBJDIR_RELEASE)/ui/debuggingWindow.o $(OBJDIR_RELEASE)/ui/glObjects.o $(OBJDIR_RELEASE)/fileio/buffer.o $(OBJDIR_RELEASE)/SceneObjects/Box.o $(OBJDIR_RELEASE)/SceneObjects/Cone.o $(OBJDIR_RELEASE)/SceneObjects/Cylinder.o $(OBJDIR_RELEASE)/SceneObjects/Sphere.o $(OBJDIR_RELEASE)/SceneObjects/Square.o $(OBJDIR_RELEASE)/SceneObjects/trimesh.o $(OBJDIR_RELEASE)/RayTracer.o $(OBJDIR_RELEASE)/fileio/imageio.o $(OBJDIR_RELEASE)/getopt.o $(OBJDIR_RELEASE)/main.o $(OBJDIR_RELEASE)/parser/Parser.o $(OBJDIR_RELEASE)/parser/ParserException.o $(OBJDIR_RELEASE)/parser/Token.o

all: debug release

clean: clean_debug clean_release

before_debug: 
	test -d bin/Debug || mkdir -p bin/Debug
	test -d $(OBJDIR_DEBUG)/ui || mkdir -p $(OBJDIR_DEBUG)/ui
	test -d $(OBJDIR_DEBUG)/scene || mkdir -p $(OBJDIR_DEBUG)/scene
	test -d $(OBJDIR_DEBUG)/parser || mkdir -p $(OBJDIR_DEBUG)/parser
	test -d $(OBJDIR_DEBUG)/fileio || mkdir -p $(OBJDIR_DEBUG)/fileio
	test -d $(OBJDIR_DEBUG)/SceneObjects || mkdir -p $(OBJDIR_DEBUG)/SceneObjects
	test -d $(OBJDIR_DEBUG) || mkdir -p $(OBJDIR_DEBUG)

after_debug: 

debug: before_debug out_debug after_debug

out_debug: before_debug $(OBJ_DEBUG) $(DEP_DEBUG)
	$(LD) $(LIBDIR_DEBUG) -o $(OUT_DEBUG) $(OBJ_DEBUG)  $(LDFLAGS_DEBUG) $(LIB_DEBUG)

$(OBJDIR_DEBUG)/ui/GraphicalUI.o: ui/GraphicalUI.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c ui/GraphicalUI.cpp -o $(OBJDIR_DEBUG)/ui/GraphicalUI.o

$(OBJDIR_DEBUG)/scene/camera.o: scene/camera.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c scene/camera.cpp -o $(OBJDIR_DEBUG)/scene/camera.o

$(OBJDIR_DEBUG)/scene/light.o: scene/light.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c scene/light.cpp -o $(OBJDIR_DEBUG)/scene/light.o

$(OBJDIR_DEBUG)/scene/material.o: scene/material.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c scene/material.cpp -o $(OBJDIR_DEBUG)/scene/material.o

$(OBJDIR_DEBUG)/scene/ray.o: scene/ray.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c scene/ray.cpp -o $(OBJDIR_DEBUG)/scene/ray.o

$(OBJDIR_DEBUG)/scene/scene.o: scene/scene.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c scene/scene.cpp -o $(OBJDIR_DEBUG)/scene/scene.o

$(OBJDIR_DEBUG)/ui/CommandLineUI.o: ui/CommandLineUI.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c ui/CommandLineUI.cpp -o $(OBJDIR_DEBUG)/ui/CommandLineUI.o

$(OBJDIR_DEBUG)/parser/Tokenizer.o: parser/Tokenizer.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c parser/Tokenizer.cpp -o $(OBJDIR_DEBUG)/parser/Tokenizer.o

$(OBJDIR_DEBUG)/ui/ModelerCamera.o: ui/ModelerCamera.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c ui/ModelerCamera.cpp -o $(OBJDIR_DEBUG)/ui/ModelerCamera.o

$(OBJDIR_DEBUG)/ui/TraceGLWindow.o: ui/TraceGLWindow.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c ui/TraceGLWindow.cpp -o $(OBJDIR_DEBUG)/ui/TraceGLWindow.o

$(OBJDIR_DEBUG)/ui/debuggingView.o: ui/debuggingView.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c ui/debuggingView.cpp -o $(OBJDIR_DEBUG)/ui/debuggingView.o

$(OBJDIR_DEBUG)/ui/debuggingWindow.o: ui/debuggingWindow.cxx
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c ui/debuggingWindow.cxx -o $(OBJDIR_DEBUG)/ui/debuggingWindow.o

$(OBJDIR_DEBUG)/ui/glObjects.o: ui/glObjects.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c ui/glObjects.cpp -o $(OBJDIR_DEBUG)/ui/glObjects.o

$(OBJDIR_DEBUG)/fileio/buffer.o: fileio/buffer.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c fileio/buffer.cpp -o $(OBJDIR_DEBUG)/fileio/buffer.o

$(OBJDIR_DEBUG)/SceneObjects/Box.o: SceneObjects/Box.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c SceneObjects/Box.cpp -o $(OBJDIR_DEBUG)/SceneObjects/Box.o

$(OBJDIR_DEBUG)/SceneObjects/Cone.o: SceneObjects/Cone.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c SceneObjects/Cone.cpp -o $(OBJDIR_DEBUG)/SceneObjects/Cone.o

$(OBJDIR_DEBUG)/SceneObjects/Cylinder.o: SceneObjects/Cylinder.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c SceneObjects/Cylinder.cpp -o $(OBJDIR_DEBUG)/SceneObjects/Cylinder.o

$(OBJDIR_DEBUG)/SceneObjects/Sphere.o: SceneObjects/Sphere.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c SceneObjects/Sphere.cpp -o $(OBJDIR_DEBUG)/SceneObjects/Sphere.o

$(OBJDIR_DEBUG)/SceneObjects/Square.o: SceneObjects/Square.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c SceneObjects/Square.cpp -o $(OBJDIR_DEBUG)/SceneObjects/Square.o

$(OBJDIR_DEBUG)/SceneObjects/trimesh.o: SceneObjects/trimesh.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c SceneObjects/trimesh.cpp -o $(OBJDIR_DEBUG)/SceneObjects/trimesh.o

$(OBJDIR_DEBUG)/RayTracer.o: RayTracer.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c RayTracer.cpp -o $(OBJDIR_DEBUG)/RayTracer.o

$(OBJDIR_DEBUG)/fileio/imageio.o: fileio/imageio.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c fileio/imageio.cpp -o $(OBJDIR_DEBUG)/fileio/imageio.o

$(OBJDIR_DEBUG)/getopt.o: getopt.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c getopt.cpp -o $(OBJDIR_DEBUG)/getopt.o

$(OBJDIR_DEBUG)/main.o: main.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c main.cpp -o $(OBJDIR_DEBUG)/main.o

$(OBJDIR_DEBUG)/parser/Parser.o: parser/Parser.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c parser/Parser.cpp -o $(OBJDIR_DEBUG)/parser/Parser.o

$(OBJDIR_DEBUG)/parser/ParserException.o: parser/ParserException.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c parser/ParserException.cpp -o $(OBJDIR_DEBUG)/parser/ParserException.o

$(OBJDIR_DEBUG)/parser/Token.o: parser/Token.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c parser/Token.cpp -o $(OBJDIR_DEBUG)/parser/Token.o

clean_debug: 
	rm -f $(OBJ_DEBUG) $(OUT_DEBUG)
	rm -rf bin/Debug
	rm -rf $(OBJDIR_DEBUG)/ui
	rm -rf $(OBJDIR_DEBUG)/scene
	rm -rf $(OBJDIR_DEBUG)/parser
	rm -rf $(OBJDIR_DEBUG)/fileio
	rm -rf $(OBJDIR_DEBUG)/SceneObjects
	rm -rf $(OBJDIR_DEBUG)

before_release: 
	test -d bin/Release || mkdir -p bin/Release
	test -d $(OBJDIR_RELEASE)/ui || mkdir -p $(OBJDIR_RELEASE)/ui
	test -d $(OBJDIR_RELEASE)/scene || mkdir -p $(OBJDIR_RELEASE)/scene
	test -d $(OBJDIR_RELEASE)/parser || mkdir -p $(OBJDIR_RELEASE)/parser
	test -d $(OBJDIR_RELEASE)/fileio || mkdir -p $(OBJDIR_RELEASE)/fileio
	test -d $(OBJDIR_RELEASE)/SceneObjects || mkdir -p $(OBJDIR_RELEASE)/SceneObjects
	test -d $(OBJDIR_RELEASE) || mkdir -p $(OBJDIR_RELEASE)

after_release: 

release: before_release out_release after_release

out_release: before_release $(OBJ_RELEASE) $(DEP_RELEASE)
	$(LD) $(LIBDIR_RELEASE) -o $(OUT_RELEASE) $(OBJ_RELEASE)  $(LDFLAGS_RELEASE) $(LIB_RELEASE)

$(OBJDIR_RELEASE)/ui/GraphicalUI.o: ui/GraphicalUI.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c ui/GraphicalUI.cpp -o $(OBJDIR_RELEASE)/ui/GraphicalUI.o

$(OBJDIR_RELEASE)/scene/camera.o: scene/camera.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c scene/camera.cpp -o $(OBJDIR_RELEASE)/scene/camera.o

$(OBJDIR_RELEASE)/scene/light.o: scene/light.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c scene/light.cpp -o $(OBJDIR_RELEASE)/scene/light.o

$(OBJDIR_RELEASE)/scene/material.o: scene/material.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c scene/material.cpp -o $(OBJDIR_RELEASE)/scene/material.o

$(OBJDIR_RELEASE)/scene/ray.o: scene/ray.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c scene/ray.cpp -o $(OBJDIR_RELEASE)/scene/ray.o

$(OBJDIR_RELEASE)/scene/scene.o: scene/scene.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c scene/scene.cpp -o $(OBJDIR_RELEASE)/scene/scene.o

$(OBJDIR_RELEASE)/ui/CommandLineUI.o: ui/CommandLineUI.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c ui/CommandLineUI.cpp -o $(OBJDIR_RELEASE)/ui/CommandLineUI.o

$(OBJDIR_RELEASE)/parser/Tokenizer.o: parser/Tokenizer.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c parser/Tokenizer.cpp -o $(OBJDIR_RELEASE)/parser/Tokenizer.o

$(OBJDIR_RELEASE)/ui/ModelerCamera.o: ui/ModelerCamera.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c ui/ModelerCamera.cpp -o $(OBJDIR_RELEASE)/ui/ModelerCamera.o

$(OBJDIR_RELEASE)/ui/TraceGLWindow.o: ui/TraceGLWindow.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c ui/TraceGLWindow.cpp -o $(OBJDIR_RELEASE)/ui/TraceGLWindow.o

$(OBJDIR_RELEASE)/ui/debuggingView.o: ui/debuggingView.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c ui/debuggingView.cpp -o $(OBJDIR_RELEASE)/ui/debuggingView.o

$(OBJDIR_RELEASE)/ui/debuggingWindow.o: ui/debuggingWindow.cxx
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c ui/debuggingWindow.cxx -o $(OBJDIR_RELEASE)/ui/debuggingWindow.o

$(OBJDIR_RELEASE)/ui/glObjects.o: ui/glObjects.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c ui/glObjects.cpp -o $(OBJDIR_RELEASE)/ui/glObjects.o

$(OBJDIR_RELEASE)/fileio/buffer.o: fileio/buffer.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c fileio/buffer.cpp -o $(OBJDIR_RELEASE)/fileio/buffer.o

$(OBJDIR_RELEASE)/SceneObjects/Box.o: SceneObjects/Box.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c SceneObjects/Box.cpp -o $(OBJDIR_RELEASE)/SceneObjects/Box.o

$(OBJDIR_RELEASE)/SceneObjects/Cone.o: SceneObjects/Cone.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c SceneObjects/Cone.cpp -o $(OBJDIR_RELEASE)/SceneObjects/Cone.o

$(OBJDIR_RELEASE)/SceneObjects/Cylinder.o: SceneObjects/Cylinder.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c SceneObjects/Cylinder.cpp -o $(OBJDIR_RELEASE)/SceneObjects/Cylinder.o

$(OBJDIR_RELEASE)/SceneObjects/Sphere.o: SceneObjects/Sphere.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c SceneObjects/Sphere.cpp -o $(OBJDIR_RELEASE)/SceneObjects/Sphere.o

$(OBJDIR_RELEASE)/SceneObjects/Square.o: SceneObjects/Square.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c SceneObjects/Square.cpp -o $(OBJDIR_RELEASE)/SceneObjects/Square.o

$(OBJDIR_RELEASE)/SceneObjects/trimesh.o: SceneObjects/trimesh.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c SceneObjects/trimesh.cpp -o $(OBJDIR_RELEASE)/SceneObjects/trimesh.o

$(OBJDIR_RELEASE)/RayTracer.o: RayTracer.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c RayTracer.cpp -o $(OBJDIR_RELEASE)/RayTracer.o

$(OBJDIR_RELEASE)/fileio/imageio.o: fileio/imageio.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c fileio/imageio.cpp -o $(OBJDIR_RELEASE)/fileio/imageio.o

$(OBJDIR_RELEASE)/getopt.o: getopt.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c getopt.cpp -o $(OBJDIR_RELEASE)/getopt.o

$(OBJDIR_RELEASE)/main.o: main.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c main.cpp -o $(OBJDIR_RELEASE)/main.o

$(OBJDIR_RELEASE)/parser/Parser.o: parser/Parser.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c parser/Parser.cpp -o $(OBJDIR_RELEASE)/parser/Parser.o

$(OBJDIR_RELEASE)/parser/ParserException.o: parser/ParserException.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c parser/ParserException.cpp -o $(OBJDIR_RELEASE)/parser/ParserException.o

$(OBJDIR_RELEASE)/parser/Token.o: parser/Token.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c parser/Token.cpp -o $(OBJDIR_RELEASE)/parser/Token.o

clean_release: 
	rm -f $(OBJ_RELEASE) $(OUT_RELEASE)
	rm -rf bin/Release
	rm -rf $(OBJDIR_RELEASE)/ui
	rm -rf $(OBJDIR_RELEASE)/scene
	rm -rf $(OBJDIR_RELEASE)/parser
	rm -rf $(OBJDIR_RELEASE)/fileio
	rm -rf $(OBJDIR_RELEASE)/SceneObjects
	rm -rf $(OBJDIR_RELEASE)

.PHONY: before_debug after_debug clean_debug before_release after_release clean_release

