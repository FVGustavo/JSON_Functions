#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define DEBUG_JSON

int json_check_str(const char* json) {
    if (json == NULL) {
        #ifdef DEBUG_JSON
        printf("json is NULL\n");
        #endif
        return -1;
    }

    size_t st_len = strlen(json);
    const char *pos = json + 1;

    if(st_len < 2){
      #ifdef DEBUG_JSON
      printf("json is too small\n");
      #endif
      return -1;
    }

    if(json[0] != '{' || json[st_len - 1] != '}'){
      #ifdef DEBUG_JSON
      printf("json doesn't start or end with brackets\n");
      #endif
      return -1;
    }

    while(pos < json + st_len - 1){ 
      while(*pos == ' ' || *pos == '\n' || *pos == '\t'){
        pos++;
      }

      if(*pos != '"'){
        #ifdef DEBUG_JSON
        printf("json key doesn't start with quotes\n");
        #endif
        return -1;
      }

      pos++; 
      const char *key_start = pos; 

      while(*pos != '"'){
        if(pos >= json + st_len - 1){
          #ifdef DEBUG_JSON
          printf("json key doesn't end with quotes\n");
          #endif
          return -1;
        }
        pos++;
      }

      if(key_start == pos){
        #ifdef DEBUG_JSON
        printf("json key is empty\n");
        #endif
        return -1;
      }

      pos++;

      while (*pos == ' ' || *pos == '\n' || *pos == '\t') {
        pos++;
      }

      if(*pos != ':'){
        #ifdef DEBUG_JSON
        printf("json doesn't have a colon after key\n");
        #endif
        return -1;
      }

      pos++; 

      while (*pos == ' ' || *pos == '\n' || *pos == '\t') {
        pos++;
      }

      if(*pos == '"'){
        pos++; 
        while(*pos != '"'){
          if(pos >= json + st_len - 1){
            #ifdef DEBUG_JSON
            printf("json value doesn't end with quotes\n");
            #endif
            return -1;
          }
          pos++;
        }
        pos++;
      }else if(!is_num(*pos) && *pos != true && *pos != false && *pos != NULL){
        #ifdef DEBUG_JSON
        printf("json value is neither a string nor a valid number/boolean/null\n");
        #endif
        return -1;
      }else{
        while (is_num(*pos) || *pos == true || *pos == false || *pos == NULL){
          pos++;
        }
      }

      while(*pos == ' ' || *pos == '\n' || *pos == '\t'){
        pos++;
      }

      if(*pos == ','){
        pos++;
        continue;
      }

      if(*pos != '}'){
        #ifdef DEBUG_JSON
        printf("json does not properly close with a bracket\n");
        #endif
        return -1;
      }
    }

    return 0; 
}
