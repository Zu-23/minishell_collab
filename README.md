# Minishell — Collaborative Prototype

A collaborative C work-in-progress for the 42 Minishell project. This snapshot centers on tokenization and lexer analysis, with additional experiments for built-ins, expansion, and signals.

## What's included

- An interactive GNU Readline prompt and command history.
- Token printing and quote-dependent tokenization.
- Token lists and lexer analysis.
- Experimental files for `cd`, `echo`, `pwd`, environment expansion, and signal handling.

## Current scope

The [main loop](main.c) reads input, prints tokens, analyzes them, and frees the token list. It does not execute commands or pipelines. The built-in, expansion, and signal source files are not listed in the current [Makefile](Makefile) and should be treated as unfinished experiments rather than working shell features.

## Requirements and build

Requires GCC, Make, and the GNU Readline development headers and library. On Debian/Ubuntu, those headers are provided by `libreadline-dev`.

```sh
make
./minishell
```

The Makefile links with `-lreadline`. Missing headers or libraries must be installed before building; the presence of experimental source files does not imply a complete shell. Targets `clean`, `fclean`, and `re` are also available.

## Exploring the prototype

At the `$>` prompt, enter input such as `echo "hello 42" | cat` to inspect tokenization. These words are parsed, not executed. Blank input is skipped; use Ctrl-D on an empty prompt to leave the main loop.

The companion [Minishell repository](https://github.com/Zu-23/Minishell) contains another parser-development snapshot.

## Concepts practiced

Collaborative development, lexical analysis, quote handling, linked lists, Readline integration, environment expansion design, and shell architecture.
