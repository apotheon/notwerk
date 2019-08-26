CC?=clang -std=c99

commit:
	@fossil commit -m '$(m)'

sync:
	@fossil sync
	@fossgit
