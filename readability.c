#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

    float Ler = 0;
    float Wrd = 1;
    float Snt = 0;

int main(void)
{

    string Text = get_string("Text: ");
    int texlen = strlen(Text);

    // Getting letters words and sentences

    int i = 0;
    while (Text[i])
    {
        if (isalpha(Text[i]))
        {
            Ler++;
        }
        if (isspace(Text[i]))
        {
            Wrd++;
        }
        if (Text[i] == 33 || Text[i] == 46 || Text[i] ==63)
        {
            Snt++;
        }
        i++;
    }

    // Index and formula for L and S
    float L = 100*(Ler/Wrd);
    float S = 100*Snt/Wrd;
    float index = 0.0588 * L - 0.296 * S - 15.8;
    int x = round(index);

    // Print logic
    if (x>16)
    {
        printf("Grade 16+\n");
    }
    else if (x<1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        for(int j = x; x >= j; j++ )
        {

            printf("Grade %i\n", j);
        }
    }
        // ----------------------------------------uncomment to debugg------------------------------------------------------- //
    /*
    float junk = i - Ler - Wrd - Snt;
    printf("Letters per 100 words: %f,\nSentences per 100 words: %f\n", L, S);
    printf("Letter: %f\nWords: %f\nSentences: %f\nIndex: %f\n",Ler, Wrd, Snt, index,);
    /*/

}
