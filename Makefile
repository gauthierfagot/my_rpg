all:
	gcc -o my_rpg main.c

clean:
	$(RM) my_rpg

fclean:
	$(RM) my_rpg

re:
	fclean
	all
