# ft_printf

## Grade		    106	/100

### Mandatory	    100	/100
###	Bonus		    06	/25

**Note**: *This project is now part of libft*

## Description

Analyse the libc's ```printf``` and its flags and recode it from scratch.
At 42, the students are not aloud to use libc functions (and very few from other libraries). We can only use what we coded ourselves (so no ```strlen``` but ```ft_strlen```).
ft_printf must be formatted the same way as libc's printfm example :
```C
ft_printf("%15s_ this works at %d %% efficiency\n", "Hey there", 100);
printf("%15s_ this works at %d %% efficiency\n", "Hey there", 100);
```

The output will be : 
```C
Hey there      _ this works at 100 % efficiency
Hey there      _ this works at 100 % efficiency
```
Ft_printf must achieve the following requirements:
- Manage the following conversions: s, S, p, d, D, i, o, O, u, U, x, X, c & C
- Manage %%
- Manage the flags #, 0, -, + & space
- Manage the minimum field-width
- Manage the precision
- Manage the flags hh, h, l, ll, j, & z.

All errors must be delt accordingly and exited properly. No unexepected quit of the function is tolerated (Segmentation fault, bus error, double free, etc). There can be no leaks.

## Usage and Bonus

Run ```make``` to compile the libftprintf.a

Then compile any project with the library : 
```console
gcc -Wall -Werror -Wextra main.c libftprintf.a -I includes
```
Some new flags :
 - b binary conversion
 - B Base conversion from 2 to 16
 - t print a char matrix
 
 example : 
 ```C
 ft_printf("********\n%t\n********\n", tab)
 ```
 Output :
 ```C
 ********
 This is a char
 matrix of
 variable size for each string.
 ********
 ```
 
