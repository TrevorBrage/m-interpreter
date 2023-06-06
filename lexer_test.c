#include "./token.h"
#include "./lexer.h"
#include <stdlib.h>
#include <string.h>

typedef struct Test
{
  TokenType expectedType;
  char* expectedLiteral;
} 
Test;

void TestNextToken()
{
  char* input = "let five = 5;"
                "let ten = 10;"
                "let add = fn(x, y) {"
                  "x + y;"
                "};"
                "let result = add(five, ten);";

  Test tests[] =
  {
    {LET, "let"},
    {IDENT, "five"},
    {ASSIGN, "="},
    {INT, "5"},
    {SEMICOLON, ";"},
    {LET, "let"},
    {IDENT, "ten"},
    {ASSIGN, "="},
    {INT, "10"},
    {SEMICOLON, ";"},
    {LET, "let"},
    {IDENT, "add"},
    {ASSIGN, "="},
    {FUNCTION, "fn"},
    {LPAREN, "("},
    {IDENT, "x"},
    {COMMA, ","},
    {IDENT, "y"},
    {RPAREN, ")"},
    {LBRACE, "{"},
    {IDENT, "x"},
    {PLUS, "+"},
    {IDENT, "y"},
    {SEMICOLON, ";"},
    {RBRACE, "}"},
    {SEMICOLON, ";"},
    {LET, "let"},
    {IDENT, "result"},
    {ASSIGN, "="},
    {IDENT, "add"},
    {LPAREN, "("},
    {IDENT, "five"},
    {COMMA, ","},
    {IDENT, "ten"},
    {RPAREN, ")"},
    {SEMICOLON, ";"},
    {EOF, ""},
  };

  Lexer lexer = CreateNewLexer(input);

  printf("%s\n", LexerNextToken(&lexer).Literal);
  printf("%s\n", LexerNextToken(&lexer).Literal);
  printf("%s\n", LexerNextToken(&lexer).Literal);
  printf("%s\n", LexerNextToken(&lexer).Literal);
  printf("%s\n", LexerNextToken(&lexer).Literal);
  printf("%s\n", LexerNextToken(&lexer).Literal);
  printf("%s\n", LexerNextToken(&lexer).Literal);
  //for (int i = 0; i < sizeof(tests) / sizeof(Test); i++)
  //{
  //  printf("----- Testing: %d -----\n", i);
  //  Test tt = tests[i];
  //  Token tok = LexerNextToken(&lexer);
  //  printf("input: %s\nposition: %d\nreadPosition: %d\nch: %c\n", lexer.input, lexer.position, lexer.readPosition, lexer.ch);
  //  printf("\nTokenType: %s\nTokenLiteral: %s\n\n", tok.Type, tok.Literal);

  //  if (strcmp(tok.Type, tt.expectedType) != 0)
  //  {
  //    printf("tests[%d] - tokentype wrong. expected=%s, got=%s", i, tt.expectedType, tok.Type);
  //    exit(1);
  //  }
  //  if (strcmp(tt.expectedLiteral, tok.Literal) != 0)
  //  {
  //    printf("tests[%d] - literal wrong. expected=%s, got=%s", i, tt.expectedLiteral, tok.Literal);
  //    exit(1);
  //  }
  //}

}

int main()
{
  TestNextToken();
}
