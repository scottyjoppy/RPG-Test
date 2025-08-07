CXX = g++
CXXFLAGS = -std=c++17
INCLUDES = -IC:\SFML\include
LIBDIRS = -LC:\SFML\lib
LIBS = -lsfml-graphics -lsfml-window -lsfml-system

TARGET = game_test.exe
SOURCES = game_test.cpp

all: $(TARGET)

$(TARGET): $(SOURCES)
	@echo Compiling $(TARGET)...
	$(CXX) $(CXXFLAGS) $(SOURCES) $(INCLUDES) $(LIBDIRS) $(LIBS) -o $(TARGET)
	@echo Build successful!

run:  $(TARGET)
	@echo Running $(TARGET)...
	@$(TARGET)
	@echo.
	@pause

test: $(TARGET) run

clean:
	@if exist $(TARGET) del /q $(TARGET)
	@echo Cleanup complete!

help:
	@echo Available targets:
	@echo	all	- Build the program (default)
	@echo	run	- Build and run the program
	@echo	test	- Same as run
	@echo	cleanup - Remove compiled files
	@echo	help	- Show this help

.PHONY: all run test clean help
