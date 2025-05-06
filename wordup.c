//Gabriel Monzon
//Project 10

#include <stdio.h>

#define GUESSES 6
#define WORD_LENGTH 5
#define Any_Size 100


int GuessCheck(char guess[]);
void Convert(char guess[]);
void CheckGuess(char guess[], char word[], char result[], char hint[]);
void ShowGuesses(char results[][WORD_LENGTH + 1], char hints[][WORD_LENGTH + 1], int count);
int AnswerCheck(char guess[], char word[]);
int stringLength(char s[]);
int StringCheck(char a[], char b[]);
int LetterCheck(char c);

int main() {

    char word[WORD_LENGTH + 1];

    char guess[Any_Size];
    char results[GUESSES][WORD_LENGTH + 1];
    char hints[GUESSES][WORD_LENGTH + 1];
    int guessCount = 0;
    int won = 0;


 FILE *f = fopen("mystery.txt", "r");
    if (f == NULL) {
        printf("File Not Opening \n");
        }
   
    fscanf(f, "%5s", word);
    fclose(f);




    while (guessCount < GUESSES && !won) {
    	printf("=========================\n");
        printf("GUESS %d! Enter your guess: ", guessCount + 1);
        scanf("%s", guess);

        Convert(guess);
        
        if(guessCount = 5)
        printf("Final Guess: \n");
        scantf("%s", guess);

        if (!GuessCheck(guess)) {
            printf("Your guess must be 5 letters long.\n");
        }

        CheckGuess(guess, word, results[guessCount], hints[guessCount]);
        ShowGuesses(results, hints, guessCount + 1);

        if (AnswerCheck(guess, word)) {
            won = 1;
           
        }

        guessCount++;
    }

    if (won && guessCount == 1) {
    	printf("===============================\n");
    	printf("             %s\n",word);
    	printf("       You won in %d guess!\n",guessCount);
        printf("             GOATED!\n");
        
    } 
    
    else if (won){
    
    printf("===============================\n");
    	printf("             %s\n",word);
    	printf("       You won in %s guess!\n", guessCount);
        printf("             Amazing!\n");
    }
    else {
        printf("You lost. better luck next time!");
    }

    return 0;
}


   

int stringLength(char s[]) {
    int length = 0;
    while (s[length] != '\0')
    length++;
    return length;
}

void Convert(char guess[]) {
    int i = 0;
    while (guess[i] != '\0') {
        if (guess[i] >= 'A' && guess[i] <= 'Z') {
            guess[i] = guess[i] + 32;
        }
        i++;
    }
}

int LetterCheck(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int GuessCheck(char guess[]) {
    if (stringLength(guess) != WORD_LENGTH) return 0;

    int i;
    for (i = 0; i < WORD_LENGTH; i++) {
        if (!LetterCheck(guess[i])) return 0;
    }

    return 1;
}

void CheckGuess(char guess[], char word[], char result[], char hint[]) {
    int used[WORD_LENGTH] = { 0 };

    int i, j;

 
    for (i = 0; i < WORD_LENGTH; i++) {
        result[i] = guess[i];
        hint[i] = ' ';
    }


    for (i = 0; i < WORD_LENGTH; i++) {
        if (guess[i] == word[i]) {
            result[i] = guess[i] - 32; 
            used[i] = 1;
        }
    }


    for (i = 0; i < WORD_LENGTH; i++) {
        if (guess[i] == word[i]) ;

        for (j = 0; j < WORD_LENGTH; j++) {
            if (!used[j] && guess[i] == word[j]) {
                hint[i] = '^';
                used[j] = 1;
              
            }
        }
    }

    result[WORD_LENGTH] = '\0';
    hint[WORD_LENGTH] = '\0';
}

void ShowGuesses(char results[][WORD_LENGTH + 1], char hints[][WORD_LENGTH + 1], int count) {
    int i;
    for (i = 0; i < count; i++) {
        printf("%s\n", results[i]);
        printf("%s\n", hints[i]);
    }
}

int AnswerCheck(char guess[], char word[]) {
    return StringCheck(guess, word);
}

int StringCheck(char a[], char b[]) {
    int i;
    for (i = 0; i < WORD_LENGTH; i++) {
        if (a[i] != b[i]) return 0;
    }
    return 1;
}


