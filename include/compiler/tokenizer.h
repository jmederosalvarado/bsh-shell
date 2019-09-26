#ifndef TOKENIZER_H
#define TOKENIZER_H

struct vector;

struct tokenizer
{
    char *text;
    struct vector *tokens;
    int makes_history;
};

struct tokenizer *tokenizer_init(char *text);
void tokenizer_init_allocated(struct tokenizer *t, char *text);

char *tokenizer_get_text(struct tokenizer *t);
struct vector *tokenizer_get_tokens(struct tokenizer *t);
int tokenizer_get_makes_history(struct tokenizer *t);

void tokenizer_tokenize(struct tokenizer *t);

#endif