from __future__ import annotations
from enum import Enum


from lexer import Token, TokenWithValue


class Node:
    def __init__(self, value: str | int):
        self._value = value
        self._children = []

    def add_child(self, child: Node):
        self._children.append(child)


# EXPECTED = [
#     KeywordInt(),
#     Identifier("main"),
#     ParenOpen(),
#     KeywordVoid(),
#     ParenClose(),
#     BraceOpen(),
#     KeywordReturn(),
#     Constant(2),
#     Semicolon(),
#     BraceClose(),
# ]


type Identifier = str


class FunctionDefinition:
    name: Identifier
    body: Statement


class Expression(Enum):
    Constant = "Constant"


class Statement:
    return_value: Expression


class Program:
    function_definition: FunctionDefinition


def parse(tokens: list[Token | TokenWithValue]) -> Node:
    ...


"""
- `program: Program` nodes can have only one child, a `function_definition`
- `function_definition` has one child, `body: Statement`, and one attribute `name: Identifier`
- `body` has one child, `return_value: Expression` 
- we only have one `Expression`, which is a `Constant`
"""

if __name__ == "__main__":
    # TODO: test that the tree is what it should be
    ...
