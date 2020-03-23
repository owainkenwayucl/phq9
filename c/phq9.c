/**
 * Re-implementation in C.
 */
#include <stdio.h>

void clear_buffer() {
   while (fgetc(stdin) != '\n');
}

int ask_question(const char *q) {
   int response;
   printf("%s\n", q);
   int error_code = 0; 

   while ((error_code < 1) || (response < 0) || (response > 3)) {
      response=-1;
      printf("> ");
      error_code = scanf("%d", &response);
      if ((error_code < 1) || (response < 0) || (response > 3))  {
         printf("Please enter a number between 0 and 3.\n");
      }
      clear_buffer();
   }
   return response;
}

void administer_test(){
   const char *questions[] =  {"Little interest or pleasure in doing things?", 
              "Feeling down, depressed, or hopeless?",
              "Trouble falling or staying asleep, or sleeping too much?",
              "Feeling tired or having little energy?",
              "Poor appetite or overeating?",
              "Feeling bad about yourself - or that you are a failure or have let yourself or your family down?",
              "Trouble concentrating on things, such as reading the newspaper or watching television?",
              "Moving or speaking so slowly that other people could have noticed?",
              "Or the opposite - being so fidgety or restless that you have been moving around a lot more than usual?",
              "Thoughts that you would be better off dead, or of hurting yourself in some way?"};
   int i, score;
   int test[9];

   printf("\nPHQ-9 testing tool - C version\n");
   printf("==================\n\n");
   printf("For each of the following questions answer:\n\n");
   printf(" 0 - Not at all\n");
   printf(" 1 - Several days\n");
   printf(" 2 - More than half the days\n");
   printf(" 3 - Nearly every day\n\n");
   printf("Over the last two weeks, how often have you been bothered by any of the following problems?\n\n");

   score = 0;
   for (i = 0; i < 9; i++){
      test[i] = ask_question(questions[i]);
      score += test[i];
   }
   printf("\nDepression severity: ");
   if (score < 5) { printf("None");}
   if ((score > 4) && (score < 10)) {printf("Mild");}
   if ((score > 9) && (score < 15)) {printf("Moderate");}
   if ((score > 14) && (score < 20)) {printf("Moderately severe");}
   if (score > 19) {printf("Severe");}
   printf("\n              Score: %d\n             Report: ", score);
   for (i = 0; i < 9; i++){
      printf("%d", test[i]);  
      if (i < 8) {printf(",");}
      printf(" ");
   }
   printf("\n\n");
}

int main(int argc, char **argv) {
   administer_test();
}
