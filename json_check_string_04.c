int json_check_str(const char* json){
  if (json == NULL){
    #ifdef DEBUG_JSON
    printf("json is NULL\n");
    #endif
    return -1;
  }

  size_t st_len = strlen(json);
  const char *position = json + 1;
  char *colon_check;
  char *comma_check;
  colon_check = strchr(json, ':');
  comma_check = strchr(json, ',');

  if (st_len < 2){
    #ifdef DEBUG_JSON
    printf("json is too small\n");
    #endif
    return -1;
  }

  if (json[0] != '{' || json[st_len - 1] != '}'){
    #ifdef DEBUG_JSON
    printf("json doesn't start nor end with brackets\n");
    #endif
    return -1;
  }

  if (st_len == 2){
    return 0;
  }

  if (*position != '"'){
    #ifdef DEBUG_JSON
    printf("json doesn't start with quotes \n");
    #endif
    return -1;
  }
  position++;

  if (json[2] == '"'){
    #ifdef DEBUG_JSON
    printf("json key is NULL\n");
    #endif
    return -1;
  }

  if (colon_check != NULL){
    #ifdef DEBUG_JSON
    printf("json has colons (key may have value)\n");
    #endif
    if (isNum(*(colon_check + 1))){
      #ifdef DEBUG_JSON
      printf("element after colon is a number\n");
      #endif
      if((*(colon_check - 1) != '"')){
        #ifdef DEBUG_JSON
        printf("element before colon isn't a quotation mark\n");
        #endif
        return -1;
      }
    }else{
      #ifdef DEBUG_JSON
      printf("element after colon isn't a number\n");
      #endif
      if((*(colon_check - 1) != '"' || *(colon_check + 1) != '"' || *(colon_check + 2) != '"')){
        #ifdef DEBUG_JSON
        printf("first element before or after the colon (or both) isn't a quotation mark\n");
        #endif
        return -1;
      }
    }
  }

  if (comma_check != NULL){
    #ifdef DEBUG_JSON
    printf("json has commas (more than one key)\n");
    #endif
    if (isNum(*(comma_check - 1))){
      #ifdef DEBUG_JSON
      printf("element before comma is a number\n");
      #endif
      if((*(comma_check + 1) != '"')){
        #ifdef DEBUG_JSON
        printf("element after comma isn't a quotation mark\n");
        #endif
        return -1;
      }
    }else{
      #ifdef DEBUG_JSON
      printf("element before comma isn't a number\n");
      #endif
      if((*(comma_check - 1) != '"' || *(comma_check + 1) != '"')){
        #ifdef DEBUG_JSON
        printf("first element before or after the comma (or both) isn't a quotation mark\n");
        #endif
        return -1;
      }
    }
  }

  for (; position < (const char *)st_len - 1; position++){
    if (*position != '"'){
      #ifdef DEBUG_JSON
      printf("json doesn't have both quotes around its keys/values\n");
      #endif
      return -1;
      break;
    }else{
      return 0;
    }
  }
  return 0;
}
