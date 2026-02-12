CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Wpedantic -g
TARGET_NAME = meu_programa
BUILD_DIR = build

# Define o caminho completo do executável
TARGET = $(BUILD_DIR)/$(TARGET_NAME)

# Lista de arquivos .c e define que os .o ficarão dentro da pasta build
SRCS = $(wildcard *.c)
OBJS = $(addprefix $(BUILD_DIR)/, $(SRCS:.c=.o))

# Regra principal
all: $(BUILD_DIR) $(TARGET)

# Cria a pasta build se ela não existir
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Linkagem final (une os .o no executável)
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

# Compilação dos arquivos objeto
# O | $(BUILD_DIR) garante que a pasta build exista antes de compilar
$(BUILD_DIR)/%.o: %.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)

run: all
	./$(TARGET)
