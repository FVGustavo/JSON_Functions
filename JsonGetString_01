#include "json.h"

int json_check_str(const char *json)
{
  char str_len = strlen(json);
  const char *position = json + 1;
  char *test_colon;

  if (str_len < 2 || json[0] != '{' || json[str_len - 1] != '}')
  {
    return -1;
  }

  if (str_len == 2)
  {
    return 0;
  }

  test_colon = strchr(json, ':');

  if (str_len > 2)
  {
    if (*position != '"' || json[str_len - 1] != '"')
    {
      return -1;
    }
    else
    {
      position++;
      for (position; position < str_len - 1; position++)
      {
        if (test_colon != NULL)
        {
          if ((*test_colon - 1) != '"' || (*test_colon + 1) != '"')
          {
            return -1;
          }
        }
        if (*position != '"')
        {
          return -1;
        }
        if (*position == '"')
        {
          return 0;
        }
      }
      return 0;
    }

    return 0;
  }
}

int json_get_str(const char *json, const char *key, char *data, size_t *len)
{
  int json_check = json_check_str(json);
  char json_test[64] = json;
  char str_len = strlen(json_test);
  char *colon_check;
  colon_check = strchr(json_test, ':');

  if (json_check != 0)
  {
    return -1;
  }

  else
  {
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
  }

  return 0;
}

int json_get_int(const char *json, const char *key, int *value)
{
}
