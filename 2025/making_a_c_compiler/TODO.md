# write a compiler driver - ✅

## Options

- `--lex`   -> run the lexer, don't parse
- `--parse` -> lex and parse, don't generate assembly
- `--codegen` -> lex, parse, generate assembly, but don't emit code

## Steps

### Preprocess

```bash
> gcc -E -P <input-file> -o <preprocessed-file>.i
```

### Compile (stub for now)

### Assemble and Link

```bash
> gcc <assembly-file>.s -o <output-file>
```

# write a lexer - ✅

```python
WORD_BOUNDARY = '\b'
IDENTIFIER = "IDENTIFIER"
CONSTANT = "CONSTANT"
KW_INT = "KW_INT"
KW_VOID = "KW_VOID"
KW_RETURN = "KW_RETURN"
PAREN_OPEN = "PAREN_OPEN"
PAREN_CLOSE = "PARENT_CLOSE"
BRACE_OPEN = "BRACE_OPEN"
BRACE_CLOSE = "BRACE_CLOSE"
SEMICOLON = "SEMICOLON"

REGEX_TABLE = (
    (r"[a-zA-Z_]\w*\b", IDENTIFIER),
    (r"[0-9]+\b", CONSTANT),
    (r"int\b", KW_INT),
    (r"void\b", KW_VOID),
    (r"return\b", KW_RETURN),
    (r"\(", PAREN_OPEN),
    (r"\)", PAREN_CLOSE),
    (r"{", BRACE_OPEN),
    (r"}", BRACE_CLOSE),
    (r";", SEMICOLON),
)
```

```pseudocode
while input isn't empty:
  if input starts with whitespace:
    trim whitespace from start of input
  else:
    find longest match at start of input for any regex in REGEX_TABLE
    if no match is found, raise an error
    convert matching substring into a token
    remove matching substring from start of input
```

We must return a list of tokens. Some have values (constants, keywords); others do not (PAREN_OPEN, SEMICOLON).

# Write a parser

- `program: Program` nodes can have only one child, a `function_definition`
- `function_definition` has one child, `body: Statement`, and one attribute `name: Identifier`
- `body` has one child, `return_value: Expression` 
- we only have one `Express`, which is a `Constant`
