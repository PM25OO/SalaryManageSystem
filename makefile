# 编译器
CC = gcc

# 编译选项
CFLAGS = -Wall -g

# 头文件
DEPS = teacher.h

# 目标文件
OBJ = main.o functions.o

# 可执行文件名称
EXEC = salary_manager.exe

# 默认目标
all: $(EXEC)

# 链接目标文件生成可执行文件
$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

# 生成 .o 文件的规则
%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

# 清理生成的文件
clean:
ifeq ($(OS),Windows_NT)
	del /Q *.o $(EXEC)
else
	rm -f *.o $(EXEC)
endif

.PHONY: all clean
