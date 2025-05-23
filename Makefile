# Find all directories containing a Makefile
SUB_MAKEFILES := $(shell find . -name Makefile -not -path "./Makefile")

# run all the makefiles
all: check

check:
	@echo "========== Building all projects =========="
	@for makefile in $(SUB_MAKEFILES); do \
		dir=$$(dirname $$makefile); \
		echo "--- Entering $$dir ---"; \
		$(MAKE) -C $$dir all || { echo "--- Error building in $$dir ---"; exit 1; }; \
		echo "--- Exiting $$dir ---"; \
		echo ""; \
	done
	@echo "========== All projects built successfully =========="

fclean: # runs fclean on each target
	@echo "========== Cleaning all projects =========="
	@for makefile in $(SUB_MAKEFILES); do \
		dir=$$(dirname $$makefile); \
		echo "--- Entering $$dir ---"; \
		$(MAKE) -C $$dir fclean || { echo "--- Error cleaning in $$dir ---"; exit 1; }; \
		echo "--- Exiting $$dir ---"; \
		echo ""; \
	done
	@echo "========== All projects cleaned successfully =========="
