CC?=clang -std=c99

help:
	@echo ' commit m=MESSAGE     commit to Fossil repo with specified message'
	@echo ' sync                 sync committed changes and push mirrors'
	@echo ' up m=MESSAGE         commit and sync with specified message'

commit:
	@fossil commit -m '$(m)'

sync:
	@fossil sync
	@fossgit

up: commit sync

testcli:
	@$(CC) src/cli_spec.c src/cli.c src/util.c
	@a.out
	@rm a.out

testutil:
	@$(CC) src/util_spec.c src/util.c
	@a.out
	@rm a.out

test: testcli testutil
