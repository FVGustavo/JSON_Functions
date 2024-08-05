#include "json.h"

int json_check_str(const char *json)
{
  if (json == NULL)
  {
    return -1;
  }

  char st_len = strlen(json);
  const char *position = json + 1;
  char *colon_check;
  colon_check = strchr(json, ':');

  if (st_len < 2)
  {
    return -1;
  }

  if (json[0] != '{' || json[st_len - 1] != '}')
  {
    return -1;
  }

  if (st_len == 2)
  {
    return 0;
  }

  if (*position != '"' || json[st_len - 2] != '"')
  {
    return -1;
  }
  position++;

  if (colon_check != NULL)
  {
    if (*(colon_check - 1) != '"' || *(colon_check + 1) != '"')
    {
      return -1;
    }
  }

  if (json[2] == '"')
  {
    return -1;
  }

  for (; position < st_len - 1; position++)
  {
    if (*position != '"')
    {
      return -1;
    }
    else
    {
      return 0;
    }
  }
  return 0;
}

int json_get_str(const char *json, const char *key, char *data, size_t *len)
{
  char str_len = strlen(json);
  char *colon_check = strchr(json, ':');

  len = (size_t)str_len;
  if (len == NULL)
  {
    return -1;
  }

  if (colon_check == NULL)
  {
    len = sizeof(key);
  }

  else
  {
    *len = *key;
    len = sizeof(key);
  }

  return 0;
}

int json_get_int(const char *json, const char *key, int *value)
{
}
