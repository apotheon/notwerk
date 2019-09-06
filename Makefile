CC?=clang -std=c99

default:
	$(CC) -o nw src/nw.c src/cli.c src/util.c

help:
	@echo
	@echo 'USAGE: make [command [args]]'
	@echo
	@echo '    commit m=MESSAGE   commit to Fossil repo with specified message'
	@echo '    sync               sync committed changes and push mirrors'
	@echo '    up m=MESSAGE       commit and sync with specified message'
	@echo
	@echo '    test               run all specs'
	@echo '    testcli            run CLI spec'
	@echo '    testutil           run Util spec'
	@echo
	@echo '    try                try basic nw commands to view output'
	@echo

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

try:
	@$(CC) src/nw.c src/cli.c src/util.c
	@echo ' --------------'
	@echo '| NO ARGUMENTS |'
	@echo ' --------------'
	@a.out; echo
	@echo -n '==========================='
	@echo '==========================='
	@echo ' --------------'
	@echo '| HELP COMMAND |'
	@echo ' --------------'
	@a.out help; echo
	@echo -n '==========================='
	@echo '==========================='
	@echo ' -----------------'
	@echo '| INVALID COMMAND |'
	@echo ' -----------------'
	@a.out bogus; echo
	@rm a.out
