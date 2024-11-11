#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//______________________________________________________________________________________________________________________

int entry = 0;
int results[10] = {10, 4, 8, 27, 99, 34, 98,3, 101, 2};
int resultslenght = sizeof(results) / sizeof(results[0]);
char mathop;

//______________________________________________________________________________________________________________________

void userentrytoint(){
    char str[20];
    int state = 0;
    while(state == 0){
        state = 1;
        printf("Bitte gib eine Zahl ein: ");
        scanf("%s", str);
        for (int i = 0; str[i] != '\0'; i++) {
            if(str[i] < 48 || str[i] > 57){
                printf("Das ist leider keine gültige Eingabe, bitte nur Ziffern verwenden.\n");
                state = 0;
                break;
            }
        }
    }
    entry = atoi(str);
}

//__________________________________________________________

void userentrymathop(){
    char str[20];
    int state = 0;
    while(state == 0){
        state = 1;
        printf("Bitte gib eine Mathe-Operation (+, -, *, /) ein: ");
        scanf("%s", str);
        for (int i = 0; str[i] != '\0'; i++) {
            if(i > 0 || (str[i] != '+' && str[i] != '-' && str[i] != '*' && str[i] != '/')){
                printf("Das ist leider keine gültige Eingabe, bitte nur eine Matheoperation (+, -, *, /) "
                       "eingeben.\n");
                state = 0;
                break;
            }
        }
    }
    mathop = str[0];
}

//__________________________________________________________

void printmainarray(){
    printf("Die 10 Zahlen sind folgende:\n"
           "Nr. |  Zahl\n"
           "___________\n"
           "___________\n");
    for (int i=0; i<resultslenght; i++){
        if (i+1 < 10){
            printf("%i   |  %i \n___________\n", i+1, results[i]);
        }else{
            printf("%i  |  %i \n", i+1, results[i]);
        }

    }
}

//__________________________________________________________

void confirm(){
    char ch;
    printf("Drücken Sie Enter, um fortzufahren...\n");

    // Warte auf Benutzereingabe
    while ((ch = getchar()) != '\n' && ch != EOF) {
        // Warte auf Enter
    }
}

//__________________________________________________________

bool entrycheck(int cnt){
    for (int i=0; i<resultslenght; i++){
        if(entry == results[i] && entry != results[cnt]){
            return true;
        }
    }
    return false;
}





//______________________________________________________________________________________________________________________

int main() {
#if 0
    // TEST AREA
    //
    printf("Die Array SAize: %i\n", sizeof(results)/sizeof(results[0]));
#endif


#if 1
    // MAIN CODE
    printf(""
           "\n\n"
           "____________________________________________________________________________________________________\n"
           "HINWEIS:\n"
           "Diese Übung ergibt nur Sinn, wenn du sie rein nach dieser Anleitung absolvierst. \n"
           "Kein Stift und Papier ist erlaubt.\n\n"
           ""
           "ERKLÄRUNG:\n"
           "Versuche alle der folgenden 10 Zahlen mit den 4 Grundrechenoperationen (+, -, *, /) in jeweils\n"
           "maximal 5 Schritten auf 2 zu bringen.\n\n"
           ""
           "ACHTUNG: Es dürfen niemals (auch nicht in Zwischenergebnissen) Kommazahlen bzw. Brüche als\n"
           "Ergebnis herauskommen. Wir rechnen nur mit ganzen Zahlen.\n"
           "Gib nur gültige Terme ein, wenn du einen ungültigen eingibst (auch ausversehen), ist der Versuch"
           "verloren!\n"
           "Gültig sind nur alle genannten Zahlen, außer der die du gerade bearbeitest. Die gültigen Zahlen werden"
           "immer angezeigt.\n\n"

           "Alles klar soweit?\n"
           "____________________________________________________________________________________________________\n\n");

    confirm();


    printf("____________________________________________________________________________________________________\n");
    printmainarray();
    printf("____________________________________________________________________________________________________\n\n");

    confirm();


    printf("____________________________________________________________________________________________________\n");
    printf("Also fangen wir mit der ersten an.\n");
    printf("____________________________________________________________________________________________________\n\n");

    confirm();


    for (int i=0; i<sizeof(results)/sizeof(results[0]); i++){
        printf("\n\n____________________________________________________________________________________________________\n");
        printf("Bearbeite die %i. Zahl. Du hast 5 Versuche...\n", i+1);
        printf("____________________________________________________________________________________________________\n");


        for(int j=1; j<=5; j++){
            printf("\n____________\n"
                   "Zahl Nr. %i aktuell beträgt sie %i, Versuch %i\n"
                   "Folgende Zahlen stehen dir zur Verfügung und sind gültig: ", i+1, results[i], j);

            //In Funktion implementieren
            for (int k=0; k<resultslenght; k++){
                if (k+1 < 10 && k != i){
                    printf("%i | ", results[k]);
                }else if(k != i){
                    printf("%i\n", results[k]);
                }
            }
            //____________

            printf("\n");
            userentrymathop();
            printf("\n");
            userentrytoint();
            printf("\n");

            if(entrycheck(i)){
                switch (mathop) {
                    case '+':
                        printf("%i %c %i = ", results[i], mathop,entry);
                        results[i] += entry;
                        printf("%i\n", results[i]);
                        break;
                    case '-':
                        printf("%i %c %i = ", results[i], mathop,entry);
                        results[i] -= entry;
                        printf("%i\n", results[i]);
                        break;
                    case '*':
                        printf("%i %c %i = ", results[i], mathop,entry);
                        results[i] *= entry;
                        printf("%i\n", results[i]);
                        break;
                    case '/':
                        if( (results[i] / entry) == ((float)results[i] / entry) ){
                            printf("%i %c %i = ", results[i], mathop,entry);
                            results[i] /= entry;
                            printf("%i\n", results[i]);
                        }else{
                            printf("%i %c %i = ", results[i], mathop,entry);
                            printf("%f\n", (float)results[i] / entry);
                            printf("Leider ist das Ergebnis eine Kommazahl und daher ungültig, der Versuch ist "
                                   "weg, eine Rechnung erfolgt nicht.");
                        }
                        break;
                }
            }else{
                printf("Leider ist die eingegebene Zahl ungültig, der Versuch ist weg, eine Rechnung erfolgt "
                       "nicht.");
            }
            if(results[i] == 2){
                printf("Super!\n");
                break;
            }
            if(j == 5){
                printf("\n\nALLE VERSUCHE WEG.\n");
            }
        }

        printf("\n____________\n"
               "Zahl Nr. %i bträgt aktuell %i.\n", i+1, results[i]);
    }

    printf("\n____________________________________________________________________________________________________\n");
    printf("Dann schauen wir uns mal deien Ergebnisse an.\n");
    printf("____________________________________________________________________________________________________\n\n");

    confirm();


    printf("____________________________________________________________________________________________________\n");
    printmainarray();
    printf("____________________________________________________________________________________________________\n\n");

    confirm();

    int points = 0;
    for (int i=0; i<sizeof(results)/sizeof(results[0]); i++){
        if(results[i] == 2){
            points++;
        }
    }

    printf("Du hast also %i Punkte. Glückwunsch (Oder auch nicht.)",points);

#endif


    return 0;
}
