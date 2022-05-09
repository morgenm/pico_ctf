#include <stdbool.h>

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



int main(int argc,char **argv) 
  char jumbled_char;
  byte bVar1;
  bool is_valid_char;
  int ret;
  undefined7 extraout_var;
  long in_FS_OFFSET;
  int i;
  int local_ec;
  char user_key [100];
  undefined local_84;
  char transformed_key [104];
  long local_10;

  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  if (argc < 2) {
    printf("USAGE: %s [KEY]\n",*argv);
    ret = 1;
  }
  else {
    strncpy(user_key,argv[1],100);
    local_84 = 0;
    i = 0;
    while( true ) {
                    // checks if char is between a and f or is a number
      is_valid_char = valid_char(user_key[i]);
      if ((int)CONCAT71(extraout_var,is_valid_char) == 0) break;
                    // If first char
      if (i == 0) {
        jumbled_char = jumble(user_key[0]);
        bVar1 = (byte)(jumbled_char >> 7) >> 4;
        transformed_key[0] = (jumbled_char + bVar1 & 0xf) - bVar1;
      }
      else {
        jumbled_char = jumble(user_key[i]);
        bVar1 = (byte)((int)jumbled_char + (int)transformed_key[i + -1] >> 0x37);
        transformed_key[i] =
             ((char)((int)jumbled_char + (int)transformed_key[i + -1]) + (bVar1 >> 4) & 0xf) -
             (bVar1 >> 4);
      }
      i = i + 1;
    }
    for (local_ec = 0; local_ec < i; local_ec = local_ec + 1) {
      transformed_key[local_ec] = transformed_key[local_ec] + 'a';
    }
    if (i == 100) {
      ret = strncmp(transformed_key,
                    "mngjlepdcbcmjmmjipmmegfkjbicaemoemkkpjgnhgomlknmoepmfbcoffikhplmadmganmlojndmfahbhaancamdhfdkiancdjf"
                    ,100);
      if (ret == 0) {
        puts("You got the key, congrats! Now xor it with the flag!");
        ret = 0;
      }
    }
    puts("Invalid key!");
    ret = 1;
  }
return ret;
}


