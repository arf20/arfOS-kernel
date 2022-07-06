// string.h: Standard C string manipulation library implementation

#include "string.h"
#include "../api/defs.h"

const char *strcpy(char *dst, const char *src) {
	size_t i = 0;
	while (src[i] != '\0') {
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return dst;
}

const char *strncpy(char *dst, const char *src, size_t count) {
	size_t i;
	for (i = 0; i < count; i++) {
		dst[i] = src[i];
	}
	dst[i] = '\0';
	return dst;
}

const char *strcat(char *dst, const char *src) {
	size_t i = 0;
	size_t j = 0;
	while (dst[i] != '\0') { i++; }
	while (src[j] != '\0') {
		dst[i] = src[j];
		i++; j++;
	}
	dst[i] = '\0';
	return dst;
}

const char *strncat(char *dst, const char *src, size_t count) {
	size_t i = 0;
	while (dst[i] != '\0') { i++; }
	for (size_t j = 0; j < count; i++, j++) {
		dst[i] = src[j];
	}
	dst[i] = '\0';
	return dst;
}

size_t strlen(const char *str) {
	size_t i = 0;
	while (str[i] != '\0') { i++; }
	return i;
}

int strcmp(const char *str1, const char *str2) {
	int t = 0;
	size_t i = 0;
	while (str1[i] != '\0' && str2[i] != '\0') {
		t += str1[i] - str2[i];
		i++;
	}
	return t;
}

int strncmp(const char *str1, const char *str2, size_t count) {
	int t = 0;
	for (size_t i = 0; i < count; i++) {
		t += str1[i] - str2[i];
	}
	return t;
}

const char *strchr(const char *str, const char c) {
	size_t i = 0;
	while (str[i] != c) {
		if (str[i] == '\0') return NULL;
		i++;
	}
	return (char*)str + i;
}

const char *strrchr(const char *str, const char c) {
	size_t i = 0;
	while (str[i] != '\0') { i++; }
	while (str[i] != c) {
		if (i == 0) return NULL;
		i--;
	}
	return (char*)str + i;
}

size_t strspn(const char *str, const char *set) {
	size_t t = 0;
	size_t i = 0;
	bool c = false;
	while (str[i] != '\0') {
		size_t j = 0;
		c = false;
		while (set[j] != '\0') {
			if (str[i] == set[j]) { c = true; break; }
			j++;
		}
		if (c) { t++; }
		else return t;
		i++;
	}
	return t;
}

size_t strcspn(const char *str, const char *set) {
	size_t t = 0;
	size_t i = 0;
	bool c = false;
	while (str[i] != '\0') {
		size_t j = 0;
		c = false;
		while (set[j] != '\0') {
			if (str[i] == set[j]) { c = true; break; }
			j++;
		}
		if (c) { return i; }
		i++;
	}
	return i;
}

const char *strpbrk(const char *str, const char *set) {
	size_t t = 0;
	size_t i = 0;
	bool c = false;
	while (str[i] != '\0') {
		size_t j = 0;
		c = false;
		while (set[j] != '\0') {
			if (str[i] == set[j]) { c = true; break; }
			j++;
		}
		if (c) { return str + i; }
		i++;
	}
	return str + i;
}

const char *strstr(const char *str1, const char *str2) {
    size_t i = 0;
    while (str2[i] != '\0') {
        if (str1[i] == '\0') return NULL;
        if (str1[i] != str2[i]) { str1++; i = 0; continue; }
        i++;
    }
    return str1;
}