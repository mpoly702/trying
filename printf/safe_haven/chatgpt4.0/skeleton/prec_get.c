char *my_prec_get(char *s, pmtrs_t *pmtrs, va_list args)
{  
    int y = 0;
    
    /*Check if the input string is NULL or empty*/
    if (!s || *s == '\0') 
    {
        /* Handle error */
        return ERROR_NULL_STRING;
    }
    
    /*Check if the first character of the string is not a period ('.')*/
    if (*s != '.') 
    {
        /* Handle error */
        return ERROR_MISSING_PERIOD;
    }
    s++;
        
        if (*s == '*')
        {
         /*Check if there is a matching argument for '*'*/
        int *arg = va_arg(args, int *);

        if (!arg) {
            /* Handle error */
            return ERROR_MISSING_ARG;
        }

        y = *arg;
        s++;
        }
        else
        {
        /*Loop to extract precision digits*/
          for (; _Adigit(*s); s++)
          {
              y = y * 10 + (*s - '0');
          }
        }
    }

    // Store precision in pmtrs if it's non-negative
    if (y >= 0) {
        pmtrs->precision = y;
    } else {
        /* Handle error */
        return ERROR_INVALID_PREC;
    }

    return s;
}
