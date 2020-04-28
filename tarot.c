#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

struct tarotCard
{
    char suit[10];
    int value;
};
static struct tarotCard pullCard();
static void printCard(struct tarotCard card);

int main(int argc, char *argv[]) {
    if(argc <= 1) {
        printf("usage: tarot <number cards>\n");
        exit(1);
    } else if (argc > 2)
    {
        printf("usage: tarot <number cards>\n");
        exit(1);
    }
    int num_cards = atoi(argv[1]);
    int i;
    time_t t;
   
    /* Intializes random number generator */
    srand((unsigned) time(&t));

    for( i = 0 ; i < num_cards ; i++ ) {
        printCard(pullCard());
    }
    
    return(0);
}

static struct tarotCard pullCard(){
    struct tarotCard card;
    
    int suit = rand() % 5;

    if (suit == 0) // pull from major arcana
    {
        card.value = rand() % 22;
    } else // pull from minor arcana
    {
        card.value = rand() % 14;
    }

    switch (suit)
    {
    case 1:
        strcpy(card.suit, "Wands");
        break;
    case 2:
        strcpy(card.suit, "Pentacles");
        break;
    case 3:
        strcpy(card.suit, "Swords");
        break;
    case 4:
        strcpy(card.suit, "Cups");
        break;
    default:
        card.suit[0] = 'M'; // flag for major arcana
        break;
    }

    return card;
}

static void printCard(struct tarotCard card){
    if (card.suit[0] == 'M')
    {
        switch (card.value)
        {
        case 0:
            printf("the Fool\n");
            break;
        case 1:
            printf("the Magician\n");
            break;
        case 2:
            printf("the High Priestess\n");
            break;
        case 3:
            printf("the Empress\n");
            break;
        case 4:
            printf("the Emperor\n");
            break;
        case 5:
            printf("the Hierophant\n");
            break;
        case 6:
            printf("the Lovers\n");
            break;
        case 7:
            printf("the Chariot\n");
            break;
        case 8:
            printf("Justice\n");
            break;
        case 9:
            printf("the Hermit\n");
            break;
        case 10:
            printf("the Wheel of Fortune\n");
            break;
        case 11:
            printf("Strength\n");
            break;
        case 12:
            printf("the Hanged Man\n");
            break;
        case 13:
            printf("Death\n");
            break;
        case 14:
            printf("Temperance\n");
            break;
        case 15:
            printf("the Devil\n");
            break;
        case 16:
            printf("the Tower\n");
            break;
        case 17:
            printf("the Star\n");
            break;
        case 18:
            printf("the Moon\n");
            break;
        case 19:
            printf("the Sun\n");
            break;
        case 20:
            printf("Judgement\n");
            break;
        case 21:
            printf("the World\n");
            break;
        default:
            printf("something went wrong!\n");
            exit(1);
            break;
        }
    } else
    {
        switch (card.value)
        {
        case 0:
            printf("the Ace of %s\n", card.suit);
            break;
        case 10:
            printf("the Page of %s\n", card.suit);
            break;
        case 11:
            printf("the Knight of %s\n", card.suit);
            break;
        case 12:
            printf("the Queen of %s\n", card.suit);
            break;
        case 13:
            printf("the King of %s\n", card.suit);
            break;
        default:
            printf("the %d of %s\n", card.value+1, card.suit);
            break;
        }
        
    }
    
    
}