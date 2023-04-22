## Representation des connaissances - AHMED ADJIBADE

### Exercice 16

My grammar :

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

## why lex & yacc ?

I choosed Lex and Yacc to identify the different expressions to suit our language.

Futhermore, the semantics routines will help me in the next exercices to handle some functionnality.
