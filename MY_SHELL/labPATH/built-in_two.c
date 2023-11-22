int unsetenv(char **args)
{
    int i;
    int j;
    
  /*Iterate through the environ array to find the element with the given name*/
    for (i = 0; environ[i] != NULL; ++i) 
    {
        /*Check if the current element starts with the given name*/
        if (strncmp(environ[i], args[1], strlen(args[1])) == 0)
        {
            /*Free the memory occupied by the element*/
            free(environ[i]);

            /*Shift the remaining elements to fill the gap*/
            for (j = i; environ[j + 1] != NULL; ++j) 
            {
                environ[j] = environ[j + 1];
            }
            
            /*Reduce the size of the environ array*/
            environ = realloc(environ, (environSize() + 1) * sizeof(char *));
            return (1); /*Exit the function since the deletion is done*/
        }
    }
}

/*Helper function to get the size of the environ array*/
int environSize()
{
    int size;

    size = 0;
    while (environ[size] != NULL)
    {
        size++;
    }
    return size;
}

/*builtin function*/

builtins m[] = {
		{"cd", printf_string}, {"env", printf_char},
		{"setenv", printf_37},
		{"exit", printf_int}, {"unsetenv", printf_dec}
	};

  for (i = 0; i < lsh_num_builtins(); i++)
  {
    if (strcmp(args[0], m[i]) == 0) {
      return (*builtin_func[i])(args);
    }
  }

  return lsh_launch(args);
}
