#include <stdio.h>

int main(void)
{
    // Say we have the following C code:
    printf("Hi!");
    printf("How are you doing today?");
    printf("Can I get some coffee?");
    printf("See you later!");
    printf("\n");

    // I'll put this in the context of someone going to a coffee shop and
    // ordering some coffee: these are some typical phrases that might occur in
    // that order during a dialogue in that situation.
    
    // But somedays we are just feeling lazy, and in those days we might want
    // to skip some of the chit chat and get to business, ykwim?
    
    // So this is what I'll propose: you give me a number, and I'll print you
    // every phrase *starting from that number*. 
    // For instance, the first phrase, "Hi!", is phrase number one. If you give
    // me the number 1, it means that you really want to talk on that
    // particular day. You'll say "Hi!", "How are you doing today?", "Can I get
    // some coffee?", and "See you later!".
    // If you give me the number 2, then you'll only start speaking from the
    // second phrase onwards. "How are you doing today?", "Can I get some
    // coffee?", "See you later!".
    // If you give me 3, you'll be brief and only say "Can I get some coffee?",
    // followed by "See you later!". How grumpy!
    
    // And... you know, maybe you just don't want coffee, or you're socially
    // awkward. In which case, just give me the number 4, and all you'll need
    // to say is "See you later!", as you sprint out of the coffee shop with no
    // coffee acquired.
    
    // A C switch statement can be perfect for all this. Let's start by getting
    // your numeric option:
    int option;
    scanf("%d", &option);

    // Now, I'll write the switch statement with no labels at all:

    switch (option)
    {
        printf("Hi!");
        printf("How are you doing today?");
        printf("Can I get some coffee?");
        printf("See you later!");
    }

    // The job of the switch statement is to take whatever option you give it,
    // and try to match to a *label* inside its curly brackets { } body
    
    // We can add labels like so:
    switch (option)
    {
        case 1:
        printf("Hi!");
        printf("How are you doing today?");
        printf("Can I get some coffee?");
        printf("See you later!");
    }

    // Now, if you give me the option 1, my switch statement will jump to that
    // label, and start executing the code from there.
    
    // Just to really stress this jumping bevahior, I'll show the behavior if
    // we put our 1 label in the second phrase: we would simply jump to
    // printf("How are you doing today?");, and start executing stuff from
    // there.
    
    switch (option)
    {
        printf("Hi!");
        case 1:
        printf("How are you doing today?");
        printf("Can I get some coffee?");
        printf("See you later!");
    }
    
    // What happens if we add more labels?
    switch (option)
    {
        case 1:
        printf("Hi!");
        case 2:
        printf("How are you doing today?");
        case 3:
        printf("Can I get some coffee?");
        case 4:
        printf("See you later!");
    }

    // Remember, labels are just that: labels. They only mean something the
    // switch statement.   
    // Once the switch statement jumps to a label, it just starts executing the
    // *code* below, and not the *other labels*. That is, once you jump to a
    // label, it's like all of the other labels were never really there.

    // So if I choose 2 for my option, the switch statement will jump to the 
    // printf("How are you doing today?");, and start executing the other
    // statements below it: printf("Can I get some coffee?");, and
    // printf("See you later!");. It's like the labels case 3: and case 4: were 
    // never really there.

    // The gist of it is: you only jump once. After jumping, case labels (which
    // are jump targets) become irrelevant.
    
    // Now, there is a way to change this behavior, and it is by means of the
    // break; keyword.
    // If you type the break keyword, and simply exit the switch statement, and
    // stop executing the code.
    
    // The coffee-shop conversation analogy kind of breaks from this point
    // forward: we would simply be saying the first phrase corresponding to the
    // number we chose, and then not say anything else:
    
    switch (option)
    {
        case 1:
        printf("Hi!");
        break;
        case 2:
        printf("How are you doing today?");
        break;
        case 3:
        printf("Can I get some coffee?");
        break;
        case 4:
        printf("See you later!");
        break;
    }

    // And we usually indent stuff, which can generate some confusion regarding
    // the exact behavior of switch statements if we do not have break
    // statements:
    
    switch (option)
    {
        case 1:
            printf("Hi!");
            break;
        case 2:
            printf("How are you doing today?");
            break;
        case 3:
            printf("Can I get some coffee?");
            break;
        case 4:
            printf("See you later!");
            break;
    }


    // There is one additional thing that you need to know about switch
    // statements: the "default" label. If no other label matches the option we
    // give it, the switch statement will jump to it.

    // This would be like memorizing something to say during the coffee shop in
    // the case that you forgot something. Yeah I don't really know anymore,
    // don't want to keep investing more time into this analogy lol.
    
    switch (option)
    {
        case 1:
            printf("Hi!");
        case 2:
            printf("How are you doing today?");
        case 3:
            printf("Can I get some coffee?");
        case 4:
            printf("See you later!");
        default:
            printf("I'll be back (said terminator style).");
    }

    return 0;
}
