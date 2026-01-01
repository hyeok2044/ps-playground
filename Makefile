CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2
TARGET = main

# 파일 목록 관리
SRCS = $(wildcard *.cpp)
IN_FILES = $(wildcard *.in)

.PHONY: run clean judge help all $(SRCS) $(IN_FILES)
.ONESHELL:

# 기본 타겟
all: help

# 1. 컴파일 규칙: make 21315.cpp
$(SRCS):
	@echo "--- Compiling $@ -> $(TARGET) ---"
	$(CXX) $(CXXFLAGS) -o $(TARGET) $@

# 2. 실행 규칙: make run <입력파일>
run:
	@ARG="$(word 2,$(MAKECMDGOALS))"
	@if [ -z "$$ARG" ]; then \
		echo "--- Running $(TARGET) (Standard Input) ---"; \
		./$(TARGET); \
	else \
		echo "--- Running $(TARGET) with input: $$ARG ---"; \
		./$(TARGET) < "$$ARG"; \
	fi

# 3. 채점 규칙: make judge
# 모든 *.in 파일을 순회하며 *.out 파일과 비교합니다.
judge:
	@if [ ! -f "./$(TARGET)" ]; then \
		echo "Error: $(TARGET) 가 없습니다. 먼저 컴파일하세요 (예: make filename.cpp)"; \
		exit 1; \
	fi
	@count=0; \
	pass=0; \
	for in_file in $(IN_FILES); do \
		base=$${in_file%.in}; \
		out_file="$$base.out"; \
		count=$$((count + 1)); \
		echo -n "Test Case $$count ($$in_file): "; \
		if [ ! -f "$$out_file" ]; then \
			echo "SKIP (정답 파일 $$out_file 이 없습니다)"; \
			continue; \
		fi; \
		./$(TARGET) < $$in_file > $$base.res; \
		if diff -Z $$base.res $$out_file > /dev/null; then \
			echo "PASS"; \
			pass=$$((pass + 1)); \
		else \
			echo "FAIL"; \
			echo "  [Diff 결과]"; \
			diff -y -Z $$base.res $$out_file | head -n 5; \
		fi; \
		rm -f $$base.res; \
	done; \
	echo "--- Result: $$pass / $$count passed ---"

# 자동완성을 위한 더미 타겟
$(IN_FILES):
	@:
$(word 2,$(MAKECMDGOALS)):
	@:

clean:
	rm -f $(TARGET) $(TARGET).exe *.res

help:
	@echo "사용법:"
	@echo "  make <파일명>.cpp      : 컴파일"
	@echo "  make run <파일명>.in   : 특정 파일로 실행"
	@echo "  make judge             : 모든 *.in / *.out 비교 채점"
	@echo "  make clean             : 실행 파일 및 임시 결과 삭제"
