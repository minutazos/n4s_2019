/*
** EPITECH PROJECT, 2020
** AIA_n4s_2019
** File description:
** Tokenize string
*/

#include "../../include/ai.h"

int element_count(char const *str, char token)
{
    int counter = 0;

    if (my_strlen(str) == 0)
        return (0);
    for (int i = 0; str[i]; ++i){
        if (str[i] == token)
            ++counter;
    }
    if (counter == 0)
        return (1);
    else
        ++counter;
    return (counter);
}

char **alloc_array(char const *str, char token, int n_words)
{
    char **array = malloc(sizeof(char *) * (n_words + 1));
    int pointer = 0;
    int length = 0;

    if (array == NULL)
        return (NULL);
    if (n_words == 1)
        array[0] = malloc(sizeof(char) * my_strlen(str));
    else if (n_words == 0) {
        free(array);
        return (NULL);
    } else {
        for (int word = 0; word < n_words; ++word) {
            for (length = 0; str[pointer] != '\0' &&
                     str[pointer] != token; ++pointer, ++length);
            array[word] = malloc(sizeof(char) * (length + 1));
            ++pointer;
        }
        return (array);
    }
    return (NULL);
}

char **tokenize_string(char *str, char token)
{
    int n_words = element_count(str, token);
    char **tokenized = alloc_array(str, token, n_words);
    int pointer = 0;
    int length = 0;
    
    if (tokenized == NULL || n_words == 0)
        return(NULL);
    for (int word = 0; word < n_words; ++word) {
        for (length = 0; str[pointer] != '\0' &&
                 str[pointer] != token; ++pointer, ++length){
            tokenized[word][length] = str[pointer];
        }
        tokenized[word][length] = '\0';
        ++pointer;
    }
    tokenized[n_words] = NULL;
    return (tokenized);
}
