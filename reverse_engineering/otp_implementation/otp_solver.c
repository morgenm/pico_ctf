#include <stdbool.h>
#include <stdio.h>

bool valid_char(char c) {
  bool bVar1;
                    // Not a number
  if ((c < '0') || ('9' < c)) {
                    // not between a and f
    if ((c < 'a') || ('f' < c)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
  }
  else {
    bVar1 = true;
  }
  return bVar1;
}

char jumble(char c){
  char bVar1;
  char local_c;

                    // if lowercase alphabet
  local_c = c;
  if ('`' < c) {
    local_c = c + '\t';
  }
  bVar1 = (char)(local_c >> 7) >> 4;
  local_c = ((local_c + bVar1 & 0xf) - bVar1) * '\x02';
  if ('\x0f' < local_c) {
    local_c = local_c + '\x01';
  }
  return local_c;
}

/*
char unjumble(char c) {
  char u = c;
  char m;

  if('`' + '\t' < c) {
    u -= '\t';
  }
  m = (char)(u << 4) << 7;
  u = u / '\x02';
  u += m;
  u = ((u - ))
}
*/

int main(int argc, char **argv) {
  char *mangled_key = "mngjlepdcbcmjmmjipmmegfkjbicaemoemkkpjgnhgomlknmoepmfbcoffikhplmadmganmlojndmfahbhaancamdhfdkiancdjf";

  char key[101];

  for(int i=0; i<100; i++) {
    for(char c=0; c<127; c++) {
      if(valid_char(c)) {
        printf("TRYING %c\n", c);
        if (i == 0) {
          char jumbled_char = jumble(c);
          char bVar1 = (jumbled_char >> 7) >> 4;
          char transformed_char = (jumbled_char + bVar1 & 0xf) - bVar1;
          printf("res: %c\n", transformed_char);
          if(transformed_char == mangled_key[0]) {
            printf("FOUND FIRST\n");
            key[0] = transformed_char;
            break;
          }
        }
        else {
          char jumbled_char = jumble(c);
          char bVar1 = (char)((int)jumbled_char + (int)key[i + -1] >> 0x37);
          char transformed_char =
            ((char)((int)jumbled_char + (int)key[i + -1]) + (bVar1 >> 4) & 0xf) -
            (bVar1 >> 4);

          if(transformed_char == mangled_key[i]) {
            printf("FOUND\n");
            key[i] = transformed_char;
            break;
          }
        }
      }
    }
    printf("Could not find char for %d!\n", i);
    break;
  }


  key[100] = '\0';
  printf("%s\n", key);
  return 0;
}
