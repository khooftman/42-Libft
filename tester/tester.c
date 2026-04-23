/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khooftma <khooftma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 11:45:57 by khooftma          #+#    #+#             */
/*   Updated: 2026/04/23 13:02:44 by khooftma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "../libft.h"

int	main(void)
{
	char *test1 = "   -1234ab56";
	char *test2 = "--123";
	char *test3 = "++123";
	char *test4 = " \t\n\r\v\f 42";
	char *test5 = "2147483647";
	char *test6 = "-2147483648";

	printf("Test 1: \"%s\"\nFT: %d | STD: %d\n\n", test1, ft_atoi(test1), atoi(test1));
	printf("Test 2: \"%s\"\nFT: %d | STD: %d\n\n", test2, ft_atoi(test2), atoi(test2));
	printf("Test 3: \"%s\"\nFT: %d | STD: %d\n\n", test3, ft_atoi(test3), atoi(test3));
	printf("Test 4: \"whitespaces\"\nFT: %d | STD: %d\n\n", ft_atoi(test4), atoi(test4));
	printf("Test 5 (MAX): %d | STD: %d\n\n", ft_atoi(test5), atoi(test5));
	printf("Test 6 (MIN): %d | STD: %d\n", ft_atoi(test6), atoi(test6));

	return (0);
	
	/*char *str = "Pindakaas met hagelslag";
	char *res1;

	printf("--- TEST 1: Normale match ---\n");
	res1 = ft_strnstr(str, "kaas", 20);
	printf("Resultaat: %s (Verwacht: kaas met hagelslag)\n\n", res1);

	printf("--- TEST 2: Lege needle (little) ---\n");
	res1 = ft_strnstr(str, "", 10);
	printf("Resultaat: %s (Verwacht: Pindakaas met hagelslag)\n\n", res1);

	printf("--- TEST 3: Match net buiten 'len' ---\n");
	// We zoeken 'kaas' (begint op index 5), maar len is 8. 
	// De 's' van kaas is op index 8, dus (i+j < len) moet dit blokkeren.
	res1 = ft_strnstr(str, "kaas", 8);
	if (res1 == NULL)
		printf("Resultaat: NULL (Correct! 'kaas' past niet binnen len 8)\n\n");
	else
		printf("Resultaat: %s (FOUT: had NULL moeten zijn)\n\n", res1);

	printf("--- TEST 4: Match precies op de grens van 'len' ---\n");
	// 'kaas' begint op 5 en eindigt op 8. Met len 9 moet hij hem wel vinden.
	res1 = ft_strnstr(str, "kaas", 9);
	printf("Resultaat: %s (Verwacht: kaas met hagelslag)\n\n", res1);

	printf("--- TEST 5: Zoeken in een lege big string ---\n");
	res1 = ft_strnstr("", "hallo", 5);
	if (res1 == NULL)
		printf("Resultaat: NULL (Correct!)\n\n");
	
	
	char *s1 = "abcdef";
	char *s2 = "abcdez";
	char *s3 = "abcdef";
	
	printf("--- TEST 1: Identieke strings ---\n");
	printf("Echt:  %d\n", memcmp(s1, s3, 6));
	printf("Jouw:  %d\n", ft_memcmp(s1, s3, 6));

	printf("\n--- TEST 2: Verschil aan het einde (f vs z) ---\n");
	printf("Echt:  %d\n", memcmp(s1, s2, 6));
	printf("Jouw:  %d\n", ft_memcmp(s1, s2, 6));

	printf("\n--- TEST 3: Verschil maar n is te klein ---\n");
	printf("Echt:  %d\n", memcmp(s1, s2, 5));
	printf("Jouw:  %d\n", ft_memcmp(s1, s2, 5));

	printf("\n--- TEST 4: n is nul ---\n");
	printf("Echt:  %d\n", memcmp(s1, s2, 0));
	printf("Jouw:  %d\n", ft_memcmp(s1, s2, 0));

	printf("\n--- TEST 5: Unsigned check (hoge waarden) ---\n");
	unsigned char u1[] = {255, 160, 80};
	unsigned char u2[] = {255, 160, 120};
	printf("Echt:  %d\n", memcmp(u1, u2, 3));
	printf("Jouw:  %d\n", ft_memcmp(u1, u2, 3));

	return (0);

	char *s = "Hallo wereld";
	int c = 'w';
	size_t n = 12;

	void *res1 = memchr(s, c, n);
	void *res2 = ft_memchr(s, c, n);

	printf("Echte memchr: %p -> %s\n", res1, (char *)res1);
	printf("Jouw ft_memchr: %p -> %s\n", res2, (char *)res2);

	if (res1 == res2)
		printf("✅ Match!\n");
	else
		printf("❌ Geen match!\n");

	return (0);

	// --- Test ft_isalpha ---
	printf("--- Test ft_isalpha ---\n");
	printf("Input 'A': %d (Echt: %d)\n", ft_isalpha('A'), isalpha('A'));
    printf("Input '9': %d (Echt: %d)\n", ft_isalpha('9'), isalpha('9'));

	// --- Test ft_isdigit --- 
	printf("\n--- Test ft_isdigit ---\n");
	printf("Input '5': %d (Echt: %d)\n", ft_isdigit('5'), isdigit('5'));
	printf("Input 'a': %d (Echt: %d)\n", ft_isdigit('a'), isdigit('a'));

		// --- Test ft_isalnum --- 
	printf("\n--- Test ft_isalnum ---\n");
	printf("Input '5': %d (Echt: %d)\n", ft_isalnum('5'), isalnum('5'));
	printf("Input 'a': %d (Echt: %d)\n", ft_isalnum('a'), isalnum('a'));

			// --- Test ft_isascii --- 
	printf("\n--- Test ft_isascii ---\n");
	printf("Input '127': %d (Echt: %d)\n", ft_isascii(127), isascii(127));
	printf("Input '*': %d (Echt: %d)\n", ft_isascii('*'), isascii('*'));

				// --- Test ft_isprint --- 
	printf("\n--- Test ft_isprint ---\n");
	printf("Input '15': %d (Echt: %d)\n", ft_isprint(15), isprint(15));
	printf("Input '*': %d (Echt: %d)\n", ft_isprint('*'), isprint('*'));

	// --- Test ft_strlen ---
	printf("--- Test ft_strlen ---\n");

	// Test 1: Normale string
	char *str1 = "Hallo";
	printf("Input '%s': %zu (Echt: %zu)\n", str1, ft_strlen(str1), strlen(str1));

	// Test 2: Lege string (Heel belangrijk!)
	char *str2 = "";
	printf("Input empty: %zu (Echt: %zu)\n", ft_strlen(str2), strlen(str2));

	// Test 3: String met spaties
	char *str3 = "Libft is leuk";
	printf("Input spaces: %zu (Echt: %zu)\n", ft_strlen(str3), strlen(str3));

	// Test 4: Lange string
	char *str4 = "0123456789";
	printf("Input '0123456789': %zu (Echt: %zu)\n", ft_strlen(str4), strlen(str4));

	//--- Test ft_memset ---
	printf("--- Test ft_memset --- \n");

	char str[10] = "ABCDEFGHI"; // Een string van 10 bytes

    printf("Voor: %s\n", str);
    
    // Vul de eerste 5 bytes met 'x'
    ft_memset(str, 'x', 5);
    
    printf("Na:   %s\n", str); // Zou "xxxxxFGHI" moeten zijn


char str[] = "Hallo";
ft_bzero(str, 2); // Zet 'H' en 'a' op 0

if (str[0] == '\0' && str[1] == '\0' && str[2] == 'l')
    printf("ft_bzero werkt!\n");
else
    printf("Er gaat iets mis...\n");


printf("--- Test ft_memcpy ---\n");
	char src1[] = "Hallo wereld!";
    char dest1[20];
    ft_memcpy(dest1, src1, 14);
    printf("Test 1 (String): %s\n", dest1);

    // TEST 2: Integers (kijken of hij bytes goed telt)
    int src2[] = {10, 20, 30, 40};
    int dest2[4];
    ft_memcpy(dest2, src2, sizeof(int) * 4);
    printf("Test 2 (Ints): %d, %d, %d, %d\n", dest2[0], dest2[1], dest2[2], dest2[3]);

    // TEST 3: Return waarde checken
    char *res = ft_memcpy(dest1, src1, 5);
    if (res == dest1)
        printf("Test 3 (Return): Pointer komt overeen! ✅\n");

    // TEST 4: NULL check
    void *res_null = ft_memcpy(NULL, NULL, 5);
    printf("Test 4 (NULL): %s\n", res_null == NULL ? "Veilig afgehandeld ✅" : "Crash ❌");

printf("--- START TEST FT_MEMMOVE ---\n\n");

	// TEST 1: Normale kopie (geen overlap)
	char src1[] = "Hallo";
	char dest1[10];
	ft_memmove(dest1, src1, 6);
	printf("Normale kopie      : %s\n", dest1);

	// TEST 2: Overlap - Bestemming ligt NA de bron (dest > src)
	// We schuiven "ABCDE" twee plekken naar rechts binnen dezelfde string
	char overlap1[] = "ABCDE12345";
	printf("Vóór overlap (R)   : %s\n", overlap1);
	ft_memmove(overlap1 + 2, overlap1, 5);
	printf("Na overlap (R)     : %s\n", overlap1);
	// Verwacht: ABABCDE345 (De 'CDE' zijn niet overschreven voor ze gekopieerd werden)

	// TEST 3: Overlap - Bestemming ligt VOOR de bron (dest < src)
	char overlap2[] = "12345ABCDE";
	printf("\nVóór overlap (L)   : %s\n", overlap2);
	ft_memmove(overlap2, overlap2 + 5, 5);
	printf("Na overlap (L)     : %s\n", overlap2);
	// Verwacht: ABCDEABCDE

	// TEST 4: n is 0
	char nzero[] = "Blijf gelijk";
	ft_memmove(nzero, "Verander", 0);
	printf("\nTest n = 0         : %s\n", nzero);

	printf("\n--- EINDE TEST ---\n");
	
	char	dst[5];          // Een buffer van maar 5 plekjes
	char	*src = "HALLO";  // Een woord van 5 letters + \0 = 6 nodig
	size_t	res;

	// We geven 5 mee als grootte, want dst is 5 bytes
	res = ft_strlcpy(dst, src, 5);

	printf("Bron string: %s\n", src);
	printf("Resultaat in dst: %s\n", dst);
	printf("Return waarde (lengte van src): %zu\n", res);

	if (res >= 5)
	{
		printf("\nLet op: De string is afgekapt (truncated)!\n");
		printf("Je had %zu bytes nodig, maar had er maar 5.\n", res + 1);
	}

	printf("--- START TEST FT_STRLCAT ---\n\n");

	// TEST 1: Genoeg ruimte (Schoon resultaat)
	char	dst1[20] = "Hallo ";
	char	*src1 = "wereld";
	size_t	res1;

	res1 = ft_strlcat(dst1, src1, 20);
	printf("Test 1 (Past wel):\n");
	printf("Resultaat: [%s], Return: %zu (Verwacht: 12)\n\n", dst1, res1);

	// TEST 2: Te weinig ruimte (Truncation)
	char	dst2[10] = "Hallo "; // "Hallo " (6) + "wereld" (6) = 12
	char	*src2 = "wereld";
	size_t	res2;

	res2 = ft_strlcat(dst2, src2, 10);
	printf("Test 2 (Te klein - Truncation):\n");
	printf("Resultaat: [%s], Return: %zu (Verwacht: 12)\n", dst2, res2);
	printf("Uitleg: De buffer is 10, dus we krijgen 9 tekens + \\0.\n\n");

	// TEST 3: Size is kleiner dan dst zelf
	char	dst3[10] = "12345";
	char	*src3 = "ABC";
	size_t	res3;

	res3 = ft_strlcat(dst3, src3, 3);
	printf("Test 3 (Size kleiner dan dst):\n");
	printf("Resultaat: [%s], Return: %zu (Verwacht: 6)\n", dst3, res3);
	printf("Uitleg: Als size <= strlen(dst), mag er niets worden geplakt.\n");

	printf("\n--- EINDE TEST ---\n");

	printf("Maak upper a : %c\n", ft_toupper('a'));
	printf("Test 'a' (wordt A): %c\n", ft_toupper('a'));
	printf("Test 'z' (wordt Z): %c\n", ft_toupper('z'));
	printf("Test 'A' (blijft A): %c\n", ft_toupper('A'));
	printf("Test '1' (blijft 1): %c\n", ft_toupper('1'));
	printf("Test '!' (blijft !): %c\n", ft_toupper('!'));

	printf("Maak lower\n");
	printf("Test 'A' (wordt A): %c\n", ft_tolower('A'));
	printf("Test 'Z' (wordt Z): %c\n", ft_tolower('Z'));

	char *str = "Leer pintelieren bij 42";
	char *res_ft;
	char *res_org;

	printf("--- TEST FT_STRCHR ---\n\n");

	// TEST 1: Karakter in het midden
	res_ft = ft_strchr(str, 'p');
	res_org = strchr(str, 'p');
	printf("Test 1 ('p'): %s\n", (res_ft == res_org) ? "✅ OK" : "❌ FOUT");
	if (res_ft) printf("   Gevonden: %s\n", res_ft);

	// TEST 2: Karakter aan het begin
	res_ft = ft_strchr(str, 'L');
	res_org = strchr(str, 'L');
	printf("Test 2 ('L'): %s\n", (res_ft == res_org) ? "✅ OK" : "❌ FOUT");

	// TEST 3: Karakter niet aanwezig (moet NULL zijn)
	res_ft = ft_strchr(str, 'z');
	res_org = strchr(str, 'z');
	printf("Test 3 ('z'): %s\n", (res_ft == res_org) ? "✅ OK" : "❌ FOUT");

	// TEST 4: De Null-terminator (Cruciaal voor Libft!)
	res_ft = ft_strchr(str, '\0');
	res_org = strchr(str, '\0');
	printf("Test 4 ('\\0'): %s\n", (res_ft == res_org) ? "✅ OK" : "❌ FOUT");

	// TEST 5: Een karakter met een hoge ASCII waarde (casting test)
	// We casten naar char om te zien of je functie goed omgaat met int c
	res_ft = ft_strchr(str, 'r' + 256); 
	res_org = strchr(str, 'r' + 256);
	printf("Test 5 (overflow): %s\n", (res_ft == res_org) ? "✅ OK" : "❌ FOUT");

	printf("\n--- EINDE TESTS ---\n");

char *str = "bonjourno"; // De 'o' komt twee keer voor
	char *res_ft;
	char *res_org;

	printf("--- TEST FT_STRRCHR ---\n\n");

	// TEST 1: Zoek naar 'o' (moet de laatste 'o' pakken, van 'no')
	res_ft = ft_strrchr(str, 'o');
	res_org = strrchr(str, 'o');
	printf("Test 1 (laatste 'o'): %s\n", (res_ft == res_org) ? "✅ OK" : "❌ FOUT");
	if (res_ft) printf("   Gevonden: %s\n", res_ft); // Moet "o" printen, niet "onjourno"

	// TEST 2: Karakter aan het begin
	res_ft = ft_strrchr(str, 'b');
	res_org = strrchr(str, 'b');
	printf("Test 2 ('b'):         %s\n", (res_ft == res_org) ? "✅ OK" : "❌ FOUT");

	// TEST 3: Karakter niet aanwezig
	res_ft = ft_strrchr(str, 'z');
	res_org = strrchr(str, 'z');
	printf("Test 3 ('z'):         %s\n", (res_ft == res_org) ? "✅ OK" : "❌ FOUT");

	// TEST 4: Zoeken naar de '\0'
	res_ft = ft_strrchr(str, '\0');
	res_org = strrchr(str, '\0');
	printf("Test 4 ('\\0'):       %s\n", (res_ft == res_org) ? "✅ OK" : "❌ FOUT");

	// TEST 5: Lege string zoeken naar 'a'
	res_ft = ft_strrchr("", 'a');
	res_org = strrchr("", 'a');
	printf("Test 5 (leeg):        %s\n", (res_ft == res_org) ? "✅ OK" : "❌ FOUT");

	printf("\n--- EINDE TESTS ---\n");
	

	printf("Test 1 (gelijk tot n): %d\n", ft_strncmp("abcde", "abczz", 3)); // Moet 0 zijn
	printf("Test 2 (verschil):      %d\n", ft_strncmp("abcde", "abczz", 4)); // Moet negatief zijn

	return (0);*/
}

