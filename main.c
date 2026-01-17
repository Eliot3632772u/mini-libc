#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "libft.h"

// Color codes for output
#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define BLUE "\033[0;34m"
#define YELLOW "\033[0;33m"
#define RESET "\033[0m"

// Comment this out if you haven't implemented bonus functions yet
#define BONUS_IMPLEMENTED

void print_test_header(const char *name) {
    printf("\n" BLUE "=== Testing %s ===" RESET "\n", name);
}

void print_result(int passed) {
    if (passed)
        printf(GREEN "✓ PASS" RESET "\n");
    else
        printf(RED "✗ FAIL" RESET "\n");
}

// ============ PART 1 TESTS ============

void test_isalpha(void) {
    print_test_header("ft_isalpha");
    
    printf("Testing 'a': ");
    print_result(ft_isalpha('a') != 0);
    
    printf("Testing 'Z': ");
    print_result(ft_isalpha('Z') != 0);
    
    printf("Testing '5': ");
    print_result(ft_isalpha('5') == 0);
    
    printf("Testing ' ': ");
    print_result(ft_isalpha(' ') == 0);
}

void test_isdigit(void) {
    print_test_header("ft_isdigit");
    
    printf("Testing '5': ");
    print_result(ft_isdigit('5') != 0);
    
    printf("Testing '0': ");
    print_result(ft_isdigit('0') != 0);
    
    printf("Testing 'a': ");
    print_result(ft_isdigit('a') == 0);
}

void test_isalnum(void) {
    print_test_header("ft_isalnum");
    
    printf("Testing 'a': ");
    print_result(ft_isalnum('a') != 0);
    
    printf("Testing '5': ");
    print_result(ft_isalnum('5') != 0);
    
    printf("Testing '@': ");
    print_result(ft_isalnum('@') == 0);
}

void test_isascii(void) {
    print_test_header("ft_isascii");
    
    printf("Testing 'a': ");
    print_result(ft_isascii('a') != 0);
    
    printf("Testing 127: ");
    print_result(ft_isascii(127) != 0);
    
    printf("Testing 128: ");
    print_result(ft_isascii(128) == 0);
}

void test_isprint(void) {
    print_test_header("ft_isprint");
    
    printf("Testing 'a': ");
    print_result(ft_isprint('a') != 0);
    
    printf("Testing ' ': ");
    print_result(ft_isprint(' ') != 0);
    
    printf("Testing '\\n': ");
    print_result(ft_isprint('\n') == 0);
}

void test_strlen(void) {
    print_test_header("ft_strlen");
    
    printf("Testing \"Hello\": ");
    print_result(ft_strlen("Hello") == 5);
    
    printf("Testing \"\": ");
    print_result(ft_strlen("") == 0);
    
    printf("Testing \"42\": ");
    print_result(ft_strlen("42") == 2);
}

void test_memset(void) {
    print_test_header("ft_memset");
    
    char buf1[10];
    char buf2[10];
    
    ft_memset(buf1, 'A', 5);
    memset(buf2, 'A', 5);
    
    printf("Testing memset with 'A': ");
    print_result(memcmp(buf1, buf2, 5) == 0);
}

void test_bzero(void) {
    print_test_header("ft_bzero");
    
    char buf[10] = "123456789";
    ft_bzero(buf, 5);
    
    printf("Testing bzero first 5 bytes: ");
    print_result(buf[0] == 0 && buf[4] == 0 && buf[5] == '6');
}

void test_memcpy(void) {
    print_test_header("ft_memcpy");
    
    char src[] = "Hello World";
    char dst1[20];
    char dst2[20];
    
    ft_memcpy(dst1, src, strlen(src) + 1);
    memcpy(dst2, src, strlen(src) + 1);
    
    printf("Testing memcpy: ");
    print_result(strcmp(dst1, dst2) == 0);
}

void test_memmove(void) {
    print_test_header("ft_memmove");
    
    char str1[] = "Hello World";
    char str2[] = "Hello World";
    
    ft_memmove(str1 + 3, str1, 5);
    memmove(str2 + 3, str2, 5);
    
    printf("Testing memmove with overlap: ");
    print_result(strcmp(str1, str2) == 0);
}

void test_strlcpy(void) {
    print_test_header("ft_strlcpy");
    
    char dst[10];
    size_t result = ft_strlcpy(dst, "Hello World", 10);
    
    printf("Testing strlcpy: ");
    print_result(strcmp(dst, "Hello Wor") == 0 && result == 11);
}

void test_strlcat(void) {
    print_test_header("ft_strlcat");
    
    char dst[20] = "Hello ";
    size_t result = ft_strlcat(dst, "World", 20);
    
    printf("Testing strlcat: ");
    print_result(strcmp(dst, "Hello World") == 0 && result == 11);
}

void test_toupper(void) {
    print_test_header("ft_toupper");
    
    printf("Testing 'a': ");
    print_result(ft_toupper('a') == 'A');
    
    printf("Testing 'Z': ");
    print_result(ft_toupper('Z') == 'Z');
}

void test_tolower(void) {
    print_test_header("ft_tolower");
    
    printf("Testing 'A': ");
    print_result(ft_tolower('A') == 'a');
    
    printf("Testing 'z': ");
    print_result(ft_tolower('z') == 'z');
}

void test_strchr(void) {
    print_test_header("ft_strchr");
    
    char *str = "Hello World";
    char *result = ft_strchr(str, 'W');
    
    printf("Testing strchr for 'W': ");
    print_result(result == str + 6);
    
    printf("Testing strchr for 'Z': ");
    print_result(ft_strchr(str, 'Z') == NULL);
}

void test_strrchr(void) {
    print_test_header("ft_strrchr");
    
    char *str = "Hello World";
    char *result = ft_strrchr(str, 'o');
    
    printf("Testing strrchr for 'o': ");
    print_result(result == str + 7);
}

void test_strncmp(void) {
    print_test_header("ft_strncmp");
    
    printf("Testing \"Hello\" vs \"Hello\": ");
    print_result(ft_strncmp("Hello", "Hello", 5) == 0);
    
    printf("Testing \"Hello\" vs \"World\": ");
    print_result(ft_strncmp("Hello", "World", 5) < 0);
}

void test_memchr(void) {
    print_test_header("ft_memchr");
    
    char str[] = "Hello World";
    void *result = ft_memchr(str, 'W', 11);
    
    printf("Testing memchr for 'W': ");
    print_result(result == (void *)(str + 6));
}

void test_memcmp(void) {
    print_test_header("ft_memcmp");
    
    printf("Testing equal strings: ");
    print_result(ft_memcmp("Hello", "Hello", 5) == 0);
    
    printf("Testing different strings: ");
    print_result(ft_memcmp("Hello", "World", 5) != 0);
}

void test_strnstr(void) {
    print_test_header("ft_strnstr");
    
    char *result = ft_strnstr("Hello World", "World", 11);
    
    printf("Testing strnstr for \"World\": ");
    print_result(result != NULL && strcmp(result, "World") == 0);
    
    printf("Testing strnstr with short len: ");
    print_result(ft_strnstr("Hello World", "World", 5) == NULL);
}

void test_atoi(void) {
    print_test_header("ft_atoi");
    
    printf("Testing \"42\": ");
    print_result(ft_atoi("42") == 42);
    
    printf("Testing \"-42\": ");
    print_result(ft_atoi("-42") == -42);
    
    printf("Testing \"  123\": ");
    print_result(ft_atoi("  123") == 123);
}

void test_calloc(void) {
    print_test_header("ft_calloc");
    
    int *arr = ft_calloc(5, sizeof(int));
    
    printf("Testing calloc (all zeros): ");
    print_result(arr != NULL && arr[0] == 0 && arr[4] == 0);
    
    free(arr);
}

void test_strdup(void) {
    print_test_header("ft_strdup");
    
    char *dup = ft_strdup("Hello");
    
    printf("Testing strdup: ");
    print_result(dup != NULL && strcmp(dup, "Hello") == 0);
    
    free(dup);
}

// ============ PART 2 TESTS ============

void test_substr(void) {
    print_test_header("ft_substr");
    
    char *sub = ft_substr("Hello World", 6, 5);
    
    printf("Testing substr: ");
    print_result(sub != NULL && strcmp(sub, "World") == 0);
    
    free(sub);
}

void test_strjoin(void) {
    print_test_header("ft_strjoin");
    
    char *joined = ft_strjoin("Hello ", "World");
    
    printf("Testing strjoin: ");
    print_result(joined != NULL && strcmp(joined, "Hello World") == 0);
    
    free(joined);
}

void test_strtrim(void) {
    print_test_header("ft_strtrim");
    
    char *trimmed = ft_strtrim("  Hello World  ", " ");
    
    printf("Testing strtrim: ");
    print_result(trimmed != NULL && strcmp(trimmed, "Hello World") == 0);
    
    free(trimmed);
}

void test_split(void) {
    print_test_header("ft_split");
    
    char **arr = ft_split("Hello,World,42", ',');
    
    printf("Testing split: ");
    print_result(arr != NULL && strcmp(arr[0], "Hello") == 0 && 
                 strcmp(arr[1], "World") == 0 && strcmp(arr[2], "42") == 0);
    
    for (int i = 0; arr[i]; i++)
        free(arr[i]);
    free(arr);
}

void test_itoa(void) {
    print_test_header("ft_itoa");
    
    char *str = ft_itoa(-42);
    
    printf("Testing itoa(-42): ");
    print_result(str != NULL && strcmp(str, "-42") == 0);
    
    free(str);
    
    str = ft_itoa(0);
    printf("Testing itoa(0): ");
    print_result(str != NULL && strcmp(str, "0") == 0);
    free(str);
    
    str = ft_itoa(-2147483648);
    printf("Testing itoa(INT_MIN): ");
    print_result(str != NULL && strcmp(str, "-2147483648") == 0);
    free(str);
}

char test_map_func(unsigned int i, char c) {
    (void)i;
    return ft_toupper(c);
}

void test_strmapi(void) {
    print_test_header("ft_strmapi");
    
    char *mapped = ft_strmapi("hello", test_map_func);
    
    printf("Testing strmapi: ");
    print_result(mapped != NULL && strcmp(mapped, "HELLO") == 0);
    
    free(mapped);
}

void test_iter_func(unsigned int i, char *c) {
    (void)i;
    *c = ft_toupper(*c);
}

void test_striteri(void) {
    print_test_header("ft_striteri");
    
    char str[] = "hello";
    ft_striteri(str, test_iter_func);
    
    printf("Testing striteri: ");
    print_result(strcmp(str, "HELLO") == 0);
}

void test_putchar_fd(void) {
    print_test_header("ft_putchar_fd");
    
    printf("Testing putchar_fd (check output): ");
    ft_putchar_fd('X', 1);
    printf(" ");
    print_result(1);
}

void test_putstr_fd(void) {
    print_test_header("ft_putstr_fd");
    
    printf("Testing putstr_fd (check output): ");
    ft_putstr_fd("Hello", 1);
    printf(" ");
    print_result(1);
}

void test_putendl_fd(void) {
    print_test_header("ft_putendl_fd");
    
    printf("Testing putendl_fd (check output): ");
    ft_putendl_fd("Hello", 1);
    print_result(1);
}

void test_putnbr_fd(void) {
    print_test_header("ft_putnbr_fd");
    
    printf("Testing putnbr_fd (check output): ");
    ft_putnbr_fd(-42, 1);
    printf(" ");
    print_result(1);
}

// ============ PART 3 TESTS (BONUS) ============

#ifdef BONUS_IMPLEMENTED

void test_lstnew(void) {
    print_test_header("ft_lstnew");
    
    char *content = "Hello";
    t_list *node = ft_lstnew(content);
    
    printf("Testing lstnew: ");
    print_result(node != NULL && node->content == content && node->next == NULL);
    
    free(node);
}

void test_lstadd_front(void) {
    print_test_header("ft_lstadd_front");
    
    t_list *lst = ft_lstnew("Second");
    t_list *new = ft_lstnew("First");
    
    ft_lstadd_front(&lst, new);
    
    printf("Testing lstadd_front: ");
    print_result(lst == new && strcmp((char *)new->next->content, "Second") == 0);
    
    free(lst->next);
    free(lst);
}

void test_lstsize(void) {
    print_test_header("ft_lstsize");
    
    t_list *lst = ft_lstnew("1");
    lst->next = ft_lstnew("2");
    lst->next->next = ft_lstnew("3");
    
    printf("Testing lstsize: ");
    print_result(ft_lstsize(lst) == 3);
    
    free(lst->next->next);
    free(lst->next);
    free(lst);
}

void test_lstlast(void) {
    print_test_header("ft_lstlast");
    
    t_list *lst = ft_lstnew("1");
    t_list *last = ft_lstnew("3");
    lst->next = ft_lstnew("2");
    lst->next->next = last;
    
    printf("Testing lstlast: ");
    print_result(ft_lstlast(lst) == last);
    
    free(lst->next->next);
    free(lst->next);
    free(lst);
}

void test_lstadd_back(void) {
    print_test_header("ft_lstadd_back");
    
    t_list *lst = ft_lstnew("First");
    t_list *new = ft_lstnew("Last");
    
    ft_lstadd_back(&lst, new);
    
    printf("Testing lstadd_back: ");
    print_result(ft_lstlast(lst) == new);
    
    free(lst->next);
    free(lst);
}

void del_content(void *content) {
    (void)content;
}

void test_lstdelone(void) {
    print_test_header("ft_lstdelone");
    
    char *str = strdup("Test");
    t_list *node = ft_lstnew(str);
    
    ft_lstdelone(node, free);
    
    printf("Testing lstdelone: ");
    print_result(1); // If no crash, it works
}

void test_lstclear(void) {
    print_test_header("ft_lstclear");
    
    t_list *lst = ft_lstnew(strdup("1"));
    lst->next = ft_lstnew(strdup("2"));
    lst->next->next = ft_lstnew(strdup("3"));
    
    ft_lstclear(&lst, free);
    
    printf("Testing lstclear: ");
    print_result(lst == NULL);
}

void iter_toupper(void *content) {
    char *str = (char *)content;
    while (*str) {
        *str = ft_toupper(*str);
        str++;
    }
}

void test_lstiter(void) {
    print_test_header("ft_lstiter");
    
    char str1[] = "hello";
    char str2[] = "world";
    t_list *lst = ft_lstnew(str1);
    lst->next = ft_lstnew(str2);
    
    ft_lstiter(lst, iter_toupper);
    
    printf("Testing lstiter: ");
    print_result(strcmp(str1, "HELLO") == 0 && strcmp(str2, "WORLD") == 0);
    
    free(lst->next);
    free(lst);
}

void *map_duplicate(void *content) {
    return strdup((char *)content);
}

void test_lstmap(void) {
    print_test_header("ft_lstmap");
    
    t_list *lst = ft_lstnew("Hello");
    lst->next = ft_lstnew("World");
    
    t_list *new_lst = ft_lstmap(lst, map_duplicate, free);
    
    printf("Testing lstmap: ");
    print_result(new_lst != NULL && new_lst != lst && 
                 strcmp((char *)new_lst->content, "Hello") == 0);
    
    ft_lstclear(&new_lst, free);
    free(lst->next);
    free(lst);
}

#endif // BONUS_IMPLEMENTED

// ============ MAIN ============

int main(void) {
    printf(BLUE "\n╔════════════════════════════════════╗\n");
    printf("║   LIBFT COMPREHENSIVE TEST SUITE   ║\n");
    printf("╚════════════════════════════════════╝\n" RESET);
    
    printf(BLUE "\n▶ PART 1 - Libc Functions\n" RESET);
    test_isalpha();
    test_isdigit();
    test_isalnum();
    test_isascii();
    test_isprint();
    test_strlen();
    test_memset();
    test_bzero();
    test_memcpy();
    test_memmove();
    test_strlcpy();
    test_strlcat();
    test_toupper();
    test_tolower();
    test_strchr();
    test_strrchr();
    test_strncmp();
    test_memchr();
    test_memcmp();
    test_strnstr();
    test_atoi();
    test_calloc();
    test_strdup();
    
    printf(BLUE "\n▶ PART 2 - Additional Functions\n" RESET);
    test_substr();
    test_strjoin();
    test_strtrim();
    test_split();
    test_itoa();
    test_strmapi();
    test_striteri();
    test_putchar_fd();
    test_putstr_fd();
    test_putendl_fd();
    test_putnbr_fd();
    
#ifdef BONUS_IMPLEMENTED
    printf(BLUE "\n▶ PART 3 - Bonus (Linked Lists)\n" RESET);
    test_lstnew();
    test_lstadd_front();
    test_lstsize();
    test_lstlast();
    test_lstadd_back();
    test_lstdelone();
    test_lstclear();
    test_lstiter();
    test_lstmap();
#else
    printf(YELLOW "\n▶ PART 3 - Bonus (Linked Lists) - SKIPPED\n" RESET);
    printf(YELLOW "   Uncomment #define BONUS_IMPLEMENTED at the top of this file\n");
    printf(YELLOW "   after implementing bonus functions.\n" RESET);
#endif
    
    printf(BLUE "\n╔════════════════════════════════════╗\n");
    printf("║        TESTS COMPLETED!            ║\n");
    printf("╚════════════════════════════════════╝\n" RESET);
    
    return 0;
}