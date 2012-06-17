#include <stdio.h>
#include "opts.h"

static void helpcb(const char *l, char s)
{
    fprintf(stderr, "HelpCB: %s %c\n", l, s);
    fprintf(stderr, "\n");
}

int main(int argc, char *argv[])
{
    float opt1;
    float optarr[3];
    int help;
    int i;

    optarr[0] = optarr[1] = optarr[2] = 0.;

    // define options
    optsAdd("opt1", 'o', OPTS_FLOAT, (void *)&opt1, NULL);
    optsAdd("help", 'h', OPTS_NONE, (void *)&help, OPTS_CB(helpcb));
    optsAddDesc("optarr", 'a', OPTS_FLOAT_ARR(3), (void *)optarr, NULL,
                "Array of three ints");
    // parse options
    if (opts(&argc, argv) != 0){
        fprintf(stderr, "Usage: %s\n", argv[0]);
        optsPrint(stderr, "    ");
        return -1;
    }

    // print some info
    fprintf(stdout, "help: %d\n", help);
    fprintf(stdout, "opt1: %f\n", (float)opt1);
    for (i = 0; i < 3; i++){
        fprintf(stdout, "optarr[%d]: %f\n", i, optarr[i]);
    }

    // print the rest of options
    for (i = 0; i < argc; i++){
        fprintf(stdout, "[%02d]: `%s'\n", i, argv[i]);
    }

    return 0;
}

