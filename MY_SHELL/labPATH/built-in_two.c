void deleteEnvironment(const char *name)
{
    int i;
    int j;
    
  /*Iterate through the environ array to find the element with the given name*/
    for (i = 0; environ[i] != NULL; ++i) 
    {
        /*Check if the current element starts with the given name*/
        if (strncmp(environ[i], name, strlen(name)) == 0)
        {
            /*Free the memory occupied by the element*/
            free(environ[i]);

            /*Shift the remaining elements to fill the gap*/
            for (int j = i; environ[j + 1] != NULL; ++j) 
            {
                environ[j] = environ[j + 1];
            }
            
            /*Reduce the size of the environ array*/
            environ = realloc(environ, (environSize() + 1) * sizeof(char *));
            return; /*Exit the function since the deletion is done*/
        }
    }
}

/*Helper function to get the size of the environ array
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
