NAME		= RPN
CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98# -Wshadow
RM	= rm -fr

SRC :=	main.cpp \
		RPN.cpp

OBJ_PATH	=./obj/
OBJ			= $(addprefix $(OBJ_PATH), $(notdir $(SRC:.cpp=.o)))
$(OBJ_PATH)%.o: %.cpp
	@mkdir -p $(OBJ_PATH)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -I $(OBJ_PATH) -o $(NAME)

PHONY := all
all:		$(NAME)

PHONY += clean
clean:
	$(RM) $(OBJ) $(OBJ_PATH)

PHONY += fclean
fclean: clean
	$(RM) $(NAME)

PHONY += re
re: fclean all

TIDY_FLAGS =	'clang-analyzer-*,\
				bugprone-*,\
				performance-*,\
				misc-const-correctness,\
				misc-misplaced-const,\
				cppcoreguidelines-avoid-const-or-ref-data-members,\
				readability-avoid-const-params-in-decls,\
				readability-const-return-type,\
				readability-make-member-function-const,\
				llvm-include-order,\
				cppcoreguidelines-init-variables,\
				llvmlibc-inline-function-decl,\
				hicpp-braces-around-statements,\
				readability-braces-around-statements,\
				google-runtime-int,\
				readability-implicit-bool-conversion,\
				readability-isolate-declaration,\
				readability-redundant-string-init,\
				cppcoreguidelines-special-member-functions,\
				hicpp-special-member-functions,\
				readability-convert-member-functions-to-static,\
				google-explicit-constructor,\
				hicpp-explicit-conversions,\
				hicpp-signed-bitwise,\
				hicpp-deprecated-headers,\
				modernize-deprecated-headers,\
				misc-use-anonymous-namespace,\
				misc-definitions-in-headers'

TIDY_EXTRA_ARGS =	--extra-arg=-std=c++98 \
					--extra-arg=-Iincludes \
					--extra-arg=-Wno-c++98-compat

CLANG_TIDY = clang-tidy-19

PHONY	+= tidy
tidy: ## run clang-tidy on project 
	@$(CLANG_TIDY) $(SRC) \
	--checks=$(TIDY_FLAGS) \
	$(TIDY_EXTRA_ARGS) \
	--header-filter='includes/.*' \
	--system-headers=false \
	--quiet \
	-- $(CXXFLAGS) $(INCLUDES)
	@echo "✅ check complete"

# DETECTED_SCAN_BUILD := $(firstword $(foreach v,$(shell seq 21 -1 15),$(if $(shell command -v scan-build-$(v) >/dev/null 2>&1 && echo scan-build-$(v)),scan-build-$(v))))
# Try to find the newest scan-build from version 21 down to 15
# If none are found in that range, default to scan-build-20 (original value)
PHONY += scan

SCAN_BUILD := $(firstword $(foreach v,$(shell seq 21 -1 15),$(if $(shell command -v scan-build-$(v)),scan-build-$(v))))
ifeq ($(SCAN_BUILD),)
SCAN_BUILD := scan-build-20
endif

scan: fclean ## Scan-build static analysis
	@echo "🔍 Running scan-build..."
	$(info Using scan-build: $(SCAN_BUILD))
	@SCAN_VIEWER=false CC=$(CC) CXX=$(CXX) $(SCAN_BUILD) \
		-enable-checker alpha \
		-enable-checker security -enable-checker unix -enable-checker core \
		-enable-checker cplusplus -enable-checker deadcode -enable-checker nullability \
		-analyzer-config aggressive-binary-operation-simplification=true \
		--status-bugs -v -V make
	@echo "✅ Scan-build analysis complete"

.PHONY = ${PHONY}
