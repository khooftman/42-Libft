/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khooftma <khooftma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 11:45:57 by khooftma          #+#    #+#             */
/*   Updated: 2026/04/22 12:18:36 by khooftma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "libft.h"

int	main(void)
{
	/*
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
	*/
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
	return (0);
}


