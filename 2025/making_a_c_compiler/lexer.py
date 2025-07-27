import re
from typing import Sequence


class Token:
    pass

    def __eq__(self, other) -> bool:
        return self.__class__ == other.__class__


class TokenWithValue:
    value: str | int

    def __repr__(self):
        return f"{self.__class__}({self.value})"

    def __eq__(self, other) -> bool:
        return self.__class__ == other.__class__ and self.value == other.value


class Identifier(TokenWithValue):
    def __init__(self, value: str):
        self.value = value


class Constant(TokenWithValue):
    def __init__(self, value: int | str):
        self.value = int(value)


class KeywordInt(Token):
    pass


class KeywordVoid(Token):
    pass


class KeywordReturn(Token):
    pass


class ParenOpen(Token):
    pass


class ParenClose(Token):
    pass


class BraceOpen(Token):
    pass


class BraceClose(Token):
    pass


class Semicolon(Token):
    pass


EXPECTED = [
    KeywordInt(),
    Identifier("main"),
    ParenOpen(),
    KeywordVoid(),
    ParenClose(),
    BraceOpen(),
    KeywordReturn(),
    Constant(2),
    Semicolon(),
    BraceClose(),
]

IDENTIFIER = r"[a-zA-Z_]\w*\b"
CONSTANT = r"[0-9]+\b"
KW_INT = r"int\b"
KW_VOID = r"void\b"
KW_RETURN = r"return\b"
PAREN_OPEN = r"\("
PAREN_CLOSE = r"\)"
BRACE_OPEN = r"{"
BRACE_CLOSE = r"}"
SEMICOLON = r";"
REGEX_TABLE = (
    ("IDENTIFIER", IDENTIFIER),
    ("CONSTANT", CONSTANT),
    ("KW_INT", KW_INT),
    ("KW_VOID", KW_VOID),
    ("KW_RETURN", KW_RETURN),
    ("PAREN_OPEN", PAREN_OPEN),
    ("PAREN_CLOSE", PAREN_CLOSE),
    ("BRACE_OPEN", BRACE_OPEN),
    ("BRACE_CLOSE", BRACE_CLOSE),
    ("SEMICOLON", SEMICOLON),
)

KWS = {
    "KW_INT": KeywordInt,
    "KW_VOID": KeywordVoid,
    "KW_RETURN": KeywordReturn,
}

TOK_NAME_TO_CLASS = KWS | {
    "IDENTIFIER": Identifier,
    "CONSTANT": Constant,
    "PAREN_OPEN": ParenOpen,
    "PAREN_CLOSE": ParenClose,
    "BRACE_OPEN": BraceOpen,
    "BRACE_CLOSE": BraceClose,
    "SEMICOLON": Semicolon,
}

KEYWORDS = ("return", "void", "int")

INPUT = """int main(void) {
    return 2;
}
"""


def lex(program_str) -> Sequence[Token]:
    tokens = []
    idx = 0

    # while input isn't empty:
    while program_str[idx:]:
        # if input starts with whitespace:
        if program_str[idx].isspace():
            # trim whitespace from start of input
            idx += 1
            continue

        all_matches = []

        for name, regex in REGEX_TABLE:
            matches = re.match(regex, program_str[idx:])
            if matches:
                all_matches.append((name, matches[0]))

        if not all_matches:
            # if no match is found, raise an error
            raise SyntaxError(program_str[idx:])

        # find longest match at start of input for any regex in REGEX_TABLE
        longest_match = None
        for kw, val in all_matches:
            if kw.startswith("KW_"):
                # keywords taken precedence
                longest_match = kw, val
                break

            if longest_match is None or val > longest_match[1]:
                longest_match = kw, val

        kw, val = longest_match  # type: ignore
        # convert matching substring into a token
        klass = TOK_NAME_TO_CLASS[kw]
        if issubclass(klass, Token):
            tok = klass()
        else:
            tok = klass(val)
        substr = val

        if substr is None:
            raise SyntaxError

        tokens.append(tok)
        # remove matching substring from start of input
        idx += len(substr)

    return tokens


if __name__ == "__main__":
    res = lex(INPUT)
    assert res == EXPECTED, str(res) + "\n\nEXPECTED:\n" + str(EXPECTED)
    print("success")
