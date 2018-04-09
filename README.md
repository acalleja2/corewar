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
Renvoie NULL, pratique en cas de sortie de fonction, il n'y a qu'à la return.
```C
freen(5, ptr1, ptr2, str, lst->next, lst);
```
----
```C
char				*str_join_n(int n, ...);
```
Join n chaines de caracteres en une seule. Ne free rien.
```C
char *new = str_join_n(3, "Hello ", "World ", "!");
```
----
```C
int					errorf(char *format, ...);
```
Affiche un message formate avec printf sur la sortie standard puis affiche errno.
Renvoie le nombre de caracteres affiches comme printf.
```C
errorf("Could not read from file %s", filename);
```
---
Toutes les fonctions du `man 3 printf`:
`(v)(d/s/as)(n)printf();`

+ d'autres trucs pas très utiles
