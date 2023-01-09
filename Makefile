CC := g++ -pthread

BUILD_DIR=build
SRC_DIR=./src
COMPILER_FLAGS = -w -I /opt/homebrew/Cellar/sfml/2.5.1_2/include
LINKER_FLAGS = -L /opt/homebrew/Cellar/sfml/2.5.1_2/lib -lsfml-graphics -lsfml-window -lsfml-system
OUTPUT_NAME=game.out

all: ${OUTPUT_NAME}

${OUTPUT_NAME}: rm mk ${BUILD_DIR}/main.o ${BUILD_DIR}/game.o ${BUILD_DIR}/player.o ${BUILD_DIR}/line.o
	$(CC) ${BUILD_DIR}/main.o ${BUILD_DIR}/game.o ${BUILD_DIR}/player.o ${BUILD_DIR}/line.o ${COMPILER_FLAGS} ${LINKER_FLAGS} -o ./${OUTPUT_NAME}

${BUILD_DIR}/main.o: ${SRC_DIR}/main.cpp
	$(CC) -c ${SRC_DIR}/main.cpp ${COMPILER_FLAGS} -o ${BUILD_DIR}/main.o

${BUILD_DIR}/game.o: ${SRC_DIR}/game.cpp
	$(CC) -c ${SRC_DIR}/game.cpp ${COMPILER_FLAGS} -o ${BUILD_DIR}/game.o

${BUILD_DIR}/player.o: ${SRC_DIR}/player.cpp
	$(CC) -c ${SRC_DIR}/player.cpp ${COMPILER_FLAGS} -o ${BUILD_DIR}/player.o

${BUILD_DIR}/line.o: ${SRC_DIR}/line.cpp
	$(CC) -c ${SRC_DIR}/line.cpp ${COMPILER_FLAGS} -o ${BUILD_DIR}/line.o

run: ${OUTPUT_NAME}
	./${OUTPUT_NAME}

mk:
	mkdir ./${BUILD_DIR}

rm:
	rm -rf ${BUILD_DIR}/ ./${OUTPUT_NAME}