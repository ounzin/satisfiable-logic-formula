## satisfiable-logic-formula - AHMED ADJIBADE

Grammar :

```
F -> atom
F -> not F
F -> (F)
F -> F && F
F -> F || F
F -> F -> F
F -> F <-> F
```

To test an expression, change the content of the `file.txt` file.

For example :

```
!p
```

or

```
p && q
```

or

```
p || q
```

and others ...

Command to launch : `make -B`
