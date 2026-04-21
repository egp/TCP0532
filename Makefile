# Makefile v2
ARDUINO_CLI ?= arduino-cli
CXX ?= c++
CXXFLAGS ?= -std=c++17 -Wall -Wextra -Werror -pedantic

LIBRARY_DIR ?= .
EXAMPLE ?= examples/ReaderAlive
FQBN ?= arduino:avr:uno
BUILD_DIR ?= build
HOST_BUILD_DIR ?= build/host

ALL_FQBNS := \
	arduino:avr:uno \
	arduino:renesas_uno:minima \
	arduino:renesas_uno:unor4wifi

HOST_TEST_SOURCES := $(sort $(wildcard tests/host/test_*.cpp))
HOST_TEST_BINS := $(patsubst tests/host/%.cpp,$(HOST_BUILD_DIR)/%,$(HOST_TEST_SOURCES))

.PHONY: help compile compile-all test clean core-update core-install-avr core-install-renesas

help:
	@echo "Targets:"
	@echo "  make compile            Compile EXAMPLE for FQBN=$(FQBN)"
	@echo "  make compile-all        Compile the example for all default boards"
	@echo "  make test               Build and run host tests"
	@echo "  make clean              Remove build artifacts"
	@echo "  make core-update        Run arduino-cli core update-index"
	@echo "  make core-install-avr   Install arduino:avr"
	@echo "  make core-install-renesas Install arduino:renesas_uno"
	@echo
	@echo "Variables:"
	@echo "  EXAMPLE=<path>          default: examples/ReaderAlive"
	@echo "  FQBN=<fqbn>             default: arduino:avr:uno"

compile:
	@mkdir -p "$(BUILD_DIR)"
	@$(ARDUINO_CLI) compile \
		--fqbn "$(FQBN)" \
		--library "$(LIBRARY_DIR)" \
		--build-path "$(BUILD_DIR)/$$(echo '$(FQBN)' | tr ':' '_')" \
		"$(EXAMPLE)"

compile-all:
	@set -e; \
	for fqbn in $(ALL_FQBNS); do \
		echo "Compiling $(EXAMPLE) for $$fqbn"; \
		$(MAKE) --no-print-directory compile FQBN=$$fqbn; \
	done

test: $(HOST_TEST_BINS)
	@set -e; \
	for test_bin in $(HOST_TEST_BINS); do \
		echo "Running $$(basename "$$test_bin")"; \
		"$$test_bin"; \
	done

$(HOST_BUILD_DIR)/test_%: tests/host/test_%.cpp src/TCP0532.cpp
	@mkdir -p "$(HOST_BUILD_DIR)"
	@$(CXX) $(CXXFLAGS) \
		-I./src \
		-I./tests/host \
		$^ \
		-o "$@"

clean:
	rm -rf "$(BUILD_DIR)"

core-update:
	$(ARDUINO_CLI) core update-index

core-install-avr:
	$(ARDUINO_CLI) core install arduino:avr

core-install-renesas:
	$(ARDUINO_CLI) core install arduino:renesas_uno
# Makefile v2