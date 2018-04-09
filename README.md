# Corewar

## Libft
Fonctions custom
### Malloc
`malloc()` ça pue donc on a `ealloc()`
C'est la meme sauf que c'est lui qui check le malloc et qui `exit()` si ça fail.
### Variadiques
```C
void				*freen(int n, ...);
```
Free n pointeurs.
Exemple
```C
freen(5, ptr1, ptr2, str, lst->next, lst);
```
----
```C
char				*str_join_n(int n, ...);
```
Join n chaines de caracteres en une seule. Ne free rien.
```C
char *new = strjoin(3, "Hello ", "World ", "!");
```
