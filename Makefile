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
