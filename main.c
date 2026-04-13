/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkotan <mkotan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 14:55:31 by mkotan            #+#    #+#             */
/*   Updated: 2026/04/13 14:55:33 by mkotan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int     fd;
    char    *line;
    int     count;

    // --- TEST 1: Normal dosya okuma ---
    printf("=== TEST 1: Dosya okuma ===\n");
    fd = open("test.txt", O_RDONLY);
    if (fd == -1) { printf("test.txt bulunamadi!\n"); return 1; }
    count = 1;
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("Satir %d: %s", count++, line);
        free(line);
    }
    close(fd);

    // --- TEST 2: Stdin (Ctrl+D ile bitir) ---
    printf("\n=== TEST 2: Stdin ===\n");
    printf("Bir şeyler yaz (Ctrl+D ile bitir):\n");
    while ((line = get_next_line(0)) != NULL)
    {
        printf("Okudum: %s", line);
        free(line);
    }

    // --- TEST 3: Geçersiz fd ---
    printf("\n=== TEST 3: Gecersiz fd ===\n");
    line = get_next_line(-1);
    printf("fd=-1 sonucu: %s\n", line == NULL ? "NULL (dogru)" : "HATA");

    return 0;
}
