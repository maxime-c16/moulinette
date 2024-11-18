# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/21 16:16:09 by mcauchy           #+#    #+#              #
#    Updated: 2024/10/21 16:16:54 by mcauchy          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

UNAME_S := $(shell uname)

ifeq ($(UNAME_S), Darwin)
	PLATFORM = macos
else ifeq ($(UNAME_S), Linux)
	PLATFORM = linux
else
	$(error Platform not supported)
endif

include Makefile.$(PLATFORM)

override PLATFORM ?= $(shell uname | tr '[:upper:]' '[:lower:]')

.PHONY: help
help:
	@echo "Platform detected: $(PLATFORM)"
	@echo "Available targets:"
	@echo "  all        - Build everything"
	@echo "  clean      - Clean object files"
	@echo "  fclean     - Clean object files and binaries"
	@echo "  re         - Rebuild everything"
