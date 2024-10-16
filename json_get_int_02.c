#include "json.h"

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

int json_check_str(const char *json)
{
  if (json == NULL)
  {
    return -1;
  }

  size_t st_len = strlen(json);
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

  for (; position < (const char *)st_len - 1; position++)
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
  if (!len || !json)
  {
    return -1;
  }

  const char *json_key = strstr(json, key);
  if (json_key == NULL)
  {
    return -1;
  }

  const char *json_data = strchr(json_key, ':');
  if (json_data == NULL)
  {
    return 0;
  }

  json_data = strchr(json_data, '"');

  const char *start = json_data + 1;
  const char *end = strchr(start, '"');

  size_t value_len = end - start;

  if (data)
  {
    memcpy(data, start, value_len);
  }

  *len = value_len;

  return 0;
}

int json_get_int(const char *json, const char *key, int *value)
{

  if (!json)
  {
    return -1;
  }

  const char *json_key = strstr(json, key);
  if (json_key == NULL)
  {
    return -1;
  }

  const char *json_data = strchr(json_key, ':');
  if (json_data == NULL)
  {
    return 0;
  }

  const char *start = NULL;
  const char *stop = NULL;

  for (const char *index = json_data; *index != '\0'; index++)
  {
    if (isdigit(*index))
    {
      if (start == NULL)
      {
        start = index;
      }
    }
    else
    {
      if (start != NULL)
      {
        stop = index;
        break;
      }
    }
  }

  if (start == NULL || stop == NULL)
  {
    return -1;
  }

  size_t value_len = stop - start;

  char json_value[64];
  strncpy(json_value, start, value_len);

  int json_num_value = atoi(json_value);

  *value = json_num_value;

  return 0;
}
