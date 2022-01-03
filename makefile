SRC_DIR = src
OBJ_DIR = obj
SORTIE_DIR= sortie
EXEC = geometrie

SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
SORTIE = $(wildcard $(SORTIE_DIR)/*)

CFLAGS += -Wall

.PHONY: all clean

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)
	$(RM) $(EXEC)
	$(RM) $(SORTIE)
