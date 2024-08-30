g++ src/*.cpp -o fish -I/usr/local/include/antlr4-runtime -std=c++17 -lantlr4-runtime -pthread -g  `llvm-config-17 --cflags --libs`
sudo cp fish /usr/local/bin