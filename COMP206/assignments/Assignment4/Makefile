CXX ?= g++-16
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic
TARGET = Wonderland
SOURCES = main.cpp Game.cpp Control.cpp Action.cpp Location.cpp Item.cpp Character.cpp Inventory.cpp TextUtils.cpp

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET)

clean:
	rm -f $(TARGET)
