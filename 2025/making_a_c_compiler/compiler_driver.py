from pathlib import Path
import subprocess
import sys
from typing import Sequence

from lexer import Token, TokenWithValue, lex as _lex


def preprocess(fn: str) -> str:
    output_fn = fn + ".i"
    subprocess.run(f"gcc -E -P {fn} -o {output_fn}", shell=True)
    return output_fn


def lex(fn) -> Sequence[Token | TokenWithValue]:
    return _lex(Path(fn).read_text())


def parse(tokens: list[Token | TokenWithValue]):
    pass


def generate_assembly():
    pass


def emit_code(fn):
    subprocess.run(f"gcc {fn} -o {fn.split('.')[0]}")
    Path(fn).unlink()


FLAGS = "--lex, --parse, --codegen".split(", ")


def main():
    args = sys.argv
    len_args = len(args)
    skip_parse, skip_codegen, skip_emit = False, False, False
    if len_args < 2:
        print("please provide an input filename")
        sys.exit(1)
    elif len_args > 3:
        print("provide one of --lex, --parse, --codegen, or no flags")
        sys.exit(1)
    elif len_args == 3:
        flag = args[2].strip()
        if flag not in FLAGS:
            print("provide one of --lex, --parse, --codegen, or no flags")
            sys.exit(1)
        match flag:
            case "--lex":
                skip_parse = True
                skip_codegen = True
                skip_emit = True
            case "--parse":
                skip_codegen = True
                skip_emit = True
            case "--codegen":
                skip_emit = True
    fn = args[1]
    print("preprocessing")
    fni = preprocess(fn)
    print("lexing")
    tokens = lex(fni)
    if not skip_parse:
        print("parsing")
        parse(tokens)
    if not skip_codegen:
        print("generating assembly (codegen)")
        generate_assembly()
    if not skip_emit:
        emit_code()


if __name__ == "__main__":
    main()
